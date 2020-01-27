
#ifndef beauty__functor___unary_function_hpp
#define beauty__functor___unary_function_hpp


namespace beauty{namespace functor{

template<class Arg, class Result>
struct unary_function{
	typedef Arg    argument_type;
	typedef Result   result_type;
};

}
}
#endif
