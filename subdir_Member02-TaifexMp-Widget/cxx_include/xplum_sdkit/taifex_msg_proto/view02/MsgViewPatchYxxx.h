#pragma once
#warning "this is template file."

#if (false) // WAY01 穩定版本。			- 1709068864#
#pragma once
namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign {
template <typename TYPE_MSG_VIEW01>
concept MsgViewPatchYxxx_Concept = //
    requires(TYPE_MSG_VIEW01 *thiz) { true; };

template <typename> class MsgViewPatchYxxx;
class MsgViewPatchYxxx_Mock;
}
namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element {
template <typename TYPE_MSG_VIEW01, typename TYPE_MSG_VIEW02_PANEL> using MsgViewPatchYxxx = std::conditional<_nsign::MsgViewPatchYxxx_Concept<TYPE_MSG_VIEW01>, _nsign::MsgViewPatchYxxx<TYPE_MSG_VIEW02_PANEL>, _nsign::MsgViewPatchYxxx_Mock>::type;
}
template <typename TYPE_MSG_VIEW02_PANEL>
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchYxxx                                                    //
{
  TYPE_MSG_VIEW02_PANEL *thiz = static_cast<TYPE_MSG_VIEW02_PANEL *>(this);

public:
};
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchYxxx_Mock {};
#endif

#if (false) // WAY02 激進版本。目前使用。	- 1709068864#
#pragma once
#include "xplum/ancestor/Pluginer.h"

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign {
template <typename TYPE_MSG_VIEW01>
concept MsgViewPatchYxxx_Concept =    //
    requires(TYPE_MSG_VIEW01 *thiz) { //
      true;
    };

template <typename> class MsgViewPatchYxxx;
}

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element {
template <typename TYPE_MSG_VIEW01, typename TYPE_MSG_VIEW02_PANEL>
using MsgViewPatchYxxx = std::conditional<_nsign::MsgViewPatchYxxx_Concept<TYPE_MSG_VIEW01>, _nsign::MsgViewPatchYxxx<TYPE_MSG_VIEW02_PANEL>, typename _nsign::MsgViewPatchYxxx<TYPE_MSG_VIEW02_PANEL>::ClassMock>::type;
}

template <typename TYPE_MSG_VIEW02_PANEL>
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchYxxx                                                    //
    : public xplum::ancestor::PluginerWay02<MsgViewPatchYxxx<TYPE_MSG_VIEW02_PANEL>, TYPE_MSG_VIEW02_PANEL> {
public:
};
#endif
