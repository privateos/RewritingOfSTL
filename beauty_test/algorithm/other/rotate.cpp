/*

#ifndef include___beauty__iterator___iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator___iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
#ifndef include___beauty__iterator___iterator_category___forward_iterator_tag_hpp
	#define include___beauty__iterator___iterator_category___forward_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#endif
#ifndef include___beauty__iterator___iterator_category___bidirectional_iterator_tag_hpp
	#define include___beauty__iterator___iterator_category___bidirectional_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#endif
#ifndef include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#define include___beauty__algorithm__algorithmbase___iter_swap_hpp
	#include<./beauty/algorithm/algorithmbase/iter_swap.hpp>
#endif
#ifndef include___beauty__algorithm__other___reverse_hpp
	#define include___beauty__algorithm__other___reverse_hpp
	#include<./beauty/algorithm/other/reverse.hpp>
#endif

namespace beauty{namespace algorithm{namespace other{
	
template<class ForwardIter>inline void
__rotate(ForwardIter first, ForwardIter middle, ForwardIter last,
beauty::iterator::iterator_category::forward_iterator_tag){
	ForwardIter i;
	for(i = middle; ; ){
		beauty::algorithm::algorithmbase::
		iter_swap(first, i);
		
		++i;
		++first;
		if(first == middle){
			if(i == last){
				return;
			}else{
				middle = i;
			}
		}else{
			if(i == last){
				i = middle;
			}
		}
	}
}
template<class ForwardIter>inline void
__rotate(ForwardIter first, ForwardIter middle, ForwardIter last,
beauty::iterator::iterator_category::bidirectional_iterator_tag){
	beauty::algorithm::other::reverse(first, middle);
	beauty::algorithm::other::reverse(middle, last);
	beauty::algorithm::other::reverse(first, last);
}
template<class ForwardIter, class Distance>inline void
__rotate_cycle(ForwardIter first, ForwardIter last,
 ForwardIter initial, Distance shift){
 	typename beauty::iterator::iterator_traits::
	 iterator_traits<ForwardIter>::value_type value = *initial;
 	ForwardIter ptr1 = initial;
 	ForwardIter ptr2 = ptr1 + shift;
 	while(ptr2 != initial){
	 	*ptr1 = *ptr2;
	 	ptr1 = ptr2;
	 	if(last - ptr2 > shift){
	 		ptr2 += shift;
	 	}else{
	 		ptr2 = first + (shift - (last - ptr2));
	 	}
	 }
	 *ptr1 = value;
}
template<class Distance>inline Distance
__gcd(Distance a, Distance b){
	Distance temp;
	while(b){
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

template<class ForwardIter>inline void
__rotate(ForwardIter first, ForwardIter middle, ForwardIter last,
piterator::random_access_iterator_tag){
	typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type n;
		
	n = beauty::algorithm::other::__gcd(middle - first, last - middle);
	while(n){
		--n;
		beauty::algorithm::other::
		__rotate_cycle(first, last, first + n, middle - first);
	}
}
template<class ForwardIter>
inline void rotate(ForwardIter first, ForwardIter middle, ForwardIter last){
	if(first == last || middle == last)return ;
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::
		iterator_category Category;
		
	beauty::algorithm::other::
	__rotate(first, middle, last, Category());
}	
}
}
}*/
#include<./beauty/algorithm/other/rotate.hpp>
int main(){
	return 0;
}