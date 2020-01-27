
#ifndef include___beauty__allocator__type_traits___type_traits_hpp
	#define include___beauty__allocator__type_traits___type_traits_hpp
	#include<./beauty/allocator/type_traits/type_traits.hpp>
#endif
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
#ifndef include___std___cstring
	#define include___std___cstring
	#include<cstring>
#endif

namespace beauty{namespace allocator{namespace function{


template<class InputIterator, class ForwardIterator>inline
ForwardIterator __uninitialized_copy_aux(InputIterator first, InputIterator last,
									ForwardIterator result,
									beauty::allocator::type_traits::true_type){
	//return copy(first, last, result);algobase
										
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
	typedef typename beautye::allocator::type_traits::
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
