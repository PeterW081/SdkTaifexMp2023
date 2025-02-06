#pragma once
#include <string>
#include "xplum_sdkit/taifex_msg_proto/_define_cxx.h"
#

///
namespace xplum_sdkit::taifex_msg_proto::util::_nshdr
{
struct MsgSessionContextReServer_MOCK;
}
namespace xplum_sdkit::taifex_msg_proto::util
{
struct MsgSessionConnectionInfo;
struct MsgSessionContext;
using MsgSessionContextReServer = _nshdr::MsgSessionContextReServer_MOCK;
}

/// MsgSessionConnectionInfo
struct                                    //
    xplum_sdkit::taifex_msg_proto::util:: //
    MsgSessionConnectionInfo
{
    std::string m_server_host;
    std::string m_server_port;
    type::TypeFcmId m_fcm_id;
    type::TypeSessionId m_session_id;
    struct
    {
        std::optional<type::uint16> m_fcm_passwd;
        void fx_scrap()
        {
            this->m_fcm_passwd = std::nullopt;
        };
    } m_secrecy;
};

/// MsgSessionContext
struct                                    //
    xplum_sdkit::taifex_msg_proto::util:: //
    MsgSessionContext
{
    auto fx_extract(MsgSessionConnectionInfo const) -> void;

  public:
    /// msg
    // X msg all layer
    type::TypeFcmId m_fcm_id;
    type::TypeSessionId m_session_id;
    // X msg Lxx layer
    std::uint8_t const m_ap_code = 4;              // L40<
    std::uint8_t const m_cancel_order_sec = 0;     // L40<
    enumerate::EnumSystemType m_trade_system_type; // L40<、L30>。
    std::uint32_t m_request_start_seq;             // L40<。
    // X msg Rxx layer
    std::shared_ptr<util::CounterMsgSeqNumV> m_counter_msg_seq;

    /// msg secrecy
    struct
    {
        std::optional<type::uint16> m_fcm_passwd;
        std::optional<type::uint16> m_append_no;
        void fx_scrap()
        {
            this->m_fcm_passwd = std::nullopt;
            this->m_append_no = std::nullopt;
        };
    } m_secrecy;
};

/// MsgSessionContextReServer_MOCK
struct                                            //
    xplum_sdkit::taifex_msg_proto::util::_nshdr:: //
    MsgSessionContextReServer_MOCK
{
    /// msg
    // X msg - L30
    auto fx_mk_append_no_with_random() -> type::uint16;
    // X msg - L40
    auto fx_get_fcm_passwd_MOCK(type::TypeFcmId, type::uint16) -> std::optional<type::uint16>; // fcm_id,
    auto fx_is_allow_login_fcm_session_MOCK(type::TypeFcmId, type::TypeSessionId) -> bool;     // fcm_id, session_id,
    // X msg - L41
    auto fx_get_msg_L41Data_size_MOCK() -> type::TypeMsgLength;
};
