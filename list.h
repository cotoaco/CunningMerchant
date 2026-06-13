#ifndef LIST_H
#define LIST_H
#include <stdexcept>
template <typename T>
class CircularList{
private:
    struct Node{
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* tail;
    size_t list_size;
public:
    CircularList() : tail(nullptr), list_size(0) {}
    ~CircularList() {
        clear();
    }
    size_t size() const {
        return list_size;
    }
    bool empty() const {
        return list_size == 0;
    }
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            newNode->next = newNode;
            tail = newNode;
        }
        else{
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        list_size++;
    }
    void clear() {
        if (empty()) return;
        Node* curr = tail->next;
        tail->next = nullptr;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        tail = nullptr;
        list_size = 0;
    }
    class Iterator {
    private:
        Node* curr;
        Node* prev;
        CircularList* list;
    friend class CircularList;
    public:
        Iterator(Node* curr, Node* prev, CircularList* list)
            : curr(curr), prev(prev), list(list) {}
        T& operator*() {return curr->data; }
        void next(){
            if(!curr) return;
            prev = curr;
            curr = curr->next;
        }
        Node* get_curr() const {return curr;}
        Node* get_prev() const {return prev;}
    };
    Iterator begin() {
        if(empty()) return Iterator(nullptr, nullptr, this);
        return Iterator(tail->next, tail, this);
    }
    void eraseAndNext(Iterator& it) {
        if (empty() || it.curr == nullptr) return;
        Node* toDelete = it.curr;
        if(list_size == 1) {
            tail = nullptr;
            it.curr = nullptr;
            it.prev = nullptr;
        }
        else{
            it.prev->next = toDelete->next;
            if(toDelete == tail) {
                tail = it.prev;
            }
            it.curr = toDelete->next;
        }
        delete toDelete;
        list_size--;
    }
};
#endif