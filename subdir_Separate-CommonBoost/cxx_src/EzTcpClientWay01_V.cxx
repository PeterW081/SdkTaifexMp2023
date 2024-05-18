#include "boost0/asio/EzTcpClientWay01_V.h"

#pragma
namespace nscxx_root = ext::boost_asio0;

// using ext::boost_asio0::EzTcpClientWay01_V;
//
nscxx_root::EzTcpClientWay01_V::EzTcpClientWay01_V(std::string_view server_host, std::string_view server_port) : EzTcpClient_A(server_host, server_port) {}
auto nscxx_root::EzTcpClientWay01_V::write_str(std::string &data, std::optional<std::chrono::seconds> timeout) -> std::size_t { return this->write(std::span(reinterpret_cast<std::byte *>(data.data()), data.size()), timeout); }
auto nscxx_root::EzTcpClientWay01_V::reade_str(std::string &data, std::optional<std::chrono::seconds> timeout) -> std::size_t { return this->reade(std::span(reinterpret_cast<std::byte *>(data.data()), data.size()), timeout); }
