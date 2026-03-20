#pragma once

#include <cstddef>
#include <utility>
#include <iostream>

template <typename T>
class DoubleList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        explicit Node(const T& value)
            : data(value), next(nullptr), prev(nullptr) {}

        explicit Node(T&& value)
            : data(std::move(value)), next(nullptr), prev(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    std::size_t listSize = 0;

public:

    DoubleList() noexcept = default;

    ~DoubleList() {
        clear();
    }

    DoubleList(const DoubleList& other) {
        Node* current = other.head;
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
    }

    DoubleList(DoubleList&& other) noexcept
        : head(other.head), tail(other.tail), listSize(other.listSize) {
        other.head = other.tail = nullptr;
        other.listSize = 0;
    }

    DoubleList& operator=(const DoubleList& other) {
        if (this == &other) return *this;

        clear();
        Node* current = other.head;
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
        return *this;
    }

    DoubleList& operator=(DoubleList&& other) noexcept {
        if (this == &other) return *this;

        clear();
        head = other.head;
        tail = other.tail;
        listSize = other.listSize;

        other.head = other.tail = nullptr;
        other.listSize = 0;

        return *this;
    }

    [[nodiscard]] bool isEmpty() const noexcept {
        return head == nullptr;
    }

    [[nodiscard]] std::size_t size() const noexcept {
        return listSize;
    }

    void pushBack(const T& value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        ++listSize;
    }

    void pushBack(T&& value) {
        Node* newNode = new Node(std::move(value));

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        ++listSize;
    }

    void pushFront(const T& value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        ++listSize;
    }

    void popBack() noexcept {
        if (isEmpty()) return;

        Node* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        --listSize;
    }

    void popFront() noexcept {
        if (isEmpty()) return;

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        --listSize;
    }

    void clear() noexcept {
        Node* current = head;

        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        head = tail = nullptr;
        listSize = 0;
    }

    bool remove(const T& value) {
        Node* current = head;

        while (current) {
            if (current->data == value) {

                if (current->prev)
                    current->prev->next = current->next;
                else
                    head = current->next;

                if (current->next)
                    current->next->prev = current->prev;
                else
                    tail = current->prev;

                delete current;
                --listSize;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    [[nodiscard]] bool contains(const T& value) const {
        Node* current = head;

        while (current) {
            if (current->data == value) return true;
            current = current->next;
        }

        return false;
    }

    void displayForward() const {
        Node* current = head;

        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }

        std::cout << "nullptr\n";
    }

    void displayBackward() const {
        Node* current = tail;

        while (current) {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }

        std::cout << "nullptr\n";
    }
};
