
#ifndef include___beauty__functor___unary_function_hpp
	#define include___beauty__functor___unary_function_hpp
	#include<./beauty/functor/unary_function.hpp>
#endif

namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
struct binder2nd:
	public beauty::functor::unary_function<
		typename Predecate::first_argument_type,
			 bool>{
	
	protected:
	Predecate pred;
	typename Predecate::second_argument_type value;
	
	public:
	explicit binder2nd(const Predecate &x,
		const typename Predecate::second_argument_type &v):
		pred(x), value(v){}
	
	bool operator () (const typename Predecate::first_argument_type &x)const{
		return pred(x, value);
	}	
};


}
}
}
