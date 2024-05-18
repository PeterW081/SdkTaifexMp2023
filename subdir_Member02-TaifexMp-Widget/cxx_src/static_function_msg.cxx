#include "xplum_sdkit/taifex_msg_proto/static_function_msg.h"

#pragma
#include "xplum_model/taifex_msg_proto/static_constant.h"

#pragma
namespace nscxx_root = xplum_sdkit::taifex_msg_proto::ez_view;
namespace nscxx::origin {
namespace message_field = xplum_model::taifex_msg_proto::message_field;
namespace mt_sizeof_msg_content = xplum_model::taifex_msg_proto::mt_sizeof_msg_content;
}

auto nscxx_root::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG(void *data) -> xplum_model::taifex_msg_proto::message_field::uint16 & {
  static_assert(std::is_same_v<xplum_model::taifex_msg_proto::message_field::uint16, decltype(nscxx::origin::message_field::hdr::msg_length)>);
  return *(reinterpret_cast<nscxx::origin::message_field::uint16 *>(reinterpret_cast<std::byte *>(data) + nscxx::origin::mt_sizeof_msg_content::OFFSETOF_MSG_LENGTH));
}

auto nscxx_root::FX_GET_MSG_LENGTH_IN_ORIGIN_MSG_1CONST(void *data) -> const xplum_model::taifex_msg_proto::message_field::uint16 & {
  static_assert(std::is_same_v<xplum_model::taifex_msg_proto::message_field::uint16, decltype(nscxx::origin::message_field::hdr::msg_length)>);
  return FX_GET_MSG_LENGTH_IN_ORIGIN_MSG(data);
}

auto nscxx_root::FX_GET_SYMBOL_TEXT_IN_VIEW_MSG_FIELD(view::message_field::SymbolX &symbol_x) -> view::message_field::origin::char0 (&)[xplum_model::taifex_msg_proto::message_field::sizeof_array::Symbol::M_SIZEOF_ARR_0_TEXT_SYMBOL] {
  using xplum_model::taifex_msg_proto::message_field::char0;
  using SizeOfArraySymbol = xplum_model::taifex_msg_proto::message_field::sizeof_array::Symbol;
  return static_cast<char0(&)[SizeOfArraySymbol::Symbol::M_SIZEOF_ARR_0_TEXT_SYMBOL]>(std::get<view::message_field::SymbolText>(symbol_x).m_symbol);
}
auto nscxx_root::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(void *data) -> const view::message_field::enumerate::MsgType {
  return view::message_field::enumerate::MsgType( //
      *reinterpret_cast<view::message_field::enumerate::MsgType::IntegerType *>(reinterpret_cast<std::byte *>(data) + nscxx::origin::mt_sizeof_msg_content::OFFSETOF_MSG_TYPE));
}
