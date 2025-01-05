#include "xplum_sdkit/taifex_msg_proto/static_function_msg.h"
#pragma

#include "xplum_model/taifex_msg_proto/network_osi_L06/constant_msg.h"

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::ez_view;
namespace nscxx
{
namespace mt_sizeof_msg_content = xplum_model::taifex_msg_proto::msg_sizeof_content;
}

extern auto      //
    nscxx_root:: //
    FX_GET_MSG_LENGTH_IN_ORIGIN_MSG(void *data) -> view::message_field::uint16
{
    static_assert(std::is_same_v<xplum_model::taifex_msg_proto::message_field::uint16, decltype(xplum_model::taifex_msg_proto::message_field::hdr::msg_length)>);
    return *(reinterpret_cast<xplum_model::taifex_msg_proto::message_field::uint16 *>(reinterpret_cast<std::byte *>(data) + nscxx::mt_sizeof_msg_content::G_offsetof_msg_length));
}

extern auto      //
    nscxx_root:: //
    FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(void const *data) -> view::message_field::origin::uint16 const &
{
    static_assert(std::is_same_v<xplum_model::taifex_msg_proto::message_field::uint16, decltype(xplum_model::taifex_msg_proto::message_field::hdr::msg_length)>);
    return *(reinterpret_cast<xplum_model::taifex_msg_proto::message_field::uint16 const *>(reinterpret_cast<std::byte const *>(data) + nscxx::mt_sizeof_msg_content::G_offsetof_msg_length));
}

extern auto      //
    nscxx_root:: //
    FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD(view::message_field::SymbolX &symbol_x) -> decltype(view::message_field::SymbolText::m_symbol)
{
    return std::get<view::message_field::SymbolText>(symbol_x).m_symbol;
}

extern auto      //
    nscxx_root:: //
    FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(void *data) -> const view::message_field::enumerate::MsgType
{
    return view::message_field::enumerate::MsgType( //
        *reinterpret_cast<view::message_field::enumerate::MsgType::IntegerType *>(reinterpret_cast<std::byte *>(data) + nscxx::mt_sizeof_msg_content::G_offsetof_msg_type));
}
