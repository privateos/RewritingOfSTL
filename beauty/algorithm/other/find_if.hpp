
#ifndef beauty__algorithm__other___find_if_hpp
#define beauty__algorithm__other___find_if_hpp


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
}
#endif
