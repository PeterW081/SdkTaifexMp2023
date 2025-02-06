#pragma once
#include "./msg_all_layer.h"
#pragma
#

///
#define nshdr_root xplum_sdkit::taifex_msg_proto
#define MACRO_XPLUM_DEFINE_FUNC(PARAM01_MSG_TYPE)                                                                                                                                                                                                              \
    template <>                                                                                                                                                                                                                                                \
    inline auto nshdr_root::view::FX_load_msg_on_span<nshdr_root::enumerate::EnumMsgType::PARAM01_MSG_TYPE>(std::span<std::byte> data) -> auto                                                                                                                 \
    {                                                                                                                                                                                                                                                          \
        return view::message::_nshdr::PARAM01_MSG_TYPE(data);                                                                                                                                                                                                  \
    };                                                                                                                                                                                                                                                         \
    template <>                                                                                                                                                                                                                                                \
    inline auto nshdr_root::view::FX_init_msg_to_span<nshdr_root::enumerate::EnumMsgType::PARAM01_MSG_TYPE>(std::span<std::byte> data) -> auto                                                                                                                 \
    {                                                                                                                                                                                                                                                          \
        return view::message::_nshdr::PARAM01_MSG_TYPE::FX_init_msg(data);                                                                                                                                                                                     \
    }
#

/// FX_load_msg_on_span(), FX_init_msg_to_span(),
MACRO_XPLUM_DEFINE_FUNC(L10);
MACRO_XPLUM_DEFINE_FUNC(L20);
MACRO_XPLUM_DEFINE_FUNC(L30);
MACRO_XPLUM_DEFINE_FUNC(L40);
MACRO_XPLUM_DEFINE_FUNC(L42);
MACRO_XPLUM_DEFINE_FUNC(L50);
MACRO_XPLUM_DEFINE_FUNC(L60);
MACRO_XPLUM_DEFINE_FUNC(R01);
MACRO_XPLUM_DEFINE_FUNC(R02);
MACRO_XPLUM_DEFINE_FUNC(R03);
MACRO_XPLUM_DEFINE_FUNC(R04);
MACRO_XPLUM_DEFINE_FUNC(R05);

/// FX_load_msg_on_span(), FX_init_msg_to_span(), - L41
template <>
inline auto            //
    nshdr_root::view:: //
    FX_load_msg_on_span<nshdr_root::enumerate::EnumMsgType::L41>(std::span<std::byte> data) -> auto
{
    return view::message::MsgL41_VIEW(data, ez_view::FX_get_msg_length_from_msg_data(data.data()));
};
template <>                    //
inline auto nshdr_root::view:: //
    FX_init_msg_to_span<nshdr_root::enumerate::EnumMsgType::L41>(std::span<std::byte> data, type::TypeMsgLength msg_length) -> auto
{
    return view::message::MsgL41_VIEW::FX_init_msg(data, msg_length);
}

///
#
#undef nshdr_root
#undef MACRO_XPLUM_DEFINE_FUNC
