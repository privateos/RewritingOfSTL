
#ifndef beauty__functor___binary_function_hpp
#define beauty__functor___binary_function_hpp


namespace beauty{namespace functor{

template<class Arg1, class Arg2, class Result>
struct binary_function{
	typedef Arg1    	first_argument_type;
	typedef Arg2       second_argument_type;
	typedef Result              result_type;
};

}
}
#endif
