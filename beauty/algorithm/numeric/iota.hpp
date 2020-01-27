
#ifndef beauty__algorithm__numeric___iota_hpp
#define beauty__algorithm__numeric___iota_hpp


namespace beauty{namespace algorithm{namespace numeric{

template<class ForwardIterator, class T>inline
void iota(ForwardIterator first, ForwardIterator last, T value){
	while(first != last){
		*first = value;
		++first;
		++value;
	}
}




}
}
}

#endif
