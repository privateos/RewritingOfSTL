
#ifndef beauty__adapter__function_pointer_adapter___mem_fun1_t_hpp
#define beauty__adapter__function_pointer_adapter___mem_fun1_t_hpp

#include<./beauty/functor/binary_function.hpp>

namespace beauty{namespace adapter{namespace function_pointer_adapter{

template<class S, class T, class A>
class mem_fun1_t:
	public beauty::functor::binary_function<T*, A, S>{
	
	protected:
	S (T::*f)(A);
	
	public:
	explicit mem_fun1_t(S (T::*x)(A)):f(x){}
	
	S operator () (T *p, A x)const{
		return (p->*f)(x);
	}	
};



}
}
}
#endif
