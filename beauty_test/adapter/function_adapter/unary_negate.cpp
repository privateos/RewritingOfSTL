
#ifndef include___beauty__functor___unary_function_hpp
	#define include___beauty__functor___unary_function_hpp
	#include<./beauty/functor/unary_function.hpp>
#endif

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
