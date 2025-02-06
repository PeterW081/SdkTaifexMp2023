#pragma once
#include "xplum/ancestor/ViewerViaEnumToInteger.h"
#include "xplum_model/taifex_msg_proto/network_osi_L06/structure_msg_field/msg_field_enumerate.h"
#

namespace xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::_nshdr
{
using xplum::ancestor::ViewerViaEnumToInteger;
using namespace xplum_model::taifex_msg_proto::message_field;
}

namespace xplum_sdkit::taifex_msg_proto::view::message_field::enumerate
{
namespace model = xplum_model::taifex_msg_proto::message_field::enumerate;

// General
class MsgType_VIEW;
class SystemType_VIEW;
class EncryptMethod_VIEW;
class IsEof_VIEW;
class SubscriptionRequestType_VIEW;
class TradeStatus_VIEW;

// Re: Order
class ExecType_VIEW;
class SymbolType_VIEW;
class Side_VIEW;
class OrderType_VIEW;
class TimeInForce_VIEW;
class PositionEffect_VIEW;
class OrderSource_VIEW;

// Re: Order - R02
class LegSide_VIEW;
class TargetId_VIEW;
class ProtocolType_VIEW;

}

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::MsgType_VIEW : public _nshdr::ViewerViaEnumToInteger<model::MessageType, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(MsgType_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::SystemType_VIEW : public _nshdr::ViewerViaEnumToInteger<model::system_type, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(SystemType_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::EncryptMethod_VIEW : public _nshdr::ViewerViaEnumToInteger<model::EncryptMethod, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(EncryptMethod_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::IsEof_VIEW : public _nshdr::ViewerViaEnumToInteger<model::is_eof, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(IsEof_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::SubscriptionRequestType_VIEW : public _nshdr::ViewerViaEnumToInteger<model::SubscriptionRequestType, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(SubscriptionRequestType_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::TradeStatus_VIEW : public _nshdr::ViewerViaEnumToInteger<model::TradeStatus, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(TradeStatus_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::ExecType_VIEW : public _nshdr::ViewerViaEnumToInteger<model::ExecType, _nshdr::char0>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(ExecType_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::SymbolType_VIEW : public _nshdr::ViewerViaEnumToInteger<model::symbol_type, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(SymbolType_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::Side_VIEW : public _nshdr::ViewerViaEnumToInteger<model::Side, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(Side_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::OrderType_VIEW : public _nshdr::ViewerViaEnumToInteger<model::OrdType, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(OrderType_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::TimeInForce_VIEW : public _nshdr::ViewerViaEnumToInteger<model::TimeInForce, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(TimeInForce_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::PositionEffect_VIEW : public _nshdr::ViewerViaEnumToInteger<model::PositionEffect, _nshdr::char0>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(PositionEffect_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::OrderSource_VIEW : public _nshdr::ViewerViaEnumToInteger<model::order_source, _nshdr::char0>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(OrderSource_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::LegSide_VIEW : public _nshdr::ViewerViaEnumToInteger<model::leg_side, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(LegSide_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::TargetId_VIEW : public _nshdr::ViewerViaEnumToInteger<model::target_id, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(TargetId_VIEW);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::ProtocolType_VIEW : public _nshdr::ViewerViaEnumToInteger<model::protocol_type, _nshdr::uint8>
{
  public:
    MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(ProtocolType_VIEW);
};
