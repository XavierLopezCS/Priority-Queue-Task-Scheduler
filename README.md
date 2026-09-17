# Priority-Queue & Task-Scheduler (C++)

This program implements a custom Priority Queue using a vector of `(description, priority)` pairs. The queue supports insertion, removal of the highest‑priority element, and retrieval of the current top task. A Task Scheduler class is built on top of the priority queue to manage user‑defined tasks with associated priorities.

## Features
### Priority Queue
- Stores `(string description, int priority)` pairs
- `push()` inserts a new task
- `top()` returns the highest‑priority task
- `pop()` removes the highest‑priority task
- `peekTop()` returns both description and priority
- `print()` displays all tasks
- Exception handling for empty queue operations

### Task Scheduler
- Adds tasks with descriptions and priorities
- Removes highest‑priority tasks
- Displays all tasks in priority order
- Uses a temporary copy of the queue to print without modifying the original

## How It Works
The priority queue is implemented using a `vector<pair<string, int>>`.  
The highest‑priority element is found by scanning the vector for the maximum `priority` value.

This approach demonstrates:
- Manual priority queue logic
- Dynamic memory management via `vector`
- Encapsulation using classes
- Exception handling (`out_of_range`)
- Separation of concerns (Queue vs Scheduler)
