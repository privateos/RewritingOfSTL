
#ifndef include___beauty__iterator__iterator_category___bidirectional_iterator_tag_hpp
	#define include___beauty__iterator__iterator_category___bidirectional_iterator_tag_hpp
	#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#endif

namespace beauty{namespace iterator{namespace iterator_category{

struct random_access_iterator_tag:
public beauty::iterator::iterator_category::bidirectional_iterator_tag{};

}
}
}