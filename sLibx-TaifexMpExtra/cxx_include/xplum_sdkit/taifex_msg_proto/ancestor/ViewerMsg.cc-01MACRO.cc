#pragma once
#include "./ViewerMsg.h"
#pragma
#

#define MACRO_XPLUM_0_VIEWERMSGFIXSIZE_0_MEMBER(PARAM01_SUBCLASS_NAME)                                                                                                                                                                                         \
    static auto FX_init_msg(std::span<std::byte> buffer) -> PARAM01_SUBCLASS_NAME                                                                                                                                                                              \
    {                                                                                                                                                                                                                                                          \
        ViewerMsg::FX_init_msg(buffer, std::nullopt);                                                                                                                                                                                                          \
        return PARAM01_SUBCLASS_NAME(buffer);                                                                                                                                                                                                                  \
    }                                                                                                                                                                                                                                                          \
    explicit PARAM01_SUBCLASS_NAME(TypeMsgData &data) : ViewerMsg(data, std::nullopt){};                                                                                                                                                                       \
    explicit PARAM01_SUBCLASS_NAME(std::span<std::byte> buffer) : ViewerMsg(buffer, std::nullopt){};                                                                                                                                                           \
    /**/
