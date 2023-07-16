#pragma once

#define MACRO_XPLUM_PROTOTYPE_VIEWER_DEPLOY_SUBCLASS(PARAM01_SUBCLASS_NAME) \
	explicit PARAM01_SUBCLASS_NAME(T& data)                                 \
		: Viewer(data){};                                                   \
	explicit PARAM01_SUBCLASS_NAME(void* data)                              \
		: Viewer(*reinterpret_cast<T*>(data)){};                            \
	//

namespace xplum::prototype
{
	template<typename T>
	class Viewer;
}

template<typename TYPENAME_T>
class xplum::prototype::Viewer
{
  public:
	auto& data() const;

  protected:
	using T = TYPENAME_T;
	T& m_data;
	explicit Viewer(T& data);
};

// ******************************** ******************************** ******************************** ******************************** //
template<typename T>
xplum::prototype::Viewer<T>::Viewer(T& data)
	: m_data(data)
{
}

template<typename T>
auto& xplum::prototype::Viewer<T>::data() const
{
	return m_data;
}
