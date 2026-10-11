*This project has been created as part of the 42 curriculum by ntshuma.*

***

# Libft
## Your very first own C library

***

# Description
This project is about writing your own custom C library (`libft.a`). It includes your own versions of standard library functions for strings and memory, as well as functions to handle numbers, files, and linked lists. Writing this library helps you understand how these tools work under the hood so you can reuse them in all your future 42 coding projects.

# Instructions

### Makefile Automation
You can compile the project, clean up temporary files, or reset everything using these simple commands in your terminal:

```bash
make          # Compiles all files and builds the 'libft.a' library
make clean    # Deletes the temporary object files (.o) to clean up space
make fclean   # Deletes the object files AND removes the 'libft.a' library completely
make re       # Cleans everything up and recompiles the library from scratch
```

### Linking the Library to Your Projects
To use this library in your future 42 assignments, include the header file at the top of your C file:

```c
#include "path/to/libft.h"
```

When compiling your project, tell the compiler to link your `libft.a` library like this:
```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```
*(The `-L.` flag tells the compiler to look in the current folder for the library, and `-lft` tells it to use your `libft.a` file).*

# Resources
* Linux man pages (`man strlen`, `man malloc`, etc.)
* [C Programming Language, 2nd Edition (K&R)](https://wikipedia.org)
* [DevNyxie's `ft_itoa` Logic Breakdown](https://devnyxie.com)
* [Mark Veligod's Libft Diagrams Reference](https://github.com)
* [42 Libft Makefile Structure Model](https://github.com)
* [Libft Video Walkthrough and Tutorial](https://youtube.com)
* [W3Schools Guide on the C NULL Pointer](https://w3schools.com)
* [Ahmed Ezzouine's Medium Guide: 1337 Libft Static Library](https://medium.com)
* [Programiz Documentation on `ctype.h/tolower`](https://programiz.com)

### AI Tool Usage Disclosure
In line with the 42 AI policy, artificial intelligence tools were used to help with the following tasks during this project:
* **Debugging Syntax:** Used to find and fix minor typos, missing semicolons, and code alignment rules.
* **Checking Edge Cases:** Used to double-check that functions work correctly with edge cases like `INT_MIN` in `ft_itoa` and out-of-bounds inputs in `ft_substr`.
* **Learning Concepts:** Used to understand the logic and pointer tracking behind linked lists for functions like `ft_lstmap`.

# Detailed description of the library created for this project

### Chapter III: Mandatory Functions — Part 1 (Standard Libc Functions)
Your own versions of standard library functions that behave exactly like the original manual pages:

| Function | Action | Original Header |
| :--- | :--- | :--- |
| `ft_isalpha` | Checks if a character is a letter. | `<ctype.h>` |
| `ft_isdigit` | Checks if a character is a number (0 to 9). | `<ctype.h>` |
| `ft_isalnum` | Checks if a character is a letter or a number. | `<ctype.h>` |
| `ft_isascii` | Checks if a character fits in the ASCII table. | `<ctype.h>` |
| `ft_isprint` | Checks if a character can be printed on screen (including space). | `<ctype.h>` |
| `ft_strlen` | Counts the number of characters in a string. | `<string.h>` |
| `ft_memset` | Fills a block of memory with a specific character. | `<string.h>` |
| `ft_bzero` | Fills a block of memory with zeroes. | `<string.h>` |
| `ft_memcpy` | Copies a block of memory from one place to another. | `<string.h>` |
| `ft_memmove` | Copies memory safely even if the source and destination overlap. | `<string.h>` |
| `ft_strlcpy` | Copies a string into a limited buffer size. | `<string.h>` |
| `ft_strlcat` | Appends one string to the end of another safely within a size limit. | `<string.h>` |
| `ft_toupper` | Converts a lowercase letter to uppercase. | `<ctype.h>` |
| `ft_tolower` | Converts an uppercase letter to lowercase. | `<ctype.h>` |
| `ft_strchr` | Finds the first time a character appears in a string. | `<string.h>` |
| `ft_strrchr` | Finds the last time a character appears in a string. | `<string.h>` |
| `ft_strncmp` | Compares two strings up to a specific number of characters. | `<string.h>` |
| `ft_memchr` | Searches a block of memory for a specific byte. | `<string.h>` |
| `ft_memcmp` | Compares two blocks of memory byte by byte. | `<string.h>` |
| `ft_strnstr` | Finds a smaller string inside a bigger string within a size limit. | `<string.h>` |
| `ft_atoi` | Converts a string of numbers into a real integer. | `<stdlib.h>` |
| `ft_calloc` | Allocates memory for an array and initializes all bytes to zero. | `<stdlib.h>` |
| `ft_strdup` | Duplicates a string by allocating new memory for it. | `<string.h>` |

### Chapter III: Mandatory Functions — Part 2 (Additional Utilities)
Extra functions that are not in the standard library but are useful for manipulating strings and writing to files:

| Function | Action | Return Value / Output |
| :--- | :--- | :--- |
| `ft_substr` | Cuts out and returns a piece of a string. | New string pointer |
| `ft_strjoin` | Combines two strings together into a brand new string. | New string pointer |
| `ft_strtrim` | Strips specified characters from the beginning and end of a string. | New string pointer |
| `ft_split` | Splits a string into an array of separate words using a delimiter. | Array of strings |
| `ft_itoa` | Converts a regular integer number into a string of text. | New string pointer |
| `ft_strmapi` | Applies a function to modify each character of a string. | New string pointer |
| `ft_striteri` | Iterates through a string to modify its characters in-place. | Modifies string directly |
| `ft_putchar_fd` | Outputs a single character to a specific file descriptor. | Writes to file/terminal |
| `ft_putstr_fd` | Outputs an entire string to a specific file descriptor. | Writes to file/terminal |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor. | Writes to file/terminal |
| `ft_putnbr_fd` | Outputs an integer number as text to a file descriptor. | Writes to file/terminal |

### Chapter IV: Mandatory Functions — Part 3 (Linked List Functions)
Functions designed to create, loop through, and clear items inside a singly-linked list using the `t_list` structure:

| Function | Action | Purpose |
| :--- | :--- | :--- |
| `ft_lstnew` | Creates a new list node with the given content. | Node Allocation |
| `ft_lstadd_front` | Adds a new node to the absolute beginning of the list. | List Update |
| `ft_lstsize` | Counts the total number of elements currently in the list. | List Count |
| `ft_lstlast` | Finds and returns a pointer to the very last node of the list. | Find End |
| `ft_lstadd_back` | Adds a new node to the absolute end of the list. | List Update |
| `ft_lstdelone` | Deletes a single node's content and frees its memory. | Node Deletion |
| `ft_lstclear` | Deletes and frees a list completely from a given point forward. | List Deletion |
| `ft_lstiter` | Loops through a list and applies a function to every node's content. | List Iteration |
| `ft_lstmap` | Creates a fresh list by applying a function to modify an old list. | List Duplication |

***

