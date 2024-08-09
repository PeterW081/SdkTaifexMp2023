#pragma once
#include "xplum_sdkit/taifex_msg_proto/view/msg_field_enumerate.h"

namespace xplum_sdkit::taifex_msg_proto::kitbag::_nshdr
{
using kitbag::CounterMsgSeqNumV;
using kitbag::CounterOrderSeqV;
using view::message_field::enumerate::SystemType;
}
namespace xplum_sdkit::taifex_msg_proto::kitbag
{
struct UnityFutureTradeSession;
}

struct                                      //
    xplum_sdkit::taifex_msg_proto::kitbag:: //
    UnityFutureTradeSession
{
  std::set<std::tuple<type::TypeFcmId, type::TypeSessionId> > m_arr_0_tcp_token;
  std::map<type::TypeFcmId, std::shared_ptr<_nshdr::CounterOrderSeqV> > m_map_0_fcm_counterOrderSeq;
};
