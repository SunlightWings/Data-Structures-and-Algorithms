#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* previous;

    Node(int data, Node* next = nullptr, Node* previous = nullptr)
        : data(data), next(next), previous(previous) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void insertAtStart(int data) {
        if (head == nullptr) {
            Node* newNode = new Node(data);
            head = newNode;
        } else {
            Node* newNode = new Node(data);
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }

    void deleteNode(int data) {
        Node* temp = head;
        if (temp->next != nullptr) {
            if (temp->data == data) {
                temp->next->previous = nullptr;
                head = temp->next;
                temp->next = nullptr;
                delete temp;
                return;
            } else {
                while (temp->next != nullptr) {
                    if (temp->data == data) {
                        break;
                    }
                    temp = temp->next;
                }

                if (temp->next) {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                    temp->next = nullptr;
                    temp->previous = nullptr;
                    delete temp;
                } else {
                    temp->previous->next = nullptr;
                    temp->previous = nullptr;
                    delete temp;
                }
                return;
            }
        }

        if (temp == nullptr) {
            return;
        }
    }

    void printDoublyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtEnd(3);
    dll.insertAtStart(4);
    dll.printDoublyLinkedList();
    dll.deleteNode(2);
    dll.printDoublyLinkedList();

    return 0;
}

/*output:
4 2 1 3 
4 1 3 
  */
