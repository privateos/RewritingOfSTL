
#ifndef beauty__algorithm__other___min_element_hpp
#define beauty__algorithm__other___min_element_hpp


namespace beauty{namespace algorithm{namespace other{
	

template<class ForwardIter>
ForwardIter min_element(ForwardIter first, ForwardIter last){
	if(first == last)return last;
	ForwardIter result = first;
	for(++first; first != last; ++first){
		if(*first < *result){
			result = first;
		}
	}
	return result;
}
template<class ForwardIter, class Compare>
ForwardIter min_element(ForwardIter first, ForwardIter last, Compare comp){
	if(first == last)return last;
	ForwardIter result = first;
	for(++first; first != last; ++first){
		if(comp(*first, *result)){
			result = first;
		}
	}
	return result;
}


}
}
}
#endif
