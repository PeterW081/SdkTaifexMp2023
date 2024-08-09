#pragma once
#include "./ViewerMsg.h"
#pragma

#include "xplum_sdkit/taifex_msg_proto/static_function_msg.h"

// using xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgFixSize;
//
template <typename TYPE_MSG>
xplum_sdkit::taifex_msg_proto::ancestor::                  //
    ViewerMsgFixSize<TYPE_MSG>::ViewerMsgFixSize (T &data) //
    : _nshdr::Viewer<T> (data)
{
}
template <typename TYPE_MSG>
xplum_sdkit::taifex_msg_proto::ancestor::                                      //
    ViewerMsgFixSize<TYPE_MSG>::ViewerMsgFixSize (std::span<std::byte> buffer) //
    : _nshdr::Viewer<T> (*reinterpret_cast<T *> (buffer.data ()))
{
  assert (M_DATA_SIZE <= buffer.size ());
}
template <typename TYPE_MSG>
template <std::size_t VAL_BUFFER_SIZE>
auto xplum_sdkit::taifex_msg_proto::ancestor:: //
    ViewerMsgFixSize<TYPE_MSG>::FX_ASSIGN_MSG (std::span<std::byte, VAL_BUFFER_SIZE> buffer) -> void
{
  static_assert (std::dynamic_extent != VAL_BUFFER_SIZE);
  static_assert (M_DATA_SIZE <= VAL_BUFFER_SIZE);
  *reinterpret_cast<T *> (buffer.data ()) = T ();
}
template <typename TYPE_MSG>
auto xplum_sdkit::taifex_msg_proto::ancestor:: //
    ViewerMsgFixSize<TYPE_MSG>::data_span () const -> std::span<std::byte, M_DATA_SIZE>
{
  return std::span<std::byte, M_DATA_SIZE> (reinterpret_cast<std::byte *> (&this->m_super_0_data), M_DATA_SIZE);
}

// using xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgZipSize;
//
template <typename TYPE_MSG, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MAX_OF_MSG_LENGTH, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MIN_OF_MSG_LENGTH>
xplum_sdkit::taifex_msg_proto::ancestor::                                                                                                //
    ViewerMsgZipSize<TYPE_MSG, VAL_MAX_OF_MSG_LENGTH, VAL_MIN_OF_MSG_LENGTH>::ViewerMsgZipSize (T &data, type::TypeMsgLength msg_length) //
    : _nshdr::Viewer<T> (data), m_data_size (msg_length + _nshdr::mt_sizeof_msg_content::SIZE_OUT_OF_MSG_LENGTH)
{
  assert (M_DATA_MAX_SIZE >= m_data_size);
  assert (M_MSG_LENGTH_MAX_VALUE >= msg_length);
  assert (M_MSG_LENGTH_MIN_VALUE <= msg_length);
}
template <typename TYPE_MSG, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MAX_OF_MSG_LENGTH, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MIN_OF_MSG_LENGTH>
xplum_sdkit::taifex_msg_proto::ancestor::                                                                                                                    //
    ViewerMsgZipSize<TYPE_MSG, VAL_MAX_OF_MSG_LENGTH, VAL_MIN_OF_MSG_LENGTH>::ViewerMsgZipSize (std::span<std::byte> buffer, type::TypeMsgLength msg_length) //
    : _nshdr::Viewer<T> (*reinterpret_cast<T *> (buffer.data ())), m_data_size (msg_length + _nshdr::mt_sizeof_msg_content::SIZE_OUT_OF_MSG_LENGTH)
{
  assert (M_DATA_MAX_SIZE >= m_data_size);
  assert (M_MSG_LENGTH_MAX_VALUE >= msg_length);
  assert (M_MSG_LENGTH_MIN_VALUE <= msg_length);

  assert (M_DATA_MAX_SIZE <= buffer.size ());
  assert (m_data_size <= buffer.size ());
}
template <typename TYPE_MSG, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MAX_OF_MSG_LENGTH, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MIN_OF_MSG_LENGTH>
template <std::size_t VAL_BUFFER_SIZE, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MSG_LENGTH>
auto xplum_sdkit::taifex_msg_proto::ancestor:: //
    ViewerMsgZipSize<TYPE_MSG, VAL_MAX_OF_MSG_LENGTH, VAL_MIN_OF_MSG_LENGTH>::FX_ASSIGN_MSG (std::span<std::byte, VAL_BUFFER_SIZE> buffer, type::TypeMsgLength msg_length) -> void
{
  static_assert (std::dynamic_extent != VAL_BUFFER_SIZE);
  static_assert (M_DATA_MAX_SIZE <= VAL_BUFFER_SIZE);
  assert (M_MSG_LENGTH_MAX_VALUE >= msg_length);
  assert (M_MSG_LENGTH_MIN_VALUE <= msg_length);
  *reinterpret_cast<T *> (buffer.data ()) = T ();
  ez_view::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG (buffer.data ()) = msg_length;
}
template <typename TYPE_MSG, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MAX_OF_MSG_LENGTH, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MIN_OF_MSG_LENGTH>
auto xplum_sdkit::taifex_msg_proto::ancestor::                                                                           //
    ViewerMsgZipSize<TYPE_MSG, VAL_MAX_OF_MSG_LENGTH, VAL_MIN_OF_MSG_LENGTH>::data_span () const -> std::span<std::byte> //
{
  return std::span<std::byte>{ reinterpret_cast<std::byte *> (&this->m_super_0_data), m_data_size };
}
