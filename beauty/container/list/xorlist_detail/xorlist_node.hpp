
#ifndef beauty__container__list__xorlist___xorlist_node_hpp
#define beauty__container__list__xorlist___xorlist_node_hpp

#include<./beauty/config.hpp>
#include<./beauty/types.hpp>


namespace beauty{namespace container{namespace list{namespace xorlist_detail{


template<class T>
struct xorlist_node{
	T value;
	union pointer_integer{
		xorlist_node<T>* pointer;
		#if beauty__config_hpp___sizeof_pointer == 1
			beauty::ubyte integer;
		#else
			#if beauty__config_hpp___sizeof_pointer == 2
				beauty::ushort integer;
			#else
				#if beauty__config_hpp___sizeof_pointer == 4
					beauty::uint integer;
				#else
					#if beauty__config_hpp___sizeof_pointer == 8
						beauty::ulong integer;
					#endif
				#endif
			#endif
		#endif 
	}u;
};


}
}
}
}
#endif
