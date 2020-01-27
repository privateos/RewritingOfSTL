
#ifndef beauty__algorithm__other___binary_search_hpp
#define beauty__algorithm__other___binary_search_hpp

#include<./beauty/algorithm/other/lower_bound.hpp>


namespace beauty{namespace algorithm{namespace other{
	
template<class ForwardIter, class T>
bool binary_search(ForwardIter first,ForwardIter last,
const T &value){
	ForwardIter i = beauty::algorithm::other::
					lower_bound(first, last, value);
	return i != last && (value < *i);
}
template<class ForwardIter, class T, class Compare>
bool binary_search(ForwardIter first,ForwardIter last,
const T &value, Compare comp){
	ForwardIter i = beauty::algorithm::other::
					lower_bound(first, last, value);
	return i != last && comp(value, *i);
}	

}
}
}
#endif
