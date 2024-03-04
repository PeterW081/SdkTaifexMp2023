#pragma once
#include <iostream>
#include <unordered_map>
#include <typeindex>

namespace xplum::ablething {
class GlobalAble;
}

class xplum::ablething::GlobalAble {
  static inline GlobalAble *M_NULLPTR = nullptr;
  static inline std::unordered_map<std::type_index, GlobalAble *> M_GLOBAL_POOL;
  template <typename TYPENAME_T> static consteval bool StaticAssert();

protected:
  GlobalAble() = default;

public:
  template <typename TYPENAME_T> static TYPENAME_T *const Get();
  template <typename TYPENAME_T> static TYPENAME_T *const &Set(std::unique_ptr<TYPENAME_T> &&ptr, const std::string &error_log_text = "");
  template <typename TYPENAME_T> static TYPENAME_T *const &Init();
  template <typename TYPENAME_T> static void Release();
};

template <typename TYPENAME_T> consteval bool xplum::ablething::GlobalAble::StaticAssert() {
  static_assert(std::is_base_of<GlobalAble, TYPENAME_T>::value);
  static_assert(std::is_convertible<TYPENAME_T *, GlobalAble *>::value);
  return true;
}

template <typename TYPENAME_T> auto xplum::ablething::GlobalAble::Get() -> TYPENAME_T *const {
  static_assert(StaticAssert<TYPENAME_T>());

  auto key = std::type_index(typeid(TYPENAME_T));
  GlobalAble *const value = M_GLOBAL_POOL.contains(key) ? M_GLOBAL_POOL.at(key) : nullptr;
  return reinterpret_cast<TYPENAME_T *const>(value);
}

template <typename TYPENAME_T> auto xplum::ablething::GlobalAble::Set(std::unique_ptr<TYPENAME_T> &&ptr, const std::string &error_log_text) -> TYPENAME_T *const & {
  static_assert(StaticAssert<TYPENAME_T>());

  auto key = std::type_index(typeid(TYPENAME_T));
  GlobalAble *&value_reference = M_GLOBAL_POOL[key];
  if (value_reference != nullptr) {
    if (!error_log_text.empty()) {
      std::cerr << error_log_text << std::endl;
    }
    assert(!(M_GLOBAL_POOL[typeid(TYPENAME_T)] != nullptr));
    return reinterpret_cast<TYPENAME_T *const &>(value_reference);
  }
  value_reference = ptr.release();
  return reinterpret_cast<TYPENAME_T *const &>(value_reference);
}

template <typename TYPENAME_T> auto xplum::ablething::GlobalAble::Init() -> TYPENAME_T *const & {
  static_assert(StaticAssert<TYPENAME_T>());

  GlobalAble *const &value_reference = M_GLOBAL_POOL[typeid(TYPENAME_T)];
  return reinterpret_cast<TYPENAME_T *const &>(value_reference);
}

template <typename TYPENAME_T> void xplum::ablething::GlobalAble::Release() {
  static_assert(StaticAssert<TYPENAME_T>());

  auto key = std::type_index(typeid(TYPENAME_T));
  GlobalAble *&value_reference = M_GLOBAL_POOL.contains(key) ? M_GLOBAL_POOL.at(key) : M_NULLPTR;
  if (value_reference != nullptr) {
    delete value_reference;
    value_reference = nullptr;
  }
}
