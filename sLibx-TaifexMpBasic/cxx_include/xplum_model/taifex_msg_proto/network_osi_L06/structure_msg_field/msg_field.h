#pragma once
#include <boost/endian/arithmetic.hpp>
#

namespace xplum_model::taifex_msg_proto::message_field
{
// using
using char0 = char;
using int8 = boost::endian::big_int8_t;
using int16 = boost::endian::big_int16_t;
using int32 = boost::endian::big_int32_t;
using int64 = boost::endian::big_int64_t;
using uint8 = boost::endian::big_uint8_t;
using uint16 = boost::endian::big_uint16_t;
using uint32 = boost::endian::big_uint32_t;

// using - array
template <std::size_t N>
using char0_arr = char[N];
template <std::size_t N>
using uint8_arr = boost::endian::big_uint8_t[N];
template <std::size_t N>
using uint16_arr = boost::endian::big_uint16_t[N];
template <std::size_t N>
using int32_arr = boost::endian::big_int32_t[N];

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
    /* FieldXX_FieldNo01 */ message_field::int32 epoch_s;
    /* FieldXX_FieldNo02 */ message_field::uint16 ms;
};

struct xplum_model::taifex_msg_proto::message_field::hdr
{
    /* FieldXX_FieldNo01 */ message_field::uint16 msg_length;
    /* FieldXX_FieldNo02 */ message_field::uint32 MsgSeqNum;
    /* FieldXX_FieldNo03 */ message_field::msg_time msg_time;
    /* FieldXX_FieldNo04 */ message_field::uint8 MessageType;
    /* FieldXX_FieldNo05 */ message_field::uint16 fcm_id;
    /* FieldXX_FieldNo06 */ message_field::uint16 session_id;
};

struct xplum_model::taifex_msg_proto::message_field::symbol_num
{
    /* FieldXX_FieldNo01 */ message_field::uint16 pseq1;
    /* FieldXX_FieldNo02 */ message_field::uint16 pseq2;
    /* FieldXX_FieldNo03 */ message_field::uint8_arr<2> leg_side;
    /* FieldXX_FieldNo04 */ message_field::uint8 comb_op;
    /* FieldXX_FieldNo05 */ message_field::uint8_arr<13> filler;
};

struct xplum_model::taifex_msg_proto::message_field::symbol_text
{
    /* FieldXX_FieldNo01 */ message_field::char0_arr<20> symbol;
};

struct xplum_model::taifex_msg_proto::message_field::long_symbol_num
{
    /* FieldXX_FieldNo01 */ message_field::uint16 pseq1;
    /* FieldXX_FieldNo02 */ message_field::uint16 pseq2;
    /* FieldXX_FieldNo03 */ message_field::uint8_arr<2> leg_side;
    /* FieldXX_FieldNo04 */ message_field::uint8 comb_op;
    /* FieldXX_FieldNo05 */ message_field::uint8_arr<33> filler;
};

struct xplum_model::taifex_msg_proto::message_field::long_symbol_text
{
    /* FieldXX_FieldNo01 */ message_field::char0_arr<40> symbol;
};

union xplum_model::taifex_msg_proto::message_field::symbol_x {
    message_field::symbol_num num;
    message_field::symbol_text text;
};

union xplum_model::taifex_msg_proto::message_field::long_symbol_x {
    message_field::long_symbol_num num;
    message_field::long_symbol_text text;
};
