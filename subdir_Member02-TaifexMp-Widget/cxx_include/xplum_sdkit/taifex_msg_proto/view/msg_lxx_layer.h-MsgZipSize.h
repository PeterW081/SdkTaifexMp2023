#pragma once
#include "XPLUM_MACRO/MACRO_INITIALIZATION.h"
#include "xplum_model/taifex_msg_proto/structure_message/msg_lxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/ViewerMsg.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field_enumerate.h"

namespace xplum_sdkit::taifex_msg_proto::view::message::_nshdr {
namespace mt_sizeof_msg_content = xplum_model::taifex_msg_proto::mt_sizeof_msg_content;
using xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgZipSize;
}

namespace xplum_sdkit::taifex_msg_proto::view::message {
namespace origin = xplum_model::taifex_msg_proto::message;

// LxxLayer - MsgZipSize
class L41;
}

/// xplum::taifex_msg_proto_sdk::view::message::L41
class xplum_sdkit::taifex_msg_proto::view::message::L41
    : public _nshdr::ViewerMsgZipSize<origin::L41<_nshdr::mt_sizeof_msg_content::VALUE_MAX_OF_MSG_LENGTH>, _nshdr::mt_sizeof_msg_content::VALUE_MAX_OF_MSG_LENGTH, _nshdr::mt_sizeof_msg_content::VALUE_MIN_OF_MSG_LENGTH_L41> {
  using TYPE_L41MaxSize = origin::L41<_nshdr::mt_sizeof_msg_content::VALUE_MAX_OF_MSG_LENGTH>;
  using TYPE_L41MinSize = origin::L41<_nshdr::mt_sizeof_msg_content::VALUE_MIN_OF_MSG_LENGTH_L41>;
  const std::size_t m_private_0_sizeof_L41_data;
  std::byte *const m_private_0_viewer_data_ptr_offset00; // L41 Field: hdr, status_code, is_eof, file_size, data,
  std::byte *const m_private_0_viewer_data_ptr_offset01; // L41 Field: CheckSum,

public:
  using TYPE_MsgOrigin = T;
  explicit L41(T &data);              // data
  explicit L41(std::span<std::byte>); // span

public:
  /* L41_FieldNo01 */ /* offset00 */ message_field::MsgHdr m_hdr = message_field::MsgHdr(*reinterpret_cast<decltype(TYPE_L41MinSize::hdr) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, hdr)));
  /* L41_FieldNo02 */ /* offset00 */ message_field::origin::uint8 &m_status_code = *reinterpret_cast<decltype(TYPE_L41MinSize::status_code) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, status_code));
  /* L41_FieldNo03 */ /* offset00 */ message_field::enumerate::IsEof m_is_eof = message_field::enumerate::IsEof(*reinterpret_cast<decltype(TYPE_L41MinSize::is_eof) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, is_eof)));
  /* L41_FieldNo04 */ /* offset00 */ message_field::origin::uint32 &m_file_size = *reinterpret_cast<decltype(TYPE_L41MinSize::file_size) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, file_size));
  /* L41_FieldNo05 */ /* offset00 */ std::span<message_field::origin::uint8> m_data = std::span(reinterpret_cast<message_field::origin::uint8 *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, data)), m_private_0_sizeof_L41_data);
  /* L41_FieldNo06 */ /* offset01 */ message_field::origin::uint8 &m_check_sum = *reinterpret_cast<decltype(TYPE_L41MinSize::CheckSum) *>(m_private_0_viewer_data_ptr_offset01 + offsetof(TYPE_L41MinSize, CheckSum));
};
inline xplum_sdkit::taifex_msg_proto::view::message::                              //
    L41::L41(T &data /*, type::TypeMsgLength msg_length = = data.hdr.msg_length*/) //
    : ViewerMsgZipSize(data, data.hdr.msg_length), m_private_0_sizeof_L41_data(data.hdr.msg_length - _nshdr::mt_sizeof_msg_content::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH),
      m_private_0_viewer_data_ptr_offset00(reinterpret_cast<std::byte *>(&this->m_super_0_data)), m_private_0_viewer_data_ptr_offset01(reinterpret_cast<std::byte *>(&this->m_super_0_data) + m_private_0_sizeof_L41_data) {
  // assert(msg_length >= _nshdr::mt_sizeof_msg_content::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH);
  assert(M_MSG_LENGTH_MAX_VALUE >= data.hdr.msg_length);
  assert(M_MSG_LENGTH_MIN_VALUE <= data.hdr.msg_length);
  // assert(data.hdr.msg_length == m_hdr.m_msg_length);
}
inline xplum_sdkit::taifex_msg_proto::view::message:: //
    L41::L41(std::span<std::byte> buffer)
    : ViewerMsgZipSize(buffer, (*reinterpret_cast<T *>(buffer.data())).hdr.msg_length), m_private_0_sizeof_L41_data((*reinterpret_cast<T *>(buffer.data())).hdr.msg_length - _nshdr::mt_sizeof_msg_content::SIZE_OUT_OF_L41_DATA_IN_MSG_LENGTH),
      m_private_0_viewer_data_ptr_offset00(reinterpret_cast<std::byte *>(&this->m_super_0_data)), m_private_0_viewer_data_ptr_offset01(reinterpret_cast<std::byte *>(&this->m_super_0_data) + m_private_0_sizeof_L41_data) {
  auto data = (*reinterpret_cast<T *>(buffer.data()));
  assert(M_MSG_LENGTH_MAX_VALUE >= data.hdr.msg_length);
  assert(M_MSG_LENGTH_MIN_VALUE <= data.hdr.msg_length);
  assert(buffer.size() >= data.hdr.msg_length);
}
