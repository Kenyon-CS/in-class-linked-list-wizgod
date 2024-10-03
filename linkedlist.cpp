#include <iostream>

template <typename T>
class node {
public:
    T data;              // Data of generic type T
    node* next;          // Pointer to the next node in the list
    node* prev;          // Pointer to the previous node in the list

    // Constructor to initialize node with value
    node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    node<T>* head;  // Pointer to the first node of the list
    node<T>* tail;  // Pointer to the last node of the list

public:
    // Constructor: Initializes an empty list
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the end (push_back)
    void push_back(T value) {
        node<T>* newNode = new node<T>(value);
        if (tail == nullptr) {  // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at the beginning (push_front)
    void push_front(T value) {
        node<T>* newNode = new node<T>(value);
        if (head == nullptr) {  // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Remove from the end (pop_back)
    void pop_back() {
        if (tail == nullptr) return;  // List is empty
        if (head == tail) {  // Only one element in the list
            delete tail;
            head = tail = nullptr;
        } else {
            node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    // Remove from the beginning (pop_front)
    void pop_front() {
        if (head == nullptr) return;  // List is empty
        if (head == tail) {  // Only one element in the list
            delete head;
            head = tail = nullptr;
        } else {
            node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    // Print the list
    void print() const {
        node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        while (head != nullptr) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list;

    // Insert values
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    std::cout << "Linked List: ";
    list.print();  // Expected output: 0 <-> 1 <-> 2 <-> 3 <-> nullptr

    // Remove from front and back
    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();  // Expected output: 1 <-> 2 <-> 3 <-> nullptr

    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();  // Expected output: 1 <-> 2 <-> nullptr

    return 0;
}
