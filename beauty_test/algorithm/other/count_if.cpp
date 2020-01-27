/*


#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

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
}*/
#include<./beauty/algorithm/other/count_if.hpp>
int main(){
	return 0;
}