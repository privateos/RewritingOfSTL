/*

#ifndef include___std___cstring
	#define include___std___cstring
	#include<cstring>
#endif
#ifndef include___beauty__allocator__type_traits___type_traits_hpp
	#define include___beauty__allocator__type_traits___type_traits_hpp
	#include<./beauty/allocator/type_traits/type_traits.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___bidirectional_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___bidirectional_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>
#endif
#ifndef include___beauty___types_hpp
	#define include___beauty___types_hpp
	#include<./beauty/types.hpp>
#endif
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace algorithm{namespace algorithmbase{

template<class BidirectionalIterator1,
class BidirectionalIterator2>inline
BidirectionalIterator2 copy_backward_category(

BidirectionalIterator1 first, BidirectionalIterator1 last,
BidirectionalIterator2 result,
	 beauty::iterator::iterator_category::bidirectional_iterator_tag){
	 	
	while(first != last){
		*--result = *--last;
	}
	return result;
	
}


template<class BidirectionalIterator1,
class BidirectionalIterator2>inline
BidirectionalIterator2 copy_backward_category(
BidirectionalIterator1 first, BidirectionalIterator1 last,
BidirectionalIterator2 result,
	beauty::iterator::iterator_category::random_access_iterator_tag){
	
	
	for(beauty::ptrdiff_t n = last - first; n > 0; --n){
		*--result = *--last;
	}
	return result;
	
	
}


template<class BidirectionalIterator1,
class BidirectionalIterator2, class BoolType>
struct copy_backward_dispatch{
	
	static BidirectionalIterator2 copy(BidirectionalIterator1 first,
		BidirectionalIterator1 last, BidirectionalIterator2 result){
		typedef typename beauty::iterator::iterator_traits::
			iterator_traits<BidirectionalIterator1>::iterator_category
		 	category;
		
		return beauty::algorithm::algorithmbase::
			copy_backward_category(first, last, result, category());
		
	}
};


template<class T>
struct copy_backward_dispatch<T*, T*,
	 beauty::allocator::type_traits::true_type>{
	
	static T* copy(T *first, T *last, T *result){
		
		
		std::memmove(result - (last - first), first, sizeof(T)*(last - first));
		return result - (last - first);
		
	}
};


template<class T>
struct copy_backward_dispatch<const T*, T*,
	 beauty::allocator::type_traits::true_type>{
	static T* copy(T *first, T *last, T *result){
		
		std::memmove(result - (last - first), first, sizeof(T)*(last - first));
		return result - (last - first);
	}
};

template<class BidirectionalIterator1,
class BidirectionalIterator2>inline
BidirectionalIterator2 copy_backward(
BidirectionalIterator1 first, BidirectionalIterator1 last,
BidirectionalIterator2 result){
	
	typedef typename beauty::allocator::type_traits::
	type_traits<BidirectionalIterator2>::has_trivial_assignment_operator
		type;

	return beauty::algorithm::algorithmbase::
		copy_backward_dispatch<BidirectionalIterator1,
		BidirectionalIterator2,type>::copy(first, last, result);
}

}
}
}
*/
#include<./beauty/algorithm/algorithmbase/copy_backward.hpp>
int main(){
	return 0;
}