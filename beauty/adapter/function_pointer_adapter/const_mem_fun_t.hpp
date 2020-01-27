
#ifndef beauty__adapter__function_pointer_adapter___const_mem_fun_t_hpp
#define beauty__adapter__function_pointer_adapter___const_mem_fun_t_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{

template<class S, class T>
class const_mem_fun_t:
	public beauty::functor::unary_function<T*, S>{
	
	protected:
	S (T::*f)()const;
	
	public:
	explicit const_mem_fun_t(S (T::*x)()const):f(x){}
	
	S operator () (const T *p)const{
		return (p->*f)();
	}	
};



}
}
}
#endif
