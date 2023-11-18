#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) : data(data), next(next) {}

    void setData(int data) {
        this->data = data;
    }

    int getData() {
        return data;
    }

    void setNext(Node* next) {
        this->next = next;
    }

    Node* getNext() {
        return next;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void printLinkedList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insertAtStart(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertBetween(Node* previousNode, int data) {
        if (previousNode->next == nullptr) {
            std::cout << "Previous node should have next node!\n";
        } else {
            Node* newNode = new Node(data);
            newNode->next = previousNode->next;
            previousNode->next = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int data) {
        Node* temp = head;
        if (temp->next != nullptr) {
            if (temp->data == data) {
                head = temp->next;
                delete temp;
                return;
            } else {
                Node* prev = nullptr;
                while (temp->next != nullptr) {
                    if (temp->data == data) {
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }

                if (temp == nullptr) {
                    return;
                }

                prev->next = temp->next;
                delete temp;
            }
        }
    }

    bool search(Node* node, int data) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == data) {
            return true;
        }
        return search(node->getNext(), data);
    }
};

int main() {
    LinkedList list;
    list.head = new Node(1);
    Node* node2 = new Node(2);
    list.head->setNext(node2);
    Node* node3 = new Node(3);
    node2->setNext(node3);
    list.insertAtStart(4);
    list.insertBetween(node2, 5);
    list.insertAtEnd(6);
    list.printLinkedList();
    std::cout << "\n";
    list.deleteNode(3);
    list.printLinkedList();
    std::cout << "\n";
    std::cout << std::boolalpha << list.search(list.head, 1) << "\n";

    return 0;
}

/*Output:
4 1 2 5 3 6 
4 1 2 5 6 
true
  */
