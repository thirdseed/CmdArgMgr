# CmdArgMgr

## Description
A light-weight command-line argument manager in C++ for command-line based tools. Determines possible arguments at compile-time, and manages their usage during runtime.

:warning: **This is currently a pre-release**, and supports only single characters arguments under the assumption that the system processes data as ASCII text. Later releases feature more robust handling, including words and numbers.

See section [Important Notes](#important-notes) for details.

## Table of Contents
- [Important Notes](#important-notes)
- [Installation](#installation)
- [Usage - Examples, Samples](#usage---examples-samples)

## Important Notes

**The version of the project currently committed is in pre-release**, meaning it currently lacks several key features.

- At this time, only single-character arguments are supported, and assumes the current system (OS, hardware, etc.) uses ASCII encoding.
- Can be used alongside other command-argument libraries - simply defer to this library when dealing with single characers.

Features that have not yet been committed include support for string and number arguments, special handling for non-ASCII systems, and an optional wrapper class to intake all of these simultaneously.

Please note that documentation, usage, examples, and sampel are currently not complete.

## Installation

1. Clone the repository.
2. Places items in the `/include/` directory into your project.

## Usage - Examples, Samples

**0. Usage Notes**

Can and should be instanced multiple times per argument group.

For example, command-line program that expects inputs like this:

`/path/to/files -u -C -L /output/path/ -A -k`

...would ideally need two instances of the below - one to handle the arguments pertaining to the "path to" handling (to assess `-u -C -L`), and another for the "output" argument handling (to assess `-A -k`).

**1. Pre-define and register a set of possible arguments**

Register them via the `registerConfigItem` function of `CmdArgMgr_Char`:

- Expects both the set of possible arguments and the `CmdArgMgr_Char` object to be `constexpr`. This enables the determination as to what command(s) are valid to be made at compile-time.
- Use ths static function `CmdArgMgr_Char::argToId` to convert a character to a format understood by the argument manager.

In all, the insertion of a command represented by the letter `u` may look like the following:
```cpp
CmdArgMgr_Char argMgr();
argMgr.registerConfigItem(CmdArgMgr_Char::argToId('u'));
```

The manager now recognizes the letter `u` as a valid argument.


**2. Enable options during runtime**

Now that the program is aware of which arguments are valid pre-compliation, we can now assess arguments during runtime.

Using the `enableOption` function of `CmdArgMgr_Char` to mark an option as enabled, like so:

```cpp
unsigned char example_arg_s = 's';
unsigned char example_arg_u = 'u';
argMgr.enableOption(CmdArgMgr_Char::argToId(example_arg_s));
```

The return value of `enableOption` will be `true` if the option was previously registered via `registerConfigItem` at compile-time, and will be false otherwise.


**3. Check options during runtime**

Use the `isOptionEnabled` function of `CmdArgMgr_Char` to determine if an option has been previously enabled:

```cpp
if (argMgr.isOptionEnabled(CmdArgMgr_Char::argToId('s')))
{
	/// ... do something
}
```

### Examples

**TBD**

### Samples

**TBD**, featured project is not yet live.

## License

MIT License