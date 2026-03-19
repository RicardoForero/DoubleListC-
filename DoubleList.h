#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <stdexcept>

/**
 * @brief Node structure for a Doubly Linked List.
 * Contains data and pointers to the adjacent nodes.
 */
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

/**
 * @brief Doubly Linked List class with head and tail pointers.
 */
template <typename T>
class DoubleList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t listSize;

public:
    DoubleList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Destructor to prevent memory leaks (O(n) complexity)
    ~DoubleList() {
        clear();
    }

    /**
     * @brief Inserts an element at the end of the list (Append).
     * Complexity: O(1)
     */
    void pushBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    /**
     * @brief Inserts an element at the beginning of the list (Prepend).
     * Complexity: O(1)
     */
    void pushFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    /**
     * @brief Traverses the list from Head to Tail.
     */
    void displayForward() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    /**
     * @brief Traverses the list from Tail to Head.
     */
    void displayBackward() const {
        Node<T>* current = tail;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
    }

    bool isEmpty() const { return head == nullptr; }
    size_t size() const { return listSize; }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        listSize = 0;
    }
    /**
     * @brief Removes the last element.
     * Complexity: O(1)
     */
    void popBack() {
        if (isEmpty()) return;
        
        Node<T>* temp = tail;
        if (head == tail) { // Solo hay un elemento
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        listSize--;
    }

    /**
     * @brief Removes the first element.
     * Complexity: O(1)
     */
    void popFront() {
        if (isEmpty()) return;

        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        listSize--;
    }

    void remove(const T& value) {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) {
            // Update the previous node's next pointer
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next; // It was the head
            }

            // Update the next node's previous pointer
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev; // It was the tail
            }

            delete current;
            listSize--;
            return; // Exit after first match
        }
        current = current->next;
    }
    }
    bool contains(const T& value) const {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}
};
#endif
