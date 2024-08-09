#pragma once
#include "./MsgViewPatchSpL40.h"
#pragma

#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_lxx_layer.h"

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign
{
template <typename TYPE_MSG_VIEW01>
concept MsgViewPatchSpL40_Concept = //
    requires (TYPE_MSG_VIEW01 * thiz)
{ //
  requires (std::is_same_v<view::message::L40, TYPE_MSG_VIEW01>);
  requires (std::is_same_v<view::message_field::uint08, decltype (thiz->m_key_value)>);
  requires (std::is_same_v<view::message_field::uint16, decltype (thiz->m_append_no)>);
};

template <typename> class MsgViewPatchSpL40;
}

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element
{
template <typename TYPE_MSG_VIEW01, typename TYPE_MSG_VIEW02_PANEL>
using MsgViewPatchSpL40 = std::conditional<_nsign::MsgViewPatchSpL40_Concept<TYPE_MSG_VIEW01>, _nsign::MsgViewPatchSpL40<TYPE_MSG_VIEW02_PANEL>, typename _nsign::MsgViewPatchSpL40<TYPE_MSG_VIEW02_PANEL>::ClassMock>::type;
}

template <typename TYPE_MSG_VIEW02_PANEL>                               //
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchSpL40                                                   //
    : public xplum::ancestor::PluginerWay02<MsgViewPatchSpL40<TYPE_MSG_VIEW02_PANEL>, TYPE_MSG_VIEW02_PANEL>
{
public:
  auto fx_assign_m_key_value_0_algorithm [[nodiscard]] (type::uint16, type::uint16) -> bool; // session_passwd, append_no, -> is_ok
};
