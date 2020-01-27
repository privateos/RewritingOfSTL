
#ifndef include___beauty__functor___unary_function_hpp
	#define include___beauty__functor___unary_function_hpp
	#include<./beauty/functor/unary_function.hpp>
#endif

namespace beauty{namespace adapter{namespace function_adapter{

template<class Op1, class Op2>
struct unary_compose:
	public beauty::functor::unary_function<
		typename Op1::argument_type,
		typename Op2::result_type>{
	
	protected:
	Op1 p1;
	Op2 p2;
	
	public:
	explicit unary_compose(const Op1 P1, const Op2 P2):
		p1(P1), p2(P2){}
	
	typename Op2::result_type operator ()
		 (const typename Op1::argument_type &x)const{
		return p1(p2(x));
	}	
};


}
}
}
