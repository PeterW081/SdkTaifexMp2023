#pragma once
#include <shared_mutex>
#include "xplum/ablething/StorageAbleV.h"
#include "xplum/taifex_msg_proto_sdk/define.h"

namespace xplum::taifex_msg_proto_sdk::prototype
{
	class CounterMsgSeqNumV;
}

class xplum::taifex_msg_proto_sdk::prototype::CounterMsgSeqNumV : public xplum::ablething::StorageAbleV::StorageAbleV
{
  public:
	using TypeMsgSeqNum = type::uint32;
	virtual ~CounterMsgSeqNumV() = default;
	virtual const type::uint32& peek() const final;
	virtual const type::uint32& next() final;

  protected:
	mutable std::shared_mutex m_mutex_read_write;
	type::uint32 m_data = 0;
	bool storage_save0(std::nullptr_t melon, ...) const override = 0;
	bool storage_load0(std::nullptr_t melon, ...) override = 0;
};
