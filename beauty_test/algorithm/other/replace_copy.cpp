

namespace beauty{namespace algorithm{namespace other{



template<class ForwardIter, class OutputIter, class T>
OutputIter replace_copy(ForwardIter first, ForwardIter last,
OutputIter result, const T &old_value, const T &new_value){
	for( ; first != last; ++first, ++result){
		*result = (*first == old_value) ? new_value : *first;
//		if(*first == old_value){
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