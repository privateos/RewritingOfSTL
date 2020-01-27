
#ifndef beauty__functor___modulus_hpp
#define beauty__functor___modulus_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct modulus:
	public beauty::functor::binary_function<T, T, T>{
	T operator () (const T &x, const T &y)const{
		return x % y;
	}
};

}
}
#endif
