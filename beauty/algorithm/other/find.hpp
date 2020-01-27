
#ifndef beauty__algorithm__other___find_hpp
#define beauty__algorithm__other___find_hpp


namespace beauty{namespace algorithm{namespace other{
	

template<class InputIter, class T>inline
InputIter find(InputIter first, InputIter last, const T &value){
	while(first != last && *first != value){
		++first;
	}
	return first;
}


}
}
}
#endif
