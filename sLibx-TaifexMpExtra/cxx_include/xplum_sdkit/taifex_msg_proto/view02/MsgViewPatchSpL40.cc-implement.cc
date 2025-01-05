#pragma once
#include "./MsgViewPatchSpL40.h"
#pragma

#include "xplum_model/taifex_msg_proto/network_osi_L06/function_msg.h"

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchSpL40;
template <typename TYPE_MSG_VIEW02_PANEL>
auto xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchSpL40<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_key_value_0_algorithm(type::uint16 session_passwd, type::uint16 append_no) -> bool
{
    namespace ns0_origin_algorithm = xplum_model::taifex_msg_proto::msg_algorithm;
    bool is_ok = true;
    if (this->thiz->m_append_no != append_no)
    {
        is_ok = false;
    }
    this->thiz->m_append_no = append_no;
    this->thiz->m_key_value = ns0_origin_algorithm::FX_msg_L40_key_value(session_passwd, append_no);
    return is_ok;
}
