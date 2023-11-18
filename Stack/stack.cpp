#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack;
    int limit;

public:
    Stack(int limit = 10) : limit(limit) {}

    // To print the contents of the stack
    void display() {
        if (stack.empty()) {
            std::cout << "Stack is empty\n";
        } else {
            for (int i : stack) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }

    // To push an element to the stack
    void push(int data) {
        if (stack.size() >= static_cast<size_t>(limit)) {
            std::cout << "Stack Overflow\n";
        } else {
            stack.push_back(data);
        }
    }

    // To pop the uppermost element
    int pop() {
        if (stack.empty()) {
            std::cout << "Stack Underflow\n";
            return -1;
        } else {
            int top = stack.back();
            stack.pop_back();
            return top;
        }
    }

    // For peeking the top-most element of the stack
    int peek() {
        if (stack.empty()) {
            std::cout << "Stack is empty\n";
            return -1;
        } else {
            return stack.back();
        }
    }

    // To check if the stack is empty
    bool isEmpty() {
        return stack.empty();
    }

    // For checking the size of the stack
    int size() {
        return stack.size();
    }
};

int main() {
    Stack myStack;
    for (int i = 0; i < 10; ++i) {
        myStack.push(i);
    }
    
    myStack.display();
    
    myStack.pop(); // Popping the top element
    myStack.display();
    
    std::cout << "Top element: " << myStack.peek() << "\n";
    std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n";
    std::cout << "Size of the stack: " << myStack.size() << "\n";

    return 0;
}


/*Output:
0 1 2 3 4 5 6 7 8 
Top element: 8
Is the stack empty? No
Size of the stack: 9
  */
