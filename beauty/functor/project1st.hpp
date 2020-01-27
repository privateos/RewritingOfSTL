
#ifndef beauty__functor___project1st_hpp
#define beauty__functor___project1st_hpp

#include<./beauty/functor/binary_function.hpp>

	
namespace beauty{namespace functor{

template<class Arg1, class Arg2>
struct project1st:
	public beauty::functor::binary_function<Arg1, Arg2, Arg1>{
	
	const Arg1 operator () (const Arg1 &x, const Arg2&)const{
		return x;
	}
};


}
}

#endif
