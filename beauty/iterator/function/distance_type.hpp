
#ifndef beauty__iterator__function___distance_type_hpp
#define beauty__iterator__function___distance_type_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace iterator{namespace function{

template<class Iterator>inline
typename beauty::iterator::iterator_traits::
iterator_traits<Iterator>::difference_type*//returnType

distance_type(const Iterator&){//functionName
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<Iterator>::difference_type Distance;
	return static_cast<Distance*>(0);
}


}
}
}
#endif
