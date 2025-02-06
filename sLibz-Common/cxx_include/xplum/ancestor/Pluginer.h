#pragma once
#

namespace xplum::ancestor
{
template <typename TYPE_subclass, typename TYPE_subclass_core>
class Pluginer;
}

template <typename TYPE_subclass, typename TYPE_subclass_core>
class                 //
    xplum::ancestor:: //
    Pluginer
{
  protected:
    TYPE_subclass_core *const thiz = static_cast<TYPE_subclass_core *>(static_cast<TYPE_subclass *>(this));
};
