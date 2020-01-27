
#ifndef beauty__adapter__function_pointer_adapter___mem_fun_ref_t_hpp
#define beauty__adapter__function_pointer_adapter___mem_fun_ref_t_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{

template<class S, class T>
class mem_fun_ref_t:
	public beauty::functor::unary_function<T, S>{
	
	protected:
	S (T::*f)();
	
	public:
	explicit mem_fun_ref_t(S (T::*x)()):f(x){}
	
	S operator () (T &p)const{
		return (p.*f)();
	}	
};



}
}
}
#endif
