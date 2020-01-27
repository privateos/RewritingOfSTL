
#ifndef beauty__container__array___carray_hpp
#define beauty__container__array___carray_hpp

#include<./beauty/types.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>
#include<./beauty/algorithm/algorithmbase/fill.hpp>

namespace beauty{namespace container{namespace array{


template<class T, beauty::size_t Size>
class carray{
	public:
	const beauty::size_t &length;
	
	typedef T*                                   iterator;
	typedef const T*                       const_iterator;
	typedef T                                  value_type;
	typedef value_type&                         reference;
	typedef const value_type&             const_reference;
	typedef value_type*                           pointer;
	typedef const value_type*              const_pointer;
	typedef beauty::size_t                      size_type;
	typedef beauty::ptrdiff_t             difference_type;
	
	protected:
	typedef carray<T, Size>                          self;
	T array[Size];
	const size_type m_length;
	

	
	public:
	carray():m_length(Size), length(m_length){}
	
	carray(const self &x):m_length(Size), length(m_length){
		beauty::algorithm::algorithmbase::
			copy(x.array, x.array + Size, array);
	}
	
	carray(const value_type &x):m_length(Size), length(m_length){
		beauty::algorithm::algorithmbase::
			fill(array, array + m_length, x);
	}
	
	template<class InputIter>
	carray(InputIter first, InputIter last):m_length(Size), length(m_length){
		beauty::algorithm::algorithmbase::
			copy(first, last, array);
	}
	
	~carray(){}
	
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
	
	reference operator [] (const size_type n){
		return *(array + n);
	}
	
	const_reference operator [] (const size_type n)const{
		return *(array + n);
	}
	
	self& operator = (const self &x){
		if(this != &x){
			beauty::algorithm::algorithmbase::
				copy(x.array, x.array + Size, array);
		}
		return *this;
	}
	
	void swap(self &x){
		value_type tmp;
		size_type n = m_length;
		pointer p1 = array;
		pointer p2 = x.array;
		while(n != 0){
			tmp = *p1;
			*p1 = *p2;
			*p2 = tmp;
			++p1;
			++p2;
		}
	}
	
};

}
}
}
#endif
