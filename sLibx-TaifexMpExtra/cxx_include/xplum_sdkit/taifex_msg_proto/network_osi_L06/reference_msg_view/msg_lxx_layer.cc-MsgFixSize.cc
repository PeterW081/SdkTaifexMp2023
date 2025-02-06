#pragma once
#include "./msg_lxx_layer.h"
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg/msg_lxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/ViewerMsg.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field_enumerate.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view_plugin/PlugerMsg_Common.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view_plugin/PlugerMsg_SP_L40.h"
#

///
namespace xplum_sdkit::taifex_msg_proto::view::message::_nshdr
{
using xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgFixSize;
using xplum_sdkit::taifex_msg_proto::view::message_plugin::PlugerMsg_Common;
using xplum_sdkit::taifex_msg_proto::view::message_plugin::PlugerMsg_SP_L40;
struct L10;
struct L20;
struct L30;
struct L40;
struct L42;
struct L50;
struct L60;
}
namespace xplum_sdkit::taifex_msg_proto::view::message
{
namespace model = xplum_model::taifex_msg_proto::message;

// LxxLayer - MsgFixSize
using MsgL10_VIEW = _nshdr::L10;
using MsgL20_VIEW = _nshdr::L20;
using MsgL30_VIEW = _nshdr::L30;
using MsgL40_VIEW = _nshdr::L40;
using MsgL42_VIEW = _nshdr::L42;
using MsgL50_VIEW = _nshdr::L50;
using MsgL60_VIEW = _nshdr::L60;
}

