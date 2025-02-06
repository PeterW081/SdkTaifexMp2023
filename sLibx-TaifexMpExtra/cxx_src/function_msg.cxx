#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/function_msg.h"
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L06/constant_msg.h"
#

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::ez_view;
namespace nscxx
{
namespace mt_sizeof_msg_content = xplum_model::taifex_msg_proto::msg_sizeof_content;
}

///
extern auto      //
    nscxx_root:: //
    FX_get_msg_length_from_msg_data(void *data) -> view::message_field::uint16_VIEW
{
    static_assert(std::is_same_v<xplum_model::taifex_msg_proto::message_field::uint16, decltype(xplum_model::taifex_msg_proto::message_field::hdr::msg_length)>);
    return *(reinterpret_cast<xplum_model::taifex_msg_proto::message_field::uint16 *>(reinterpret_cast<std::byte *>(data) + nscxx::mt_sizeof_msg_content::G_offsetof_msg_length));
}
extern auto      //
    nscxx_root:: //
    FX_get_symbol_text(view::message_field::SymbolX_VIEW &symbol_x) -> decltype(view::message_field::SymbolText_VIEW::m_symbol)
{
    return std::get<view::message_field::SymbolText_VIEW>(symbol_x).m_symbol;
}
extern auto      //
    nscxx_root:: //
    FX_get_msg_type_from_msg_data(void *data) -> view::message_field::enumerate::MsgType_VIEW
{
    return view::message_field::enumerate::MsgType_VIEW( //
        *reinterpret_cast<view::message_field::enumerate::MsgType_VIEW::IntegerType *>(reinterpret_cast<std::byte *>(data) + nscxx::mt_sizeof_msg_content::G_offsetof_msg_type));
}
