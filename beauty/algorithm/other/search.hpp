
#ifndef beauty__algorithm__other___search_hpp
#define beauty__algorithm__other___search_hpp

#include<./beauty/algorithm/other/find.hpp>
#include<./beauty/algorithm/other/find_if.hpp>

namespace beauty{namespace algorithm{namespace other{
	
template<class ForwardIter1, class ForwardIter2>
ForwardIter1 search(ForwardIter1 first1, ForwardIter1 last1,
ForwardIter2 first2, ForwardIter2 last2){
	if(first1 == last1 || first2 == last2)return first1;
	ForwardIter2 temp(first2);
	++temp;
	if(temp == last2){
		return beauty::algorithm::other::find(first1, last1, *first2);
	}
	ForwardIter2 p1, p;
	ForwardIter1 cur;
	p1 = first2;
	++p1;
	while(first1 != last1){
		first1 = beauty::algorithm::other::find(first1, last1, *first2);
		if(first1 == last1)return first1;
		cur = first1;
		if(++cur == last1)return last1;
		p = p1;
		while(*cur == *p){
			if(++p == last2)return first1;
			if(++cur == last1)return last1;
		}
		++first1;
	}
	return first1;
}
template<class ForwardIter1, class ForwardIter2, class BinaryOper>
ForwardIter1 search(ForwardIter1 first1, ForwardIter1 last1,
ForwardIter2 first2, ForwardIter2 last2, BinaryOper pred){
	if(first1 == last1 || first2 == last2)return first1;
	
	ForwardIter2 temp(first2);
	if(++temp == last2){
		return beauty::algorithm::other::find_if(first1, last1, *first2, pred);
	}
	
	ForwardIter2 p1, p;
	ForwardIter1 cur;
	p1 = first2;
	++p1;
	
	while(first1 != last1){
		first1 = beauty::algorithm::other::find_if(first1, last1, *first2, pred);
		if(first1 == last1)return first1;
		
		cur = first1;
		if(++cur == last1)return last1;
		
		p = p1;
		
		while(pred(*p,*cur)){
			if(++p == last2)return first1;
			if(++cur == last1)return last1;
		}
		++first1;
	}
	return first1;
}

	
}
}
}
#endif
