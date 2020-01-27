
#ifndef beauty__functor___greater_equal_hpp
#define beauty__functor___greater_equal_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct greater_equal:
	public beauty::functor	::binary_function<T, T, bool>{
	bool operator () (const T &x, const T &y)const{
		return x >= y;
	}
};

}
}
#endif
