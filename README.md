# Double Linked List Implementation in C++

This project provides a robust implementation of a **Double Linked List** data structure, demonstrating core concepts of Object-Oriented Programming (OOP) and memory management in C++.

## 👥 Authors
* **MATALLANA CIFUENTES VICENTE ARMANDO**
* **RICARDO FORERO ORTIZ**

---

## 🚀 Language: C++
**C++** is a high-performance, compiled, and general-purpose programming language. It is widely used in systems programming, game development, and applications where efficiency is critical.

Key features used in this project:
* **Classes and Objects:** To encapsulate data and behavior.
* **Pointers:** For direct memory manipulation and linking nodes.
* **Dynamic Memory Allocation:** To manage the lifecycle of list elements at runtime.
* **Templates (Optional):** To allow the list to store any data type.

---

# Java vs. C++ Comparison


| Feature | Java | C++ |
| :--- | :--- | :--- |
| **Memory Management** | Automatic (Garbage Collector) | Manual (new/delete) or Smart Pointers |
| **Platform** | Independent (Runs on JVM) | Platform-Dependent (Native code) |
| **Pointers** | No direct pointer manipulation | Supports pointer arithmetic |
| **Inheritance** | Single inheritance (Multiple via Interfaces) | Supports Multiple Inheritance |
| **Performance** | Generally slower (Interpretation/JIT) | High performance (Direct hardware access) |
| **Paradigm** | Strictly Object-Oriented | Multiparadigm (Procedural, OOP, Generic) |

---

## 🏗️ Data Structure: Double Linked List
A **Double Linked List** is a linear data structure where each element (called a **Node**) contains three parts:
1. **Data:** The actual value stored.
2. **Next Pointer:** A reference to the following node in the sequence.
3. **Previous Pointer:** A reference to the preceding node.

### Advantages:
* **Bidirectional Traversal:** You can iterate through the list both forwards and backwards.
* **Efficient Deletions:** Removing a node is easier than in a singly linked list because you already have a pointer to the previous element.
* **Dynamic Size:** It grows or shrinks during execution, unlike a standard array.

---

## 🛠️ Common Operations Included
* `pushFront()`: Adds an element at the beginning.
* `pushBack()`: Adds an element at the end.
* `remove()`: Removes a specific element.
* `displayForward()`: Prints the list from head to tail.
* `displayBackward()`: Prints the list from tail to head.

---

## Compiling Process

### C++ (Compilation to Native Code)
C++ uses a **compiler** (like `g++` or `clang`) to transform source code directly into machine-specific instructions.
1. **Pre-processing:** Handles `#include` and `#define` directives.
2. **Compilation:** Translates code into Assembly.
3. **Assembly:** Creates object files (`.o` or `.obj`).
4. **Linking:** Combines object files into a single **executable binary**.

### Java (Compilation to Bytecode)
Java follows a **"Write Once, Run Anywhere"** philosophy by using an intermediate step.
1. **Compilation:** The `javac` compiler turns `.java` files into **Bytecode** (`.class` files).
2. **Interpretation:** The **Java Virtual Machine (JVM)** reads the Bytecode.
3. **Execution:** The JVM uses **JIT (Just-In-Time)** compilation to turn Bytecode into machine code at runtime.
