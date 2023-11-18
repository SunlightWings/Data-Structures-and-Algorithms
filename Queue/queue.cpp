#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> queue;
    int front;
    int rear;
    int limit;
    int size;

public:
    Queue(int limit = 10) : front(-1), rear(-1), limit(limit), size(0) {}

    // To print the contents of the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
        } else {
            for (int i : queue) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }

    // To check if the queue is empty
    bool isEmpty() {
        return size <= 0;
    }

    // To add an element from the rear end of the queue
    void enqueue(int data) {
        if (size >= limit) {
            std::cout << "Queue Overflow\n";
        } else {
            queue.push_back(data);
            if (front == -1) {
                front = rear = 0;
            } else {
                rear = size;
            }
            size++;
        }
    }

    // To pop an element from the front end of the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
        } else {
            queue.erase(queue.begin());
            size--;
            if (size == 0) {
                front = rear = -1;
            } else {
                rear = size - 1;
            }
        }
    }

    // To get the size of the queue
    int getSize() {
        return size;
    }

    // To get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        } else {
            return queue.front();
        }
    }

    // To get the rear element of the queue
    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        } else {
            return queue.back();
        }
    }
};

int main() {
    Queue myQueue;
    for (int i = 0; i < 10; ++i) {
        myQueue.enqueue(i);
    }

    myQueue.display();
    std::cout << "Queue Size: " << myQueue.getSize() << "\n";

    myQueue.dequeue();
    myQueue.display();
    std::cout << "Queue Size: " << myQueue.getSize() << "\n";
    std::cout << "Front Element: " << myQueue.getFront() << "\n";
    std::cout << "Rear Element: " << myQueue.getRear() << "\n";

    return 0;
}


/*
Output:
0 1 2 3 4 5 6 7 8 9 
Queue Size: 10
1 2 3 4 5 6 7 8 9 
Queue Size: 9
Front Element: 1
Rear Element: 9
  */
