# Dynamic Stack Implementation in C

A comprehensive stack data structure implementation in C programming language using dynamic memory allocation and pointers. This project demonstrates advanced memory management techniques, user interaction, and fundamental data structure operations.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Stack Data Structure](#stack-data-structure)
- [Stack Operations](#stack-operations)
- [Applications of Stack](#applications-of-stack)
- [Pointer Implementation Details](#pointer-implementation-details)
- [Installation and Usage](#installation-and-usage)
- [Code Structure](#code-structure)
- [Memory Management](#memory-management)
- [Error Handling](#error-handling)
- [Example Usage](#example-usage)
- [Compilation Instructions](#compilation-instructions)
- [Author](#author)

## Overview

This project implements a **dynamic stack** data structure in C using pointers and dynamic memory allocation. Unlike traditional fixed-size array implementations, this stack can grow and shrink at runtime based on user requirements. The implementation follows the **Last In, First Out (LIFO)** principle and provides a menu-driven interface for easy interaction.

### Key Highlights
- **Dynamic Memory Management**: Uses `malloc()`, `realloc()`, and `free()` functions
- **Pointer-Based Implementation**: Leverages C pointers for efficient memory usage
- **Interactive Menu System**: User-friendly command-line interface
- **Automatic Capacity Expansion**: Handles stack overflow by resizing
- **Comprehensive Error Handling**: Robust underflow and overflow detection

## Features

### Core Functionality
- ✅ **Dynamic Stack Creation** with user-defined initial capacity
- ✅ **Push Operation** with automatic memory expansion
- ✅ **Pop Operation** with underflow protection
- ✅ **Display Operation** showing stack contents with positions
- ✅ **Memory Cleanup** on program termination

### Advanced Features
- 🔄 **Automatic Resizing**: Stack expands when capacity is exceeded
- 🛡️ **Memory Safety**: Proper allocation and deallocation
- 📊 **Visual Feedback**: Clear display of stack state and operations
- ⚡ **Efficient Implementation**: Pointer-based for optimal performance

## Stack Data Structure

### What is a Stack?

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. Think of it like a stack of plates where you can only add or remove plates from the top.

```
    Top →  [5] ← Last inserted (First to be removed)
           [3]
           [1]
           [7] ← First inserted (Last to be removed)
```

### Stack Characteristics
- **Linear Structure**: Elements arranged in sequential order
- **LIFO Access**: Last element inserted is first to be removed
- **Single Access Point**: All operations occur at the top
- **Dynamic Size**: Can grow or shrink during runtime (in this implementation)

## Stack Operations

### 1. Push Operation
**Purpose**: Adds a new element to the top of the stack

**Algorithm**:
1. Check if stack is full (overflow condition)
2. If full, offer memory reallocation option
3. Increment top pointer
4. Insert new element at top position
5. Display confirmation message

**Time Complexity**: O(1) average, O(n) worst case (during reallocation)
**Space Complexity**: O(1)

### 2. Pop Operation
**Purpose**: Removes and returns the top element from the stack

**Algorithm**:
1. Check if stack is empty (underflow condition)
2. If empty, display error message
3. Store top element value
4. Decrement top pointer
5. Return the stored value

**Time Complexity**: O(1)
**Space Complexity**: O(1)

### 3. Display Operation
**Purpose**: Shows all elements in the stack from top to bottom

**Algorithm**:
1. Check if stack is empty
2. If empty, display appropriate message
3. Iterate from top to bottom
4. Display each element with its position
5. Show total element count

**Time Complexity**: O(n) where n is number of elements
**Space Complexity**: O(1)

## Applications of Stack

Stacks are fundamental data structures with numerous real-world applications:

### 1. Function Call Management
- **Call Stack**: Manages function calls and returns
- **Local Variables**: Stores function parameters and local variables
- **Return Addresses**: Keeps track of where to return after function completion

### 2. Expression Evaluation
- **Infix to Postfix Conversion**: Converting mathematical expressions
- **Postfix Evaluation**: Evaluating postfix expressions
- **Parentheses Matching**: Checking balanced parentheses in expressions

### 3. Memory Management
- **Stack Memory**: Automatic memory allocation for local variables
- **Recursion**: Managing recursive function calls
- **Undo Operations**: Implementing undo functionality in applications

### 4. Backtracking Algorithms
- **Maze Solving**: Finding paths through mazes
- **N-Queens Problem**: Solving constraint satisfaction problems
- **Depth-First Search**: Tree and graph traversal algorithms

### 5. Browser History
- **Back Button**: Navigating to previously visited pages
- **Forward Button**: Implementing browser navigation
- **Session Management**: Managing browsing sessions

### 6. Compiler Design
- **Syntax Parsing**: Parsing source code syntax
- **Symbol Table Management**: Managing identifiers and scopes
- **Code Generation**: Generating intermediate code

### 7. Operating Systems
- **Process Management**: Managing process states
- **Interrupt Handling**: Handling system interrupts
- **Context Switching**: Saving and restoring process contexts

## Pointer Implementation Details

This implementation extensively uses **C pointers** for several advantages:

### Memory Efficiency
```c
int *stack = NULL;  // Pointer to dynamically allocated memory
int *top;           // Pointer to track stack top
int *capacity;      // Pointer to current capacity
```

### Dynamic Memory Allocation
```c
// Initial allocation
*stack = (int *)malloc(sizeof(int) * (*capacity));

// Reallocation for expansion
int *temp = (int *)realloc(*stack, newSize * sizeof(int));
```

### Pointer Advantages
- **Memory Efficiency**: Only allocates required memory
- **Dynamic Sizing**: Can grow/shrink at runtime
- **Direct Memory Access**: Faster than array indexing
- **Flexible Memory Management**: Control over allocation/deallocation

### Pointer Operations Used
- **Address-of Operator (&)**: Getting memory addresses
- **Dereference Operator (*)**: Accessing values at addresses
- **Pointer Arithmetic**: Navigating through memory
- **Double Pointers (**)**: Modifying pointer values in functions

## Installation and Usage

### Prerequisites
- GCC Compiler (GNU Compiler Collection)
- Standard C Libraries (`stdio.h`, `stdlib.h`)

### Quick Start
1. Clone or download the source code
2. Compile using GCC
3. Run the executable
4. Follow the interactive menu

### Menu Options
```
Menu:
1 for push    - Add element to stack
2 for pop     - Remove element from stack  
3 for display - Show all stack elements
4 for exit    - Terminate program
```

## Code Structure

### File Organization
```
📁 Project Root
├── 📄 stack.c          # Main source code
├── 📄 README.md        # This documentation
```

### Function Breakdown

#### `main()` Function
- **Purpose**: Program entry point and menu management
- **Features**: User interaction, memory cleanup, program flow control
- **Memory Management**: Ensures proper cleanup on exit

#### `push()` Function
```c
void push(int **stack, int *top, int item, int *capacity)
```
- **Parameters**: Double pointer to stack, top pointer, item to push, capacity pointer
- **Features**: Dynamic allocation, overflow handling, memory expansion
- **Return**: None (void)

#### `pop()` Function
```c
void pop(int *stack, int *top)
```
- **Parameters**: Stack pointer, top pointer
- **Features**: Underflow checking, element removal, position update
- **Return**: None (displays popped element)

#### `display()` Function
```c
void display(int *stack, int *top)
```
- **Parameters**: Stack pointer, top pointer
- **Features**: Complete stack visualization, position tracking
- **Return**: None (displays stack contents)

## Memory Management

### Dynamic Allocation Strategy
The implementation uses sophisticated memory management:

#### Initial Allocation
```c
if (*stack == NULL) {
    *stack = (int *)malloc(sizeof(int) * (*capacity));
}
```

#### Memory Expansion
```c
int *temp = (int *)realloc(*stack, newSize * sizeof(int));
if (temp == NULL) {
    puts("Reallocation failed!");
    return;
}
*stack = temp;
```

#### Memory Cleanup
```c
if (stack != NULL) free(stack);
```

### Memory Safety Features
- **Null Pointer Checks**: Prevents segmentation faults
- **Allocation Failure Handling**: Graceful handling of memory exhaustion
- **Proper Deallocation**: Prevents memory leaks
- **Reallocation Safety**: Uses temporary pointer to avoid data loss

## Error Handling

### Stack Overflow Protection
- Detects when stack reaches maximum capacity
- Offers user choice for memory expansion
- Validates new capacity input
- Handles reallocation failures gracefully

### Stack Underflow Protection
- Checks for empty stack before pop operations
- Displays clear error messages
- Maintains program stability
- Prevents invalid memory access

### Memory Error Handling
- Validates malloc/realloc return values
- Handles allocation failures appropriately
- Provides user feedback for memory issues
- Ensures program doesn't crash on memory errors

## Example Usage

### Sample Session
```
Enter initial stack capacity: 3

Menu :
1 for push
2 for pop
3 for display
4 for exit
Enter your choice : 1
Enter item to push: 10
Stack created with capacity 3
Successfully pushed 10 (position 0)

Enter your choice : 1
Enter item to push: 20
Successfully pushed 20 (position 1)

Enter your choice : 3

Stack contents (top to bottom):
Position    Value
--------    -----
1           20 <- TOP
0           10
Total elements: 2

Enter your choice : 1
Enter item to push: 30
Successfully pushed 30 (position 2)

Enter your choice : 1
Enter item to push: 40
Stack overflow! Current capacity: 3
Do you want to reallocate memory? (y/n): y
Enter new stack size (must be > 3): 5
Stack resized from 3 to 5
Successfully pushed 40 (position 3)

Enter your choice : 2
Popped item: 40
Current top position: 2

Enter your choice : 4
Exiting program. Goodbye!
```

## Compilation Instructions

### Using GCC (Recommended)
```bash
gcc -o stack stack.c
./stack
```

### With Debug Information
```bash
gcc -g -o stack stack.c
./stack
```

### With Warnings (Recommended for Development)
```bash
gcc -Wall -Wextra -o stack stack.c
./stack
```

### For Production (Optimized)
```bash
gcc -O2 -o stack stack.c
./stack
```

## Author

**Argha Ghosh**  
📧 Email: [tojog75@gmail.com](mailto:tojog75@gmail.com)

---

### Additional Notes

This implementation serves as an excellent educational resource for understanding:
- Dynamic memory allocation in C
- Pointer manipulation and double pointers
- Stack data structure principles
- Memory management best practices
- Error handling in C programs
- User interface design in console applications

The code demonstrates professional programming practices including proper error handling, memory management, and user-friendly interfaces, making it suitable for both learning and practical applications.
