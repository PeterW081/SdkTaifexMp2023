#pragma once

namespace xplum::ablething
{
class StorageAble_V;
}

class xplum::ablething::StorageAble_V
{
  public:
    template <typename TYPE, typename RETURN, typename... PARAM>
    static bool STORAGE_SAVE(RETURN (TYPE::*func)(PARAM...) const, StorageAble_V *ptr, PARAM... param);
    template <typename TYPE, typename RETURN, typename... PARAM>
    static bool STORAGE_LOAD(RETURN (TYPE::*func)(PARAM...), StorageAble_V *ptr, PARAM... param);

  protected:
    // StorageAbleV() = default;
    virtual bool storage_save0(std::nullptr_t melon, ...) const = 0;
    virtual bool storage_load0(std::nullptr_t melon, ...) = 0;
};

template <typename TYPE, typename RETURN, typename... PARAM>
bool xplum::ablething::StorageAble_V::STORAGE_SAVE(RETURN (TYPE::*)(PARAM...) const, StorageAble_V *ptr, PARAM... param)
{
    static_assert(std::is_base_of<StorageAble_V, TYPE>::value);
    return ptr->storage_save0(nullptr, param...);
}

template <typename TYPE, typename RETURN, typename... PARAM>
bool xplum::ablething::StorageAble_V::STORAGE_LOAD(RETURN (TYPE::*)(PARAM...), StorageAble_V *ptr, PARAM... param)
{
    static_assert(std::is_base_of<StorageAble_V, TYPE>::value);
    return ptr->storage_load0(nullptr, param...);
}
