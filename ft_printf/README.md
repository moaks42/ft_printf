*This project has been created as part of the 42 curriculum by moaks.*

# ft_printf

## Description

`ft_printf` is a custom re-implementation of the C standard library's `printf()`
function, built as a static library (`libftprintf.a`). The goal of the project is
to understand and reproduce the behavior of a variadic function, i.e. a function
that can accept a variable number of arguments of different types, and to convert
those arguments into formatted output written to standard output.

This implementation does **not** manage its own output buffering (each character
is written directly with `write`), and it handles the mandatory set of format
conversions defined by the subject:

| Conversion | Description                                   |
|------------|------------------------------------------------|
| `%c`       | Prints a single character                      |
| `%s`       | Prints a string                                 |
| `%p`       | Prints a `void *` pointer in hexadecimal        |
| `%d`       | Prints a decimal (base 10) signed number        |
| `%i`       | Prints a decimal (base 10) signed integer       |
| `%u`       | Prints an unsigned decimal (base 10) number     |
| `%x`       | Prints a number in hexadecimal (lowercase)      |
| `%X`       | Prints a number in hexadecimal (uppercase)      |
| `%%`       | Prints a literal `%`                            |
| `%f`       | Prints a double, float                           |

Flags, field width, and precision (the bonus part of the subject) are not
implemented in this version - only the mandatory conversions listed above are
supported.

## Instructions

### Compilation

The project is compiled into a static library using the provided `Makefile`:

```bash
make        # builds libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and the library
make re     # fclean + all
```

This produces `libftprintf.a` at the root of the project, built with `ar -rc`
and compiled with `-Wall -Wextra -Werror`.

### Usage

To use `ft_printf` in your own project, include the header and link the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    return (0);
}
```

Compile and link against the library, for example:

```bash
cc main.c -L. -lftprintf -o my_program
```

`ft_printf` follows the same prototype as the original `printf`:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters written, just like the original function.

## Algorithm and data structure

No dynamic data structure (list, array, etc.) is required for this project,
since output is produced and written character by character as the format
string is parsed - there is no need to accumulate the result in memory.

The implementation is organized around three main ideas:

1. **Parsing loop (`ft_printf`)** - The format string is scanned one character
   at a time. Regular characters are written directly. When a `%` is
   encountered, the next character is treated as a conversion specifier and
   dispatched to a dedicated handler.

2. **Specifier dispatch (`ft_specifier`)** - A single function maps each
   supported conversion character (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`)
   to the appropriate `va_arg` extraction and output helper. This keeps the
   parsing loop simple and makes it straightforward to add new conversions.

3. **Output helpers** - Small, single-purpose functions handle the actual
   formatting:
   - `ft_putchar` / `ft_putstr` write characters and strings via `write(2)`,
     and `ft_putstr` prints `"(null)"` when given a `NULL` pointer, matching
     glibc's behavior.
   - `ft_putnbr` recursively prints signed decimal numbers (handling the
     negative sign separately before recursing on the absolute value).
   - `ft_puthex` / `ft_unsigned_hex` recursively convert a number to any base
     (16 for hex, 10 for `%u`) by dividing the value and printing digits from
     a lookup string (`"0123456789abcdef"` or its uppercase counterpart),
     which lets `%x`, `%X` and `%u` share the same base-conversion logic.
   - `ft_pointer` prints the `0x` prefix followed by the pointer's address in
     hexadecimal, or `"(nil)"` for a `NULL` pointer.

Recursion was chosen for the number-printing functions because it naturally
prints digits in the correct (most-significant-first) order without needing
to build a temporary string/array and reverse it - each call prints the
higher-order digits before returning to print the current digit.

Every helper returns the number of characters it wrote, and these counts are
summed up through `ft_specifier` and the main loop so that `ft_printf` can
return the total number of characters printed, mirroring the return value of
the original `printf`.

## Resources

- [`printf(3)` - Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C variadic functions (`stdarg.h`) - cppreference](https://en.cppreference.com/w/c/variadic)
- 42 Norm documentation (campus intranet)

### AI usage

An AI assistant (Claude) was used only to generate this `README.md` file -
formatting the project description, usage instructions, and the
algorithm/data-structure write-up based on the existing source code. The
`ft_printf` implementation itself (parsing logic, specifier handling, and all
output helper functions) was written without AI assistance.
