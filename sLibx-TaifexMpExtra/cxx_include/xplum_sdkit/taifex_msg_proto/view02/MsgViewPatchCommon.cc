#pragma once
#include "./MsgViewPatchCommon.h"
#pragma

#if (true)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <boost/date_time/posix_time/posix_time.hpp>
#pragma GCC diagnostic pop
#endif
#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#include "xplum_sdkit/taifex_msg_proto/view/msg_lxx_layer.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/msg_kitbag_common.h"

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign
{
template <typename TYPE_MSG_VIEW01>
concept MsgViewPatchCommon_Concept =  //
    requires(TYPE_MSG_VIEW01 *thiz) { //
        requires(std::is_same_v<view::message_field::MsgTime, decltype(thiz->m_hdr.m_msg_time)>);
        requires(std::is_same_v<view::message_field::uint08, decltype(thiz->m_check_sum)>);
        requires(std::is_same_v<view::message_field::uint32, decltype(thiz->m_hdr.m_msg_seq_num)>);
    };

template <typename>
class MsgViewPatchCommon;
}

namespace xplum_sdkit::taifex_msg_proto::view02::msg_view_element
{
template <typename TYPE_MSG_VIEW01, typename TYPE_MSG_VIEW02_PANEL>
using MsgViewPatchCommon = std::conditional<_nsign::MsgViewPatchCommon_Concept<TYPE_MSG_VIEW01>, _nsign::MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>, typename _nsign::MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::ClassMock>::type;
}

template <typename TYPE_MSG_VIEW02_PANEL>                               //
class xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon                                                  //
    : public xplum::ancestor::PluginerWay02<MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>, TYPE_MSG_VIEW02_PANEL>
{
  public:
    // fx_assign_m_msg_time()
    void fx_assign_m_msg_time(type::int32, type::uint16);                                       // 【】linux_time_stamp_s, millisecond,
    void fx_assign_m_msg_time_0_time_now();                                                     // 【】
    void fx_assign_m_msg_time_0_time_point(std::int64_t);                                       // 【     】rvalue_time_since_epoch_microseconds
    void fx_assign_m_msg_time_0_time_point(timeval);                                            // 【C    】rvalue
    void fx_assign_m_msg_time_0_time_point(std::chrono::time_point<std::chrono::system_clock>); // 【Std  】rvalue
    void fx_assign_m_msg_time_0_time_point(boost::posix_time::ptime);                           // 【Boost】rvalue
    // fx_assign_m_check_sum()
    void fx_assign_m_check_sum_0_algorithm();
    //	fx_assign_m_msg_seq_num()
    void fx_assign_m_msg_seq_num(type::uint32);                         // rvalue
    void fx_assign_m_msg_seq_num_0_seed(ancestor::CounterMsgSeqNumV &); // seed
};
