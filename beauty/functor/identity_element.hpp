
#ifndef beauty__functor___identity_element_hpp
#define beauty__functor___identity_element_hpp

#include<./beauty/functor/plus.hpp>
#include<./beauty/functor/multiplies.hpp>


namespace beauty{namespace functor{

template<class T>
inline T identity_element(beauty::functor::plus<T>){
	return T(0);
}

template<class T>
inline T identity_element(beauty::functor::multiplies<T>){
	return T(1);
}


}
}
#endif
