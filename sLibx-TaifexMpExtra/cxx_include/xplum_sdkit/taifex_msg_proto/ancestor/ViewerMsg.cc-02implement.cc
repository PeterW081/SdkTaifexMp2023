#pragma once
#include "./ViewerMsg.h"
#pragma
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/function_msg.h"
#

/// ViewerMsg - static
template <typename TYPE_msg_data, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VALUE_min_of_msg_length>
auto                                                    //
    xplum_sdkit::taifex_msg_proto::ancestor::           //
    ViewerMsg<TYPE_msg_data, VALUE_min_of_msg_length>:: //
    FX_init_msg(std::span<std::byte> buffer, std::optional<type::TypeMsgLength> msg_length_0_special) -> void
{
    auto msg_length = msg_length_0_special.value_or(sizeof(TYPE_msg_data) - _nshdr::mt_sizeof_msg_content::G_size_out_of_msg_length);
    assert(M_msg_data_size_max_value <= buffer.size());
    assert(M_msg_length_max_value >= msg_length);
    assert(M_msg_length_min_value <= msg_length);
    *reinterpret_cast<TYPE_msg_data *>(buffer.data()) = TYPE_msg_data();
    ez_view::FX_get_msg_length_from_msg_data(buffer.data()) = msg_length;
}

/// ViewerMsg
template <typename TYPE_msg_data, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VALUE_min_of_msg_length>
/*Constructor*/ xplum_sdkit::taifex_msg_proto::ancestor:: //
    ViewerMsg<TYPE_msg_data, VALUE_min_of_msg_length>::   //
    ViewerMsg(TYPE_msg_data &data, std::optional<type::TypeMsgLength> msg_length_0_special)
    : _nshdr::Viewer<TYPE_msg_data>(data), M_msg_length_0_special(msg_length_0_special)
{
    using THIS = std::remove_pointer_t<decltype(this)>;
    if (msg_length_0_special.has_value())
    {
        assert(not msg_length_0_special.has_value() || msg_length_0_special.value() <= THIS::M_msg_length_max_value);
        assert(not msg_length_0_special.has_value() || msg_length_0_special.value() >= THIS::M_msg_length_min_value);
    }
}
template <typename TYPE_msg_data, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VALUE_min_of_msg_length>
/*Constructor*/ xplum_sdkit::taifex_msg_proto::ancestor::                                           //
    ViewerMsg<TYPE_msg_data, VALUE_min_of_msg_length>::                                             //
    ViewerMsg(std::span<std::byte> buffer, std::optional<type::TypeMsgLength> msg_length_0_special) //
    : _nshdr::Viewer<TYPE_msg_data>(*reinterpret_cast<TYPE_msg_data *>(buffer.data())), M_msg_length_0_special(msg_length_0_special)
{
    using THIS = std::remove_pointer_t<decltype(this)>;
    if (msg_length_0_special.has_value())
    {
        assert(buffer.size() >= THIS::M_msg_data_size_max_value);
        assert(buffer.size() >= msg_length_0_special.value() + _nshdr::mt_sizeof_msg_content::G_size_out_of_msg_length);
        assert(msg_length_0_special.value() <= THIS::M_msg_length_max_value);
        assert(msg_length_0_special.value() >= THIS::M_msg_length_min_value);
    }
    else
    {
        assert(buffer.size() >= sizeof(TYPE_msg_data));
    }
}
template <typename TYPE_msg_data, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VALUE_min_of_msg_length>
auto                                                    //
    xplum_sdkit::taifex_msg_proto::ancestor::           //
    ViewerMsg<TYPE_msg_data, VALUE_min_of_msg_length>:: //
    fx_span() const -> std::span<std::byte>             //
{
    auto span = std::span<std::byte>();
    if (not this->M_msg_length_0_special.has_value())
    {
        span = std::span<std::byte>(reinterpret_cast<std::byte *>(&this->m_super_0_data), sizeof(TYPE_msg_data));
    }
    else
    {
        span = std::span<std::byte>(reinterpret_cast<std::byte *>(&this->m_super_0_data), this->M_msg_length_0_special.value() + _nshdr::mt_sizeof_msg_content::G_size_out_of_msg_length);
    }
    return span;
}
