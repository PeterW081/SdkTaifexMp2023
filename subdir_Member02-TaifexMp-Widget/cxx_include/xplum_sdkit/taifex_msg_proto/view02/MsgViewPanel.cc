#pragma once
#include "./MsgViewPanel.h"
#pragma

#include "xplum_sdkit/taifex_msg_proto/view02/MsgViewPatchCommon.h"
#include "xplum_sdkit/taifex_msg_proto/view02/MsgViewPatchReOrderNo.h"
#include "xplum_sdkit/taifex_msg_proto/view02/MsgViewPatchSpL40.h"
#include "xplum_sdkit/taifex_msg_proto/view02/MsgViewPatchSpL41.h"

// clang-format off
#define MACRO_XPLUM_VIEW02_MSGVIEWPANEL_DEPLOY_ALIASCLASS_0OVERLOAD(PARAM01_ALIASCLASS_NAME) /**/ using PARAM01_ALIASCLASS_NAME = view02::msg_view_element::MsgViewPanel<view::message::PARAM01_ALIASCLASS_NAME>
// clang-format on

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element
{
template <typename>
class MsgViewPanel;
}

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::MsgViewPanel;
//
template <typename TYPE_MSG_VIEW01>
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::MsgViewPanel : public TYPE_MSG_VIEW01,
                                                                              public MsgViewPatchCommon</*   */ TYPE_MSG_VIEW01, MsgViewPanel<TYPE_MSG_VIEW01>>,
                                                                              public MsgViewPatchReOrderNo</**/ TYPE_MSG_VIEW01, MsgViewPanel<TYPE_MSG_VIEW01>>,
                                                                              public MsgViewPatchSpL40</*    */ TYPE_MSG_VIEW01, MsgViewPanel<TYPE_MSG_VIEW01>>,
                                                                              public MsgViewPatchSpL41</*    */ TYPE_MSG_VIEW01, MsgViewPanel<TYPE_MSG_VIEW01>>
{
  public:
    explicit MsgViewPanel(TYPE_MSG_VIEW01::TYPE_MsgOrigin &data) : TYPE_MSG_VIEW01(data){};
    explicit MsgViewPanel(std::span<std::byte> buffer) : TYPE_MSG_VIEW01(buffer){};

    template <std::size_t VAL_BUFFER_SIZE>
    static auto FX_ASSIGN_MSG(std::span<std::byte, VAL_BUFFER_SIZE>) -> MsgViewPanel<TYPE_MSG_VIEW01>; // buffer

    template <std::size_t VAL_BUFFER_SIZE>
        requires std::derived_from<TYPE_MSG_VIEW01, ancestor::ViewerMsgZipSize<typename TYPE_MSG_VIEW01::T, TYPE_MSG_VIEW01::M_MSG_LENGTH_MAX_VALUE, TYPE_MSG_VIEW01::M_MSG_LENGTH_MIN_VALUE>>
    static auto FX_ASSIGN_MSG(std::span<std::byte, VAL_BUFFER_SIZE>, type::TypeMsgLength) -> MsgViewPanel<TYPE_MSG_VIEW01>; // buffer, msg_length,
};
