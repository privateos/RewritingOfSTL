
#ifndef include___beauty___types_hpp
	#define include___beauty___types_hpp
	#include<./beauty/types.hpp>
#endif
#ifndef include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___random_access_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>
#endif

namespace beauty{namespace iterator{namespace iterator_traits{


template<class Iterator>
struct iterator_traits{
	typedef typename Iterator::iterator_category			iterator_category;
	typedef typename Iterator::value_type					   value_type;
	typedef typename Iterator::difference_type			  difference_type;
	typedef typename Iterator::pointer							  pointer;
	typedef typename Iterator::reference							reference;
};

template<class T>
struct iterator_traits<T*>{
	typedef beauty::iterator::iterator_category::random_access_iterator_tag
												iterator_category;
	typedef T										   value_type;
	typedef beauty::size_t						  difference_type;
	typedef T*											  pointer;
	typedef T&											reference;
};

template<class T>
struct iterator_traits<const T*>{
	typedef beauty::iterator::iterator_category::random_access_iterator_tag
												iterator_category;
	typedef T										   value_type;
	typedef beauty::size_t						  difference_type;
	typedef T*											  pointer;
	typedef T&											reference;
};


}
}
}
