#include <gtest/gtest.h>
#pragma
#
#include "xplum_model/taifex_msg_proto/network_osi_L05/constant_tcp.h"
#include "xplum_sdkit/taifex_msg_proto/kitbag/action_kitbag_tcp_contact.h"
#include "xplum_sdkit/taifex_msg_proto/view02/msg_all_layer.h"
#include "xplum_sdkit/taifex_msg_proto/network/EzV3_TaifexMpSocketer_Sync.h"
#

namespace nscxx
{
using namespace xplum_model::taifex_msg_proto::tcp_parament;
using namespace xplum_sdkit::taifex_msg_proto;
static const auto G_PATTERN_UNITY_TCP_SESSION = kitbag::UnityTcpSession{
    .m_server_host = "127.0.0.1",
    .m_server_port = "8080",
    .m_fcm_id = 1087,
    .m_session_id = 2437,
    .m_secrecy =
        {
            .m_fcm_passwd = 3347,
        },
};
}

TEST(Example01_MsgLxx, Example01_01MsgLxxRawClient)
{
#if (true)
    GTEST_SKIP();
#endif

    using nscxx::view::message_field::enumerate::MsgType;

    std::array<std::byte, 1024> buffer = {};
    auto unity = nscxx::G_PATTERN_UNITY_TCP_SESSION;
    auto tcp_client_msg0 = nscxx::network::EzV3_TaifexMpSocketer_Sync(nscxx::network::EumeTcpEndpointSide::CLIENT, unity.m_server_host, unity.m_server_port);
    auto &tcp_client_msg = dynamic_cast<xplum::ancestor::SocketerSync_V &>(tcp_client_msg0);
    auto tcp_read_timeout = std::chrono::seconds(nscxx::G_lxx_layer_timeout_s);
    tcp_client_msg.fv_start(tcp_read_timeout);

    std::shared_ptr counter_msg_seq = std::make_shared<nscxx::kitbag::CounterMsgSeqNumSimple>();
    unity.m_counter_msg_seq = counter_msg_seq;
    unity.m_request_start_seq = counter_msg_seq->peek().value_or(0);

    // write - L10
    {
        auto msg_view = nscxx::view02::message::L10::FX_ASSIGN_MSG(std::span(buffer));
        msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
        msg_view.m_hdr.m_session_id = unity.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_client_msg.fv_write(buffer);
    }
    // reade - L10
    {
        tcp_client_msg.fv_reade(buffer, tcp_read_timeout);
        ASSERT_TRUE(MsgType::EnumType::L10 == nscxx::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value());
        auto msg_view = nscxx::view02::message::L10(buffer);
    }
    // write - L20
    {
        auto msg_view = nscxx::view02::message::L20::FX_ASSIGN_MSG(std::span(buffer));
        msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
        msg_view.m_hdr.m_session_id = unity.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_client_msg.fv_write(buffer);
    }
    // reade - L30
    {
        tcp_client_msg.fv_reade(buffer, tcp_read_timeout);
        ASSERT_TRUE(MsgType::EnumType::L30 == nscxx::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value());
        auto msg_view = nscxx::view02::message::L30(buffer);
        unity.m_secrecy.m_append_no = msg_view.m_append_no;
        unity.m_trade_system_type = msg_view.m_system_type.enum_value();
    }
    // write - L40
    {
        auto msg_view = nscxx::view02::message::L40::FX_ASSIGN_MSG(std::span(buffer));
        {
            bool is_ok;
            msg_view.m_append_no = unity.m_secrecy.m_append_no.value();
            is_ok = msg_view.fx_assign_m_key_value_0_algorithm(unity.m_secrecy.m_fcm_passwd.value(), unity.m_secrecy.m_append_no.value());
            unity.m_secrecy.m_fcm_passwd = std::nullopt;
            unity.m_secrecy.m_append_no = std::nullopt;
            ASSERT_TRUE(is_ok);
        }
        {
            msg_view.m_system_type.operator_assign(unity.m_trade_system_type);
            msg_view.m_request_start_seq = unity.m_request_start_seq;
            msg_view.m_ap_code = unity.m_ap_code;
            msg_view.m_cancel_order_sec = unity.m_cancel_order_sec;
        }
        {
            msg_view.m_fcm_id = unity.m_fcm_id;
            msg_view.m_session_id = unity.m_session_id;
        }
        msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
        msg_view.m_hdr.m_session_id = unity.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_client_msg.fv_write(buffer);
    }
    // reade - L41, L42, L50,
    {
        tcp_client_msg.fv_reade(buffer, tcp_read_timeout);
        ASSERT_TRUE(false                                                                                                         //
                    || MsgType::EnumType::L41 == nscxx::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value() //
                    || MsgType::EnumType::L42 == nscxx::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value() //
                    || MsgType::EnumType::L50 == nscxx::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value() //
        );
        switch (nscxx::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value())
        {
        case MsgType::EnumType::L41:
        case MsgType::EnumType::L42:
            FAIL() << "TODO"; // TODO
            std::abort();
        case MsgType::EnumType::L50: {
            auto msg_view = nscxx::view02::message::L50(buffer);
            break;
        }
        [[unlikely]] default:
            FAIL() << "TODO"; // TODO
            std::abort();
        }
    }
    // write - L60
    {
        auto msg_view = nscxx::view02::message::L60::FX_ASSIGN_MSG(std::span(buffer));
        ASSERT_TRUE(MsgType::EnumType::L60 == nscxx::ez_view::FX_GET_MSG_TYPE_IN_ORIGIN_MSG_1CONST(buffer.data()).enum_value());
        msg_view.m_hdr.m_fcm_id = unity.m_fcm_id;
        msg_view.m_hdr.m_session_id = unity.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_client_msg.fv_write(buffer);
    }

    //
    unity.m_secrecy.fx_scrap();
}
