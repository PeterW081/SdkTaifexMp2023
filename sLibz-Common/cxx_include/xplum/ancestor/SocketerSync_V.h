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
    virtual auto fv_is_ready() const -> bool = 0;
    virtual auto fv_write_sync(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;
    virtual auto fv_reade_sync(std::span<std::byte>, std::optional<std::chrono::seconds> = std::nullopt) -> std::size_t = 0;
    virtual auto fv_start_sync(std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;
    virtual auto fv_close_sync(std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;
    virtual auto fv_reset_sync(std::optional<std::chrono::seconds> = std::nullopt) -> bool = 0;
    virtual auto fv_xxxxx_sync_cancel() -> void = 0;

  protected:
    explicit SocketerSync_V() = default;
};
