#ifndef COMMANDARGMGR_CHAR_TPP
#define COMMANDARGMGR_CHAR_TPP

// Ensure the parser knows about the symbols defined in CmdArgMgr_Char.hpp
#include "CmdArgMgr_Char.hpp"

constexpr CmdArgMgr_Char::CmdArgMgr_Char() : valid_options(0), enabled_options(0) {}

constexpr CmdArgMgr_Char::CmdArgIdType CmdArgMgr_Char::_argToId(const CmdArgType& arg)
{
	return arg - (arg <= 'A' ? 'A' : 'a');
}

bool CmdArgMgr_Char::_enableOption(const CmdArgIdType& id)
{
	bool isValidOption = isBitSet(valid_options, id);

	if (isValidOption)
	{
		enabled_options |= (static_cast<uint64_t>(1) << id);
	}

	return isValidOption;
}

bool CmdArgMgr_Char::_isOptionEnabled(const CmdArgIdType& id) const
{
	return isBitSet(enabled_options, id);
}

constexpr void CmdArgMgr_Char::_registerConfigItem(const CmdArgIdType& id)
{
	valid_options |= (static_cast<uint64_t>(1) << id);
}

constexpr uint64_t CmdArgMgr_Char::idTo64BitIdx(const CmdArgIdType& id) const
{
	return (static_cast<uint64_t>(1) << id);
}

inline void CmdArgMgr_Char::setBit(uint64_t& bitmask, const CmdArgIdType& id)
{
	bitmask |= idTo64BitIdx(id);//(static_cast<uint64_t>(1) << id);
}

inline bool CmdArgMgr_Char::isBitSet(const uint64_t& bitmask, const CmdArgIdType& id) const
{
	return (bitmask & idTo64BitIdx(id));
	//return (bitmask & (static_cast<uint64_t>(1) << id));
}

#endif // COMMANDARGMGR_CHAR_TPP