#pragma once
#include <map>
#include <set>
#include <shared_mutex>
#include "xplum/ablething/StorageAbleV.h"
#include "xplum/taifex_msg_proto_sdk/define.h"

namespace xplum::taifex_msg_proto_sdk::prototype
{
	class CounterOrderSeqV;
}

class xplum::taifex_msg_proto_sdk::prototype::CounterOrderSeqV : public xplum::ablething::StorageAbleV::StorageAbleV
{
  public:
	using TypeOrderNo = type::uint32;
	using TypeOrderId = type::uint32;
	virtual ~CounterOrderSeqV() = default;
	virtual const type::uint32& next_order_no() final;
	virtual const type::uint32& peek_order_no() const final;
	virtual const type::uint32& next_order_id(type::uint32 order_no) final;
	virtual const type::uint32& peek_order_id(type::uint32 order_no) const final;

  protected:
	mutable std::shared_mutex m_mutex_read_write;
	type::uint32 m_order_no = 0;
	std::map<type::uint32, type::uint32> m_map_K_order_no_V_order_id;
	bool storage_save0(std::nullptr_t melon, ...) const override = 0;
	bool storage_load0(std::nullptr_t melon, ...) override = 0;
};
