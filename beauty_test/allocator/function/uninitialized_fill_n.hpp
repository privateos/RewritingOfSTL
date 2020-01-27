
#ifndef include___beauty__allocator__type_traits___type_traits_hpp
	#define include___beauty__allocator__type_traits___type_traits_hpp
	#include<./beauty/allocator/type_traits/type_traits.hpp>
#endif
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace allocator{namespace function{


template<class ForwardIterator, class Size, class T>inline
ForwardIterator __uninitialized_fill_n_aux(ForwardIteator first, Size n, const T &x,
			beauty::allocator::type_traits::true_type){
	//return fill_n(first, n, x);algobase
}
template<class ForwardIterator, class Size, class T>inline
ForwardIterator __uninitialized_fill_n_aux(ForwardIteator first, Size n, const T &x,
			beauty::allocator::type_traits::false_type){
	while(n){
		--n;
		beauty::allocator::function::construct(&*first, x);
		++first;
	}
	return first;
}

template<class ForwardIterator, class Size, class T>inline
ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T &x){
	typedef typename beauty::iterator::iterator_traits::
		iterator_traits<ForwardIterator>::value_type value_type;
	typedef typename beauty::allocator::type_traits::
		type_traits<value_type>::is_POD_type             is_POD;
		
	return __uninitialized_fill_n_aux(first, n, x, is_POD());
}

}
}
}
