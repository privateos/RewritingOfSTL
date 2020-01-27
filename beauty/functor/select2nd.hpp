
#ifndef beauty__functor___select2nd_hpp
#define beauty__functor___select2nd_hpp

#include<./beauty/functor/unary_function.hpp>

	
namespace beauty{namespace functor{

template<class Pair>
struct select2nd:
	public beauty::functor::unary_function<Pair, typename Pair::second_type>{
	
	const typename Pair::second_type& operator () (const Pair &p)const{
		return p.second;
	}
};


}
}
#endif
