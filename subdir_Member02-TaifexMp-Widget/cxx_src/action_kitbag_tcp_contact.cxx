#include "xplum_sdkit/taifex_msg_proto/kitbag/action_kitbag_tcp_contact.h"
#pragma

#include <random>
namespace nscxx_root = xplum_sdkit::taifex_msg_proto::kitbag;

/// UnityTcpSessionPluginServer_MOCK
auto                                        //
    xplum_sdkit::taifex_msg_proto::kitbag:: //
    UnityTcpSessionPluginReServer_MOCK::    //
    fx_is_allow_login_fcm_session (type::TypeFcmId, type::TypeSessionId) -> bool
{
  return true;
}
auto                                        //
    xplum_sdkit::taifex_msg_proto::kitbag:: //
    UnityTcpSessionPluginReServer_MOCK::    //
    fx_is_have_L41 (type::uint32) -> bool
{
  return false;
}
auto                                        //
    xplum_sdkit::taifex_msg_proto::kitbag:: //
    UnityTcpSessionPluginReServer_MOCK::    //
    fx_mk_append_no_with_random () -> type::uint16
{
  auto itc_random_seed = std::default_random_engine (std::chrono::system_clock::now ().time_since_epoch ().count ());
  auto itc_random_deal = std::uniform_int_distribution<std::int16_t> (0, 999);
  return itc_random_deal.operator() (itc_random_seed);
}
auto                                        //
    xplum_sdkit::taifex_msg_proto::kitbag:: //
    UnityTcpSessionPluginReServer_MOCK::    //
    fx_get_fcm_passwd (xplum_model::taifex_msg_proto::type::uint16 fp01) -> std::optional<type::uint16>
{
  return fp01;
}
