
#ifndef beauty__functor___logical_and_hpp
#define beauty__functor___logical_and_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct logical_and:
	public beauty::functor::binary_function<T, T, T>{
	T operator () (const T &x, const T &y)const{
		return x&&y;
	}	
};


}
}
#endif
