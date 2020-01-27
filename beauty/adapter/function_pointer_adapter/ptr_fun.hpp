
#ifndef beauty__adapter__function_pointer_adapter___ptr_fun_hpp
#define beauty__adapter__function_pointer_adapter___ptr_fun_hpp

#include<./beauty/adapter/function_pointer_adapter/pointer_to_unary_function.hpp>
#include<./beauty/adapter/function_pointer_adapter/pointer_to_binary_function.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{


template<class Arg, class Result>
inline beauty::adapter::function_pointer_adapter::
pointer_to_unary_function<Arg, Result>
	ptr_fun(Result (*x)(Arg)){
		return beauty::adapter::function_pointer_adapter::
			pointer_to_unary_function<Arg, Result>(x);
}


template<class Arg1, class Arg2, class Result>
inline beauty::adapter::function_pointer_adapter::
pointer_to_binary_function<Arg1, Arg2, Result>
	ptr_fun(Result (*x)(Arg1, Arg2)){
	
	return beauty::adapter::function_pointer_adapter::
		pointer_to_binary_function<Arg1, Arg2, Result>(x);
}

}
}
}
#endif




