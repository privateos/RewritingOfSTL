
#ifndef beauty__allocator__function___construct_hpp
#define beauty__allocator__function___construct_hpp

#include<./beauty/header.hpp>


namespace beauty{namespace allocator{namespace function{

template<class T1, class T2>inline
void construct(T1 *p, T2 &value){
	new(p) T1(value);
}
template<class T>inline
void construct(T *p){
	new(p) T();
}


}
}
}
#endif
