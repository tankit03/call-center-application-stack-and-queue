# Stack, Queue, and Call Center Implementation

This repository contains an implementation of a stack and a queue, along with a call center simulation. The project is assessed based on various criteria as follows:

## Part 1: Stack

- **Function `stack_create()`:** Correctly allocates and initializes a stack.
- **Function `stack_free()`:** Correctly frees the memory allocated by a stack with no memory leaks.
- **Function `stack_isempty()`:** Correctly determines whether a stack is empty.
- **Function `stack_push()`:** Correctly pushes a value onto a stack with O(1) average runtime complexity.
- **Function `stack_pop()`:** Correctly pops a value from a stack and returns it, with O(1) average runtime complexity.
- **Function `stack_top()`:** Correctly returns the top value on a stack with O(1) average runtime complexity.
- The stack implementation correctly uses a linked list for its underlying data storage using only the linked list implementation's interface functions (i.e., without accessing the internals of the list implementation).

## Part 2: Queue

- **Function `queue_create()`:** Correctly allocates and initializes a queue.
- **Function `queue_free()`:** Correctly frees the memory allocated by a queue with no memory leaks.
- **Function `queue_isempty()`:** Correctly determines whether a queue is empty.
- **Function `queue_enqueue()`:** Correctly enqueues a value into a queue with O(1) average runtime complexity.
- **Function `queue_dequeue()`:** Correctly dequeues a value from a queue and returns it, with O(1) average runtime complexity.
- **Function `queue_front()`:** Correctly returns the front value from a queue with O(1) average runtime complexity.
- The queue implementation correctly uses a dynamic array for its underlying data storage using only the dynamic array implementation's interface functions (i.e., without accessing the internals of the dynamic array implementation).

## Part 3: A Call Center

- Use of a queue in Part 2 to keep track of incoming calls.
- Use of a stack in Part 1 to keep track of answered calls.
- Each call is stored as a struct, containing ID, name, and reason.
- Correct implementation of four options described plus quit.
- Clear and readable instructions and output.

This project provides an opportunity to learn and practice stack and queue data structures and apply them in a real-world scenario, simulating a call center.

