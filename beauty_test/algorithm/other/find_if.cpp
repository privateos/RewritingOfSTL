/*

namespace beauty{namespace algorithm{namespace other{
	

template<class InputIter, class T, class Equal>inline
InputIter find_if(InputIter first, InputIter last, const T &value, Equal eq){
	while(first != last && !eq(*first, value)){
		++first;
	}
	return first;
}
template<class InputIter, class Predicate>inline
InputIter find_if(InputIter first, InputIter last, Predicate op){
	while(first != last && !op(*first)){
		++first;
	}
	return first;
}


}
}
}*/
#include<./beauty/algorithm/other/find_if.hpp>
int main(){
	return 0;
}