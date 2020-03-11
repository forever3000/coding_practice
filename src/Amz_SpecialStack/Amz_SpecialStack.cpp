#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    private:
        stack<int> a;
    public:
        SpecialStack(){};
        ~SpecialStack(){};
        void Push(int);
        int Pop();
        bool IsEmpty();
        bool IsFull(int);
        int GetMin();
};

void SpecialStack::Push(int value) {
    if (a.empty()) {
        a.push(value);
    } else {
        if (value > a.top()) {
            int temp = a.top();
            a.pop();
            a.push(value);
            a.push(temp);
        } else {
            a.push(value);
        }
    }
}

int SpecialStack::Pop() {
    if (a.size() == 0) {
        return -1;
    } else {
        if (a.size() > 1) {
            int min = a.top();
            a.pop();
            int temp = a.top();
            a.pop();
            a.push(min);
            return temp;
        } else {
            int temp = a.top();
            a.pop();
            return temp;
        }
    }
}

bool SpecialStack::IsEmpty() {
    return (a.empty());
}

bool SpecialStack::IsFull (int n) {
    if (a.size() > n) {
        return true;
    } else {
        return false;
    }
}

int SpecialStack::GetMin () {
    return a.top();
}

int main (void) {
    SpecialStack *stack = new SpecialStack;
    stack->Push(5);
    stack->Push(6);
    stack->Push(7);
    stack->Push(3);
    stack->Push(2);
    stack->Push(10);
    stack->Push(9);
    cout << "Pop = " << stack->Pop() << endl;
    cout << "Pop = " << stack->Pop() << endl;
    cout << "Pop = " << stack->Pop() << endl;
    cout << "Empty = " << stack->IsEmpty() << endl;
    cout << "Min = " << stack->GetMin() << endl;
    cout << "Full = " << stack->IsFull(5) << endl;

    return 0;
}
