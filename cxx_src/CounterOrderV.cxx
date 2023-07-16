#include "xplum/taifex_msg_proto_sdk/prototype/CounterOrderSeqV.h"
using xplum::taifex_msg_proto_sdk::prototype::CounterOrderSeqV;

auto CounterOrderSeqV::next_order_no() -> const type::uint32&
{
	auto write_lock = std::unique_lock(m_mutex_read_write);
	this->m_order_no++;
	while(!this->m_map_K_order_no_V_order_id.contains(this->m_order_no))
	{
		this->m_order_no++;
	}
	this->m_map_K_order_no_V_order_id[this->m_order_no] = 0;
	return this->m_order_no;
}

auto CounterOrderSeqV::peek_order_no() const -> const type::uint32&
{
	auto read_lock = std::shared_lock(m_mutex_read_write);
	return this->m_order_no;
}

auto CounterOrderSeqV::next_order_id(type::uint32 order_no) -> const type::uint32&
{
	auto write_lock = std::unique_lock(m_mutex_read_write);
	type::uint32& order_id = this->m_map_K_order_no_V_order_id[order_no];
	order_id++;
	return order_id;
}

auto CounterOrderSeqV::peek_order_id(type::uint32 order_no) const -> const type::uint32&
{
	auto read_lock = std::shared_lock(m_mutex_read_write);
	return this->m_map_K_order_no_V_order_id.at(order_no);
}
