
#ifndef BEAUTY__OUT__CONTAINER_HPP
#define BEAUTY__OUT__CONTAINER_HPP

// ./beauty/
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>
#include<./beauty/exception.hpp>


// ./beauty/allocator/
#include<./beauty/allocator/simple_allocator.hpp>




// ./beauty/container/hashtable/
#include<./beauty/container/hashtable/hashtable.hpp>
#include<./beauty/container/hashtable/hash_function.hpp>



// ./beauty/container/map/
#include<./beauty/container/map/hash_map.hpp>
#include<./beauty/container/map/hash_multimap.hpp>
#include<./beauty/container/map/tree_map.hpp>
#include<./beauty/container/map/tree_multimap.hpp>


// ./beauty/container/set/
#include<./beauty/container/set/hash_multiset.hpp>
#include<./beauty/container/set/hash_set.hpp>
#include<./beauty/container/set/tree_set.hpp>
#include<./beauty/container/set/tree_multiset.hpp>



// ./beauty/container/queue/
#include<./beauty/container/queue/deque.hpp>
#include<./beauty/container/queue/priority_queue.hpp>
#include<./beauty/container/queue/queue.hpp>
#include<./beauty/container/queue/seque.hpp>



// ./beauty/container/array/
#include<./beauty/container/array/carray.hpp>
#include<./beauty/container/array/cpparray.hpp>
#include<./beauty/container/array/vector.hpp>
#include<./beauty/container/array/tree_array.hpp>


// ./beauty/container/list/
#include<./beauty/container/list/list.hpp>
#include<./beauty/container/list/slist.hpp>
#include<./beauty/container/list/xorlist.hpp>
#include<./beauty/container/list/seqlist.hpp>



// ./beauty/container/pair/
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/pair/make_pair.hpp>
#include<./beauty/container/pair/pair_operator_function.hpp>



// ./beauty/container/stack/
#include<./beauty/container/stack/stack.hpp>
#include<./beauty/container/stack/seqstack.hpp>



// ./beauty/container/tree/
#include<./beauty/container/tree/rb_tree.hpp>
#include<./beauty/container/tree/avl_tree.hpp>



namespace future{
using namespace beauty;
using namespace beauty::allocator;
using namespace beauty::container::hashtable;
using namespace beauty::container::map;
using namespace beauty::container::set;
using namespace beauty::container::queue;
using namespace beauty::container::array;
using namespace beauty::container::list;
using namespace beauty::container::pair;
using namespace beauty::container::stack;
using namespace beauty::container::tree;


}
#endif
