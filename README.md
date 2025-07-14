# 🔁 LRU Cache Implementation in C++

This project demonstrates a memory-efficient **Least Recently Used (LRU) Cache** implementation in C++ using a combination of **doubly linked list** and **unordered_map**.

## 📌 Features

- ✅ Constant Time `O(1)` `get()` and `put()` operations
- ✅ Uses doubly linked list for tracking recent usage
- ✅ Manual memory management using raw pointers
- ✅ Demonstrates cache eviction policy
- ✅ Hands-on use of C++ STL (`unordered_map`)

## 🛠️ Technologies Used

- C++
- Standard Template Library (STL)
- Pointers and Dynamic Memory Management

## 🚀 How It Works

- **`unordered_map`** stores key-node mappings for O(1) access.
- **Doubly linked list** maintains the order of usage (most recently used at front).
- When capacity is reached, least recently used item is removed from the back.
- Every `get()` or `put()` moves the used node to the front of the list.

## 🧪 Sample Output

1
-1
-1
3
4

