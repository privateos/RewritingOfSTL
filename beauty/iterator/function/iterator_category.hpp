
#ifndef beauty__iterator__function___iterator_category_hpp
#define beauty__iterator__function___iterator_category_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace iterator{namespace function{

template<class Iterator>inline
typename beauty::iterator::iterator_traits::
iterator_traits<Iterator>::iterator_category//returnType

iterator_category(const Iterator&){//functionName
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<Iterator>::iterator_category Category;
	return Category();
}


}
}
}
#endif
