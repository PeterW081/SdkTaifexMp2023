#pragma once
#include "xplum/ancestor/ViewerViaEnumToInteger.h"
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field.h"
#include "xplum_model/taifex_msg_proto/structure_message_field/msg_field_enumerate.h"

namespace xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::_nshdr
{
using xplum::ancestor::ViewerViaEnumToInteger;
using namespace xplum_model::taifex_msg_proto::message_field;
}

namespace xplum_sdkit::taifex_msg_proto::view::message_field::enumerate
{
namespace origin = xplum_model::taifex_msg_proto::message_field::enumerate;

// General
class MsgType;
class SystemType;
class EncryptMethod;
class IsEof;
class SubscriptionRequestType;
class TradeStatus;

// Re: Order
class ExecType;
class SymbolType;
class Side;
class OrderType;
class TimeInForce;
class PositionEffect;
class OrderSource;

// Re: Order - R02
class LegSide;
class TargetId;
class ProtocolType;

}

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::MsgType : public _nshdr::ViewerViaEnumToInteger<origin::MessageType, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (MsgType);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::SystemType : public _nshdr::ViewerViaEnumToInteger<origin::system_type, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (SystemType);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::EncryptMethod : public _nshdr::ViewerViaEnumToInteger<origin::EncryptMethod, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (EncryptMethod);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::IsEof : public _nshdr::ViewerViaEnumToInteger<origin::is_eof, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (IsEof);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::SubscriptionRequestType : public _nshdr::ViewerViaEnumToInteger<origin::SubscriptionRequestType, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (SubscriptionRequestType);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::TradeStatus : public _nshdr::ViewerViaEnumToInteger<origin::TradeStatus, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (TradeStatus);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::ExecType : public _nshdr::ViewerViaEnumToInteger<origin::ExecType, _nshdr::char0>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (ExecType);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::SymbolType : public _nshdr::ViewerViaEnumToInteger<origin::symbol_type, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (SymbolType);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::Side : public _nshdr::ViewerViaEnumToInteger<origin::Side, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (Side);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::OrderType : public _nshdr::ViewerViaEnumToInteger<origin::OrdType, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (OrderType);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::TimeInForce : public _nshdr::ViewerViaEnumToInteger<origin::TimeInForce, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (TimeInForce);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::PositionEffect : public _nshdr::ViewerViaEnumToInteger<origin::PositionEffect, _nshdr::char0>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (PositionEffect);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::OrderSource : public _nshdr::ViewerViaEnumToInteger<origin::order_source, _nshdr::char0>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (OrderSource);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::LegSide : public _nshdr::ViewerViaEnumToInteger<origin::leg_side, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (LegSide);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::TargetId : public _nshdr::ViewerViaEnumToInteger<origin::target_id, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (TargetId);
};

class xplum_sdkit::taifex_msg_proto::view::message_field::enumerate::ProtocolType : public _nshdr::ViewerViaEnumToInteger<origin::protocol_type, _nshdr::uint8>
{
public:
  MACRO_XPLUM_ANCESTOR_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS (ProtocolType);
};
