#pragma once
#include "./PlugerMsg_Common.h"
#pragma
#if (true)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <boost/date_time/posix_time/posix_time.hpp>
#pragma GCC diagnostic pop
#endif
#include "xplum/ancestor/Pluginer.h"
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#

/// namespace
namespace xplum_sdkit::taifex_msg_proto::view::message_plugin
{
template <typename TYPE_msg_view>
class PlugerMsg_Common;
}

/// class - PlugerMsg_Common
template <typename TYPE_msg_view>
class                                                     //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common                                      //
    : public xplum::ancestor::Pluginer<PlugerMsg_Common<TYPE_msg_view>, TYPE_msg_view>
{
  protected:
    explicit PlugerMsg_Common();

  public:
    // fx_assign_m_fcm_id_session_id()
    auto fx_assign_m_fcm_id_session_id(type::TypeFcmId, type::TypeSessionId) -> void;
    // fx_assign_m_msg_time()
    auto fx_assign_m_msg_time(type::int32, type::uint16) -> void;                                       // 【】linux_time_stamp_s, millisecond,
    auto fx_assign_m_msg_time_0_time_now() -> void;                                                     // 【】
    auto fx_assign_m_msg_time_0_time_point(std::int64_t) -> void;                                       // 【     】rvalue_time_since_epoch_microseconds
    auto fx_assign_m_msg_time_0_time_point(timeval) -> void;                                            // 【C    】rvalue
    auto fx_assign_m_msg_time_0_time_point(std::chrono::time_point<std::chrono::system_clock>) -> void; // 【Std  】rvalue
    auto fx_assign_m_msg_time_0_time_point(boost::posix_time::ptime) -> void;                           // 【Boost】rvalue
    // fx_assign_m_check_sum()
    auto fx_assert_m_check_sum() const -> bool;
    auto fx_assign_m_check_sum_0_algorithm() -> void;
    // fx_assign_m_msg_seq_num()
    auto fx_assign_m_msg_seq_num(type::uint32) -> void;                          // rvalue
    auto fx_assign_m_msg_seq_num_0_seed(ancestor::CounterMsgSeqNum_V &) -> void; // seed
};
