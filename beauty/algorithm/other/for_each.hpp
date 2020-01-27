
#ifndef beauty__algorithm__other___for_each_hpp
#define beauty__algorithm__other___for_each_hpp


namespace beauty{namespace algorithm{namespace other{
	


template<class InputIter, class Function>
Function for_each(InputIter first, InputIter last, Function f){
	for( ; first != last; ++first){
		f(*first);
	}
	return f;
}
template<class InputIter, class Size, class Function>
Function for_each(InputIter first, Size n, Function f){
	while(n > 0){
		f(*first);
		++first;
		--n;
	}
	return f;
}

}
}
}
#endif
