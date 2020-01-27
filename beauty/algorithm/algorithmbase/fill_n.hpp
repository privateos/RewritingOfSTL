

#ifndef beauty__algorithm__algorithmbase___fill_n_hpp
#define beauty__algorithm__algorithmbase___fill_n_hpp


namespace beauty{namespace algorithm{namespace algorithmbase{


template <class _OutputIter, class _Size, class _Tp>
_OutputIter fill_n(_OutputIter __first, _Size __n, const _Tp& __value) {

  for ( ; __n > 0; --__n, ++__first)
    *__first = __value;
  return __first;
}


}
}
}
#endif
