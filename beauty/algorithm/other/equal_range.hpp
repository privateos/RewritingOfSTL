
#ifndef beauty__algorithm__other___equal_range_hpp
#define beauty__algorithm__other___equal_range_hpp

#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/pair/make_pair.hpp>
#include<./beauty/container/pair/pair_operator_function.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>
#include<./beauty/algorithm/other/lower_bound.hpp>
#include<./beauty/algorithm/other/upper_bound.hpp>
#include<./beauty/iterator/function/distance.hpp>
#include<./beauty/iterator/function/advance.hpp>

namespace beauty{namespace algorithm{namespace other{


template<class ForwardIter, class T>
inline beauty::container::pair::pair<ForwardIter, ForwardIter>
	__equal_range(ForwardIter first, ForwardIter last, const T &value,
	beauty::iterator::iterator_category::forward_iterator_tag){

	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type Distance;

	Distance len = beauty::iterator::function::distance(first, last);
	Distance half;
	ForwardIter left, right, middle;
	while(len > 0){
		half = len>>1;
		middle = first;
		beauty::iterator::function::
			advance(middle, half);

		if(*middle < value){
			first = middle;
			++first;
			len -= half + 1;
		}else{
			if(value < *middle){
				//last = middle;
				len = half;
			}else{
				left = beauty::algorithm::other::
					lower_bound(first, middle, value);
				beauty::iterator::function::
					advance(first, len);
				right = beauty::algorithm::other::
					upper_bound(++middle, first, value);
				return beauty::container::pair::
					pair<ForwardIter, ForwardIter>(left, right);
			}
		}
	}
	return beauty::container::pair::
		pair<ForwardIter, ForwardIter>(first, first);

}

template<class ForwardIter, class T, class BinaryOper>
inline beauty::container::pair::pair<ForwardIter, ForwardIter>
	__equal_range(ForwardIter first, ForwardIter last, const T &value,
	BinaryOper pred,
	beauty::iterator::iterator_category::forward_iterator_tag){

	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type Distance;

	Distance len = beauty::iterator::function::distance(first, last);
	Distance half;
	ForwardIter left, right, middle;
	while(len > 0){
		half = len>>1;
		middle = first;
		beauty::iterator::function::
			advance(middle, half);

		if(pred(*middle, value)){
			first = middle;
			++first;
			len -= half + 1;
		}else{
			if(pred(value, *middle)){
				//last = middle;
				len = half;
			}else{
				left = beauty::algorithm::other::
					lower_bound(first, middle, value, pred);
				beauty::iterator::function::
					advance(first, len);
				right = beauty::algorithm::other::
					upper_bound(++middle, first, value, pred);
				return beauty::container::pair::
					pair<ForwardIter, ForwardIter>(left, right);
			}
		}
	}
	return beauty::container::pair::
		pair<ForwardIter, ForwardIter>(first, first);

}




template<class ForwardIter, class T>
inline beauty::container::pair::pair<ForwardIter, ForwardIter>
	__equal_range(ForwardIter first, ForwardIter last, const T &value,
	beauty::iterator::iterator_category::random_access_iterator_tag){

	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type Distance;

	Distance len = last - first;
	Distance half;
	ForwardIter left, right, middle;
	while(len > 0){
		half = len>>1;
		middle = first + half;
		if(*middle < value){
			first = middle;
			++first;
			len -= half + 1;
		}else{
			if(value < *middle){
				//last = middle;
				len = half;
			}else{
				left = beauty::algorithm::other::
					lower_bound(first, middle, value);
				right = beauty::algorithm::other::
					upper_bound(++middle, first + len, value);
				return beauty::container::pair::
					pair<ForwardIter, ForwardIter>(left, right);
			}
		}
	}
	return beauty::container::pair::
		pair<ForwardIter, ForwardIter>(first, first);
}

template<class ForwardIter, class T, class BinaryOper>
inline beauty::container::pair::pair<ForwardIter, ForwardIter>
	__equal_range(ForwardIter first, ForwardIter last, const T &value,
	BinaryOper pred,
	beauty::iterator::iterator_category::random_access_iterator_tag){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type Distance;

	Distance len = last - first;
	Distance half;
	ForwardIter left, right, middle;
	while(len > 0){
		half = len>>1;
		middle = first + half;
		if(pred(*middle, value)){
			first = middle;
			++first;
			len -= half + 1;
		}else{
			if(pred(value, *middle)){
				//last = middle;
				len = half;
			}else{
				left = beauty::algorithm::other::
					lower_bound(first, middle, value, pred);
				right = beauty::algorithm::other::
					upper_bound(++middle, first + len, value, pred);
				return beauty::container::pair::
					pair<ForwardIter, ForwardIter>(left, right);
			}
		}
	}
	return beauty::container::pair::
		pair<ForwardIter, ForwardIter>(first, first);
}




template<class ForwardIter, class T>
inline beauty::container::pair::pair<ForwardIter, ForwardIter>
	equal_range(ForwardIter first, ForwardIter last, const T &value){
		
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::iterator_category category;
	return beauty::algorithm::other::
		__equal_range(first, last, value, category());
}

template<class ForwardIter, class T, class BinaryOper>
inline beauty::container::pair::pair<ForwardIter, ForwardIter>
	equal_range(ForwardIter first, ForwardIter last, const T &value,
		BinaryOper pred){
			
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::iterator_category category;
	return beauty::algorithm::other::
		__equal_range(first, last, value, pred, category());
}

}
}
}
#endif
