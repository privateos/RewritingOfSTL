
#ifndef beauty__adapter__function_adapter___binary_negate_hpp
#define beauty__adapter__function_adapter___binary_negate_hpp

#include<./beauty/functor/binary_function.hpp>


namespace beauty{namespace adapter{namespace function_adapter{

template<class Predecate>
struct binary_negate:
	public beauty::functor::binary_function<
		typename Predecate::first_argument_type,
		typename Predecate::second_argument_type,
			bool>{
	
	protected:
	Predecate pred;
	public:
	explicit binary_negate(const Predecate &x):pred(x){}
	
	bool operator () (const typename Predecate::first_argument_type &x,
					const typename Predecate::second_argument_type &y)const{
		return !pred(x, y);
	}	
};


}
}
}

#endif
