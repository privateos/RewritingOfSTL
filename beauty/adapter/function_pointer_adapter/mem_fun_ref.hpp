
#ifndef beauty__adapter__function_pointer_adapter___mem_fun_ref_hpp
#define beauty__adapter__function_pointer_adapter___mem_fun_ref_hpp

#include<./beauty/adapter/function_pointer_adapter/mem_fun_ref_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/const_mem_fun_ref_t.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{

template<class S, class T>
inline beauty::adapter::function_pointer_adapter::
mem_fun_ref_t<S, T>
	mem_fun_ref(S (T::*x)()){
	
	return beauty::adapter::function_pointer_adapter::
		mem_fun_ref_t<S, T>(x);
}

template<class S, class T>
inline beauty::adapter::function_pointer_adapter::
const_mem_fun_ref_t<S, T>
	mem_fun_ref(S (T::*x)()const){

	return beauty::adapter::function_pointer_adapter::
		const_mem_fun_ref_t	<S, T>(x);
}


}
}
}
#endif
