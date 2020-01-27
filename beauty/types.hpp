
#ifndef beauty___types_hpp
#define beauty___types_hpp


#include<./beauty/config.hpp>

namespace beauty{



typedef unsigned int size_t;
typedef signed int ptrdiff_t;

typedef unsigned char uint8_t;
typedef signed char sint8_t;
typedef unsigned short uint16_t;
typedef signed short sint16_t;
typedef unsigned long uint32_t;
typedef signed long sint32_t;
#if beauty__config_hpp___has_long_long_type
	typedef unsigned long long uint64_t;
	typedef signed long long sint64_t;
#endif

////////////////////////////////////
typedef uint8_t ubyte;
typedef sint8_t sbyte;
typedef uint16_t ushort;
typedef sint16_t sshort;
typedef uint32_t uint;
typedef sint32_t sint;
typedef uint64_t ulong;
typedef sint64_t slong;
////////////////////////////////////

///////////////////////////////////
typedef uint size_type;
typedef sint difference_type;
///////////////////////////////////


}
#endif
