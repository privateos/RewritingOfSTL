
#ifndef beauty__adapter__function_adapter___not2_hpp
#define beauty__adapter__function_adapter___not2_hpp

#include<./beauty/adapter/function_adapter/binary_negate.hpp>


namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
inline beauty::adapter::function_adapter::binary_negate<Predecate>
	not2(const Predecate &x){
	return beauty::adapter::function_adapter::
		binary_negate<Predecate>(x);	
}


}
}
}
#endif
