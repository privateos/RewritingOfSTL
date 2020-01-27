/*

#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
#ifndef include___beauty__iterator__function___distance_hpp
	#define include___beauty__iterator__function___distance_hpp
	#include<./beauty/iterator/function/distance.hpp>
#endif
#ifndef include___beauty__iterator__function___advance_hpp
	#define include___beauty__iterator__function___advance_hpp
	#include<./beauty/iterator/function/advance.hpp>
#endif
namespace beauty{namespace algorithm{namespace other{
	
template<class ForwardIter, class T>
ForwardIter upper_bound(ForwardIter first, ForwardIter last, const T &value){
	typename beauty::iterator::iterator_traits::
	iterator_traits<ForwardIter>::difference_type
	 	half, len = 0;
	ForwardIter i ;
	beauty::iterator::function::distance(first, last, len);
	while(len > 0){
		half = len>>1;
		i = first;
		beauty::iterator::function::advance(i, half);
		if(value < *i){
			len = half;
		}else{
			first = i;
			++first;
			len = len - half - 1;
		}
	}
	return first;
}
template<class ForwardIter, class T, class Compare>
ForwardIter upper_bound(ForwardIter first, ForwardIter last,
 const T &value, Compare comp){
	typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIter>::difference_type
	 	half, len = 0;
	ForwardIter i ;
	beauty::iterator::function::distance(first, last, len);
	while(len > 0){
		half = len>>1;
		i = first;
		beauty::iterator::function::advance(i, half);
		if(comp(value, *i)){
			len = half;
		}else{
			first = i;
			++first;
			len = len - half - 1;
		}
	}
	return first;
}	

}
}
}*/
#include<./beauty/algorithm/other/upper_bound.hpp>
int main(){
	return 0;
}