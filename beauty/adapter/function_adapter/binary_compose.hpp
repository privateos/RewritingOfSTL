
#ifndef beauty__adapter__function_adapter___binary_compose_hpp
#define beauty__adapter__function_adapter___binary_compose_hpp

#include<./beauty/functor/unary_function.hpp>


namespace beauty{namespace adapter{namespace function_adapter{

template<class Op1, class Op2, class Op3>
struct binary_compose:
	public beauty::functor::unary_function<
		typename Op2::argument_type,
		typename Op1::result_type>{
	
	protected:
	Op1 p1;
	Op2 p2;
	Op3 p3;
	
	public:
	explicit binary_compose(const Op1 &P1, const Op2 &P2, const Op3 &P3):
		p1(P1), p2(P2), p3(P3){}
	
	typename Op1::result_type
		operator () (const typename Op2::argument_type &x)const{
		return p1(p2(x), p3(x));	
	}	
};


}
}
}
#endif
