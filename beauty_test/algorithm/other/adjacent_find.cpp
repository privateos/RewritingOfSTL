/*

namespace beauty{namespace algorithm{namespace other{
	

template<class ForwardIter>
ForwardIter adjacent_find(ForwardIter first, ForwardIter last){
	if(first == last)return last;
	ForwardIter next = first;
	while(++next != last){
		if(*first == *next)return first;
		first = next;
	}
	return last;
}
template<class ForwardIter, class BinaryOper>
ForwardIter adjacent_find(ForwardIter first, ForwardIter last, BinaryOper op){
	if(first == last)return last;
	ForwardIter next = first;
	while(++next != last){
		if(op(*first, *next))return first;
		first = next;
	}
	return last;
}


}
}
}*/
#include<./beauty/algorithm/other/adjacent_find.hpp>
int main(){
	return 0;
}