#include "LinkedList.h"


template <typename Item_Type>
LinkedList<Item_Type>::LinkedList() : head(nullptr), tail(nullptr), num_items(0) {}


template <typename Item_Type>
LinkedList<Item_Type>::~LinkedList() {
    Node<Item_Type>* current = head;
    Node<Item_Type>* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

template <typename Item_Type>
void LinkedList<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (!head) {
        head = tail = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void LinkedList<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template <typename Item_Type>
void LinkedList<Item_Type>::pop_front() {
    if (head) {
        Node<Item_Type>* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (num_items == 0) {
            tail = nullptr;
        }
    }
}

template <typename Item_Type>
void LinkedList<Item_Type>::pop_back() {
    if (head) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            num_items--;
        }
        else {
            Node<Item_Type>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
            num_items--;
        }
    }
}

template <typename Item_Type>
Item_Type LinkedList<Item_Type>::front() const {
    if (head) {
        return head->data;
    }
    else {
        throw out_of_range("List is empty");
    }
}

template <typename Item_Type>
Item_Type LinkedList<Item_Type>::back() const {
    if (tail) {
        return tail->data;
    }
    else {
        throw out_of_range("List is empty");
    }
}

template <typename Item_Type>
bool LinkedList<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void LinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        index = num_items;
    }
    if (index == 0) {
        push_front(item);
    }
    else if (index == num_items) {
        push_back(item);
    }
    else {
        Node<Item_Type>* new_node = new Node<Item_Type>(item);
        Node<Item_Type>* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        num_items++;
    }
}

template <typename Item_Type>
bool LinkedList<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node<Item_Type>* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node<Item_Type>* to_remove = temp->next;
        temp->next = to_remove->next;
        delete to_remove;
        num_items--;
    }
    return true;
}

template <typename Item_Type>
size_t LinkedList<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}

template <typename Item_Type>
void LinkedList<Item_Type>::displayList() const {
    Node<Item_Type>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Explicit instantiation for int type
template class LinkedList<int>;
