
#ifndef include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#define include___beauty__iterator__iterator_traits___iterator_traits_hpp
	#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>
#endif

namespace beauty{namespace iterator{namespace function{

template<class Iterator>inline

typename beauty::iterator::iterator_traits::
	iterator_traits<Iterator>::value_type*//returnType
value_type(const Iterator&){//functionName
	typedef beauty::iterator::iterator_traits::iterator_traits<Iterator>
	::value_type valueType;
	return static_cast<valueType*>(0);
}


}
}
}
