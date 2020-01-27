/*


#ifndef include___beauty__algorithm__other___find_hpp
	#define include___beauty__algorithm__other___find_hpp
	#include<./beauty/algorithm/other/find.hpp>
#endif

namespace beauty{namespace algorithm{namespace other{
	


template<class ForwardIter, class T>
ForwardIter remove(ForwardIter first, ForwardIter last, const T &value){
	first = beauty::algorithm::other::find(first, last, value);
	if(first == last)return last;
	ForwardIter next = first;
	for(++next; next != last; ++next){
		if(*next != value){
			*first = *next;
			++first;
		}
	}
	return first;
}

}
}
}*/
#include<./beauty/algorithm/other/remove.hpp>
int main(){
	return 0;
}