
#ifndef beauty__adapter__function_adapter___bind2nd_hpp
#define beauty__adapter__function_adapter___bind2nd_hpp

#include<./beauty/adapter/function_adapter/binder2nd.hpp>


namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
inline beauty::adapter::function_adapter::binder2nd<Predecate>
	bind2nd(const Predecate &x,
	 const typename Predecate::second_argument_type &v){
	
	return beauty::adapter::function_adapter::
		binder2nd<Predecate>(x, v);		
}


}
}
}
#endif
