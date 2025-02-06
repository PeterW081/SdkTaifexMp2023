#pragma once
#include "./PlugerMsg_SP_L40.h"
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L06/function_msg.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg/msg_lxx_layer.h"
#

/// PlugerMsg_SP_L40
template <typename TYPE_msg_view>
/*Constructor*/                                       //
xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_SP_L40<TYPE_msg_view>::                 //
    PlugerMsg_SP_L40()
{
    using MsgL40_DATA = xplum_model::taifex_msg_proto::message::L40;
    static_assert(                      //
        requires(TYPE_msg_view *thiz) { //
            requires(std::is_same_v<MsgL40_DATA, typename TYPE_msg_view::TypeMsgData>);
            requires(std::is_same_v<view::message_field::uint08_VIEW, decltype(thiz->m_key_value)>);
            requires(std::is_same_v<view::message_field::uint16_VIEW, decltype(thiz->m_append_no)>);
        });
}

/// PlugerMsg_SP_L40 - fx_assign_m_key_value_0_algorithm()
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_SP_L40<TYPE_msg_view>::                     //
    fx_assign_m_key_value_0_algorithm(type::uint16 session_passwd, type::uint16 append_no) -> bool
{
    namespace nsfunc_algorithm = xplum_model::taifex_msg_proto::msg_algorithm;
    bool is_ok = true;
    if (this->thiz->m_append_no != append_no)
    {
        is_ok = false;
    }
    this->thiz->m_append_no = append_no;
    this->thiz->m_key_value = nsfunc_algorithm::FX_msg_L40_key_value(session_passwd, append_no);
    return is_ok;
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_SP_L40<TYPE_msg_view>::                     //
    fx_assert_m_key_value(type::uint16 session_passwd, type::uint16 append_no) const -> bool
{
    namespace nsfunc_algorithm = xplum_model::taifex_msg_proto::msg_algorithm;
    return this->thiz->m_append_no == append_no //
           && this->thiz->m_key_value == nsfunc_algorithm::FX_msg_L40_key_value(session_passwd, append_no);
}
