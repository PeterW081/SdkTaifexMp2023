#pragma once
#include <list>
#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_lxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_sp_L41.h"

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign {
template <typename TYPE_MSG_VIEW01>
concept MsgViewPatchSpL41_Concept =   //
    requires(TYPE_MSG_VIEW01 *thiz) { //
      requires(std::is_same_v<view::message::L41, TYPE_MSG_VIEW01>);
      requires(std::is_same_v<view::message_field::uint32, decltype(thiz->m_file_size)>);
      requires(std::is_same_v<std::span<view::message_field::origin::uint8>, decltype(thiz->m_data)>);
    };

template <typename> class MsgViewPatchSpL41;
}

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element {
template <typename TYPE_MSG_VIEW01, typename TYPE_MSG_VIEW02_PANEL>
using MsgViewPatchSpL41 = std::conditional<_nsign::MsgViewPatchSpL41_Concept<TYPE_MSG_VIEW01>, _nsign::MsgViewPatchSpL41<TYPE_MSG_VIEW02_PANEL>, typename _nsign::MsgViewPatchSpL41<TYPE_MSG_VIEW02_PANEL>::ClassMock>::type;
}

template <typename TYPE_MSG_VIEW02_PANEL>
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchSpL41                                                   //
    : public xplum::ancestor::PluginerWay02<MsgViewPatchSpL41<TYPE_MSG_VIEW02_PANEL>, TYPE_MSG_VIEW02_PANEL> {
public:
  // fx_virgin_m_data();
  auto fx_virgin_m_data() -> std::list<kitbag::UnionL41DataMember>;
};
