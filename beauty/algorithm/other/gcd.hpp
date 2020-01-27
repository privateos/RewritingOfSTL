
#ifndef beauty__algorithm__other___gcd_hpp
#define beauty__algorithm__other___gcd_hpp

	
namespace beauty{namespace algorithm{namespace other{

template<class T>inline T
gcd(const T a, const T b){
	T temp;
	while(b){
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}	
	
}
}
}
#endif
