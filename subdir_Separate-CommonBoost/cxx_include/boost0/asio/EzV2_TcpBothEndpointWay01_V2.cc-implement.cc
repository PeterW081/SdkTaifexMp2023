#pragma once
#include "./EzV2_TcpBothEndpointWay01_V2.h"
#pragma

/// EzV2_TcpBothEndpointWay01_V2
template <ext::boost_asio0::EumeTcpEndpointSide V, typename T>                                //
/*Constructor*/ ext::boost_asio0::                                                            //
    EzV2_TcpBothEndpointWay01_V2<V, T>::                                                      //
    EzV2_TcpBothEndpointWay01_V2 (std::string_view server_host, std::string_view server_port) //
    : T (V, server_host, server_port), EzV2_TcpBothEndpoint_A (V, server_host, server_port)
{
}
