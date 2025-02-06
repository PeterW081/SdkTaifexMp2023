#pragma once
#include "./ViewerMsg.h"
#pragma
#include <span>
#include "xplum/ancestor/Viewer.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/constant_msg.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#

namespace xplum_sdkit::taifex_msg_proto::ancestor::_nshdr
{
namespace mt_sizeof_msg_content = xplum_model::taifex_msg_proto::msg_sizeof_content;
using xplum::ancestor::Viewer;
}

namespace xplum_sdkit::taifex_msg_proto::ancestor
{
//
template <typename TYPE_msg, type::TypeMsgLength VALUE_min_of_msg_length>
class ViewerMsg;
//
template <typename TYPE_msg>
using ViewerMsgFixSize = ViewerMsg<TYPE_msg, sizeof(TYPE_msg) - _nshdr::mt_sizeof_msg_content::G_size_out_of_msg_length>;
}

template <typename TYPE_msg_data, xplum_sdkit::taifex_msg_proto::type::TypeMsgLength VALUE_min_of_msg_length>
class                                         //
    xplum_sdkit::taifex_msg_proto::ancestor:: //
    ViewerMsg : public _nshdr::Viewer<TYPE_msg_data>
{
  public:
    using TypeMsgData = TYPE_msg_data;
    auto fx_span() const -> std::span<std::byte>;

  protected:
    //
    static inline const std::size_t M_msg_data_size = sizeof(TYPE_msg_data);
    static inline const std::size_t M_msg_data_size_max_value = _nshdr::mt_sizeof_msg_content::G_value_max_of_msg_length + _nshdr::mt_sizeof_msg_content::G_size_out_of_msg_length;
    static inline const type::TypeMsgLength M_msg_length_max_value = _nshdr::mt_sizeof_msg_content::G_value_max_of_msg_length;
    static inline const type::TypeMsgLength M_msg_length_min_value = VALUE_min_of_msg_length;
    const std::optional<type::TypeMsgLength> M_msg_length_0_special;
    //
    static auto FX_init_msg(std::span<std::byte>, std::optional<type::TypeMsgLength>) -> void; // buffer, msg_length_0_special,
    explicit ViewerMsg(TypeMsgData &, std::optional<type::TypeMsgLength>);                     // data,   msg_length_0_special,
    explicit ViewerMsg(std::span<std::byte>, std::optional<type::TypeMsgLength>);              // buffer, msg_length_0_special,

  private:
    static_assert(M_msg_length_min_value <= M_msg_length_max_value);
};
