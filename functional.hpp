
#ifndef BEAUTY__OUT__FUNCTIONAL_HPP
#define BEAUTY__OUT__FUNCTIONAL_HPP


// ./beauty/
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>
#include<./beauty/exception.hpp>


// ./beauty/functor/
#include<./beauty/functor/binary_function.hpp>
#include<./beauty/functor/divides.hpp>
#include<./beauty/functor/equal_to.hpp>
#include<./beauty/functor/greater.hpp>
#include<./beauty/functor/greater_equal.hpp>
#include<./beauty/functor/identity.hpp>
#include<./beauty/functor/identity_element.hpp>
#include<./beauty/functor/less.hpp>
#include<./beauty/functor/less_equal.hpp>
#include<./beauty/functor/logical_and.hpp>
#include<./beauty/functor/logical_not.hpp>
#include<./beauty/functor/logical_or.hpp>
#include<./beauty/functor/minus.hpp>
#include<./beauty/functor/modulus.hpp>
#include<./beauty/functor/multiplies.hpp>
#include<./beauty/functor/negate.hpp>
#include<./beauty/functor/not_equal_to.hpp>
#include<./beauty/functor/plus.hpp>
#include<./beauty/functor/project1st.hpp>
#include<./beauty/functor/project2nd.hpp>
#include<./beauty/functor/select1st.hpp>
#include<./beauty/functor/select2nd.hpp>
#include<./beauty/functor/unary_function.hpp>




// ./beauty/adapter/function_adapter/
#include<./beauty/adapter/function_adapter/binary_compose.hpp>
#include<./beauty/adapter/function_adapter/binary_negate.hpp>
#include<./beauty/adapter/function_adapter/bind1st.hpp>
#include<./beauty/adapter/function_adapter/bind2nd.hpp>
#include<./beauty/adapter/function_adapter/binder1st.hpp>
#include<./beauty/adapter/function_adapter/binder2nd.hpp>
#include<./beauty/adapter/function_adapter/compose1.hpp>
#include<./beauty/adapter/function_adapter/compose2.hpp>
#include<./beauty/adapter/function_adapter/not1.hpp>
#include<./beauty/adapter/function_adapter/not2.hpp>
#include<./beauty/adapter/function_adapter/unary_compose.hpp>
#include<./beauty/adapter/function_adapter/unary_negate.hpp>





// ./beauty/adapter/function_pointer_adapter/
#include<./beauty/adapter/function_pointer_adapter/const_mem_fun_ref_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/const_mem_fun_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/const_mem_fun1_ref_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/const_mem_fun1_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun_ref.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun_ref_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun1.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun1_ref.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun1_ref_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/mem_fun1_t.hpp>
#include<./beauty/adapter/function_pointer_adapter/pointer_to_binary_function.hpp>
#include<./beauty/adapter/function_pointer_adapter/pointer_to_unary_function.hpp>
#include<./beauty/adapter/function_pointer_adapter/ptr_fun.hpp>




// ./beauty/container/hashtable/
#include<./beauty/container/hashtable/hash_function.hpp>




namespace future{
using namespace beauty;
using namespace beauty::functor;
using namespace beauty::adapter::function_adapter;
using namespace beauty::adapter::function_pointer_adapter;
using namespace beauty::container::hashtable;
}
#endif
