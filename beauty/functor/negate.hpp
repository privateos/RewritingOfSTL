
#ifndef beauty__functor___negate_hpp
#define beauty__functor___negate_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace functor{

template<class T>
struct negate:
	public beauty::functor::unary_function<T, T>{
	T operator () (const T &x)const{
		return -x;
	}
};

}
}
#endif
