
#ifndef include___std___new_h
	#define include___std___new_h
	#include<new.h>
#endif

namespace beauty{namespace allocator{namespace function{

template<class T>
inline void destroy(T *p){
	p->~T();
}



}
}
}
