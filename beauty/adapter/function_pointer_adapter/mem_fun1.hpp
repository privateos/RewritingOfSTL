
#ifndef beauty__adapter__function_pointer_adapter___mem_fun1_hpp
#define beauty__adapter__function_pointer_adapter___mem_fun1_hpp

#include<./beauty/adapter/function_pointer_adapter/mem_fun1_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/const_mem_fun1_t.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{



template<class S, class T, class A>
inline beauty::adapter::function_pointer_adapter::
mem_fun1_t<S, T, A>
	mem_fun1(S (T::*x)(A)){

	return beauty::adapter::function_pointer_adapter::
		mem_fun1_t<S, T, A>(x);
}

template<class S, class T, class A>
inline beauty::adapter::function_pointer_adapter::
const_mem_fun1_t<S, T, A>
	mem_fun1(S (T::*x)(A)const){
	
	return beauty::adapter::function_pointer_adapter::
		const_mem_fun1_t<S, T, A>(x);
}


}
}
}
#endif
