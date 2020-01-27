
#ifndef beauty__adapter__function_adapter___bind1st_hpp
#define beauty__adapter__function_adapter___bind1st_hpp

#include<./beauty/adapter/function_adapter/binder1st.hpp>



namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
inline beauty::adapter::function_adapter::binder1st<Predecate>
	bind1st(const Predecate &x,
	 const typename Predecate::first_argument_type &v){
	
	return beauty::adapter::function_adapter::
		binder1st<Predecate>(x, v);		
}


}
}
}
#endif
