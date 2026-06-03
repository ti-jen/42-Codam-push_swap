*This project has been created as part of the 42 curriculum by webbers, tkroon*

# Push_swap

`push_swap` sorts a list of numbers using three different sorting algorithms and outputs the instructions required to sort the list.

## Description

The goal of this project is to create a sorting program that sorts a list of numbers using only a limited set of operations and two stacks (`lst_a` and `lst_b`).

The program supports three different sorting algorithms. You can manually choose an algorithm using flags, or let the program automatically select the best algorithm based on how disordered the list is.

The available operations are:

```txt
push_a, push_b, push_ab,
rotate_a, rotate_b, rotate_ab,
reverse_rotate_a, reverse_rotate_b, reverse_rotate_ab,
swap_a, swap_b, swap_ab
```

### How the program works

1. The program reads the input arguments.
2. It checks whether any flags were provided.
3. It creates the list of numbers.
4. It validates the input:

   * Detects duplicate numbers
   * Detects invalid input
5. If an error occurs, the program frees all allocated memory and exits with an error message.
6. After validation, the program selects the sorting algorithm:

   * A specific algorithm if a flag is provided
   * Otherwise, an adaptive algorithm based on the disorder level of the list


## Adaptive Algorithm Selection

#### Simple Algorithm — Selection Sort
```txt
disorder < 20%
```

#### Medium Algorithm — Bucket Sort

```txt
20% ≤ disorder < 50%
```

#### Complex Algorithm — Radix Sort (MSD)

```txt
disorder ≥ 50%
```


# Algorithms

## Selection Sort

(text here)

---

## Bucket Sort

Bucket sort was chosen because it is easy to understand and performs well for medium-sized datasets. It groups numbers that are close together, reducing the number of rotations needed during sorting.

### How it works

1. The program checks the size of the list.
2. It divides the list size by n√ to determine the bucket size.
3. The highest values are pushed into `lst_b` in groups (buckets).
4. This process repeats until `lst_a` is empty.
5. Finally, a simple selection sort is used to move the numbers back into `lst_a` in sorted order.

---

## Quick Sort

Quick sort was chosen because it is an efficient sorting algorithm, especially for push_swap.

### How it works

1. The program calculates a pivot by adding the lowest and highest values and dividing the result by 2.
2. All values lower than the pivot are pushed to `lst_b`.
3. This process is repeated recursively until only 2 numbers remain.
4. The algorithm then returns to the previous partitions and repeats the same process on the remaining elements until the entire array is sorted.

---

# Instructions

## Building the Program

```bash
# Build the complete program
make all

# Remove object files
make clean

# Remove all generated files
make fclean

# Rebuild the project
make re
```

---

## Usage

To use `push_swap`, run the program followed by the numbers you want to sort:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output the operations required to sort the list:

```txt
ra
pb
rra
pb
pb
etc.
```

---

## Sorting Flags

You can manually select a sorting algorithm using flags:

```bash
./push_swap --simple      # Use Selection Sort
./push_swap --medium      # Use Bucket Sort
./push_swap --complex     # Use Radix Sort
./push_swap --adaptive    # Automatically choose the best algorithm
```

---

## Benchmark Mode

Use `--bench` to display statistics about the sorting process.
Benchmark information is printed to `stderr`.

```bash
./push_swap --bench 8 93 5 12 50 3
```

Example output:

```txt
[bench] disorder:        60.0%
[bench] strategy:        Adaptive / O(n log n)
[bench] total_ops:       18
[bench] sa: 0 sb: 0 ss: 0 pa: 6 pb: 6
[bench] ra: 2 rb: 0 rr: 0 rra: 2 rrb: 2 rrr: 0
```

---

# Resources

* [Push Swap Visualizer](https://push-swap42-visualizer.vercel.app/?utm_source=chatgpt.com)
* [ChatGPT](https://chatgpt.com/?utm_source=chatgpt.com)
* [Push Swap Tester](https://github.com/gemartin99/Push-Swap-Tester?utm_source=chatgpt.com)
* [GeeksforGeeks — Sorting Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/?utm_source=chatgpt.com)

---

# AI Usage

AI was used to help create this README file and assist with explaining certain algorithms.
