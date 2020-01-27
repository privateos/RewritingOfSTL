
#ifndef beauty__algorithm__algorithmbase___min_hpp
#define beauty__algorithm__algorithmbase___min_hpp


namespace beauty{namespace algorithm{namespace algorithmbase{


template<class T>
inline const T& min(const T &a, const T &b){
	return a < b ? a : b;
}
template<class T, class Compare>
inline const T& min(const T &a, const T &b, Compare comp){
	return comp(a, b) ? a : b;
}


}
}
}
#endif
