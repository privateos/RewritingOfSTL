
#ifndef include___beauty__functor___unary_function_hpp
	#define include___beauty__functor___unary_function_hpp
	#include<./beauty/functor/unary_function.hpp>
#endif

namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
struct binder1st:
	public beauty::functor::unary_function<
		typename Predecate::second_argument_type,
			 bool>{
	
	protected:
	Predecate pred;
	typename Predecate::first_argument_type value;
	
	public:
	explicit binder1st(const Predecate &x,
		const typename Predecate::first_argument_type &v):
		pred(x), value(v){}
	
	bool operator () (const typename Predecate::second_argument_type &x)const{
		return pred(value, x);
	}	
};


}
}
}
