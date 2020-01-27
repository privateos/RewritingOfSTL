
#ifndef beauty__allocator__type_traits___type_traits_hpp
#define beauty__allocator__type_traits___type_traits_hpp

#include<./beauty/allocator/type_traits/true_type.hpp>
#include<./beauty/allocator/type_traits/false_type.hpp>
#include<./beauty/config.hpp>







#define beauty__allocator__type_traits__type_traits___type_dispatch(type)\
TEMPLATE_NULL struct type_traits<type>{\
	typedef beauty::allocator::type_traits::\
		true_type          has_trivial_default_constructor;\
	typedef beauty::allocator::type_traits::\
		true_type             has_trivial_copy_constructor;\
	typedef beauty::allocator::type_traits::\
		true_type          has_trivial_assignment_operator;\
	typedef beauty::allocator::type_traits::\
		true_type          		    has_trivial_destructor;\
	typedef beauty::allocator::type_traits::\
		true_type          			    		is_POD_type;\
};

#define beauty__allocator__type_traits__type_traits___type(type)\
beauty__allocator__type_traits__type_traits___type_dispatch(type)\
beauty__allocator__type_traits__type_traits___type_dispatch(unsigned type)\
//beauty__allocator__type_traits__type_traits___type_dispatch(signed type)

namespace beauty{namespace allocator{namespace type_traits{


template<class T>
struct type_traits{
	typedef beauty::allocator::type_traits::
		false_type          has_trivial_default_constructor;
	typedef beauty::allocator::type_traits::
		false_type             has_trivial_copy_constructor;
	typedef beauty::allocator::type_traits::
		false_type          has_trivial_assignment_operator;
	typedef beauty::allocator::type_traits::
		false_type          		 has_trivial_destructor;
	typedef beauty::allocator::type_traits::
		false_type          					is_POD_type;
};

beauty__allocator__type_traits__type_traits___type_dispatch(bool)
beauty__allocator__type_traits__type_traits___type(char)
beauty__allocator__type_traits__type_traits___type(short)
beauty__allocator__type_traits__type_traits___type(int)
beauty__allocator__type_traits__type_traits___type(long)
beauty__allocator__type_traits__type_traits___type_dispatch(float)
beauty__allocator__type_traits__type_traits___type_dispatch(double)
beauty__allocator__type_traits__type_traits___type_dispatch(long double)

template<class T>
struct type_traits<T*>{
	typedef beauty::allocator::type_traits::
		true_type          has_trivial_default_constructor;
	typedef beauty::allocator::type_traits::
		true_type             has_trivial_copy_constructor;
	typedef beauty::allocator::type_traits::
		true_type          has_trivial_assignment_operator;
	typedef beauty::allocator::type_traits::
		true_type          		    has_trivial_destructor;
	typedef beauty::allocator::type_traits::
		true_type          			    	   is_POD_type;
};

}
}
}
#endif
