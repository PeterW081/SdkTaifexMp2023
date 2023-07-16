#pragma once
#include "xplum/prototype/ViewerViaEnumToInteger.h"
#include "xplum/taifex_msg_proto/message_field/msg_field_enumerate.h"


namespace xplum::taifex_msg_proto_sdk::view::message_field::enumerate
{
	namespace define0
	{
		using xplum::prototype::ViewerViaEnumToInteger;
		using namespace xplum::taifex_msg_proto::message_field;
	}
	namespace raw = xplum::taifex_msg_proto::message_field::enumerate;

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

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::MsgType : public define0::ViewerViaEnumToInteger<raw::MessageType, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(MsgType);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::SystemType : public define0::ViewerViaEnumToInteger<raw::system_type, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(SystemType);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::EncryptMethod : public define0::ViewerViaEnumToInteger<raw::EncryptMethod, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(EncryptMethod);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::IsEof : public define0::ViewerViaEnumToInteger<raw::is_eof, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(IsEof);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::SubscriptionRequestType : public define0::ViewerViaEnumToInteger<raw::SubscriptionRequestType, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(SubscriptionRequestType);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::TradeStatus : public define0::ViewerViaEnumToInteger<raw::TradeStatus, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(TradeStatus);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::ExecType : public define0::ViewerViaEnumToInteger<raw::ExecType, define0::char0>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(ExecType);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::SymbolType : public define0::ViewerViaEnumToInteger<raw::symbol_type, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(SymbolType);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::Side : public define0::ViewerViaEnumToInteger<raw::Side, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(Side);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::OrderType : public define0::ViewerViaEnumToInteger<raw::OrdType, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(OrderType);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::TimeInForce : public define0::ViewerViaEnumToInteger<raw::TimeInForce, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(TimeInForce);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::PositionEffect : public define0::ViewerViaEnumToInteger<raw::PositionEffect, define0::char0>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(PositionEffect);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::OrderSource : public define0::ViewerViaEnumToInteger<raw::order_source, define0::char0>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(OrderSource);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::LegSide : public define0::ViewerViaEnumToInteger<raw::leg_side, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(LegSide);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::TargetId : public define0::ViewerViaEnumToInteger<raw::target_id, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(TargetId);
};

class xplum::taifex_msg_proto_sdk::view::message_field::enumerate::ProtocolType : public define0::ViewerViaEnumToInteger<raw::protocol_type, define0::uint8>
{
  public:
	MACRO_XPLUM_PROTOTYPE_VIEWERVIAENUMTOINTEGER_DEPLOY_SUBCLASS(ProtocolType);
};
