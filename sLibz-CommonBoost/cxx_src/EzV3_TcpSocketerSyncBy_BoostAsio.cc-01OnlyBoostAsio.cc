#include "boost0/asio/EzV3_TcpSocketerSyncBy_BoostAsio.h"
#pragma
#
#include <boost/asio.hpp>
#

///
namespace nscxx_root = ext::boost_asio0;
namespace nscxx
{
using ext::boost_asio0::EnumTcpSocketAction;
using ext::boost_asio0::EumeTcpEndpointSide;
using TYPE_asio_acceptor = boost::asio::ip::tcp::acceptor;
using TYPE_asio_resolver = boost::asio::ip::tcp::resolver;
using TYPE_asio_io_context = boost::asio::io_context;
using TYPE_asio_socket = boost::asio::ip::tcp::socket;

struct BoostAsioAsync;
}
struct nscxx::BoostAsioAsync : protected nscxx_root::EzV3_TcpSocketerSyncBy_BoostAsio
{
    using THIS = BoostAsioAsync;

  public:
    template <EumeTcpEndpointSide VALUE_tcp_side, typename T>
        requires((VALUE_tcp_side == EumeTcpEndpointSide::SERVER && std::is_same_v<T, TYPE_WRAP_TcpEpMemberServer>) || (VALUE_tcp_side == EumeTcpEndpointSide::CLIENT && std::is_same_v<T, TYPE_WRAP_TcpEpMemberClient>))
    static auto FX_tcp_ep_start(T &, std::string_view, std::string_view, std::optional<std::chrono::seconds> &) -> bool;
    //
    template <EumeTcpEndpointSide VALUE_tcp_side, typename T>
        requires((VALUE_tcp_side == EumeTcpEndpointSide::SERVER && std::is_same_v<T, TYPE_WRAP_TcpEpMemberServer>) || (VALUE_tcp_side == EumeTcpEndpointSide::CLIENT && std::is_same_v<T, TYPE_WRAP_TcpEpMemberClient>))
    static auto FX_tcp_ep_close(T &) -> bool;
    //
    template <EnumTcpSocketAction VALUE_tcp_action>
        requires(VALUE_tcp_action == EnumTcpSocketAction::READE || VALUE_tcp_action == EnumTcpSocketAction::WRITE)
    static auto FX_tcp_ep_action(TYPE_WRAP_TcpEpMemberBoth &, std::span<std::byte> &, std::optional<std::chrono::seconds> &) -> std::pair<boost::system::error_code, std::size_t>;
    //
  private:
    template <typename T>
    static auto FX_tcp_ep_action_0_run_one_with_timeout(TYPE_WRAP_TcpEpMemberBoth &, std::optional<std::chrono::seconds> &, std::optional<T> &, std::function<void()>) -> void;
};

/// EzV3_TcpSocketerSyncBy_BoostAsio - 01
struct           //
    nscxx_root:: //
    EzV3_TcpSocketerSyncBy_BoostAsio::TYPE_WRAP_TcpEpMemberBoth
{
    bool m_is_ought_init = false;
    std::unique_ptr<nscxx::TYPE_asio_io_context> m_io_context;
    std::unique_ptr<nscxx::TYPE_asio_socket> m_socket;
};
struct           //
    nscxx_root:: //
    EzV3_TcpSocketerSyncBy_BoostAsio::TYPE_WRAP_TcpEpMemberServer : TYPE_WRAP_TcpEpMemberBoth
{
    std::unique_ptr<nscxx::TYPE_asio_acceptor> m_acceptor;
};
struct           //
    nscxx_root:: //
    EzV3_TcpSocketerSyncBy_BoostAsio::TYPE_WRAP_TcpEpMemberClient : TYPE_WRAP_TcpEpMemberBoth
{
    std::unique_ptr<nscxx::TYPE_asio_resolver> m_resolver;
};

