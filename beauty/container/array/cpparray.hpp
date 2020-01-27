
#ifndef beauty__container__array___cpparray_hpp
#define beauty__container__array___cpparray_hpp

#include<./beauty/types.hpp>
#include<./beauty/config.hpp>
#include<./beauty/allocator/function/uninitialized_fill_n.hpp>
#include<./beauty/allocator/function/uninitialized_copy.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>
#include<./beauty/algorithm/algorithmbase/fill.hpp>

namespace beauty{namespace container{namespace array{
	
template<class T, class alloc = 
beauty::allocator::allocator>
class cpparray{
	protected:
	typedef cpparray<T, alloc>                           self;
	typedef beauty::allocator::simple_allocator<T, alloc>
						                            allocator;


	T *array;
	beauty::size_t m_length;
	
	public:
	const beauty::size_t &length;

	public:
	typedef T*                                        iterator;
	typedef const T*                            const_iterator;
	typedef T                                       value_type;
	typedef T&                                       reference;
	typedef const T&                           const_reference;
	typedef T*                                         pointer;
	typedef const T*                             const_pointer;
	typedef beauty::size_t                           size_type;
	typedef beauty::ptrdiff_t                  difference_type;

	protected:

	void allocate(){
		array = allocator::allocate(m_length);
	}
	
	void deallocate(){
		allocator::deallocate(array, m_length);
		array = nullptr;
	}
	
	void clear(){
		beauty::allocator::function::
			destroy(array, array + m_length);
		deallocate();
	}

	void initialize(const value_type &x){
		allocate();
		beauty::allocator::function::
			uninitialized_fill_n(array, m_length, x);
	}

    void initialize(const self &x){
    	allocate();
    	beauty::allocator::function::
    		uninitialized_copy(x.array, x.array + m_length, array);
	}
	
	public:
	cpparray(size_type len):
		m_length(len),length(m_length){
		initialize(value_type());
	}
	
	cpparray(size_type len, const value_type &x):
		m_length(len), length(m_length){
		initialize(x);
	}
	
	cpparray(const self &x):
		m_length(x.m_length), length(m_length){
		initialize(x);
	}
	
//	cpparray

	~cpparray(){
		clear();
	}

	iterator begin(){
		return array;
	}
	
	const_iterator begin()const{
		return array;
	}
	
	iterator end(){
		return array + m_length;
	}
	
	const_iterator end()const{
		return array + m_length;
	}

	reference at(const size_type n){
		return array[n];
	}

	const_reference at(const size_type n)const{
		return array[n];
	}
	
	void reset(){
		beauty::algorithm::algorithmbase::
			fill(array, array + m_length, value_type());
	}
	
	void reset(const value_type &x){
		beauty::algorithm::algorithmbase::
			fill(array, array + m_length, x);
	}
	
	void swap(const self &x){
		size_type n = m_length;
		m_length = x.m_length;
		x.m_length = n;
		
		pointer p = array;
		array = x.array;
		x.array = p;
	}
	
	reference operator [] (const size_type n){
		return array[n];
	}
	
	const_reference operator [] (const size_type n)const{
		return array[n];
	}
	

	self& operator = (const self &x){
		if(this != &x){
			size_type n = (m_length < x.m_length) ? m_length : x.m_length;
			beauty::algorithm::algorithmbase::
				copy(x.array, x.array + m_length, array);
		}
		return *this;
	}

};

}
}
}
#endif
