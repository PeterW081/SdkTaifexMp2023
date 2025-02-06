#pragma once
#include "./PlugerMsg_SP_L41.h"
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg/msg_lxx_layer.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg/msg_rxx_layer.h"
#

/// PlugerMsg_SP_L41
template <typename TYPE_msg_view>
/*Constructor*/                                       //
xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_SP_L41<TYPE_msg_view>::                 //
    PlugerMsg_SP_L41()
{
    using MsgL41_DATA = xplum_model::taifex_msg_proto::message::L41<>;
    static_assert(                      //
        requires(TYPE_msg_view *thiz) { //
            requires(std::is_same_v<MsgL41_DATA, typename TYPE_msg_view::TypeMsgData>);
            requires(std::is_same_v<view::message_field::uint32_VIEW, decltype(thiz->m_file_size)>);
            requires(std::is_same_v<std::span<view::message_field::model::uint8>, decltype(thiz->m_data)>);
        });
}

/// PlugerMsg_SP_L41 - fx_virgin_m_data()
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_SP_L41<TYPE_msg_view>::                     //
    fx_virgin_m_data() -> std::list<util::UnionL41DataMember>
{
    namespace nsfunc_msg_sizeof_content = xplum_model::taifex_msg_proto::msg_sizeof_content;
    using MsgR02_DATA = xplum_model::taifex_msg_proto::message::R02;
    using MsgR03_DATA = xplum_model::taifex_msg_proto::message::R03;

    auto result = std::list<util::UnionL41DataMember>();
    auto const L41_data_size = this->thiz->m_file_size;
    auto const L41_data_data = this->thiz->m_data.data();
    for (std::intptr_t i = 0, j = L41_data_size; i < j;)
    {
        void *message = L41_data_data + i;
        auto message_head = view::message_field::MsgHdr_VIEW(message);
        i += static_cast<std::intptr_t>(nsfunc_msg_sizeof_content::G_size_out_of_msg_length) + message_head.m_msg_length;
        switch (message_head.m_message_type.enum_value())
        {
        case view::message_field::enumerate::MsgType_VIEW::EnumType::R02:
            result.emplace_back(reinterpret_cast<MsgR02_DATA *>(message));
            break;
        case view::message_field::enumerate::MsgType_VIEW::EnumType::R03:
            result.emplace_back(reinterpret_cast<MsgR03_DATA *>(message));
            break;
        default:
            result.emplace_back() = std::span<const std::byte>(reinterpret_cast<const std::byte *>(message), nsfunc_msg_sizeof_content::G_size_out_of_msg_length + message_head.m_msg_length);
            break;
        }
    }
    return result;
}
