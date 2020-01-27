/*


#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace algorithm{namespace other{
	

template<class InputIter, class T>
typename beauty::iterator::iterator_traits::
iterator_traits<InputIter>::difference_type
count(InputIter first, InputIter last, const T &value){
	typename beauty::iterator::iterator_traits::
		iterator_traits<InputIter>::difference_type n = 0;
	for( ; first != last; ++first){
		if(*first == value){
			++n;
		}
	}
	return n;
}
template<class InputIter, class T, class BinaryOper>
typename beauty::iterator::iterator_traits::
iterator_traits<InputIter>::difference_type
count(InputIter first, InputIter last, const T &value, BinaryOper op){
	
	typename beauty::iterator::iterator_traits::
		iterator_traits<InputIter>::difference_type n = 0;
	for( ; first != last; ++first){
		if(op(*first, value)){
			++n;
		}
	}
	return n;
}


}
}
}*/
#include<./beauty/algorithm/other/count.hpp>
int main(){
	return 0;
}