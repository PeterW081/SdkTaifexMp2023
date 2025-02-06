#pragma once
#include "./msg_lxx_layer.h"
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg/msg_lxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/ViewerMsg.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field_enumerate.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view_plugin/PlugerMsg_Common.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view_plugin/PlugerMsg_SP_L41.h"
#

namespace xplum_sdkit::taifex_msg_proto::view::message::_nshdr
{
namespace msg_sizeof_content = xplum_model::taifex_msg_proto::msg_sizeof_content;
using xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsg;
using xplum_sdkit::taifex_msg_proto::view::message_plugin::PlugerMsg_Common;
using xplum_sdkit::taifex_msg_proto::view::message_plugin::PlugerMsg_SP_L41;
}

namespace xplum_sdkit::taifex_msg_proto::view::message
{
namespace model = xplum_model::taifex_msg_proto::message;

// LxxLayer - MsgZipSize
class MsgL41_VIEW;
}

/// xplum::taifex_msg_proto_sdk::view::message::L41
class                                              //
    xplum_sdkit::taifex_msg_proto::view::message:: //
    MsgL41_VIEW                                    //
    : public _nshdr::ViewerMsg<model::L41<>, _nshdr::msg_sizeof_content::G_value_min_of_msg_length_L41>,
      public _nshdr::PlugerMsg_Common<MsgL41_VIEW>,
      public _nshdr::PlugerMsg_SP_L41<MsgL41_VIEW>
{
    using TYPE_L41MinSize = model::L41<M_msg_length_min_value>;
    const std::size_t m_private_0_sizeof_L41_data;
    std::byte *const m_private_0_viewer_data_ptr_offset00; // L41 Field: hdr, status_code, is_eof, file_size, data,
    std::byte *const m_private_0_viewer_data_ptr_offset01; // L41 Field: CheckSum,

  public:
    static auto FX_init_msg(std::span<std::byte>, type::TypeMsgLength) -> MsgL41_VIEW; // buffer, msg_length,
    explicit MsgL41_VIEW(TypeMsgData &, type::TypeMsgLength);                          // data,   msg_length,
    explicit MsgL41_VIEW(std::span<std::byte>, type::TypeMsgLength);                   // buffer, msg_length,

  public:
    /* L41_FieldNo01 */ /* offset00 */ view::message_field::MsgHdr_VIEW m_hdr = message_field::MsgHdr_VIEW(*reinterpret_cast<decltype(TYPE_L41MinSize::hdr) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, hdr)));
    /* L41_FieldNo02 */ /* offset00 */ view::message_field::uint08_VIEW m_status_code = *reinterpret_cast<decltype(TYPE_L41MinSize::status_code) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, status_code));
    /* L41_FieldNo03 */ /* offset00 */ view::message_field::enumerate::IsEof_VIEW m_is_eof =
        message_field::enumerate::IsEof_VIEW(*reinterpret_cast<decltype(TYPE_L41MinSize::is_eof) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, is_eof)));
    /* L41_FieldNo04 */ /* offset00 */ view::message_field::uint32_VIEW m_file_size = *reinterpret_cast<decltype(TYPE_L41MinSize::file_size) *>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, file_size));
    /* L41_FieldNo05 */ /* offset00 */ view::message_field::array::L41_Data_SPAN m_data =
        std::span(reinterpret_cast<view::message_field::array::L41_Data_SPAN::pointer>(m_private_0_viewer_data_ptr_offset00 + offsetof(TYPE_L41MinSize, data)), m_private_0_sizeof_L41_data);
    /* L41_FieldNo06 */ /* offset01 */ view::message_field::uint08_VIEW m_check_sum = *reinterpret_cast<decltype(TYPE_L41MinSize::CheckSum) *>(m_private_0_viewer_data_ptr_offset01 + offsetof(TYPE_L41MinSize, CheckSum));
};

/// xplum::taifex_msg_proto_sdk::view::message::L41 - 02
inline auto                                        //
    xplum_sdkit::taifex_msg_proto::view::message:: //
    MsgL41_VIEW::                                  //
    FX_init_msg(std::span<std::byte> buffer, type::TypeMsgLength msg_length) -> MsgL41_VIEW
{
    ViewerMsg::FX_init_msg(buffer, msg_length);
    return MsgL41_VIEW(buffer, msg_length);
}
/*Constructor*/ inline                                             //
    xplum_sdkit::taifex_msg_proto::view::message::                 //
    MsgL41_VIEW::                                                  //
    MsgL41_VIEW(TypeMsgData &data, type::TypeMsgLength msg_length) //
    : ViewerMsg(data, msg_length), m_private_0_sizeof_L41_data(msg_length - _nshdr::msg_sizeof_content::G_size_out_of_L41_data_in_msg_length), m_private_0_viewer_data_ptr_offset00(reinterpret_cast<std::byte *>(&this->m_super_0_data)),
      m_private_0_viewer_data_ptr_offset01(reinterpret_cast<std::byte *>(&this->m_super_0_data) + m_private_0_sizeof_L41_data)
{
}
/*Constructor*/ inline                                                       //
    xplum_sdkit::taifex_msg_proto::view::message::                           //
    MsgL41_VIEW::                                                            //
    MsgL41_VIEW(std::span<std::byte> buffer, type::TypeMsgLength msg_length) //
    : ViewerMsg(buffer, msg_length), m_private_0_sizeof_L41_data((*reinterpret_cast<T *>(buffer.data())).hdr.msg_length - _nshdr::msg_sizeof_content::G_size_out_of_L41_data_in_msg_length),
      m_private_0_viewer_data_ptr_offset00(reinterpret_cast<std::byte *>(&this->m_super_0_data)), m_private_0_viewer_data_ptr_offset01(reinterpret_cast<std::byte *>(&this->m_super_0_data) + m_private_0_sizeof_L41_data)
{
}
