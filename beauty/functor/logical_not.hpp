
#ifndef beauty__functor___logical_not_hpp
#define beauty__functor___logical_not_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct logical_not:
	public beauty::functor::unary_function<T, T>{
	T operator () (const T &x)const{
		return !x;
	}	
};


}
}
#endif
