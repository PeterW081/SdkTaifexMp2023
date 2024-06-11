#pragma once
#include "boost0/asio/EzV2_TcpBothEndpoint_A.h"

namespace ext::boost_asio0 {
template <EumeTcpEndpointSide, typename> class EzV2_TcpBothEndpointWay01_V2;
}

template <ext::boost_asio0::EumeTcpEndpointSide V, typename T> //
class                                                          //
    ext::boost_asio0 ::                                        //
    EzV2_TcpBothEndpointWay01_V2                               //
    : public T {
  static_assert(std::is_base_of_v<EzV2_TcpBothEndpoint_A, T>);
  static_assert(false                               //
                || V == EumeTcpEndpointSide::CLIENT //
                || V == EumeTcpEndpointSide::SERVER //
  );

public:
  explicit EzV2_TcpBothEndpointWay01_V2() = delete;
  explicit EzV2_TcpBothEndpointWay01_V2(std::string_view, std::string_view); // host, port,
};
