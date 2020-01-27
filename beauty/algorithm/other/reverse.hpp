
#ifndef beauty__algorithm__other___reverse_hpp
#define beauty__algorithm__other___reverse_hpp

#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>

namespace beauty{namespace algorithm{namespace other{
	
template<class BidirectionalIter>
inline void __reverse(BidirectionalIter first, BidirectionalIter last,
beauty::iterator::iterator_category::bidirectional_iterator_tag){
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
beauty::iterator::iterator_category::random_access_iterator_tag){
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
}

#endif
