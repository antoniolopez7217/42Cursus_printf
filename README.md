# 42Cursus_printf

Second project of 42 Cursus which consists in replicating the **`printf()`** function of the libc.

The prototype of **`ft_printf()`** will be:

```C
int ft_printf(char const *, ...);
```


The following conversions will be implemented:

| Conversion  | Description |
| ------------- | ------------- |
| **%c** | Prints a single character  |
| **%s** | Prints a string (as defined by default in C)|
| **%p** | The void pointer * given as argument is printed in hexadecimal format|
| **%d** | Prints a decimal number (base 10)|
| **%i** | Prints an integer in base 10|
| **%u** | Prints an unsigned decimal number (base 10)|
| **%x** | Prints a hexadecimal number (base 16) in lowercase|
| **%X** | Prints a hexadecimal number (base 16) in uppercase|
| **%%** | Prints the percent symbol|



## How to use it?

### 1. Compiling the function

To **compile the function**, you need to enter in the repository where printf is and run:

```C
make
```

### 2. Cleaning the files

You can remove the .o files with:

```C
make clean
```
To remove all the files generated by `make`:

```C
make fclean
```

### 3. Using the function in your code

In case that you want to **use the printf function** in your code, you need to include the header in your .c files:

```C
#include "ft_printf.h"
```

Then you need to compile your main.c file with the libftprintf.a file generated after compiling it with `make`.

```C
cc -Wall -Wextra -Werror main.c libftprintf.a
```

## Useful links

- [Information about the functions `va_arg`, `va_copy`, `va_end`, `va_start`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170)
- How to test the project? -> [Francinette](https://github.com/xicodomingues/francinette)


[![Linkedin Badge](https://img.shields.io/badge/-Linkedin-blue?style=flat&logo=Linkedin&logoColor=white)](https://www.linkedin.com/in/antoniolopezchamorro)
