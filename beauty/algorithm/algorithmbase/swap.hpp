
#ifndef beauty__algorithm__algorithmbase___swap_hpp
#define beauty__algorithm__algorithmbase___swap_hpp


namespace beauty{namespace algorithm{namespace algorithmbase{


template<class T>
inline void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}


}
}
}
#endif
