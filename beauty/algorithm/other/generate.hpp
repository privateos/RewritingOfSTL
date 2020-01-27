
#ifndef beauty__algorithm__other___generate_hpp
#define beauty__algorithm__other___generate_hpp


namespace beauty{namespace algorithm{namespace other{
	

template<class ForwardIter, class Generator>
void generate(ForwardIter first, ForwardIter last, Generator gen){
	for( ; first != last; ++first){
		*first = gen();
	}
}


}
}
}
#endif
