
#ifndef beauty__iterator__function___value_type_hpp
#define beauty__iterator__function___value_type_hpp

#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>


namespace beauty{namespace iterator{namespace function{

template<class Iterator>inline

typename beauty::iterator::iterator_traits::
	iterator_traits<Iterator>::value_type*//returnType
value_type(const Iterator&){//functionName
	typedef typename beauty::iterator::iterator_traits::
	iterator_traits<Iterator>::value_type valueType;
	return static_cast<valueType*>(0);
}


}
}
}
#endif
