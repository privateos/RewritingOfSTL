
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace iterator{namespace function{

template<class Iterator>inline
typename beauty::iterator::iterator_traits::
iterator_traits<Iterator>::iterator_category//returnType

iterator_category(const Iterator&){//functionName
	typedef beauty::iterator::iterator_traits::iterator_traits<Iterator>
	::iterator_category Category;
	return Category();
}


}
}
}