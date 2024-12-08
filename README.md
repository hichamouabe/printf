# ft_printf - Custom Implementation of C `printf`

`ft_printf` is a reimplementation of the standard C library function `printf`. This project provides a deep dive into variadic functions, memory management, and formatted output processing. It is designed for educational purposes to enhance understanding of complex C concepts while producing a reusable and extensible library.

---

## Table of Contents
- [Overview](#overview)
- [File Structure](#file-structure)
- [Compilation](#compilation)
- [Supported Features](#supported-features)
- [Usage](#usage)
- [Contributing](#contributing)

---

## Overview

This project replicates the functionality of `printf`, a versatile and widely used function in C. The implementation supports various format specifiers and handles flags, field widths, and precision effectively. The project outputs a reusable static library, `libftprintf.a`, that can be linked in other C projects.

---

## File Structure

The project is organized as follows:

```
printf-github/
├── include/
│   └── ft_printf.h         # Header file containing prototypes and macros
├── src/
│   ├── ft_buffer_utils.c   # Buffer management functions
│   ├── ft_char_utils.c     # Character processing utilities
│   ├── ft_general_utils.c  # General utilities like ft_strlen and ft_calloc
│   ├── ft_number_utils.c   # Functions for handling numeric outputs
│   ├── ft_padding_utils.c  # Padding and spacing logic for formatted outputs
│   ├── ft_parser.c         # Format parsing logic
│   ├── ft_printf.c         # Core implementation of ft_printf
│   ├── ft_too_many_functions.c  # Miscellaneous helper functions
├── Makefile                # Build system
```

This structure ensures modularity and separation of concerns, enabling easier debugging and maintenance.

---

## Compilation

### Build the Library
Run the following command to build the library:
```bash
make
```
This generates a static library `libftprintf.a` in the root directory.

### Clean Up
Remove object files:
```bash
make clean
```

Remove all generated files, including the library:
```bash
make fclean
```

Rebuild everything:
```bash
make re
```

---

## Supported Features

The `ft_printf` implementation includes support for the following format specifiers:

| Conversion | Description                                      |
|------------|--------------------------------------------------|
| `%c`       | Prints a single character                       |
| `%s`       | Prints a string                                 |
| `%p`       | Prints a pointer address in hexadecimal format  |
| `%d`/`%i`  | Prints an integer in decimal format             |
| `%u`       | Prints an unsigned integer                      |
| `%x`/`%X`  | Prints a hexadecimal number (lower/uppercase)   |
| `%%`       | Prints a literal percent symbol                 |

### Flags and Modifiers
- **Flags**: `-`, `0`, `.`, `#`, `+`, and space.
- **Width and Precision**: Handles dynamic and static width and precision specifications.

---

## Usage

### Function Prototype
```c
int ft_printf(const char *format, ...);
```

### Example Code
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You scored %d%% on the test.\n", "Student", 95);
    return 0;
}
```

### Compile and Run
```bash
gcc main.c libftprintf.a -o my_program
./my_program
```

---

## Contributing

Contributions are welcome! If you identify bugs or have ideas for improvements, feel free to fork the repository and submit a pull request. Suggestions for additional features, performance optimizations, or test cases are encouraged.