/// namespace nscxx - 01
template <>
auto nscxx::BoostAsioAsync::FX_tcp_ep_start<nscxx::EumeTcpEndpointSide::SERVER, nscxx::BoostAsioAsync::TYPE_WRAP_TcpEpMemberServer> //
    (TYPE_WRAP_TcpEpMemberServer &fp_tcp_ep_member, std::string_view fp_tcp_ep_host, std::string_view fp_tcp_ep_port, std::optional<std::chrono::seconds> &fp_timeout) -> bool
{
    using boost::asio::ip::tcp;
    /// - server: init
    if (fp_tcp_ep_member.m_is_ought_init)
    {
        fp_tcp_ep_member.m_is_ought_init = false;
        auto boost_asio_endpoint = fp_tcp_ep_host.empty()                                                                               //
                                       ? tcp::endpoint(tcp::v4(), std::stoi(fp_tcp_ep_port.data()))                                     //
                                       : tcp::endpoint(boost::asio::ip::make_address(fp_tcp_ep_host), std::stoi(fp_tcp_ep_port.data())) //
            ;
        fp_tcp_ep_member.m_io_context = std::make_unique<TYPE_asio_io_context>();
        fp_tcp_ep_member.m_socket = nullptr;
        fp_tcp_ep_member.m_acceptor = std::make_unique<nscxx::TYPE_asio_acceptor>(fp_tcp_ep_member.m_io_context.operator*(), boost_asio_endpoint);
    }
    /// - server: start, reset,
    auto boost_error_code = std::optional<boost::system::error_code>();
    auto async_func = [&boost_error_code, &fp_tcp_ep_member](const boost::system::error_code &fp_error_code, nscxx::TYPE_asio_socket fp_socket) {
        boost_error_code = fp_error_code;
        fp_tcp_ep_member.m_socket = std::make_unique<nscxx::TYPE_asio_socket>(std::move(fp_socket));
    };
    fp_tcp_ep_member.m_acceptor->async_accept(async_func);
    THIS::FX_tcp_ep_action_0_run_one_with_timeout(fp_tcp_ep_member, fp_timeout, boost_error_code, nullptr);
    return boost_error_code.has_value() && not static_cast<bool>(boost_error_code.value());
}
template <>
auto nscxx::BoostAsioAsync::FX_tcp_ep_start<nscxx::EumeTcpEndpointSide::CLIENT, nscxx::BoostAsioAsync::TYPE_WRAP_TcpEpMemberClient> //
    (TYPE_WRAP_TcpEpMemberClient &fp_tcp_ep_member, std::string_view fp_tcp_ep_host, std::string_view fp_tcp_ep_port, std::optional<std::chrono::seconds> &fp_timeout) -> bool
{
    using boost::asio::ip::tcp;
    /// - client: init
    if (fp_tcp_ep_member.m_is_ought_init)
    {
        fp_tcp_ep_member.m_is_ought_init = false;
        fp_tcp_ep_member.m_io_context = std::make_unique<nscxx::TYPE_asio_io_context>();
        fp_tcp_ep_member.m_socket = std::make_unique<nscxx::TYPE_asio_socket>(fp_tcp_ep_member.m_io_context.operator*());
        fp_tcp_ep_member.m_resolver = std::make_unique<nscxx::TYPE_asio_resolver>(fp_tcp_ep_member.m_io_context.operator*());
    }
    /// - client: start, reset,
    auto boost_error_code = std::optional<boost::system::error_code>();
    auto async_func = [&boost_error_code](const boost::system::error_code &fp_error_code, const tcp::endpoint &) { boost_error_code = fp_error_code; };
    auto func_when_done_mark_false = [&fp_tcp_ep_member]() -> void { fp_tcp_ep_member.m_socket->cancel(); };
    boost::asio::async_connect( //
        fp_tcp_ep_member.m_socket.operator*(), fp_tcp_ep_member.m_resolver->resolve(fp_tcp_ep_host, fp_tcp_ep_port), async_func);
    THIS::FX_tcp_ep_action_0_run_one_with_timeout(fp_tcp_ep_member, fp_timeout, boost_error_code, func_when_done_mark_false);
    return boost_error_code.has_value() && not static_cast<bool>(boost_error_code.value());
}
template <nscxx::EumeTcpEndpointSide VALUE_tcp_side, typename T>
    requires((VALUE_tcp_side == nscxx::EumeTcpEndpointSide::SERVER && std::is_same_v<T, nscxx::BoostAsioAsync::TYPE_WRAP_TcpEpMemberServer>) || //
             (VALUE_tcp_side == nscxx::EumeTcpEndpointSide::CLIENT && std::is_same_v<T, nscxx::BoostAsioAsync::TYPE_WRAP_TcpEpMemberClient>))
