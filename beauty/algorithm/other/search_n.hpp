
#ifndef beauty__algorithm__other___search_n_hpp
#define beauty__algorithm__other___search_n_hpp

#include<./beauty/algorithm/other/find.hpp>
#include<./beauty/algorithm/other/find_if.hpp>

namespace beauty{namespace algorithm{namespace other{
	
template<class ForwardIter, class Integer, class T>
ForwardIter search_n(ForwardIter first, ForwardIter last,
 Integer n, const T &value){
	if(n <= 0)return first;
	
	first = beauty::algorithm::other::find(first, last, value);

	Integer c;
	ForwardIter i;
	while(first != last){
		c = n - 1;
		i = first;
		++i;
		while(i != last && c != 0 && *i == value){
			++i;
			--c;
		}
		if(c == 0){
			return first;
		}else{
			first = beauty::algorithm::other::find(i, last, value);
		}		
	}
	return first;
}
template<class ForwardIter, class Integer, class T, class BinaryOper>
ForwardIter search_n(ForwardIter first, ForwardIter last,
 Integer n, const T &value, BinaryOper pred){
	if(n <= 0)return first;
	
	first = beauty::algorithm::other::find_if(first, last, value, pred);

	Integer c;
	ForwardIter i;
	while(first != last){
		c = n - 1;
		i = first;
		++i;
		while(i != last && c != 0 && pred(*i, value)){
			++i;
			--c;
		}
		if(c == 0){
			return first;
		}else{
			first = beauty::algorithm::other::find_if(i, last, value, pred);
		}		
	}
	return first;
}	

}
}
}
#endif