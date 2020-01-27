
#ifndef beauty__adapter__function_adapter___compose2_hpp
#define beauty__adapter__function_adapter___compose2_hpp

#include<./beauty/adapter/function_adapter/binary_compose.hpp>


namespace beauty{namespace adaper{namespace function_adaper{

template<class Op1, class Op2, class Op3>
inline beauty::adapter::function_adapter::binary_compose<Op1, Op2, Op3>
	compose2(const Op1 &p1, const Op2 &p2, const Op3 &p3){
	
	return beauty::adapter::function_adapter::
		binary_compose<Op1, Op2, Op3>(p1, p2, p3);	
}


}
}
}
#endif
