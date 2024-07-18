<img src="readme/push_swap.png" alt="push_swap" width="900"/>

# Push Swap
**Push Swap** is a course **42** project that immerses you in the world of sorting algorithms, particularly using stacks. It's a bit like a minimalist board game where you have to sort a pile of numbers using a limited set of instructions.<br>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

## 📒 Index

- [About](#about)
- [Approach](#approach)
  - [Installation](#installation)
- [Development](#development)
  - [File Structure](#file-structure)
  <!--- [Diagram Architecture](#diagram-architecture)  -->
- [Notes](#notes)
- [Credits](#credits)

## About

Your goal is to sort stack A **using the minimum number of these instructions (along with stack B)**. Each action performed (sa, sb, ra, rb, rr, ..) **counts as a move**. At the end, the program reads your instructions and performs the necessary rotations and swaps to sort the stack. The program then calculates the score, which corresponds to the total number of movements performed.<br>

### **The possible actions are:**

* **pa (push A)**: *Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.*
* **pb (push B)**: *Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.*
* **sa (swap A)**: *Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.*
* **sb (swap B)**: *Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.*
* **ss**: *sa and sb at the same time.*
* **ra (rotate A)**: *Shift all elements of stack A up by 1. The first element becomes the last one.*
* **rb (rotate B)**: *Shift all elements of stack B up by 1. The first element becomes the last one.*
* **rr**: *ra and rb at the same time.*
* **rra (reverse rotate A)**: *Shift all elements of stack A down by 1. The last element becomes the first one.*
* **rrb (reverse rotate B)**: *Shift all elements of stack b down by 1. The last element becomes the first one.*
* **rrr**: *rra and rrb at the same time.*

## Approach

This project turned out to be a captivating experience for me, as it went beyond mere C programming and presented a significant algorithmic challenge. If you're a beginner in this field seeking a stimulating challenge, look no further.<br>

I had already heard about the various algorithmic approaches employed by other students for this project, including the renowned "Mechanical Turk" method. However, the idea of resorting to a ready-made solution didn't sit well with me. So, I decided to put my thinking cap on and devise an efficient way to sort unique random numbers, whether positive or negative.<br>

The idea came to me to pre-sort the numbers in a list to identify the appropriate element to move. However, a second challenge presented itself: I was familiar with the concept of linked lists, but using them didn't bring me any joy.<br>

Therefore, I decided to seize this opportunity to solve two problems at once by implementing the project using linked lists. I devoted considerable time to this project, particularly focusing on optimizing "push" instructions.<br>

In the end, I realized that I had invested far more time than anticipated, and the bitter taste of the instructions didn't align with my initial goal.<br>

Despite these mixed feelings, this project has enabled me to acquire a wealth of valuable knowledge and skills.<br>

### **Push Swap Results:**

**100 Numbers:**

* **Worst = 795 instructions**
* **Median = 727 instructions**
* **Best = 652 instructions**

**500 Numbers:**

* **Worst = 7963 instructions**
* **Median = 7522 instructions**
* **Best = 7044 instructions**

## Installation
```bash
# Clone this repository
$ git clone https://github.com/HaruSnak/Push_Swap.git

# Go into the repository
$ cd Push_Swap

# To compile the program
$ make

# Execution example
$ ./push_swap 4 67 3 87 23 (Example)

# Allows you to do a complete cleaning of your construction environment
$ make fclean # Or make clean
```

## Development

### File Structure

```
.
└── 📁push_swap
    └── Makefile
    └── 📁includes
        └── 📁libft
            └── Makefile
            └── 📁char
                └── ft_isalnum.c
                └── ft_isalnum.o
                └── ft_isalpha.c
                └── ft_isalpha.o
                └── ft_isascii.c
                └── ft_isascii.o
                └── ft_isdigit.c
                └── ft_isdigit.o
                └── ft_isprint.c
                └── ft_isprint.o
                └── ft_tolower.c
                └── ft_tolower.o
                └── ft_toupper.c
                └── ft_toupper.o
            └── 📁conv
                └── ft_atoi.c
                └── ft_atoi.o
                └── ft_itoa.c
                └── ft_itoa.o
            └── 📁gnl
                └── get_next_line.c
                └── get_next_line.o
            └── 📁includes
                └── libft.h
            └── libft.a
            └── 📁lst
                └── ft_lstadd_back_bonus.c
                └── ft_lstadd_front_bonus.c
                └── ft_lstclear_bonus.c
                └── ft_lstdelone_bonus.c
                └── ft_lstiter_bonus.c
                └── ft_lstlast_bonus.c
                └── ft_lstmap_bonus.c
                └── ft_lstnew_bonus.c
                └── ft_lstsize_bonus.c
            └── 📁mem
                └── ft_bzero.c
                └── ft_bzero.o
                └── ft_calloc.c
                └── ft_calloc.o
                └── ft_memchr.c
                └── ft_memchr.o
                └── ft_memcmp.c
                └── ft_memcmp.o
                └── ft_memcpy.c
                └── ft_memcpy.o
                └── ft_memmove.c
                └── ft_memmove.o
                └── ft_memset.c
                └── ft_memset.o
            └── 📁printf
                └── ft_conv_primary.c
                └── ft_conv_primary.o
                └── ft_conv_specifies.c
                └── ft_conv_specifies.o
                └── ft_conv_suit.c
                └── ft_conv_suit.o
                └── ft_printf.c
                └── ft_printf.o
            └── 📁put
                └── ft_putchar.c
                └── ft_putchar.o
                └── ft_putchar_fd.c
                └── ft_putchar_fd.o
                └── ft_putendl_fd.c
                └── ft_putendl_fd.o
                └── ft_putnbr.c
                └── ft_putnbr.o
                └── ft_putnbr_fd.c
                └── ft_putnbr_fd.o
                └── ft_putstr.c
                └── ft_putstr.o
                └── ft_putstr_fd.c
                └── ft_putstr_fd.o
            └── 📁str
                └── ft_split.c
                └── ft_split.o
                └── ft_strchr.c
                └── ft_strchr.o
                └── ft_strdup.c
                └── ft_strdup.o
                └── ft_striteri.c
                └── ft_striteri.o
                └── ft_strjoin.c
                └── ft_strjoin.o
                └── ft_strlcat.c
                └── ft_strlcat.o
                └── ft_strlcpy.c
                └── ft_strlcpy.o
                └── ft_strlen.c
                └── ft_strlen.o
                └── ft_strmapi.c
                └── ft_strmapi.o
                └── ft_strncmp.c
                └── ft_strncmp.o
                └── ft_strnstr.c
                └── ft_strnstr.o
                └── ft_strrchr.c
                └── ft_strrchr.o
                └── ft_strtrim.c
                └── ft_strtrim.o
                └── ft_substr.c
                └── ft_substr.o
        └── push_swap.h
    └── numbers.py
    └── 📁srcs
        └── a.out
        └── algo_sorting.c
        └── algo_sorting_extract.c
        └── algo_sorting_iteration.c
        └── algo_sorting_pre.c
        └── algo_sorting_three.c
        └── algo_sortingmore.c
        └── algo_utils.c
        └── 📁bonus
            └── checker
            └── checker.c
        └── case_errors.c
        └── checker_linux
        └── 📁commands
            └── commands.c
            └── commands2.c
        └── parsing.c
        └── push_swap.c
        └── ranking.c
        └── split.c
```

<!--### Diagram Architecture
Write the build Instruction here.-->

## Notes

*Small error on my part, for which there is a good chance that I will re-push the correction to get 100/100*
<p align="left">
    <img src="https://image.noelshack.com/fichiers/2024/29/4/1721314123-sans-titre.png"
         alt="Sponsored by Evil Martians" width="216" height="164">
</p>

## Credits

Below you will find the links used for this project:

- [Norm 42](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)
- [Mechanical Turk](https://en.wikipedia.org/wiki/Amazon_Mechanical_Turk)
- [Fred Orion | Similar method | inspiration](https://www.youtube.com/watch?v=2aMrmWOgLvU)

[contributors-shield]: https://img.shields.io/github/contributors/HaruSnak/Push_Swap.svg?style=for-the-badge
[contributors-url]: https://github.com/HaruSnak/Push_Swap/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/HaruSnak/Push_Swap.svg?style=for-the-badge
[forks-url]: https://github.com/HaruSnak/Push_Swap/network/members
[stars-shield]: https://img.shields.io/github/stars/HaruSnak/Push_Swap.svg?style=for-the-badge
[stars-url]: https://github.com/HaruSnak/Push_Swap/stargazers
[issues-shield]: https://img.shields.io/github/issues/HaruSnak/Push_Swap.svg?style=for-the-badge
[issues-url]: https://github.com/HaruSnak/Push_Swap/issues
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/shany-moreno-5a863b2aa
