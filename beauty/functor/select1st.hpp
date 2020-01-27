
#ifndef beauty__functor___select1st_hpp
#define beauty__functor___select1st_hpp

#include<./beauty/functor/unary_function.hpp>

	
namespace beauty{namespace functor{

template<class Pair>
struct select1st:
	public beauty::functor::unary_function<Pair, typename Pair::first_type>{
	
	const typename Pair::first_type& operator () (const Pair &p)const{
		return p.first;
	}
};


}
}
#endif
