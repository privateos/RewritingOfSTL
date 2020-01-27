

#ifndef include___beauty__algorithm__other___find_if_hpp
	#define include___beauty__algorithm__other___find_if_hpp
	#include<./beauty/algorithm/other/find_if.hpp>
#endif
namespace beauty{namespace algorithm{namespace other{
	

template<class ForwardIter, class T, class Equal>
ForwardIter remove_if(ForwardIter first, ForwardIter last,
 const T &value, Equal eq){
	first = beauty::algorithm::other::find_if(first, last, value, eq);
	if(first == last)return last;
	ForwardIter next = first;
	for(++next; next != last; ++next){
		if(!eq(*next, value)){
			*first = *next;
			++first;
		}
	}
	return first;
}
template<class ForwardIter, class Predicate>
ForwardIter remove_if(ForwardIter first, ForwardIter last,
Predicate pred){
	first = beauty::algorithm::other::find_if(first, last, pred);
	if(first == last)return last;
	ForwardIter next = first;
	for(++next; next != last; ++next){
		if(!pred(*next)){
			*first = *next;
			++first;
		}
	}
	return first;
}


}
}
}