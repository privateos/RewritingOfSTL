
#ifndef beauty__algorithm__numeric___power_hpp
#define beauty__algorithm__numeric___power_hpp

#include<./beauty/functor/multiplies.hpp>
#include<./beauty/functor/identity_element.hpp>


namespace beauty{namespace algorithm{namespace numeric{

template<class T, class Integer, class MonoidOperation>inline
T power(T x, Integer n, MonoidOperation op){
	if(n == 0){
		return beauty::functor::identity_element(op);
	}else{
		T result;
		while((n&1) == 0){
			n >>= 1;
			x = op(x, x);
		}
		result = x;
		n >>= 1;
		while(n != 0){
			x = op(x, x);
			if((n&1) != 0){
				result = op(result, x);
			}
			n >>= 1;
		}
		return result;
	}
}

template<class T, class Integer>inline
T power(T x, Integer n){
	return power(x, n, beauty::functor::multiplies<T>());
}


}
}
}
#endif
