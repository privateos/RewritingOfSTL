
#ifndef beauty__adapter__function_adapter___not1_hpp
#define beauty__adapter__function_adapter___not1_hpp

#include<./beauty/adapter/function_adapter/unary_negate.hpp>


namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
inline beauty::adapter::function_adapter::unary_negate<Predecate>
	not1(const Predecate &x){
	return beauty::adapter::function_adapter::
		unary_negate<Predecate>(x);	
}


}
}
}
#endif
