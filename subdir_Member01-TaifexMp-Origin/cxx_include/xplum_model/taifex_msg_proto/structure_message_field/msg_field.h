#pragma once
#include "boost0/big_endian_integer.h"
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field_sizeof_array.h"

namespace xplum_model::taifex_msg_proto::message_field
{
// using
using char0 = char;
using int8 = ext::boost0::big_endian_int08;
using int16 = ext::boost0::big_endian_int16;
using int32 = ext::boost0::big_endian_int32;
using int64 = ext::boost0::big_endian_int64;
using uint8 = ext::boost0::big_endian_uint08;
using uint16 = ext::boost0::big_endian_uint16;
using uint32 = ext::boost0::big_endian_uint32;

// struct
struct hdr;
struct msg_time;
struct symbol_num;
struct symbol_text;
struct long_symbol_num;
struct long_symbol_text;

// struct - union
union symbol_x;
union long_symbol_x;

}

struct xplum_model::taifex_msg_proto::message_field::msg_time
{
  /* FieldXX_FieldNo01 */ int32 epoch_s;
  /* FieldXX_FieldNo02 */ uint16 ms;
};

struct xplum_model::taifex_msg_proto::message_field::hdr
{
  /* FieldXX_FieldNo01 */ uint16 msg_length;
  /* FieldXX_FieldNo02 */ uint32 MsgSeqNum;
  /* FieldXX_FieldNo03 */ msg_time msg_time;
  /* FieldXX_FieldNo04 */ uint8 MessageType;
  /* FieldXX_FieldNo05 */ uint16 fcm_id;
  /* FieldXX_FieldNo06 */ uint16 session_id;
};

struct xplum_model::taifex_msg_proto::message_field::symbol_num
{
  /* FieldXX_FieldNo01 */ uint16 pseq1;
  /* FieldXX_FieldNo02 */ uint16 pseq2;
  /* FieldXX_FieldNo03 */ uint8 leg_side[sizeof_array::Symbol::M_SIZEOF_ARR_0_NUM_LEG_SIDE];
  /* FieldXX_FieldNo04 */ uint8 comb_op;
  /* FieldXX_FieldNo05 */ uint8 filler[sizeof_array::Symbol::M_SIZEOF_ARR_0_NUM_FILLER];
};

struct xplum_model::taifex_msg_proto::message_field::symbol_text
{
  /* FieldXX_FieldNo01 */ char0 symbol[sizeof_array::Symbol::M_SIZEOF_ARR_0_TEXT_SYMBOL];
};

struct xplum_model::taifex_msg_proto::message_field::long_symbol_num
{
  /* FieldXX_FieldNo01 */ uint16 pseq1;
  /* FieldXX_FieldNo02 */ uint16 pseq2;
  /* FieldXX_FieldNo03 */ uint8 leg_side[sizeof_array::LongSymbol::M_SIZEOF_ARR_0_NUM_LEG_SIDE];
  /* FieldXX_FieldNo04 */ uint8 comb_op;
  /* FieldXX_FieldNo05 */ uint8 filler[sizeof_array::LongSymbol::M_SIZEOF_ARR_0_NUM_FILLER];
};

struct xplum_model::taifex_msg_proto::message_field::long_symbol_text
{
  /* FieldXX_FieldNo01 */ char0 symbol[sizeof_array::LongSymbol::M_SIZEOF_ARR_0_TEXT_SYMBOL];
};

union xplum_model::taifex_msg_proto::message_field::symbol_x
{
  symbol_num num;
  symbol_text text;
};

union xplum_model::taifex_msg_proto::message_field::long_symbol_x
{
  long_symbol_num num;
  long_symbol_text text;
};
