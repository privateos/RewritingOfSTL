
#ifndef beauty__algorithm__other___remove_copy_hpp
#define beauty__algorithm__other___remove_copy_hpp


namespace beauty{namespace algorithm{namespace other{
	

template<class InputIter, class OutputIter, class T>
OutputIter remove_copy(InputIter first, InputIter last,
OutputIter result, const T &value){
	for( ; first != last; ++first){
		if(*first != value){
			*result = *first;
			++result;
		}
	}
	return result;
}


}
}
}
#endif
