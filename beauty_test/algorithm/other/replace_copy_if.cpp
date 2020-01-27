

namespace beauty{namespace algorithm{namespace other{



template<class ForwardIter, class OutputIter, class T, class Equal>
OutputIter replace_copy_if(ForwardIter first, ForwardIter last,
OutputIter result, const T &old_value, const T &new_value, Equal eq){
	for( ; first != last; ++first, ++result){
		*result = (eq(*first, old_value)) ? new_value : *first;
//		if(eq(*first, old_value)){
//			*result = new_value;
//		}else{
//			*result = *first;
//		}
	}
	return result;
}
template<class ForwardIter, class OutputIter, class T, class Predicate>
OutputIter replace_copy_if(ForwardIter first, ForwardIter last,
OutputIter result, const T &new_value, Predicate pred){
	for( ; first != last; ++first, ++result){
		*result = (pred(*first)) ? new_value : *first;
//		if(pred(*first)){
//			*result = new_value;
//		}else{
//			*result = *first;
//		}
	}
	return result;
}

}
}
}