/*


namespace beauty{namespace algorithm{namespace other{


template<class ForwardIter, class T, class Equal>
void replace_if(ForwardIter first, ForwardIter last,
 const T &old_value, const T &new_value, Equal eq){
 	for( ; first != last; ++first){
	 	if(eq(*first, old_value)){
	 		*first = new_value;
	 	}
	 }
}
template<class ForwardIter, class T, class Predicate>
void replace_if(ForwardIter first, ForwardIter last,
const T &new_value, Predicate pred){
 	for( ; first != last; ++first){
	 	if(pred(*first)){
	 		*first = new_value;
	 	}
	 }
}

}
}
}*/
#include<./beauty/algorithm/other/replace_if.hpp>
int main(){
	return 0;
}