auto nscxx::BoostAsioAsync::FX_tcp_ep_close(T &fp_tcp_ep_member) -> bool
{
    if constexpr (VALUE_tcp_side == nscxx::EumeTcpEndpointSide::SERVER)
    {
        TYPE_WRAP_TcpEpMemberServer &T0 = fp_tcp_ep_member;
        T0.m_acceptor.reset();
        T0.m_socket.reset();
        T0.m_io_context.reset();
    }
    if constexpr (VALUE_tcp_side == nscxx::EumeTcpEndpointSide::CLIENT)
    {
        TYPE_WRAP_TcpEpMemberClient &T0 = fp_tcp_ep_member;
        T0.m_resolver.reset();
        T0.m_socket.reset();
        T0.m_io_context.reset();
    }
    return true;
}

/// namespace nscxx - 02
template <nscxx::EnumTcpSocketAction VALUE_tcp_action>
    requires(VALUE_tcp_action == nscxx::EnumTcpSocketAction::READE || VALUE_tcp_action == nscxx::EnumTcpSocketAction::WRITE)
auto nscxx::BoostAsioAsync::FX_tcp_ep_action(TYPE_WRAP_TcpEpMemberBoth &fp_tcp_ep_member, std::span<std::byte> &fp_span, std::optional<std::chrono::seconds> &fp_timeout) -> std::pair<boost::system::error_code, std::size_t>
{
    auto boost_error_code = boost::system::error_code();
    auto sizeof_xxx = std::optional<std::size_t>();
    auto &fp_socket = fp_tcp_ep_member.m_socket.operator*();
    /// - server, client, : reade, write,
    auto async_func = [&boost_error_code, &sizeof_xxx](boost::system::error_code fp_boost_error_code, std::size_t fp_sizeof_write) -> void {
        boost_error_code = fp_boost_error_code;
        sizeof_xxx = fp_sizeof_write;
    };
    // X
    if constexpr (VALUE_tcp_action == EnumTcpSocketAction::READE)
    {
        boost::asio::async_read(fp_socket, boost::asio::buffer(fp_span.data(), fp_span.size()), async_func);
    }
    if constexpr (VALUE_tcp_action == EnumTcpSocketAction::WRITE)
    {
        boost::asio::async_write(fp_socket, boost::asio::buffer(fp_span.data(), fp_span.size()), async_func);
    }
    // X
    auto func_when_done_mark_false = [&fp_socket]() -> void { fp_socket.cancel(); };
    THIS::FX_tcp_ep_action_0_run_one_with_timeout(fp_tcp_ep_member, fp_timeout, sizeof_xxx, func_when_done_mark_false);
    ///
    return std::pair{boost_error_code, sizeof_xxx.value()};
}
template <typename T>
auto nscxx::BoostAsioAsync::FX_tcp_ep_action_0_run_one_with_timeout(TYPE_WRAP_TcpEpMemberBoth &fp_tcp_ep_member, std::optional<std::chrono::seconds> &fp_timeout, std::optional<T> &fp_done_mark, std::function<void()> fp_func_when_done_mark_false) -> void
{
    auto &fp_io_context = fp_tcp_ep_member.m_io_context.operator*();
    if (not fp_timeout.has_value())
    {
        fp_io_context.restart();
        fp_io_context.run_one();
    }
    else
    {
        fp_io_context.restart();
        fp_io_context.run_one_for(fp_timeout.value());
        if (not fp_done_mark.has_value())
        {
            if (fp_func_when_done_mark_false != nullptr)
            {
                fp_func_when_done_mark_false();
            }
            fp_io_context.poll_one();
        }
    }
}
