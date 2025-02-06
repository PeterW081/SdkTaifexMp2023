#pragma once

namespace xplum::ablething
{
class StorageAble_V;
}

class xplum::ablething::StorageAble_V
{
  public:
    template <typename TYPE, typename RETURN, typename... PARAM>
    static bool FX_storage_save(RETURN (TYPE::*func)(PARAM...) const, StorageAble_V *ptr, PARAM... param);
    template <typename TYPE, typename RETURN, typename... PARAM>
    static bool FX_storage_load(RETURN (TYPE::*func)(PARAM...), StorageAble_V *ptr, PARAM... param);

  protected:
    // StorageAbleV() = default;
    virtual bool fv_storage_save0(std::nullptr_t melon, ...) const = 0;
    virtual bool fv_storage_load0(std::nullptr_t melon, ...) = 0;
};

template <typename TYPE, typename RETURN, typename... PARAM>
bool xplum::ablething::StorageAble_V::FX_storage_save(RETURN (TYPE::*)(PARAM...) const, StorageAble_V *ptr, PARAM... param)
{
    static_assert(std::is_base_of<StorageAble_V, TYPE>::value);
    return ptr->fv_storage_save0(nullptr, param...);
}

template <typename TYPE, typename RETURN, typename... PARAM>
bool xplum::ablething::StorageAble_V::FX_storage_load(RETURN (TYPE::*)(PARAM...), StorageAble_V *ptr, PARAM... param)
{
    static_assert(std::is_base_of<StorageAble_V, TYPE>::value);
    return ptr->fv_storage_load0(nullptr, param...);
}
