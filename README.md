# CIS 343 Operating Systems — Balancing Symbols Assignment

## Overview

This project is a C++ program that checks if a string of symbols is balanced. The symbols considered are braces (`[ ]`) and parentheses (`( )`). The program uses a **stack data structure implemented via a linked list** to verify the correct matching and nesting of these symbols.

## Problem Description

Compilers may generate confusing errors when a brace, parenthesis, or bracket is missing. This program aims to identify whether a string of symbols is balanced to avoid such issues.

### Examples of valid and invalid symbol sequences:

| Sequence | Balanced?  |
|----------|------------|
| `()()`   | Legal      |
| `([)]`   | Illegal    |
| `([])`   | Legal      |
| `([()])` | Legal      |

## Solution Approach

The algorithm uses a stack to track opening symbols and validate closing symbols:

1. Create an empty stack.
2. Read characters in the string one by one.
3. If the character is an opening symbol (`(` or `[`), push it onto the stack.
4. If the character is a closing symbol (`)` or `]`):
   - If the stack is empty, report an error.
   - Otherwise, pop the top element from the stack.
   - If the popped symbol does not correspond to the matching opening symbol, report an error.
5. After processing all characters, if the stack is not empty, report an error; otherwise, the sequence is legal.

## Implementation Requirements

- Language: **C++**
- Implement your own **stack using a linked list**.
- Define a `StringNode` class containing:
  - A character for the symbol.
  - A pointer to the next node.
- Implement linked list methods:
  - `AddFront`: Add an element to the front of the list (push onto the stack).
  - `RemoveFront`: Remove an element from the front of the list (pop from the stack) and free memory.
- The program reads input from a file specified via the command line (`argc` and `argv`).
- Each line in the input file contains a string of symbols (max length 255).
- The program should:
  - Print each symbol in the input line on its own line.
  - Push symbols onto the stack using `AddFront`.
  - Pop and print symbols from the stack using `RemoveFront`.

## Usage

```bash
./balance_checker input.txt
