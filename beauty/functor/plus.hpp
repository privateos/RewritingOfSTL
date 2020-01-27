
#ifndef beauty__functor___plus_hpp
#define beauty__functor___plus_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct plus:
	public beauty::functor	::binary_function<T, T, T>{
	T operator () (const T &x, const T &y)const{
		return x + y;
	}
};

}
}
#endif
