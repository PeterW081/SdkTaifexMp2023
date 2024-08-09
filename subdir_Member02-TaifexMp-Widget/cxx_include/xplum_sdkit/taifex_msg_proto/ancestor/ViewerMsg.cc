#pragma once
#include "./ViewerMsg.h"
#pragma

#include <span>
#include "xplum/ancestor/Viewer.h"
#include "xplum_model/taifex_msg_proto/static_constant.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"

#define MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(PARAM01_SUBCLASS_NAME)                                                                                                                                                                           \
  using TYPE_MsgOrigin = T;                                                                                                                                                                                                                                    \
  explicit PARAM01_SUBCLASS_NAME (T &data) : ViewerMsgFixSize (data){};                                                                                                                                                                                        \
  explicit PARAM01_SUBCLASS_NAME (std::span<std::byte> buffer) : ViewerMsgFixSize (buffer){};                                                                                                                                                                  \
  //

namespace xplum_sdkit::taifex_msg_proto::ancestor::_nshdr
{
namespace mt_sizeof_msg_content = xplum_model::taifex_msg_proto::mt_sizeof_msg_content;
using xplum::ancestor::Viewer;
}

namespace xplum_sdkit::taifex_msg_proto::ancestor
{
template <typename TYPE_MSG> class ViewerMsgFixSize;

template <typename TYPE_MSG, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MAX_OF_MSG_LENGTH, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MIN_OF_MSG_LENGTH> class ViewerMsgZipSize;

}

template <typename TYPE_MSG> class xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgFixSize : public _nshdr::Viewer<TYPE_MSG>
{
public:
  using T = TYPE_MSG;

public:
  static const std::size_t M_DATA_SIZE = sizeof (T);
  template <std::size_t VAL_BUFFER_SIZE> static auto FX_ASSIGN_MSG (std::span<std::byte, VAL_BUFFER_SIZE>) -> void; // buffer
  explicit ViewerMsgFixSize (T &);                                                                                  // data
  explicit ViewerMsgFixSize (std::span<std::byte>);                                                                 // buffer
  auto data_span () const -> std::span<std::byte, M_DATA_SIZE>;
};

template <typename TYPE_MSG, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MAX_OF_MSG_LENGTH, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VAL_MIN_OF_MSG_LENGTH>
class xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgZipSize : public _nshdr::Viewer<TYPE_MSG>
{
public:
  using T = TYPE_MSG;

public:
  static const std::size_t M_DATA_MAX_SIZE = sizeof (TYPE_MSG);
  static const type::TypeMsgLength M_MSG_LENGTH_MAX_VALUE = VAL_MAX_OF_MSG_LENGTH;
  static const type::TypeMsgLength M_MSG_LENGTH_MIN_VALUE = VAL_MIN_OF_MSG_LENGTH;

  template <std::size_t VAL_BUFFER_SIZE, type::TypeMsgLength VAL_MSG_LENGTH = VAL_MAX_OF_MSG_LENGTH> static auto FX_ASSIGN_MSG (std::span<std::byte, VAL_BUFFER_SIZE>, type::TypeMsgLength = VAL_MSG_LENGTH) -> void; // buffer, msg_length,

  explicit ViewerMsgZipSize (T &, type::TypeMsgLength);                  // data,   msg_length,
  explicit ViewerMsgZipSize (std::span<std::byte>, type::TypeMsgLength); // buffer, msg_length,
  auto data_span () const -> std::span<std::byte>;

private:
  const std::size_t m_data_size;

private:
  static_assert (M_DATA_MAX_SIZE == M_MSG_LENGTH_MAX_VALUE + _nshdr::mt_sizeof_msg_content::SIZE_OUT_OF_MSG_LENGTH);
};
