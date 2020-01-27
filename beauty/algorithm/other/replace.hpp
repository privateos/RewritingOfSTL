
#ifndef beauty__algorithm__other___replace_hpp
#define beauty__algorithm__other___replace_hpp

namespace beauty{namespace algorithm{namespace other{



template<class ForwardIter, class T>
void replace(ForwardIter first, ForwardIter last,
 const T &old_value, const T &new_value){
 	for( ; first != last; ++first){
	 	if(*first == old_value){
	 		*first = new_value;
	 	}
	 }
}

}
}
}
#endif
