
#ifndef BEAUTY__OUT__ITERATOR_HPP
#define BEAUTY__OUT__ITERATOR_HPP

// ./beauty/
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>
#include<./beauty/exception.hpp>


// ./beauty/iterator/function/
#include<./beauty/iterator/function/advance.hpp>
#include<./beauty/iterator/function/distance.hpp>
#include<./beauty/iterator/function/distance_type.hpp>
#include<./beauty/iterator/function/iterator_category.hpp>
#include<./beauty/iterator/function/value_type.hpp>



// ./beauty/iterator/iterator_category/
#include<./beauty/iterator/iterator_category/bidirectional_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/input_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/output_iterator_tag.hpp>
#include<./beauty/iterator/iterator_category/random_access_iterator_tag.hpp>



// ./beauty/iterator/iterator_traits/
#include<./beauty/iterator/iterator_traits/iterator.hpp>
#include<./beauty/iterator/iterator_traits/iterator_traits.hpp>



namespace future{
using namespace beauty;
using namespace beauty::iterator::function;
using namespace beauty::iterator::iterator_category;
using namespace beauty::iterator::iterator_traits;

}
#endif
