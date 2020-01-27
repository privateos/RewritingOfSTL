
#ifndef beauty__algorithm__numeric___inner_product_hpp
#define beauty__algorithm__numeric___inner_product_hpp

namespace beauty{namespace algorithm{namespace numeric{

template<class InputIterator1, class InputIterator2, class T>inline
T inner_product(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, T init){
	for( ; first1 != last1; ++first1, ++first2){
		init = init + (*first1)*(*first2);
	}
	return init;
}

template<class InputIterator1, class InputIterator2, class T,
class BinaryOperation>inline
T inner_product(InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, T init, BinaryOperation op){
	for( ; first1 != last1; ++first1, ++first2){
		init = init + op(*first1, *first2);
	}
	return init;
}




}
}
}
#endif
