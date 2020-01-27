
#ifndef beauty__functor___project2nd_hpp
#define beauty__functor___project2nd_hpp

#include<./beauty/functor/binary_function.hpp>

	
namespace beauty{namespace functor{

template<class Arg1, class Arg2>
struct project2nd:
	public beauty::functor::binary_function<Arg1, Arg2, Arg2>{
	
	const Arg2 operator () (const Arg1 &, const Arg2&x)const{
		return x;
	}
};


}
}
#endif
