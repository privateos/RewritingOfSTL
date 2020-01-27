
#ifndef beauty__adapter__function_pointer_adapter___pointer_to_unary_function_hpp
#define beauty__adapter__function_pointer_adapter___pointer_to_unary_function_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{

template<class Arg, class Result>
struct pointer_to_unary_function:
	beauty::functor::unary_function<Arg, Result>{
	
	protected:
	Result (*ptr)(Arg);
	
	public:
	pointer_to_unary_function(){}
	
	pointer_to_unary_function(Result (*x)(Arg)):ptr(x){}
	
	Result operator () (Arg x)const{
		return ptr(x);
	}	
};


}
}
}
#endif




