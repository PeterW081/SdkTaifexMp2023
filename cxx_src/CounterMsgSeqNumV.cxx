#include "xplum/taifex_msg_proto_sdk/prototype/CounterMsgSeqNumV.h"
using xplum::taifex_msg_proto_sdk::prototype::CounterMsgSeqNumV;

auto CounterMsgSeqNumV::next() -> const std::uint32_t&
{
	auto write_lock = std::unique_lock(m_mutex_read_write);
	this->m_data++;
	return this->m_data;
}

auto CounterMsgSeqNumV::peek() const -> const std::uint32_t&
{
	auto read_lock = std::shared_lock(m_mutex_read_write);
	return this->m_data;
}
