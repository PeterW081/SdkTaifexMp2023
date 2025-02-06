#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/msg_util_session_context.h"
#pragma
#

namespace nscxx_root = xplum_sdkit::taifex_msg_proto::util;
namespace nscxx
{
}

/// MsgSessionContexts
auto                    //
    nscxx_root::        //
    MsgSessionContext:: //
    fx_extract(MsgSessionConnectionInfo const info) -> void
{
    this->m_secrecy.m_fcm_passwd = info.m_secrecy.m_fcm_passwd;
    this->m_fcm_id = info.m_fcm_id;
    this->m_session_id = info.m_session_id;
}

/// MsgSessionContextReServer_MOCK - implement
#if (true)
#include <random>
auto                                              //
    xplum_sdkit::taifex_msg_proto::util::_nshdr:: //
    MsgSessionContextReServer_MOCK::              //
    fx_get_msg_L41Data_size_MOCK() -> type::TypeMsgLength
{
    return 0;
}
auto                                              //
    xplum_sdkit::taifex_msg_proto::util::_nshdr:: //
    MsgSessionContextReServer_MOCK::              //
    fx_mk_append_no_with_random() -> type::uint16
{
    auto itc_random_seed = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
    auto itc_random_deal = std::uniform_int_distribution<std::int16_t>(0, 999);
    return itc_random_deal.operator()(itc_random_seed);
}
auto                                              //
    xplum_sdkit::taifex_msg_proto::util::_nshdr:: //
    MsgSessionContextReServer_MOCK::              //
    fx_is_allow_login_fcm_session_MOCK(type::TypeFcmId, type::TypeSessionId) -> bool
{
    return true;
}
auto                                              //
    xplum_sdkit::taifex_msg_proto::util::_nshdr:: //
    MsgSessionContextReServer_MOCK::              //
    fx_get_fcm_passwd_MOCK(type::TypeFcmId, type::uint16 value) -> std::optional<type::uint16>
{
    return value;
}
#endif
