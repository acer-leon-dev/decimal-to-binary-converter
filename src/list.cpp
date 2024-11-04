#include "list.hpp"
#include <iostream>
#include <cstddef>

// Construct a new, empty linked list
list::list () {
    // Set the cursor the head node
    head = nullptr;
    cursor_ptr = nullptr;
}

// Move the cursor to next node
void list::next(){
    if (cursor_ptr != nullptr) {
        cursor_ptr = cursor_ptr->next;
    }
    std::cout << "Moved to next node" << std::endl;
}

// Movr the cursor to previous node
void list::prev(){
    // Iterate from the head node until reaching the node before the current cursor
    node * temp = head;
    while (temp->next != cursor_ptr) {
        temp = temp->next;
    }
    cursor_ptr = temp;
    std::cout << "Moved to previous node" << std::endl;

}

// Get node value at the cursor
int list::get() {
    return cursor_ptr->value; 
}

// Set node value at the cursor
void list::set(int value) {
    cursor_ptr->value = value;
}

// Insert node after the cursor
void list::insert(int value) {
    // Create pointer to new node
    node ptr_new;
    ptr_new.value = value;
    // If list is empty:
    if (head == nullptr) {
        std::cout << "Currently empty" << std::endl;
        head = &ptr_new;
        cursor_ptr = &ptr_new;
        ptr_new.next = &ptr_new;
    } else if (cursor_ptr->next == head) {
        std::cout << "Currently at last node" << std::endl;
        cursor_ptr->next = &ptr_new;
        ptr_new.next = head;
    // Cursor is at a middle node:
    } else {
        std::cout << "Currently at a middle node" << std::endl;
        ptr_new.next = cursor_ptr->next;
        cursor_ptr->next = &ptr_new;
    }
    std::cout << "Added " << get() << std::endl << std::endl;
}

// Remove node at the cursor
void list::remove() {
    node * temp = head;
    while (temp->next != cursor_ptr) {
        temp = temp->next;
    }
    node * previous = temp;
    previous->next = cursor_ptr->next;
    delete cursor_ptr;
}

// DOES NOT WORK
std::ostream & operator <<(std::ostream &out, const list &src) {
    node * temp = src.head;

    do {
        out << temp->value;
        if (temp->next != src.head) {
            out << " -> ";    
        }

        temp = temp->next;
    } while (1);

    return out;
}