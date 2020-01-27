
#ifndef include___beauty__allocator__type_traits___type_traits_hpp
	#define include___beauty__allocator__type_traits___type_traits_hpp
	#include<./beauty/allocator/type_traits/type_traits.hpp>
#endif
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace allocator{namespace function{


template<class ForwardIterator, class T>inline
void __uninitialized_fill_aux(ForwardIterator firs, ForwardIterator last,
							const T &x,
							beauty::allocator::type_traits::true_type){
	//fill(first, last, x);algobase
}
template<class ForwardIterator, class T>inline
void __uninitialized_fill_aux(ForwardIterator firs, ForwardIterator last,
							const T &x,
							beauty::allocator::type_traits::false_type){
	while(first != last){
		beauty::allocator::function::construct(&*first, x);
		++first;
	}
}
template<class ForwardIterator, class T>inline
void uninitialized_fill(ForwardIterator first, ForwardIterator last,
					const T &x){

	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIterator>::value_type value_type;
	typedef typename beauty::allocator::type_traits::
		type_traits<value_type>::is_POD_type is_POD;
		
	__uninitialized_fill_aux(first, last, x, is_POD());

}



}
}
}
