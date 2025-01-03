#ifndef COMMANDARGMGR_CHAR_HPP
#define COMMANDARGMGR_CHAR_HPP

#include <cstdint>
#include "CmdArgMgr.hpp"

/**
 * \brief A specialization of `CmdArgMgr` for `unsigned char` and `uint8_t`.
 *
 * An instantiable child of `CmdArgMgr` for processing single-character command
 * arguments. Collects and defines data and functions related to the handling of
 * single-character command arguments.
 * 
 * \par
 * Acts as an intermediary step for the templated class `CmdArgMgr_Char`; gives a
 * valid pointer-type when we've yet to determine its templated type(s).
 * \n(For more details, see the documentation for \ref CmdArgMgr_Char.)
 * 
 * \note
 * This class is a specialization of `CmdArgMgr` with pre-defined template arguments.
 * \n(For more details, see the documentation for \ref CmdArgMgr.)
 */
class CmdArgMgr_Char : public CmdArgMgr<CmdArgMgr_Char, unsigned char, uint8_t>
{
	public:
		// Forward type aliases

		constexpr CmdArgMgr_Char();

		/**
		 * \internal
		 * \brief Psuedo-private. Converts an input `unsigned char` into
		 * a unique `uint8_t` ID..
		 *
		 * \param arg Command-argument to format as ID.
		 *
		 * \return The input command argument formatted as an ID.
		 *
		 * \attention This aliased-function is intended only to be called
		 * by a parent function.
		 */
		static constexpr CmdArgIdType _argToId(const CmdArgType& arg);

		/**
		 * \internal
		 * \brief Psuedo-private. Registers a config ID as valid.
		 *
		 * Registers a command-argument into a repository of command-arguments
		 * we're allowed to use (assuring it is a valid command-argument - a
		 * prerequisite to enabling options).
		 *
		 * \param id Command-argument ID to register as set.
		 * 
		 * \note Not to be confused with `_enableOption`, which is intended
		 * to set an argument as currently in-use.
		 *
		 * \attention This aliased-function is intended only to be called
		 * by a parent function.
		 */
		constexpr void _registerConfigItem(const CmdArgIdType& id);

		/**
		 * \brief Psuedo-private. Given an argument ID, enables an option.
		 *
		 * \param id Command-argument ID to enable.
		 *
		 * \return If whether the option exists as registered and was
		 * successfully enabled.
		 *
		 * \note Not to be confused with `_registerConfigItem`, which is
		 * intended signify that an argument is recognized by our program.
		 * 
		 * \attention This aliased-function is intended only to be called
		 * by a parent function.
		 */
		bool _enableOption(const CmdArgIdType& id);

		 /**
		 * \internal
		 * \brief Psuedo-private. Given an argument ID, determines if
		 * whether an option is enabled or not.
		 *
		 * \param id Command-argument ID to check.
		 *
		 * \return If whether the option is enabled or not.
		 * 
		 * \attention This aliased-function is intended only to be called
		 * by a parent function.
		 */
		bool _isOptionEnabled(const CmdArgIdType& id) const;

	protected:
		// May be initialized through constexpr function/constructor; but explicitly mutable, as options may are set during runtime
		mutable uint64_t enabled_options;

	private:
		//  Must be initialized through constexpr function/constructor; immutable, as known options are pre-determined
		uint64_t valid_options;

		/**
		 *\breif Creates a 64-bit number where `1` is set at a given bit position.
		 * 
		 * \param id The bit position at which to set `1`.
		 * 
		 * \return A 64-bit number where `1` is set at the given position.
		 */
		constexpr uint64_t idTo64BitIdx(const CmdArgIdType& id) const;

		/**
		 *\breif Given a 64-bit number and bit position, sets a bit to `1` at the given bit
		 * position.
		 * 
		 * \param bitmask The bitmask to modify.
		 * \param id The position of the bit to set within the given bit mask.
		 * 
		 */
		inline void setBit(uint64_t& bitmask, const CmdArgIdType& id);

		/**
		 * \brief Given a 64-bit number and bit position, determines if a bit to `1` at
		 * the given bit position.
		 *
		 * \param bitmask The bitmask to check.
		 * \param id The position of the bit to check for within the given bit mask.
		 * 
		 * \return If whether a bit is set or not.
		 */
		inline bool isBitSet(const uint64_t& bitmask, const CmdArgIdType& id) const;
};

// Include template implementation
#include "CmdArgMgr_Char.inl"

#endif // COMMANDARGMGR_CHAR_HPP