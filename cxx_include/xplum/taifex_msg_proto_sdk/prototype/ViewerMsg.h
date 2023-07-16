#pragma once
#include <span>
#include "xplum/prototype/Viewer.h"

#define MACRO_XPLUM_PROTOTYPE_VIEWERMSGFIXSIZE_DEPLOY_SUBCLASS(PARAM01_SUBCLASS_NAME) \
	explicit PARAM01_SUBCLASS_NAME(T& data)                                           \
		: ViewerMsgFixSize(data){};                                                   \
	explicit PARAM01_SUBCLASS_NAME(void* data)                                        \
		: ViewerMsgFixSize(*reinterpret_cast<T*>(data)){};                            \
	//


namespace xplum::taifex_msg_proto_sdk::prototype
{
	namespace define0
	{
		using xplum::prototype::Viewer;
	}

	template<typename TYPENAME_T>
	class ViewerMsgFixSize;

	template<typename TYPENAME_T>
	class ViewerMsgZipSize;
}

template<typename TYPENAME_T>
class xplum::taifex_msg_proto_sdk::prototype::ViewerMsgFixSize : public define0::Viewer<TYPENAME_T>
{
  public:
	using T = TYPENAME_T;
	static const std::size_t M_DATA_SIZE = sizeof(T);
	explicit ViewerMsgFixSize(T& data);
	std::span<const std::byte, M_DATA_SIZE> data_span();
};

template<typename TYPENAME_T>
class xplum::taifex_msg_proto_sdk::prototype::ViewerMsgZipSize : public define0::Viewer<TYPENAME_T>
{
  public:
	static const std::size_t M_DATA_MAX_SIZE = sizeof(TYPENAME_T);
	using T = TYPENAME_T;
	const std::size_t m_data_size;
	explicit ViewerMsgZipSize(T& data, std::size_t data_size);
	std::span<const std::byte> data_span();
};

// ******************************** ******************************** ******************************** ******************************** //
// ViewerMsgFixSize
template<typename TP01>
xplum::taifex_msg_proto_sdk::prototype::ViewerMsgFixSize<TP01>::ViewerMsgFixSize(T& data)
	: define0::Viewer<T>(data)
{
}

template<typename TP01>
auto xplum::taifex_msg_proto_sdk::prototype::ViewerMsgFixSize<TP01>::data_span() -> std::span<const std::byte, M_DATA_SIZE>
{
	return std::span<const std::byte, M_DATA_SIZE>(reinterpret_cast<const std::byte*>(&this->m_data), M_DATA_SIZE);
}

// ViewerMsgVariableSize
template<typename TP01>
xplum::taifex_msg_proto_sdk::prototype::ViewerMsgZipSize<TP01>::ViewerMsgZipSize(T& data, std::size_t data_size)
	: define0::Viewer<T>(data)
	, m_data_size(data_size)
{
	assert(M_DATA_MAX_SIZE >= data_size);
}

template<typename TP01>
auto xplum::taifex_msg_proto_sdk::prototype::ViewerMsgZipSize<TP01>::data_span() -> std::span<const std::byte>
{
	return std::span<const std::byte>{reinterpret_cast<const std::byte*>(&this->m_data), m_data_size};
}
