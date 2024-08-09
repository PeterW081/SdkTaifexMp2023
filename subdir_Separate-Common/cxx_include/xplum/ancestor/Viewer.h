#pragma once

#define MACRO_XPLUM_ANCESTOR_VIEWER_DEPLOY_SUBCLASS(PARAM01_SUBCLASS_NAME)                                                                                                                                                                                     \
  explicit PARAM01_SUBCLASS_NAME (T &data) : Viewer (data){};                                                                                                                                                                                                  \
  explicit PARAM01_SUBCLASS_NAME (void *data) : Viewer (*reinterpret_cast<T *> (data)){};                                                                                                                                                                      \
  //

namespace xplum::ancestor
{
template <typename T> class Viewer;
}

template <typename TYPENAME_T> class xplum::ancestor::Viewer
{
public:
  Viewer () = delete;

public:
  auto &data () const;

protected:
  using T = TYPENAME_T;
  T &m_super_0_data;
  explicit Viewer (T &data);
};

// ******************************** ******************************** ******************************** ******************************** //
template <typename T> xplum::ancestor::Viewer<T>::Viewer (T &data) : m_super_0_data (data) {}

template <typename T>
auto &
xplum::ancestor::Viewer<T>::data () const
{
  return m_super_0_data;
}
