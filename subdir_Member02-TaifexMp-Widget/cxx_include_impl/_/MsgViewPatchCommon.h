#include_next "xplum_sdkit/taifex_msg_proto/view02/MsgViewPatchCommon.h"

#pragma once
#include "xplum_model/taifex_msg_proto/static_function_msg.h"

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchCommon;
// > fx_assign_m_msg_time()
//
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_time(type::int32 linux_time_stamp_s, type::uint16 millisecond) {
  // XXXX 取得當前時間：
  this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = linux_time_stamp_s;
  this->thiz->m_hdr.m_msg_time.m_millisecond = millisecond;
}
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_time_0_time_now() {
  // XXXX 取得當前時間：
  constexpr auto int_1k = 1000;
  timeval value = timeval();
  gettimeofday(&value, nullptr);
  this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(value.tv_sec);
  this->thiz->m_hdr.m_msg_time.m_millisecond = value.tv_usec / int_1k;
}
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_time_0_time_point(std::int64_t rvalue_time_since_epoch_microseconds) {
  // XXXX 取得當前時間：rvalue_time_since_epoch_microseconds = std::chrono::system_clock::now().time_since_epoch().count();
  constexpr auto int_1k = 1000;
  constexpr auto int_1kk = 1000 * 1000;
  this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(rvalue_time_since_epoch_microseconds / int_1kk);
  this->thiz->m_hdr.m_msg_time.m_millisecond = (rvalue_time_since_epoch_microseconds % int_1kk) / int_1k;
}
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_time_0_time_point(timeval rvalue) {
  // XXXX 取得當前時間：gettimeofday(&rvalue, nullptr);
  constexpr auto int_1k = 1000;
  this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(rvalue.tv_sec);
  this->thiz->m_hdr.m_msg_time.m_millisecond = rvalue.tv_usec / int_1k;
}
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_time_0_time_point(std::chrono::time_point<std::chrono::system_clock> rvalue) {
  // XXXX 取得當前時間：rvalue = std::chrono::system_clock::now();
  constexpr auto int_1k = 1000;
  this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(std::chrono::duration_cast<std::chrono::seconds>(rvalue.time_since_epoch()).count());
  this->thiz->m_hdr.m_msg_time.m_millisecond = std::chrono::duration_cast<std::chrono::milliseconds>(rvalue.time_since_epoch()).count() % int_1k;
}
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_time_0_time_point(boost::posix_time::ptime rvalue) {
  // XXXX 取得當前時間：rvalue = boost::posix_time::second_clock::local_time();
  constexpr auto int_1k = 1000;
  constexpr auto linex_timestamp_base = boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1));
  boost::posix_time::time_duration timestamp = rvalue - linex_timestamp_base;
  this->thiz->m_hdr.m_msg_time.m_linux_time_stamp_s = static_cast<type::int32>(timestamp.total_seconds());
  this->thiz->m_hdr.m_msg_time.m_millisecond = timestamp.total_milliseconds() % int_1k;
}

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchCommon;
// > fx_assign_m_check_sum()
//
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_check_sum_0_algorithm() {
  namespace ns0_origin_algorithm = xplum_model::taifex_msg_proto::algorithm;
  const auto &data = this->thiz->data_span();
  this->thiz->m_check_sum = ns0_origin_algorithm::FX_MSG_CHECK_SUM(data.data(), data.size());
}

// using xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign::MsgViewPatchCommon;
// > fx_assign_m_msg_seq_num()
//
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_seq_num(type::uint32 rvalue) {
  this->thiz->m_hdr.m_msg_seq_num = rvalue;
}
template <typename TYPE_MSG_VIEW02_PANEL>
void xplum_sdkit::taifex_msg_proto::view02::msg_view_element::_nsign:: //
    MsgViewPatchCommon<TYPE_MSG_VIEW02_PANEL>::fx_assign_m_msg_seq_num_0_seed(ancestor::CounterMsgSeqNumV &seed) {
  this->thiz->m_hdr.m_msg_seq_num = seed.next_0_prefix_increment();
}