/// xplum::taifex_msg_proto_sdk::view::message::L10
#define LXX L10
struct xplum_sdkit::taifex_msg_proto::view::message::_nshdr::LXX : ViewerMsgFixSize<model::LXX>, PlugerMsg_Common<LXX>
{
    MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(LXX);
    /* L10_FieldNo01 */ view::message_field::MsgHdr_VIEW m_hdr = view::message_field::MsgHdr_VIEW(m_super_0_data.hdr);
    /* L10_FieldNo02 */ view::message_field::uint08_VIEW m_status_code = m_super_0_data.status_code;
    /* L10_FieldNo03 */ view::message_field::uint32_VIEW m_start_in_bound_num = m_super_0_data.start_in_bound_num;
    /* L10_FieldNo04 */ view::message_field::uint08_VIEW m_check_sum = m_super_0_data.CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L20
#define LXX L20
struct xplum_sdkit::taifex_msg_proto::view::message::_nshdr::LXX : ViewerMsgFixSize<model::LXX>, PlugerMsg_Common<LXX>
{
    MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(LXX);
    /* L20_FieldNo01 */ view::message_field::MsgHdr_VIEW m_hdr = view::message_field::MsgHdr_VIEW(m_super_0_data.hdr);
    /* L20_FieldNo02 */ view::message_field::uint08_VIEW m_status_code = m_super_0_data.status_code;
    /* L20_FieldNo03 */ view::message_field::uint08_VIEW m_check_sum = m_super_0_data.CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L30
#define LXX L30
struct xplum_sdkit::taifex_msg_proto::view::message::_nshdr::LXX : ViewerMsgFixSize<model::LXX>, PlugerMsg_Common<LXX>
{
    MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(LXX);
    /* L30_FieldNo01 */ view::message_field::MsgHdr_VIEW m_hdr = view::message_field::MsgHdr_VIEW(m_super_0_data.hdr);
    /* L30_FieldNo02 */ view::message_field::uint08_VIEW m_status_code = m_super_0_data.status_code;
    /* L30_FieldNo03 */ view::message_field::uint16_VIEW m_append_no = m_super_0_data.append_no;
    /* L30_FieldNo04 */ view::message_field::uint32_VIEW m_end_out_bound_num = m_super_0_data.end_out_bound_num;
    /* L30_FieldNo05 */ view::message_field::enumerate::SystemType_VIEW m_system_type = view::message_field::enumerate::SystemType_VIEW(m_super_0_data.system_type);
    /* L30_FieldNo06 */ view::message_field::enumerate::EncryptMethod_VIEW m_encrypt_method = view::message_field::enumerate::EncryptMethod_VIEW(m_super_0_data.EncryptMethod);
    /* L30_FieldNo07 */ view::message_field::uint08_VIEW m_check_sum = m_super_0_data.CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L40
#define LXX L40
struct xplum_sdkit::taifex_msg_proto::view::message::_nshdr::LXX : ViewerMsgFixSize<model::LXX>, PlugerMsg_Common<LXX>, PlugerMsg_SP_L40<LXX>
{
    MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(LXX);
    /* L40_FieldNo01 */ view::message_field::MsgHdr_VIEW m_hdr = view::message_field::MsgHdr_VIEW(m_super_0_data.hdr);
    /* L40_FieldNo02 */ view::message_field::uint08_VIEW m_status_code = m_super_0_data.status_code;
    /* L40_FieldNo03 */ view::message_field::uint16_VIEW m_append_no = m_super_0_data.append_no;
    /* L40_FieldNo04 */ view::message_field::uint16_VIEW m_fcm_id = m_super_0_data.fcm_id;
    /* L40_FieldNo05 */ view::message_field::uint16_VIEW m_session_id = m_super_0_data.session_id;
    /* L40_FieldNo06 */ view::message_field::enumerate::SystemType_VIEW m_system_type = view::message_field::enumerate::SystemType_VIEW(m_super_0_data.system_type);
    /* L40_FieldNo07 */ view::message_field::uint08_VIEW m_ap_code = m_super_0_data.ap_code;
    /* L40_FieldNo08 */ view::message_field::uint08_VIEW m_key_value = m_super_0_data.key_value;
    /* L40_FieldNo09 */ view::message_field::uint32_VIEW m_request_start_seq = m_super_0_data.request_start_seq;
    /* L40_FieldNo10 */ view::message_field::uint08_VIEW m_cancel_order_sec = m_super_0_data.cancel_order_sec;
    /* L40_FieldNo11 */ view::message_field::uint08_VIEW m_check_sum = m_super_0_data.CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L42
#define LXX L42
struct xplum_sdkit::taifex_msg_proto::view::message::_nshdr::LXX : ViewerMsgFixSize<model::LXX>, PlugerMsg_Common<LXX>
{
    MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(LXX);
    /* L42_FieldNo01 */ view::message_field::MsgHdr_VIEW m_hdr = view::message_field::MsgHdr_VIEW(m_super_0_data.hdr);
    /* L42_FieldNo02 */ view::message_field::uint08_VIEW m_status_code = m_super_0_data.status_code;
    /* L42_FieldNo03 */ view::message_field::uint08_VIEW m_check_sum = m_super_0_data.CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L50
#define LXX L50
struct xplum_sdkit::taifex_msg_proto::view::message::_nshdr::LXX : ViewerMsgFixSize<model::LXX>, PlugerMsg_Common<LXX>
{
    MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(LXX);
    /* L50_FieldNo01 */ view::message_field::MsgHdr_VIEW m_hdr = view::message_field::MsgHdr_VIEW(m_super_0_data.hdr);
    /* L50_FieldNo02 */ view::message_field::uint08_VIEW m_status_code = m_super_0_data.status_code;
    /* L50_FieldNo03 */ view::message_field::uint08_VIEW m_heart_bt_int = m_super_0_data.HeartBtInt;
    /* L50_FieldNo04 */ view::message_field::uint16_VIEW m_max_flow_ctrl_cnt = m_super_0_data.max_flow_ctrl_cnt;
    /* L50_FieldNo05 */ view::message_field::uint08_VIEW m_check_sum = m_super_0_data.CheckSum;
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L60
#define LXX L60
struct xplum_sdkit::taifex_msg_proto::view::message::_nshdr::LXX : ViewerMsgFixSize<model::LXX>, PlugerMsg_Common<LXX>
{
    MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(LXX);
    /* L60_FieldNo01 */ view::message_field::MsgHdr_VIEW m_hdr = view::message_field::MsgHdr_VIEW(m_super_0_data.hdr);
    /* L60_FieldNo02 */ view::message_field::uint08_VIEW m_status_code = m_super_0_data.status_code;
    /* L60_FieldNo03 */ view::message_field::uint08_VIEW m_check_sum = m_super_0_data.CheckSum;
};
#undef LXX

///
///
#if (defined(LXX) || defined(RXX))
#error
#error // RXX should undef here.
#error // LXX should undef here.
#endif
