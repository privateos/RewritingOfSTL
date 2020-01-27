/*


#ifdef include___beauty__iteator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iteator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace algorithm{namespace algorithmbase{


template<class ForwardIterator1, class ForwardIterator2>
inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b){
	typename piterator::iterator_traits<ForwardIterator1>::value_type
	temp = *a;
	*a = *b;
	*b = temp;
}


}
}
}*/
#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
int main(){
	return 0;
}