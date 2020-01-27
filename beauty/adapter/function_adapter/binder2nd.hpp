

#ifndef beauty__adapter__function_adapter___binder2nd_hpp
#define beauty__adapter__function_adapter___binder2nd_hpp

#include<./beauty/functor/unary_function.hpp>


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
#endif
