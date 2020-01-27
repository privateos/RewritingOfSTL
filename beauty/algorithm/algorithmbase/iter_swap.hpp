
#ifndef beauty__algorithm__algorithmbase___iter_swap_hpp
#define beauty__algorithm__algorithmbase___iter_swap_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace algorithm{namespace algorithmbase{


template<class ForwardIterator1, class ForwardIterator2>
inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b){
	typename beauty::iterator::iterator_traits::
	iterator_traits<ForwardIterator1>::value_type
	temp = *a;
	*a = *b;
	*b = temp;
}


}
}
}
#endif
