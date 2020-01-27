
#ifndef beauty__algorithm__algorithmbase___max_hpp
#define beauty__algorithm__algorithmbase___max_hpp


namespace beauty{namespace algorithm{namespace algorithmbase{



template<class T>
inline const T& max(const T &a, const T &b){
	return a < b ? b : a;
} 
template<class T, class Compare>
inline const T& max(const T &a, const T &b, Compare comp){
	return comp(a, b) ? b : a;
}

}
}
}
#endif
