
#ifndef beauty__functor___divides_hpp
#define beauty__functor___divides_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct divides:
	public beauty::functor::binary_function<T, T, T>{
	T operator () (const T &x, const T &y)const{
		return x / y;
	}
};

}
}
#endif
