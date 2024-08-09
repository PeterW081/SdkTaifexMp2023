#pragma once
#include <cstddef>

namespace xplum_model::taifex_msg_proto::message_field::sizeof_array
{
struct Order;
struct Symbol;
struct LongSymbol;
struct R02MsgField;
}

struct xplum_model::taifex_msg_proto::message_field::sizeof_array::Order
{
  static const std::size_t M_SIZEOF_ARR_0_ORDER_NO = 5;    // char0
  static const std::size_t M_SIZEOF_ARR_0_USER_DEFINE = 8; // char0
  static const std::size_t M_SIZEOF_ARR_0_INFO_SOURCE = 3; // char0
};

struct xplum_model::taifex_msg_proto::message_field::sizeof_array::Symbol
{
  static const std::size_t M_SIZEOF_ARR_0_NUM_LEG_SIDE = 2; // uint8
  static const std::size_t M_SIZEOF_ARR_0_NUM_FILLER = 13;  // uint8
  static const std::size_t M_SIZEOF_ARR_0_TEXT_SYMBOL = 20; // char0
};

struct xplum_model::taifex_msg_proto::message_field::sizeof_array::LongSymbol
{
  static const std::size_t M_SIZEOF_ARR_0_NUM_LEG_SIDE = 2; // uint8
  static const std::size_t M_SIZEOF_ARR_0_NUM_FILLER = 33;  // uint8
  static const std::size_t M_SIZEOF_ARR_0_TEXT_SYMBOL = 40; // char0
};

struct xplum_model::taifex_msg_proto::message_field::sizeof_array::R02MsgField
{
  static const std::size_t M_SIZEOF_ARR_0_LEG_SIDE = 2; // uint8
  static const std::size_t M_SIZEOF_ARR_0_LEG_PX = 2;   // int32
  static const std::size_t M_SIZEOF_ARR_0_LEG_QTY = 2;  // uint16
};
