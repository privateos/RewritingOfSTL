
#ifndef beauty___config_hpp
#define beauty___config_hpp


namespace beauty{
/*

*/
//#define explicit
#define noexcept throw()
#define final
#define constexpr
#define override
#define nullptr 0

#define TEMPLATE_NULL template<>

//0 no   1 yes
#define beauty__config_hpp___has_rvalue_reference 0
#define beauty__config_hpp___has_long_long_type 1
#define beauty__config_hpp___has_long_double_type 0
#define beauty__config_hpp___has_wchar_t_type 1
#define beauty__config_hpp___has_char16_t_type 0
#define beauty__config_hpp___has_char32_t_type 0


//sizeof(type)
#define beauty__config_hpp___sizeof_pointer 4  //sizeof(void*)


}
#endif

