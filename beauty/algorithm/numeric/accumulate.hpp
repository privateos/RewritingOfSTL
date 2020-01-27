
#ifndef beauty__algorithm__numeric___accumulate_hpp
#define beauty__algorithm__numeric___accumulate_hpp

namespace beauty{namespace algorithm{namespace numeric{

template <class _InputIterator, class _Tp>inline
_Tp accumulate(_InputIterator __first, _InputIterator __last, _Tp __init)
{
  for ( ; __first != __last; ++__first)
    __init = __init + *__first;
  return __init;
}

template <class _InputIterator, class _Tp, class _BinaryOperation>inline
_Tp accumulate(_InputIterator __first, _InputIterator __last, _Tp __init,
               _BinaryOperation __binary_op)
{
  for ( ; __first != __last; ++__first)
    __init = __binary_op(__init, *__first);
  return __init;
}

}
}
}
#endif
