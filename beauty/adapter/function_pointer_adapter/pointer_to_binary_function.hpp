
#ifndef beauty__adapter__function_pointer_adapter___pointer_to_binary_function_hpp
#define beauty__adapter__function_pointer_adapter___pointer_to_binary_function_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace adapter{namespace function_pointer_adapter{

template<class Arg1, class Arg2, class Result>
struct pointer_to_binary_function:
	beauty::functor::binary_function<Arg1, Arg2, Result>{
	
	protected:
	Result (*ptr)(Arg1, Arg2);
	
	public:
	pointer_to_binary_function(){}
	
	pointer_to_binary_function(Result (*x)(Arg1, Arg2)):ptr(x){}
	
	Result operator () (Arg1 x, Arg2 y)const{
		return ptr(x, y);
	}	
};


}
}
}
#endif




