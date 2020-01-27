
#ifndef beauty__container__array___tree_array_hpp
#define beauty__container__array___tree_array_hpp

#include<./beauty/config.hpp>
#include<./beauty/types.hpp>
#include<./beauty/header.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>

namespace beauty{namespace container{namespace array{

template<class INT_TYPE, class alloc = beauty::allocator::allocator>
class tree_array{
	public:
	//typedef void                     iterator;
	//typedef void               const_iterator;
	typedef INT_TYPE               value_type;
	typedef value_type*               pointer;
	typedef const value_type*   const_pointer;
	typedef value_type&             reference;
	typedef const value_type& const_reference;
	typedef beauty::ptrdiff_t difference_type;
	typedef beauty::size_t          size_type;
	
	protected:
	typedef tree_array<INT_TYPE, alloc>  self;
	typedef beauty::allocator::
		simple_allocator<value_type, alloc>
					                allocator;
	
	size_type m_length;
	pointer m_array;
	
	void initialize(size_type n){
		m_array = allocator::allocate(n);
		std::memset(m_array, 0, sizeof(value_type)*n);
	}
	
	void destroy(){
		if(m_length){
			allocator::deallocate(m_array, m_length);
			m_array = nullptr;
			m_length = 0;
		}	
	}
	
	size_type lowbit(size_type x)const{
		return x&(-x);
	}
	public:
	tree_array(size_type n):m_array(nullptr), m_length(n){
		initialize(n);
	}
	
	tree_array(const self& ta):m_array(nullptr), m_length(0){
		*this = ta;
	}
	
	~tree_array(){
		destroy();
	}
	
	value_type sum(size_type n)const{
		//check n if n > m_length throw exception
		
		value_type t_sum = 0;
		while(n){
			t_sum += m_array[n - 1];
			n -= lowbit(n);
		}
		return t_sum;
	}
	
	void change(size_type pos, value_type old_value, value_type new_value){
		//check pos if pos >= m_length throw exception
		if(old_value < new_value){
			value_type val = new_value - old_value;
			while(pos < m_length){
				m_array[pos] += val;
				pos += lowbit(pos + 1);
			}
		}else{
			if(new_value < old_value){
				value_type val = old_value - new_value;
				while(pos < m_length){
					m_array[pos] -= val;
					pos += lowbit(pos + 1);
				}
			}
		}
	}
	
	void clear(){
		std::memset(m_array, 0, sizeof(value_type)*m_length);
	}
	
	self& operator = (const self &ta){
		if(this != &ta){
			if(m_length != ta.m_length){
				pointer p = allocator::allocate(ta.m_length);
				beauty::algorithm::algorithmbase::
					copy(ta.m_array, ta.m_array + ta.m_length, p);
				destroy();
				m_array = p;
				m_length = ta.m_length;
				
			}else{
				beauty::algorithm::algorithmbase::
					copy(ta.m_array, ta.m_array + m_length, m_array);
			}
		}
		return *this;
	}
	
	void swap(self &ta){
		if(this != &ta){
			pointer tmp_array = m_array;
			size_type tmp_length = m_length;
			m_array = ta.m_array;
			m_length = ta.m_length;
			ta.m_array = tmp_array;
			ta.m_length = tmp_length;
		}
	}
};

template<class INT_TYPE, class alloc>
inline void swap(tree_array<INT_TYPE, alloc> &a, tree_array<INT_TYPE, alloc> &b){
	a.swap(b);
}


}
}
}


#endif
