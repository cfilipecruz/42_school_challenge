# _This project has been created as part of the 42 curriculum by cmarques_

# 🖨️ ft_printf

---

## 🧾 Description

**ft_printf** is a custom implementation of the standard C `printf()` function.

The goal of this project is to understand:
- variadic functions
- formatted output
- recursion
- hexadecimal conversion
- low-level output handling in C

The function reproduces the behavior of `printf` for the following conversions:

- `%c` → character
- `%s` → string
- `%p` → pointer address
- `%d` / `%i` → signed integers
- `%u` → unsigned integers
- `%x` / `%X` → hexadecimal
- `%%` → percent sign

The function returns the total number of printed characters.

---

## ⚙️ Instructions

### Compilation

Compile the project with:

make

This generates:

libftprintf.a

---

### Usage

Include the header:

#include "ft_printf.h"

Compile your program with the library:

cc main.c libftprintf.a

---

### Cleaning

make clean   → removes object files  
make fclean  → removes object files and library  
make re      → recompiles everything  

---

## ⚡ Implementation Details

The format string is parsed sequentially.  
When `%` is found, the next character determines which function is executed.

The project uses variadic arguments:
- va_list
- va_start
- va_arg
- va_end

Numbers are printed using recursion to avoid extra memory allocation.

Hexadecimal conversion is done by repeatedly dividing by 16 and printing digits.

Pointers are cast to unsigned long and printed in hexadecimal with a `0x` prefix.

No complex data structures are used. The project relies on:
- recursion
- pointers
- primitive types
- variadic functions

---

## 📦 Files

- ft_printf.c
- ft_putchar.c
- ft_putstr.c
- ft_putnbr.c
- ft_putnbr_u.c
- ft_puthex.c
- ft_putpoint.c
- ft_strlen.c
- ft_printf.h
- Makefile

---

## 📚 Resources

### Documentation

- man printf
- man stdarg
- GNU C Library documentation
- https://en.cppreference.com/w/c/variadic

---

### AI Usage

AI tools were used to:
- understand variadic functions
- clarify parsing logic
- debug edge cases
- improve documentation
- increase test cases
- improve information

---

## 👨‍💻 Author

- cmarques (42 Student)