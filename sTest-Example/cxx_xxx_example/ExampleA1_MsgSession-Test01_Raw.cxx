#include <gtest/gtest.h>
#pragma
#include "xplum_model/taifex_msg_proto/network_osi_L05/constant_tcp.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/msg_util_session_context.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L05/partition_msg_session/MsgSocketer_Sync.h"
#include "xplum_sdkit/taifex_msg_proto/network_osi_L06/reference_msg/msg_all_layer.h"
#

namespace nscxx
{
using namespace xplum_model::taifex_msg_proto;
using namespace xplum_sdkit::taifex_msg_proto;
static auto const G_test_connection_info = util::MsgSessionConnectionInfo{
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

TEST(ExampleA1_MsgSession, Test01_Raw)
{
#if (true)
    GTEST_SKIP();
#endif

    ///
    using nscxx::enumerate::EnumMsgType;
    constexpr auto stc_side = ext::boost_asio0::EnumTcpEndpointSide::CLIENT;

    ///
    auto buffer = std::array<std::byte, 1024>();
    // X tcp
    auto tcp_host = nscxx::G_test_connection_info.m_server_host;
    auto tcp_port = nscxx::G_test_connection_info.m_server_port;
    auto tcp_timeout = std::chrono::seconds();
    // X msg_session_context
    auto msg_sesion_context = nscxx::util::MsgSessionContext();
    msg_sesion_context.fx_extract(nscxx::G_test_connection_info);

    ///
    auto tcp_socket = nscxx::network::EzV4_MsgSocketer_Sync(stc_side, tcp_host, tcp_port);
    tcp_socket.fv_start_sync(std::nullopt);

    ///
    tcp_timeout = std::chrono::seconds(nscxx::tcp_parament::G_lxx_layer_timeout_s);
    // X L10 - ClientToServer
    {
        auto msg_view = nscxx::view::message::MsgL10_VIEW::FX_init_msg(buffer);
        msg_view.m_hdr.m_fcm_id = msg_sesion_context.m_fcm_id;
        msg_view.m_hdr.m_session_id = msg_sesion_context.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
    // X L10 - ServerToClient
    {
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        ASSERT_TRUE(EnumMsgType::L10 == nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value());
        auto msg_view = nscxx::view::message::MsgL10_VIEW(buffer);
    }
    // X L20
    {
        auto msg_view = nscxx::view::message::MsgL20_VIEW::FX_init_msg(buffer);
        msg_view.m_hdr.m_fcm_id = msg_sesion_context.m_fcm_id;
        msg_view.m_hdr.m_session_id = msg_sesion_context.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
    // X L30
    {
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        ASSERT_TRUE(EnumMsgType::L30 == nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value());
        auto msg_view = nscxx::view::message::MsgL30_VIEW(buffer);
        msg_sesion_context.m_secrecy.m_append_no = msg_view.m_append_no;
        msg_sesion_context.m_trade_system_type = msg_view.m_system_type.enum_value();
    }
    // X L40
    {
        auto msg_view = nscxx::view::message::MsgL40_VIEW::FX_init_msg(buffer);
        {
            bool is_ok;
            msg_view.m_append_no = msg_sesion_context.m_secrecy.m_append_no.value();
            is_ok = msg_view.fx_assign_m_key_value_0_algorithm(msg_sesion_context.m_secrecy.m_fcm_passwd.value(), msg_sesion_context.m_secrecy.m_append_no.value());
            msg_sesion_context.m_secrecy.m_fcm_passwd = std::nullopt;
            msg_sesion_context.m_secrecy.m_append_no = std::nullopt;
            ASSERT_TRUE(is_ok);
        }
        {
            msg_view.m_system_type.operator_assign(msg_sesion_context.m_trade_system_type);
            msg_view.m_request_start_seq = msg_sesion_context.m_request_start_seq;
            msg_view.m_ap_code = msg_sesion_context.m_ap_code;
            msg_view.m_cancel_order_sec = msg_sesion_context.m_cancel_order_sec;
        }
        {
            msg_view.m_fcm_id = msg_sesion_context.m_fcm_id;
            msg_view.m_session_id = msg_sesion_context.m_session_id;
        }
        msg_view.m_hdr.m_fcm_id = msg_sesion_context.m_fcm_id;
        msg_view.m_hdr.m_session_id = msg_sesion_context.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
    // X L41, L42, L50,
    {
        tcp_socket.fv_reade_sync(buffer, tcp_timeout);
        ASSERT_TRUE(false                                                                                            //
                    || EnumMsgType::L41 == nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value() //
                    || EnumMsgType::L42 == nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value() //
                    || EnumMsgType::L50 == nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value() //
        );
        switch (nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value())
        {
        case EnumMsgType::L41:
        case EnumMsgType::L42:
            FAIL() << "TODO"; // TODO
            std::abort();
        case EnumMsgType::L50: {
            auto msg_view = nscxx::view::message::MsgL50_VIEW(buffer);
            break;
        }
        [[unlikely]] default:
            FAIL() << "TODO"; // TODO
            std::abort();
        }
    }
    // X L60
    {
        auto msg_view = nscxx::view::message::MsgL60_VIEW::FX_init_msg(buffer);
        ASSERT_TRUE(EnumMsgType::L60 == nscxx::ez_view::FX_get_msg_type_from_msg_data(buffer.data()).enum_value());
        msg_view.m_hdr.m_fcm_id = msg_sesion_context.m_fcm_id;
        msg_view.m_hdr.m_session_id = msg_sesion_context.m_session_id;
        msg_view.fx_assign_m_msg_time_0_time_now();
        msg_view.fx_assign_m_check_sum_0_algorithm();
        tcp_socket.fv_write_sync(buffer, tcp_timeout);
    }
    // X
    msg_sesion_context.m_secrecy.fx_scrap();
}
