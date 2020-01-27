
#ifndef beauty__allocator__function___uninitialized_fill_n_hpp
#define beauty__allocator__function___uninitialized_fill_n_hpp

#include<./beauty/allocator/type_traits/type_traits.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/algorithm/algorithmbase/fill_n.hpp>
#include<./beauty/allocator/function/construct.hpp>


namespace beauty{namespace allocator{namespace function{


template<class ForwardIterator, class Size, class T>inline
ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first, Size n, const T &x,
			beauty::allocator::type_traits::true_type){
	return beauty::algorithm::algorithmbase::fill_n(first, n, x);
}

template<class ForwardIterator, class Size, class T>inline
ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first, Size n, const T &x,
			beauty::allocator::type_traits::false_type){
	for( ; n > 0; --n){
		
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
#endif
