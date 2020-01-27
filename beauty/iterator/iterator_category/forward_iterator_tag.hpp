
#ifndef beauty__iterator__iterator_category___forward_iterator_tag_hpp
#define beauty__iterator__iterator_category___forward_iterator_tag_hpp

#include<./beauty/iterator/iterator_category/input_iterator_tag.hpp>


namespace beauty{namespace iterator{namespace iterator_category{

struct forward_iterator_tag:
public beauty::iterator::iterator_category::input_iterator_tag{};

}
}
}
#endif
