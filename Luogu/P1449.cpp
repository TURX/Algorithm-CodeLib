#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct StackBox {
    int stack[1003], cnt = 0;
    inline void push(const int& x) {
        stack[cnt++] = x;
    }
    inline void pop() {
        cnt--;
    }
    inline int top() {
        return stack[cnt - 1];
    }
    inline bool empty() {
        return !cnt;
    }
} Stack;

string expression;
char currentRead;
int currentNumber, a, b;

int main() {
    while((currentRead = getchar()) != '@') {
        if(currentRead >= '0' && currentRead <= '9') {
            currentNumber = currentNumber * 10 + (currentRead - '0');
        } else {
            switch(currentRead) {
                case '.':
                    Stack.push(currentNumber);
                    currentNumber = 0;
                    break;
                case '-':
                    b = Stack.top(); Stack.pop();
                    a = Stack.top(); Stack.pop();
                    Stack.push(a - b);
                    break;
                case '+':
                    b = Stack.top(); Stack.pop();
                    a = Stack.top(); Stack.pop();
                    Stack.push(a + b);
                    break;
                case '*':
                    b = Stack.top(); Stack.pop();
                    a = Stack.top(); Stack.pop();
                    Stack.push(a * b);
                    break;
                case '/':
                    b = Stack.top(); Stack.pop();
                    a = Stack.top(); Stack.pop();
                    Stack.push(a / b);
                    break;
            }
        }
    }
    printf("%d\n", Stack.top());
    return 0;
}