/*

#ifndef include___beauty__algorithm__other___lower_bound_hpp
	#define include___beauty__algorithm__other___lower_bound_hpp
	#include<./beauty/algorithm/other/lower_bound.hpp>
#endif

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
}*/
#include<./beauty/algorithm/other/binary_search.hpp>
int main(){
	return 0;
}