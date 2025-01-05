#pragma once
#include <chrono>
#include <span>
#include <optional>

namespace xplum::ancestor
{
class SocketerSync_V;
}

class xplum::ancestor::SocketerSync_V
{
  public:
    virtual ~SocketerSync_V() = default;
    explicit SocketerSync_V(const SocketerSync_V &) = delete;
    auto operator=(const SocketerSync_V &) -> SocketerSync_V & = delete;

  public:
    virtual auto fv_reade(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;
    virtual auto fv_write(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;
    virtual auto fv_start(std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;
    virtual auto fv_close(std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;
    virtual auto fv_reset(std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;

  protected:
    explicit SocketerSync_V() = default;
};
