
#ifndef beauty__allocator__function___uninitialized_copy_hpp
#define beauty__allocator__function___uninitialized_copy_hpp

#include<./beauty/allocator/type_traits/type_traits.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/header.hpp>
#include<./beauty/algorithm/algorithmbase/copy.hpp>


namespace beauty{namespace allocator{namespace function{


template<class InputIterator, class ForwardIterator>inline
ForwardIterator __uninitialized_copy_aux(InputIterator first, InputIterator last,
									ForwardIterator result,
									beauty::allocator::type_traits::true_type){
	return beauty::algorithm::algorithmbase::copy(first, last, result);
										
}
template<class InputIterator, class ForwardIterator>inline
ForwardIterator __uninitialized_copy_aux(InputIterator first, InputIterator last,
									ForwardIterator result,
									beauty::allocator::type_traits::false_type){
	while(first != last){
		beauty::allocator::function::construct(&*result, *first);
		++first;
		++result;
	}
	return result;

}
template<class InputIterator, class ForwardIterator>inline
ForwardIterator uninitialized_copy(InputIterator first, InputIterator last,
								ForwardIterator result){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIterator>::value_type value_type;
	typedef typename beauty::allocator::type_traits::
		type_traits<value_type>::is_POD_type is_POD;

	return __uninitialized_copy_aux(first, last, result, is_POD());
}
inline char* uninitialized_copy(char *first, char *last, char *result){
	std::memmove(result, first, last - first);
	return result + (last - first);
}
inline wchar_t* uninitialized_copy(wchar_t *first, wchar_t *last, wchar_t *result){
	std::memmove(result, first, (last - first)*sizeof(wchar_t));
	return result + (last - first);
}

}
}
}
#endif
