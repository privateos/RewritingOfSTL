
#ifndef beauty__container__pair___make_pair_hpp
#define beauty__container__pair___make_pair_hpp

#include<./beauty/container/pair/pair.hpp>


namespace beauty{namespace container{namespace pair{


template<class T1, class T2>
inline beauty::container::pair::pair<T1,T2> make_pair(const T1 &x, const T2 &y){
	return beauty::container::pair::pair<T1,T2>(x, y);
}


}
}
}
#endif
