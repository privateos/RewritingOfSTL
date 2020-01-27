
#ifndef beauty__functor___equal_to_hpp
#define beauty__functor___equal_to_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct equal_to:
	public beauty::functor	::binary_function<T, T, bool>{
	bool operator () (const T &x, const T &y)const{
		return x == y;
	}
};

}
}
#endif
