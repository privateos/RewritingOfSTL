/*


#ifndef include___std___cstring
	#define include___std___cstring
	#include<cstring>
#endif
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif
#ifndef include___beauty__allocator__type_traits___type_traits_hpp
	#define include___beauty__allocator__type_traits___type_traits_hpp
	#include<./beauty/allocator/type_traits/type_traits.hpp>
#endif
#ifndef include___beauty__allocator__type_traits___false_type_hpp
	#define include___beauty__allocator__type_traits___false_type_hpp
	#include<./beauty/allocator/type_traits/false_type.hpp>
#endif
#ifndef include___beauty__allocator__type_traits___true_type_hpp
	#define include___beauty__allocator__type_traits___true_type_hpp
	#include<./beauty/allocator/type_traits/true_type.hpp>
#endif
#ifndef include___beauty___types_hpp
	#define include___beauty___types_hpp
	#include<./beauty/types.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___input_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___input_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/input_iterator_tag.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
#endif

namespace beauty{namespace algorithm{namespace algorithmbase{

inline char* copy(const char *first, const char *last, char *result){
	std::memmove(result, first, last - first);
	return result + (last - first);
}
inline wchar_t* copy(const wchar_t *first, const wchar_t *last,
 wchar_t *result){
 	std::memmove(result, first, sizeof(wchar_t)*(last - first));
	return result + (last - first);	
}

template<class InputIterator, class OutputIterator>inline
OutputIterator __copy(InputIterator first, InputIterator last,
				OutputIterator result, 
				beauty::iterator::iterator_category::input_iterator_tag){
	for( ; first != last; ++first, ++result){
		*result = *first;
	}				
	return result;					
}
template<class InputIterator, class OutputIterator>inline
OutputIterator __copy(InputIterator first, InputIterator last,
			OutputIterator result, 
			beauty::iterator::iterator_category::random_access_iterator_tag){
	for(beauty::ptrdiff_t n = last - first; n > 0; --n, ++result, ++first){
		*result = *first;
	}				
	return result;					
}
template<class InputIterator, class OutputIterator>
struct copy_dispatch{
	OutputIterator operator ()(InputIterator first, InputIterator last,
						OutputIterator result){
		typedef typename beauty::iterator::iterator_traits::
		iterator_traits<InputIterator>::iterator_category
				Category;
		
		return beauty::algorithm::algorithmbase::
				__copy(first, last, result, Category());					
	}
};
template<class T>
inline T* copy_t(const T *first, const T *last, T *result,
			beauty::allocator::type_traits::true_type){
	std::memmove(result, first, sizeof(T)*(last - first));
	return result + (last - first);
}
template<class T>
inline T* copy_t(const T *first, const T *last, T *result,
			beauty::allocator::type_traits::false_type){
	for(beauty::ptrdiff_t n = last - first; n > 0; --n, ++result, ++first){
		*result = *first;
	}
	return result;
}
template<class T>
struct copy_dispatch<T*,T*>{
	T* operator ()(const T*first, const T*last, T *result){
		typedef typename beauty::allocator::type_traits::
			type_traits<T>::has_trivial_assignment_operator t;
		return beauty::algorithm::algorithmbase::
				copy_t(first, last, result, t());
	}
};

template<class T>
struct copy_dispatch<const T*,T*>{
	T* operator ()(const T*first, const T*last, T *result){
		typedef typename beauty::allocator::type_traits::
			type_traits<T>::has_trivial_assignment_operator t;
		return beauty::algorithm::algorithmbase::
				copy_t(first, last, result, t());
	}
};
template<class InputIterator, class OutputIterator>
inline OutputIterator copy(InputIterator first, InputIterator last,
				OutputIterator result){
		
	return beauty::algorithm::algorithmbase::
			copy_dispatch<InputIterator,OutputIterator>()
			(first, last, result);			
}

}
}
}*/
#include<./beauty/algorithm/algorithmbase/copy.hpp>
int main(){
	return 0;
}
