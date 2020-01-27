
#ifndef beauty__adapter__function_adapter___unary_negate_hpp
#define beauty__adapter__function_adapter___unary_negate_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
struct unary_negate:
	public beauty::functor::unary_function<typename Predecate::argument_type, bool>{
	
	protected:
	Predecate pred;
	public:
	explicit unary_negate(const Predecate &x):pred(x){}
	
	bool operator () (const typename Predecate::argument_type &x)const{
		return !pred(x);
	}	
};


}
}
}
#endif
