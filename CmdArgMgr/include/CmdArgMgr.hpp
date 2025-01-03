#ifndef COMMANDARGMGR_HPP
#define COMMANDARGMGR_HPP

/**
 * \brief Basis for Argument Manager types.
 *
 * This function swaps the values of two variables of any type.
 *
 * \tparam Derived The child class on which to base CRTP-like pattern.
 * \tparam CmdArgInputT The base-type of a command-argument.
 * \tparam CmdArgT The base-type of a command-argument's ID.
 * 
 * \note The term "command-argument" is used to avoid confusion with the term "argument" in programming contexts.
 * 
 * \attention This class is not meant to be directly instantiable. Use only as a parent for other classes.
 */
template <typename Derived, typename CmdArgT, typename CmdArgIdT>
class CmdArgMgr
{
	public:
		using CmdArgType = CmdArgT;
		using CmdArgIdType = CmdArgIdT;

	    /**
	     * \brief Formats an input command argument as an ID.
		 * 
		 * An alias for the derived class' `_argToId` static function,
		 * intended to convert a commmand-argument of the `CmdArgT` type
		  into a trackable/unique indexed value of the `CmdArgIdT` type.
		 * 
		 * \param arg Command-argument to format as ID.
		 * 
		 * \return The input command argument formatted as an ID.
		 */
		static constexpr CmdArgIdT argToId(const CmdArgT& arg);

		/**
		 * Registers a config ID as valid.
		 *
		 * An alias for the derived class' `_registerConfigItem` function,
		 * intended to register a command-argument into a repository of
		 * command-arguments we're allowed to use (assuring it is a valid
		 * command-argument - a prerequisite to enabling options).
		 *
		 * \param id Command-argument ID to register as set.
		 * 
		 * \note Not to be confused with `enableOption`, which is intended
		 * to set an argument as currently in-use.
		 */
		constexpr void registerConfigItem(const CmdArgIdT& id);

		/**
		 * \brief Given an argument ID, enables an option.
		 *
		 * An alias for the derived class' `_enabledOption` function,
		 * intended to enable an option, and determine if whether that
		 * option exists and can be enabled.
		 *
		 * \param id Command-argument ID to enable.
		 *
		 * \return If whether the option exists as registered and was
		 * successfully enabled.
		 * 
		 * \note Not to be confused with `registerConfigItem`, which is
		 * intended signify that an argument is recognized by our program.
		 */
		bool enableOption(const CmdArgIdT& id);

		/**
		 * \brief Given an argument ID, determines if whether an option is
		 * enabled or not.
		 *
		 * An alias for the derived class' `_isOptionEnabled` function,
		 * intended to determine if whether an option is enabled or not.
		 *
		 * \param id Command-argument ID to check.
		 *
		 * \return If whether the option is enabled or not.
		 */
		bool isOptionEnabled(const CmdArgIdT& id);

	protected:
		constexpr CmdArgMgr() {}
};

// Include template implementation
#include "CmdArgMgr.inl"

#endif //COMMANDARGMGR_HPP