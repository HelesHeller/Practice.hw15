#include <iostream>
#include<windows.h>

using namespace std;

template <typename T>
class LinkedList 
{
private:
    struct Node 
    {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() 
    {
        DeleteAll();
    }

    void AddToHead(const T& value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(const T& value) 
    {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (head == nullptr) {
            return; // Список порожній
        }

        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;

        if (head == nullptr) {
            tail = nullptr; // Список був з одного елемента
        }
    }

    void DeleteFromTail() {
        if (tail == nullptr) {
            return; // Список порожній
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* currentNode = head;
        while (currentNode->next != tail) {
            currentNode = currentNode->next;
        }

        currentNode->next = nullptr;
        delete tail;
        tail = currentNode;
    }

    void DeleteAll() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }

        head = nullptr;
        tail = nullptr;
    }

    void Show() const {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
};


int main() {
    LinkedList<int> list;

    list.AddToHead(3);
    list.AddToHead(2);
    list.AddToHead(1);

    list.AddToTail(4);
    list.AddToTail(5);

    list.Show(); // Виведе: 1 2 3 4 5

    list.DeleteFromHead();
    list.DeleteFromTail();

    list.Show(); // Виведе: 2 3 4

    list.DeleteAll();

    list.Show(); // Виведе пустий рядок

    return 0;
}
