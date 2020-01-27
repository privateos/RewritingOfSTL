
#ifndef beauty__algorithm__other___find_end_hpp
#define beauty__algorithm__other___find_end_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#include<./beauty/algorithm/other/search.hpp>


namespace beauty{namespace algorithm{namespace other{
	

template<class ForwardIter1, class ForwardIter2>
inline ForwardIter1 __find_end(ForwardIter1 first1, ForwardIter1 last1,
	ForwardIter2 first2, ForwardIter2 last2,
	beauty::iterator::iterator_category::forward_iterator_tag,
	beauty::iterator::iterator_category::forward_iterator_tag){


	ForwardIter1 result = last1;
	ForwardIter1 new_result;
	while(true){
		new_result = beauty::algorithm::other::
			search(first1, last1, first2, last2);
		if(new_result == last1){
			return result;
		}else{
			result = new_result;
			first1 = new_result;
			++first1;
		}
	}
}

template<class ForwardIter1, class ForwardIter2, class BinaryOper>
inline ForwardIter1 __find_end(ForwardIter1 first1, ForwardIter1 last1,
	ForwardIter2 first2, ForwardIter2 last2, BinaryOper pred,
	beauty::iterator::iterator_category::forward_iterator_tag,
	beauty::iterator::iterator_category::forward_iterator_tag){


	ForwardIter1 result = last1;
	ForwardIter1 new_result;
	while(true){
		new_result = beauty::algorithm::other::
			search(first1, last1, first2, last2, pred);
		if(new_result == last1){
			return result;
		}else{
			result = new_result;
			first1 = new_result;
			++first1;
		}
	}
}




template<class ForwardIter1, class ForwardIter2>
inline ForwardIter1 __find_end(ForwardIter1 first1, ForwardIter1 last1,
	ForwardIter2 first2, ForwardIter2 last2,
	beauty::iterator::iterator_category::bidirectional_iterator_tag,
	beauty::iterator::iterator_category::bidirectional_iterator_tag){


	ForwardIter1 new_last1;
	ForwardIter2 new_last2;
	ForwardIter1 flag = last1;
	while(true){
		new_last1 = flag;
		new_last2 = last2;
		while(true){
			if(first2 == new_last2){
				return new_last1;
			}
			if(first1 == new_last1){
				return last1;
			}
			if(*--new_last2 != *--new_last1){
				--flag;
				break;
			}
		}
	}
}

template<class ForwardIter1, class ForwardIter2, class BinaryOper>
inline ForwardIter1 __find_end(ForwardIter1 first1, ForwardIter1 last1,
	ForwardIter2 first2, ForwardIter2 last2, BinaryOper pred,
	beauty::iterator::iterator_category::bidirectional_iterator_tag,
	beauty::iterator::iterator_category::bidirectional_iterator_tag){


	ForwardIter1 new_last1;
	ForwardIter2 new_last2;
	ForwardIter1 flag = last1;
	while(true){
		new_last1 = flag;
		new_last2 = last2;
		while(true){
			if(first2 == new_last2){
				return new_last1;
			}
			if(first1 == new_last1){
				return last1;
			}
			if(!pred(*--new_last1, *--new_last2)){
				--flag;
				break;
			}
		}
	}
}



template<class ForwardIter1, class ForwardIter2>
inline ForwardIter1 find_end(ForwardIter1 first1, ForwardIter1 last1,
	ForwardIter2 first2, ForwardIter2 last2){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter1>::iterator_category category1;
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter2>::iterator_category category2;

	return beauty::algorithm::other
		::__find_end(first1, last1, first2, last2,
		 category1(), category2());
}

template<class ForwardIter1, class ForwardIter2, class BinaryOper>
inline ForwardIter1 find_end(ForwardIter1 first1, ForwardIter1 last1,
	ForwardIter2 first2, ForwardIter2 last2, BinaryOper pred){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter1>::iterator_category category1;
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter2>::iterator_category category2;

	return beauty::algorithm::other
		::__find_end(first1, last1,
			first2, last2, pred,
		 category1(), category2());
}

}
}
}
#endif
