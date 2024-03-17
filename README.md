# Push_Swap

<img src="https://raw.githubusercontent.com/ridaelfagrouch/push_swap_42/main/assets/push_swap.png" align="right"
     alt="libft" width="300" height="110">

**Push Swap** is a course **42** project that immerses you in the world of sorting algorithms, particularly using stacks. It's a bit like a minimalist board game where you have to sort a pile of numbers using a limited set of instructions.<br>
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

### **Approach**

This project turned out to be a captivating experience for me, as it went beyond mere C programming and presented a significant algorithmic challenge. If you're a beginner in this field seeking a stimulating challenge, look no further.<br>

I had already heard about the various algorithmic approaches employed by other students for this project, including the renowned "Mechanical Turk" method. However, the idea of resorting to a ready-made solution didn't sit well with me. So, I decided to put my thinking cap on and devise an efficient way to sort unique random numbers, whether positive or negative.<br>

The idea came to me to pre-sort the numbers in a list to identify the appropriate element to move. However, a second challenge presented itself: I was familiar with the concept of linked lists, but using them didn't bring me any joy.<br>

Therefore, I decided to seize this opportunity to solve two problems at once by implementing the project using linked lists. I devoted considerable time to this project, particularly focusing on optimizing "push" instructions.<br>

In the end, I realized that I had invested far more time than anticipated, and the bitter taste of the instructions didn't align with my initial goal.<br>

Despite these mixed feelings, this project has enabled me to acquire a wealth of valuable knowledge and skills.<br>

#### **Push Swap Results:**

**100 Numbers:**

* **Worst = 795 instructions**
* **Median = 727 instructions**
* **Best = 652 instructions**
* 
**500 Numbers:**

* **Worst = 7963 instructions**
* **Median = 7522 instructions**
* **Best = 7044 instructions**

## How To Use

### **Compilation**

```bash
# To compile the program
$ make

# To compile the bonus if there is one
$ make bonus

# Allows you to do a complete cleaning of your construction environment
$ make fclean
```

## Notes

Soon
<!--<p align="left">
    <img src="https://image.noelshack.com/fichiers/2024/11/2/1710270009-125.png"
         alt="Sponsored by Evil Martians" width="216" height="164">
</p>-->



## Credits

Below you will find the links used for this project:

- [Norm 42](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)
- [Mechanical Turk](https://en.wikipedia.org/wiki/Amazon_Mechanical_Turk)
- [Fred Orion | Similar method | inspiration](https://www.youtube.com/watch?v=2aMrmWOgLvU)
