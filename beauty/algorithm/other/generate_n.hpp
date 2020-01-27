
#ifndef beauty__algorithm__other___generate_n_hpp
#define beauty__algorithm__other___generate_n_hpp


namespace beauty{namespace algorithm{namespace other{
	


template<class OutputIter, class Size, class Generator>
OutputIter generate_n(OutputIter first, Size n, Generator gen){
	for( ; n > 0; --n, ++first){
		*first = gen();
	}
	return first;
}

}
}
}
#endif
