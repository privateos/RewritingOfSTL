
#ifndef beauty__algorithm__other___count_if_hpp
#define beauty__algorithm__other___count_if_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace algorithm{namespace other{
	


template<class ForwardIter,class Predicate>
typename beauty::iterator::iterator_traits::
iterator_traits<ForwardIter>::difference_type
count_if(ForwardIter first, ForwardIter last, Predicate op){
	typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type n = 0;
	for( ; first != last; ++first){
		if(op(*first)){
			++n;
		}
	}
	return n;
}

}
}
}
#endif
