
#ifndef beauty__algorithm__other___lcm_hpp
#define beauty__algorithm__other___lcm_hpp

#include<./beauty/algorithm/other/gcd.hpp>


namespace beauty{namespace algorithm{namespace other{
	
template<class T>inline T
lcm(const T &a, const T &b){
	return a*b/beauty::algorithm::other::gcd(a, b);
}

	
}
}
}
#endif
