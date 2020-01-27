
#ifndef beauty__allocator__function___uninitialized_fill_hpp
#define beauty__allocator__function___uninitialized_fill_hpp

#include<./beauty/allocator/type_traits/type_traits.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#include<./beauty/algorithm/algorithmbase/fill.hpp>
#include<./beauty/allocator/function/construct.hpp>


namespace beauty{namespace allocator{namespace function{


template<class ForwardIterator, class T>inline
void __uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
							const T &x,
							beauty::allocator::type_traits::true_type){
	beauty::algorithm::algorithmbase::fill(first, last, x);
}
template<class ForwardIterator, class T>inline
void __uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
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
#endif
