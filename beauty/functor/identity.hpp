
#ifndef beauty__functor___identity_hpp
#define beauty__functor___identity_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct identity:
	public beauty::functor::unary_function<T, T>{
	
	const T& operator () (const T &a)const{
		return a;
	}	
};


}
}
#endif
