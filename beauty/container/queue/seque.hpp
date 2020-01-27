
#ifndef beauty__container__queue___seque_hpp
#define beauty__container__queue___seque_hpp

#include<./beauty/types.hpp>
#include<./beauty/container/list/seqlist.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>

namespace beauty{namespace container{namespace queue{


static const beauty::size_t seque_default_size = 16;

template<class T, class alloc = beauty::allocator::allocator>
class seque{
	public:
	//typedef void                                  iterator; 
	//typedef void                            const_iterator;
	typedef T                                   value_type;
	typedef value_type&                          reference;
	typedef const value_type&              const_reference;
	//typedef value_type*                            pointer;
	//typedef const value_type*                const_pointer;
	typedef beauty::ptrdiff_t              difference_type;
	typedef beauty::size_t                       size_type;
	
	protected:
	typedef seque<T, alloc>                           self;
	typedef T                                         node;
	typedef T*                                   link_type;
	typedef beauty::allocator::
		simple_allocator<node, alloc>            allocator;
		
	link_type m_array;
	size_type m_head;
	size_type m_tail;
	size_type m_array_size;
	size_type m_use_size;
	
	void initialize(){
		m_array = allocator::allocate(m_array_size);
	}
	
	
	public:
	seque():m_head(0), m_tail(0), m_use_size(0),
		m_array_size(seque_default_size){
		initialize();	
	}
	
	seque(size_type n):m_head(0), m_tail(0), m_use_size(0),
		m_array_size(n){
		initialize();	
	}
	
	seque(const self &q):m_head(0), m_tail(q.m_use_size - 1),
		 m_use_size(q.m_use_size), m_array_size(q.m_array_size){
		 	
		initialize();		
		
		link_type p = m_array;
		size_type n = 0;
		
		while(n < m_use_size){
			beauty::allocator::function::
				construct(p, *(q.m_array + (q.m_head + n)%m_array_size));
			++p;
			++n;
		}
	}
	
	~seque(){
		clear();
		allocator::deallocate(m_array, m_array_size);
	}
	
	void clear(){
		if(m_use_size){
			if(m_head < m_tail){
				beauty::allocator::function::
					destroy(m_array + m_head, m_array + m_tail + 1);
			}else{
				beauty::allocator::function::
					destroy(m_array + m_head, m_array + m_array_size);
				beauty::allocator::function::
					destroy(m_array, m_array + m_tail + 1);
			}
			m_head = 0;
			m_tail = 0;
			m_use_size = 0;
		}
	}
	
	bool is_empty()const{
		return m_use_size == 0;
	}
	
	bool empty()const{
		return m_use_size == 0;
	}
	
	bool is_full()const{
		return m_use_size == m_array_size;
	}
	
	bool full()const{
		return m_use_size == m_array_size;
	}
	
	size_type size()const{
		return m_use_size;
	}
	
	size_type max_size()const{
		return m_array_size;
	}
	
	void push(const value_type &v){
		m_tail = (m_tail + 1)%m_array_size;
		beauty::allocator::function::
			construct(m_array + m_tail, v);
	}
	
	void pop(){
		beauty::allocator::function::
			destroy(m_array + m_head);
		m_head = (m_head + 1)%m_array_size;
	}
	
	reference top(){
		return m_array[m_head];
	}
	
	const_reference top()const{
		return m_array[m_head];
	}
	
	reference front(){
		return m_array[m_head];
	}
	
	const_reference front()const{
		return m_array[m_head];
	}
	
	reference back(){
		return m_array[m_tail];
	}
	
	const_reference back()const{
		return m_array[m_tail];
	}
	
	void swap(self &q){
		if(this != &q){
			link_type tmp_link = m_array;
			m_array = q.m_array;
			q.m_array = tmp_link;
			
			size_type tmp_size = m_head;
			m_head = q.m_head;
			q.m_head = tmp_size;
			
			tmp_size = m_tail;
			m_tail = q.m_tail;
			q.m_tail = tmp_size;
			
			tmp_size = m_array_size;
			m_array_size = q.m_array_size;
			q.m_array_size = tmp_size;
			
			tmp_size = m_use_size;
			m_use_size = q.m_use_size;
			q.m_use_size = tmp_size;
		}
	}
};

template<class T, class alloc>
inline void swap(seque<T, alloc> &a, seque<T, alloc> &b){
	a.swap(b);
}

}
}
}

#endif
