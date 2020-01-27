
#ifndef beauty__adapter__function_pointer_adapter___const_mem_fun1_t_hp
#define beauty__adapter__function_pointer_adapter___const_mem_fun1_t_hp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{

template<class S, class T, class A>
class const_mem_fun1_t:
	public beauty::functor::binary_function<T*, A, S>{
	
	protected:
	S (T::*f)(A)const;
	
	public:
	explicit const_mem_fun1_t(S (T::*x)(A)const):f(x){}
	
	S operator () (T *p, A x)const{
		return (p->*f)(x);
	}	
};



}
}
}
#endif
