
#ifndef beauty__iterator__iterator_traits___iterator_hpp
#define beauty__iterator__iterator_traits___iterator_hpp

#include<./beauty/types.hpp>


namespace beauty{namespace iterator{namespace iterator_traits{


template<class Category, class T, class Distance = beauty::size_t,
class Pointer = T*, class Reference = T&>
struct iterator{
	typedef Category					iterator_category;
	typedef T								   value_type;
	typedef Distance					  difference_type;
	typedef Pointer								  pointer;
	typedef Reference							reference;
};

}
}
}
#endif
