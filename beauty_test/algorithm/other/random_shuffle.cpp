/*


#ifndef include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#define include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#endif
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
#ifndef include___std___cstdlib
	#define include___std___cstdlib
	#include<cstdlib>
#endif

namespace beauty{namespace algorithm{namespace other{


template<class RandomAccessIter>
void random_shuffle(RandomAccessIter first, RandomAccessIter last){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<RandomAccessIter>
		::difference_type Distance;
	
	for(RandomAccessIter i = first + 1; i != last; ++i){
		beauty::algorithm::algorithmbase::
		iter_swap(i , first + Distance(std::rand()%(i - first + 1)));
	}
}
template<class RandomAccessIter, class RandomAccessGenerator>
void random_shuffle(RandomAccessIter first, RandomAccessIter last,
RandomAccessGenerator &Random){
	
	for(RandomAccessIter i = first + 1; i != last; ++i){
		beauty::algorithm::algorithmbase::
		iter_swap(i , first + Random(i - first + 1));
	}
}


}
}
}*/
#include<./beauty/algorithm/other/random_shuffle.hpp>
int main(){
	return 0;
}