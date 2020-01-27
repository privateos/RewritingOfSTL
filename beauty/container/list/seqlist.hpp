
#ifndef beauty__container__list___seqlist_hpp
#define beauty__container__list___seqlist_hpp

#include<./beauty/types.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>
#include<./beauty/algorithm/algorithmbase/copy_backward.hpp>


namespace beauty{namespace container{namespace list{


static const beauty::size_t seqlist_default_size = 16;


template<class T, class alloc = beauty::allocator::allocator>
class seqlist{
	public:
	typedef T*                                      iterator;
	typedef const T*                          const_iterator;
	typedef T                                     value_type;
	typedef value_type&                            reference;
	typedef const value_type&                const_reference;
	typedef value_type*                              pointer;
	typedef const value_type*                  const_pointer;
	typedef beauty::ptrdiff_t                difference_type;
	typedef beauty::size_t                         size_type;
	
	protected:
	typedef beauty::allocator::simple_allocator<T, alloc>
										           allocator;
	typedef value_type                                  node;
	typedef node*                                  link_type;
	typedef seqlist<T, alloc>                           self;
	
	link_type m_array;
	size_type m_array_size;
	size_type m_end_flag;
	
	void initialize(){
		m_array = allocator::allocate(m_array_size);
	}
	
	
	public:
	seqlist():m_end_flag(0), m_array_size(seqlist_default_size){
		initialize();
	}
	
	seqlist(size_type n):m_end_flag(0), m_array_size(n){
		initialize();
	}
	
	seqlist(const self &L){
		m_array_size = L.m_array_size;
		m_end_flag = L.m_end_flag;
		initialize();
		
		while(m_end_flag){
			--m_end_flag;
			beauty::allocator::function::
				construct(m_array + m_end_flag,
				   *(L.m_array + m_end_flag));
		}
		m_end_flag = L.m_end_flag;
	}
	
	~seqlist(){
		clear();
		allocator::deallocate(m_array, m_array_size);
	}
	
	void clear(){
		beauty::allocator::function::
			destroy(m_array, m_array + m_end_flag);
		m_end_flag = 0; 
	}
	
	iterator begin(){
		return m_array;
	}
	
	const_iterator begin()const{
		return m_array;
	}
	
	iterator end(){
		return m_array + m_end_flag;
	}
	
	const_iterator end()const{
		return m_array + m_end_flag;
	}
	
	iterator head(){
		return m_array;
	}
	
	const_iterator head()const{
		return m_array;
	}
	
	iterator tail(){
		return m_end_flag == 0 ?
			(m_array) : (m_array + m_end_flag - 1);
	}
	
	const_iterator tail()const{
		return m_end_flag == 0 ?
			(m_array) : (m_array + m_end_flag - 1);	
	}
	
	bool is_empty()const{
		return m_end_flag == 0;
	}
	
	bool empty()const{
		return m_end_flag == 0;
	}
	
	bool is_full()const{
		return m_end_flag == m_array_size;
	}
	
	bool full()const{
		return m_end_flag == m_array_size;
	}
	
	size_type size()const{
		return m_end_flag;
	}
	
	size_type max_size()const{
		return m_array_size;
	}
	
	
	void push_back(const value_type &v){
		beauty::allocator::function::
			construct(m_array + m_end_flag, v);
		++m_end_flag;
	}
	
	void push_front(const value_type &v){
		if(m_end_flag){
			push_back(value_type());
			beauty::algorithm::algorithmbase::
				copy_backward(m_array,
					 m_array + m_end_flag - 1, m_array + m_end_flag);
			*m_array = v;
		}else{
			push_back(v);
		}
	}
	
	void append(const value_type &v){
		push_back(v);
	}
	
	void pop_front(){
		beauty::algorithm::algorithmbase::
			copy(m_array + 1, m_array + m_end_flag, m_array);
		--m_end_flag;
		beauty::allocator::function::
			destroy(m_array + m_end_flag);
	}
	
	void pop_back(){
		--m_end_flag;
		beauty::allocator::function::
			destroy(m_array + m_end_flag);
	}
	
	void insert(size_type index, const value_type &v){
		if(index == m_end_flag){
			push_back(v);
		}else{
			push_back(value_type());
			beauty::algorithm::algorithmbase::
				copy_backward(m_array + index,
					m_array + m_end_flag - 1, m_array + m_end_flag);
			*(m_array + index) = v;
		}
	}
	
	void erase(size_type index){
		if(index == 0){
			pop_front();
		}else{
			beauty::algorithm::algorithmbase::
				copy(m_array + index + 1, m_array + m_end_flag,
						m_array + index);
			--m_end_flag;
			beauty::allocator::function::
				destroy(m_array + m_end_flag);
		}
	}
	
	iterator erase(iterator pos){
		if(pos == m_array + m_end_flag){
			pop_back();
			return tail();
		}else{
			erase(pos - m_array);
			return pos;
		}
	}
	
	const_iterator erase(const_iterator pos){
		if(pos == m_array + m_end_flag){
			pop_back();
			return tail();
		}else{
			erase(pos - m_array);
			return pos;
		}
	}
	
	reference front(){
		return *m_array;
	}
	
	const_reference front()const{
		return *m_array;
	}
	
	reference back(){
		return m_array[m_end_flag - 1];
	}
	
	const_reference back()const{
		return m_array[m_end_flag - 1];
	}
	
	reference at(size_type index){
		return m_array[index];
	}
	
	const_reference at(size_type index)const{
		return m_array[index];
	}
	
	void swap(self &L){
		if(this != &L){
			link_type tmp_link = m_array;
			m_array = L.m_array;
			L.m_array = tmp_link;
			
			size_type tmp_size = m_array_size;
			m_array_size = L.m_array_size;
			L.m_array_size = tmp_size;
			
			tmp_size = m_end_flag;
			m_end_flag = L.m_end_flag;
			L.m_end_flag = tmp_size;
		}
		
	}
	
	reference operator [] (size_type index){
		return m_array[index];
	}
	
	const_reference operator [] (size_type index)const{
		return m_array[index];
	}
};

template<class T, class alloc>
inline void swap(seqlist<T, alloc> &a, seqlist<T, alloc> &b){
	a.swap(b);
}

}
}
}

#endif
