/*

#ifndef include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#define include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#endif
#ifndef include___beauty__iterator___iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator___iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace algorithm{namespace other{
	
template<class BidirectionalIter>
inline void __reverse(BidirectionalIter first, BidirectionalIter last,
piterator::bidirectional_iterator_tag){
	--last;
	while(first < last){
		beauty::algorithm::algorithmbase::
		iter_swap(first, last);
		++first;
		--last;
	}
}
template<class BidirectionalIter>
inline void __reverse(BidirectionalIter first, BidirectionalIter last,
piterator::random_access_iterator_tag){
	while(1){
		if(first == last || first == --last){
			return ;
		}else{
			beauty::algorithm::algorithmbase::
			iter_swap(first, last);
			++first;
		}
	}
}
template<class BidirectionalIter>
inline void reverse(BidirectionalIter first, BidirectionalIter last){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<BidirectionalIter>::
	iterator_category Category;
	
	beauty::algorithm::other::
	__reverse(first, last,Category());
}

	
}
}
}*/
#include<./beauty/algorithm/other/reverse.hpp>
int main(){
	return 0;
}