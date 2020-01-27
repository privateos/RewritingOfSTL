
#ifndef beauty__algorithm__algorithmbase___copy_backward_hpp
#define beauty__algorithm__algorithmbase___copy_backward_hpp

#include<./beauty/header.hpp>
#include<./beauty/allocator/type_traits/type_traits.hpp>
#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>
#include<./beauty/types.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


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
#endif
