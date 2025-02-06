#pragma once
#include "./PlugerMsg_Common.h"
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L06/function_msg.h"
#include "xplum_sdkit/taifex_msg_proto/ancestor/CounterMsgSeqNum_V.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg_view/msg_field.h"
#

/// PlugerMsg_Common
template <typename TYPE_msg_view>
/*Constructor*/                                       //
xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                 //
    PlugerMsg_Common()
{
    static_assert(                      //
        requires(TYPE_msg_view *thiz) { //
            requires(std::is_same_v<view::message_field::MsgHdr_VIEW, decltype(thiz->m_hdr)>);
            requires(std::is_same_v<view::message_field::uint08_VIEW, decltype(thiz->m_check_sum)>);
        });
}

/// PlugerMsg_Common - fx_assign_m_fcm_id_session_id()
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_fcm_id_session_id(type::TypeFcmId fcm_id, type::TypeSessionId session_id) -> void
{
    this->thiz->m_hdr.m_fcm_id = fcm_id;
    this->thiz->m_hdr.m_session_id = session_id;
}

/// PlugerMsg_Common - fx_assign_m_msg_time()
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_time(type::int32 linux_time_stamp_s, type::uint16 millisecond) -> void
{
    // XXXX 取得當前時間：
    this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = linux_time_stamp_s;
    this->thiz->m_hdr.m_msg_time.m_millisecond = millisecond;
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_time_0_time_now() -> void
{
    // XXXX 取得當前時間：
    constexpr auto int_1k = 1000;
    timeval value = timeval();
    gettimeofday(&value, nullptr);
    this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(value.tv_sec);
    this->thiz->m_hdr.m_msg_time.m_millisecond = value.tv_usec / int_1k;
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_time_0_time_point(std::int64_t rvalue_time_since_epoch_microseconds) -> void
{
    // XXXX 取得當前時間：rvalue_time_since_epoch_microseconds = std::chrono::system_clock::now().time_since_epoch().count();
    constexpr auto int_1k = 1000;
    constexpr auto int_1kk = 1000 * 1000;
    this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(rvalue_time_since_epoch_microseconds / int_1kk);
    this->thiz->m_hdr.m_msg_time.m_millisecond = (rvalue_time_since_epoch_microseconds % int_1kk) / int_1k;
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_time_0_time_point(timeval rvalue) -> void
{
    // XXXX 取得當前時間：gettimeofday(&rvalue, nullptr);
    constexpr auto int_1k = 1000;
    this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(rvalue.tv_sec);
    this->thiz->m_hdr.m_msg_time.m_millisecond = rvalue.tv_usec / int_1k;
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_time_0_time_point(std::chrono::time_point<std::chrono::system_clock> rvalue) -> void
{
    // XXXX 取得當前時間：rvalue = std::chrono::system_clock::now();
    constexpr auto int_1k = 1000;
    this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(std::chrono::duration_cast<std::chrono::seconds>(rvalue.time_since_epoch()).count());
    this->thiz->m_hdr.m_msg_time.m_millisecond = std::chrono::duration_cast<std::chrono::milliseconds>(rvalue.time_since_epoch()).count() % int_1k;
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_time_0_time_point(boost::posix_time::ptime rvalue) -> void
{
    // XXXX 取得當前時間：rvalue = boost::posix_time::second_clock::local_time();
    constexpr auto int_1k = 1000;
    constexpr auto linex_timestamp_base = boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1));
    boost::posix_time::time_duration timestamp = rvalue - linex_timestamp_base;
    this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(timestamp.total_seconds());
    this->thiz->m_hdr.m_msg_time.m_millisecond = timestamp.total_milliseconds() % int_1k;
}

/// PlugerMsg_Common - fx_assign_m_check_sum_0_algorithm()
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_check_sum_0_algorithm() -> void
{
    namespace nsfunc_algorithm = xplum_model::taifex_msg_proto::msg_algorithm;
    const auto &data = this->thiz->fx_span();
    this->thiz->m_check_sum = nsfunc_algorithm::FX_msg_check_sum(data.data(), data.size());
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assert_m_check_sum() const -> bool
{
    namespace nsfunc_algorithm = xplum_model::taifex_msg_proto::msg_algorithm;
    const auto &data = this->thiz->fx_span();
    return this->thiz->m_check_sum == nsfunc_algorithm::FX_msg_check_sum(data.data(), data.size());
}

/// PlugerMsg_Common - fx_assign_m_msg_seq_num()
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_seq_num(type::uint32 rvalue) -> void
{
    this->thiz->m_hdr.m_msg_seq_num = rvalue;
}
template <typename TYPE_msg_view>
auto                                                      //
    xplum_sdkit::taifex_msg_proto::view::message_plugin:: //
    PlugerMsg_Common<TYPE_msg_view>::                     //
    fx_assign_m_msg_seq_num_0_seed(ancestor::CounterMsgSeqNum_V &seed) -> void
{
    this->thiz->m_hdr.m_msg_seq_num = seed.fv_next_0_prefix_increment();
}
