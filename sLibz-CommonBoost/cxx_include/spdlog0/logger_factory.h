#pragma once
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace ext::spdlog0
{
template <typename T>
extern auto FX_logger_factory(T *) -> std::unique_ptr<spdlog::logger>;
}

///
template <typename T>
extern auto ext::spdlog0::FX_logger_factory(T *ptr) -> std::unique_ptr<spdlog::logger>
{
    auto logger_name = std::to_string(reinterpret_cast<std::intptr_t>(ptr)) + "-" + typeid(ptr).name();
    auto logger = std::make_unique<spdlog::logger>(logger_name, std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    logger->set_pattern("%v");
    logger->set_level(spdlog::level::level_enum::info);
    return logger;
}
