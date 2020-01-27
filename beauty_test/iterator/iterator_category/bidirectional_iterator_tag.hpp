
#ifndef include___beauty__iterator__iterator_category___forward_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___forward_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#endif



namespace beauty{namespace iterator{namespace iterator_category{

struct bidirectional_iterator_tag:
public beauty::iterator::iterator_category::forward_iterator_tag{};

}
}
}