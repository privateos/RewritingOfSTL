
#ifndef beauty__allocator__function___destroy_hpp
#define beauty__allocator__function___destroy_hpp

#include<./beauty/header.hpp>
#include<./beauty/config.hpp>
#include<./beauty/allocator/type_traits/type_traits.hpp>
#include<./beauty/allocator/type_traits/true_type.hpp>
#include<./beauty/allocator/type_traits/false_type.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace allocator{namespace function{

template<class T>
inline void destroy(T *p){
	p->~T();
}




template<class ForwardIter>inline 
void __destroy(ForwardIter first, ForwardIter last, 
beauty::allocator::type_traits::false_type ){
	
	for( ; first != last; ++first){
		destroy(&*first);
	}
	
}
template<class ForwardIter>inline 
void __destroy(ForwardIter first, ForwardIter last, 
beauty::allocator::type_traits::true_type ){	
}

template<class ForwardIter>
inline void destroy(ForwardIter first, ForwardIter last){
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<ForwardIter>::value_type  value_type;
	
	typedef typename beauty::allocator::type_traits::
	type_traits<value_type>::has_trivial_destructor HTD;
	
	__destroy(first, last, HTD());
}



inline void destroy(char*, char*){}
inline void destroy(unsigned char*, unsigned char*){}
inline void destroy(signed char*, signed char*){}
#if beauty__config_hpp___has_wchar_t_type
	inline void destroy(wchar_t*, wchar_t*){}
	//inline void destroy(unsigned wchar_t*, unsigned wchar_t*){}
	//inline void destroy(signed wchar_t*, signed wchar_t*){}
#endif
#if beauty__config_hpp___has_char16_t_type
	inline void destroy(char16_t*, char16_t*){}
	inline void destroy(unsigned char16_t*, unsigned char16_t*){}
	inline void destroy(signed char16_t*, signed char16_t*){}
#endif
#if beauty__config_hpp___has_char32_t_type
	inline void destroy(char32_t*, char32_t*){}
	inline void destroy(unsigned char32_t*, unsigned char32_t*){}
	inline void destroy(signed char32_t*, signed char32_t*){}
#endif


inline void destry(short*, short*){}
inline void destroy(unsigned short*, unsigned short*){}
inline void destroy(int*, int*){}
inline void destroy(unsigned int*, unsigned int*){}
inline void destroy(long int*, long int*){}
inline void destroy(unsigned long int*, unsigned long int*){}
#if beauty__config_hpp___has_long_long_type
	inline void destroy(long long int*, long long int*){}
	inline void destroy(unsigned long long int*, unsigned long long int*){}
#endif


inline void destroy(float*, float*){}
inline void destroy(double*, double*){}
#if beauty__config_hpp___has_long_double_type
	inline void destroy(long double*, long double*){}
#endif

}
}
}
#endif
