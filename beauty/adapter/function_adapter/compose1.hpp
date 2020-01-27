
#ifndef beauty__adapter__function_adapter___compose1_hpp
#define beauty__adapter__function_adapter___compose1_hpp

#include<./beauty/adapter/function_adapter/unary_compose.hpp>


namespace beauty{namespace adapter{namespace function_adapter{

template<class Op1, class Op2>
inline beauty::adapter::function_adapter::unary_compose<Op1, Op2>
	compose1(const Op1 &p1, const Op2 &p2){
	
	return beauty::adapter::function_adapter::
		unary_compose<Op1, Op2>(p1, p2);		
}


}
}
}
#endif
