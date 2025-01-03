#ifndef COMMANDARGMGR_TPP
#define COMMANDARGMGR_TPP

// Ensure the parser knows about the symbols defined in CmdArgMgr.hpp
#include "CmdArgMgr.hpp"

template <typename Derived, typename CmdArgT, typename CmdArgIdT>
constexpr CmdArgIdT CmdArgMgr<Derived, CmdArgT, CmdArgIdT>::argToId(const CmdArgT& arg)
{
	return Derived::_argToId(arg);
}

template<typename Derived, typename CmdArgT, typename CmdArgIdT>
inline constexpr void CmdArgMgr<Derived, CmdArgT, CmdArgIdT>::registerConfigItem(const CmdArgIdT& id)
{
	return static_cast<Derived*>(this)->_registerConfigItem(id);
}

template<typename Derived, typename CmdArgT, typename CmdArgIdT>
inline bool CmdArgMgr<Derived, CmdArgT, CmdArgIdT>::enableOption(const CmdArgIdT& id)
{
	return static_cast<Derived*>(this)->_enableOption(id);
}

template<typename Derived, typename CmdArgT, typename CmdArgIdT>
inline bool CmdArgMgr<Derived, CmdArgT, CmdArgIdT>::isOptionEnabled(const CmdArgIdT& id)
{
	return static_cast<Derived*>(this)->_isOptionEnabled(id);
}

#endif //COMMANDARGMGR_TPP