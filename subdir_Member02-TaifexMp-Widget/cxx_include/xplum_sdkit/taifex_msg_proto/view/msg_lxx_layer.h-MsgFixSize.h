#pragma once
#include "XPLUM_SDKIT_MACRO/MACRO_INITIALIZATION_OVERLOAD.h"
#include "xplum_model/taifex_msg_proto/structure_message/msg_lxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/ViewerMsg.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_field_enumerate.h"

namespace xplum_sdkit::taifex_msg_proto::view::message::_nshdr {
namespace mt_sizeof_msg_content = xplum_model::taifex_msg_proto::mt_sizeof_msg_content;
using xplum_sdkit::taifex_msg_proto::ancestor::ViewerMsgFixSize;
}

namespace xplum_sdkit::taifex_msg_proto::view::message {
namespace origin = xplum_model::taifex_msg_proto::message;

// LxxLayer - MsgFixSize
class L10;
class L20;
class L30;
class L40;
class L42;
class L50;
class L60;
}

/// xplum::taifex_msg_proto_sdk::view::message::L10
#define LXX L10
class xplum_sdkit::taifex_msg_proto::view::message::LXX : public _nshdr::ViewerMsgFixSize<origin::LXX> {
public:
  MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
  /* L10_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
  /* L10_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
  /* L10_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.start_in_bound_num, m_start_in_bound_num);
  /* L10_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L20
#define LXX L20
class xplum_sdkit::taifex_msg_proto::view::message::LXX : public _nshdr::ViewerMsgFixSize<origin::LXX> {
public:
  MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
  /* L20_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
  /* L20_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
  /* L20_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L30
#define LXX L30
class xplum_sdkit::taifex_msg_proto::view::message::LXX : public _nshdr::ViewerMsgFixSize<origin::LXX> {
public:
  MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
  /* L30_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
  /* L30_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
  /* L30_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.append_no, m_append_no);
  /* L30_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.end_out_bound_num, m_end_out_bound_num);
  /* L30_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.system_type, m_system_type, message_field::enumerate::SystemType);
  /* L30_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.EncryptMethod, m_encrypt_method, message_field::enumerate::EncryptMethod);
  /* L30_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L40
#define LXX L40
class xplum_sdkit::taifex_msg_proto::view::message::LXX : public _nshdr::ViewerMsgFixSize<origin::LXX> {
public:
  MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
  /* L40_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
  /* L40_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
  /* L40_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.append_no, m_append_no);
  /* L40_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.fcm_id, m_fcm_id);
  /* L40_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.session_id, m_session_id);
  /* L40_FieldNo06 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.system_type, m_system_type, message_field::enumerate::SystemType);
  /* L40_FieldNo07 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.ap_code, m_ap_code);
  /* L40_FieldNo08 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.key_value, m_key_value);
  /* L40_FieldNo09 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.request_start_seq, m_request_start_seq);
  /* L40_FieldNo10 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.cancel_order_sec, m_cancel_order_sec);
  /* L40_FieldNo11 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L42
#define LXX L42
class xplum_sdkit::taifex_msg_proto::view::message::LXX : public _nshdr::ViewerMsgFixSize<origin::LXX> {
public:
  MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
  /* L42_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
  /* L42_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
  /* L42_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L50
#define LXX L50
class xplum_sdkit::taifex_msg_proto::view::message::LXX : public _nshdr::ViewerMsgFixSize<origin::LXX> {
public:
  MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
  /* L50_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
  /* L50_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
  /* L50_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.HeartBtInt, m_heart_bt_int);
  /* L50_FieldNo04 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.max_flow_ctrl_cnt, m_max_flow_ctrl_cnt);
  /* L50_FieldNo05 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef LXX

/// xplum::taifex_msg_proto_sdk::view::message::L60
#define LXX L60
class xplum_sdkit::taifex_msg_proto::view::message::LXX : public _nshdr::ViewerMsgFixSize<origin::LXX> {
public:
  MACRO_XPLUM_ANCESTOR_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(LXX);
  /* L60_FieldNo01 */ MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(m_super_0_data.hdr, m_hdr, message_field::MsgHdr);
  /* L60_FieldNo02 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.status_code, m_status_code);
  /* L60_FieldNo03 */ MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(m_super_0_data.CheckSum, m_check_sum);
};
#undef LXX

///
///
#if (defined(LXX) || defined(RXX))
#error
#error // RXX should undef here.
#error // LXX should undef here.
#endif
