
#include <iostream>
using namespace std;

bool prime_num(int x) {
    if (x == 0 || x == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
struct stack {
    int inf;
    stack* next;
};

void push(stack*& h, int x) {
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack*& h) {
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack*& h) {
    stack* head1 = NULL;
    while (h) {
        push(head1, pop(h));
    }
    h = head1;
}

void print(stack*& h) {
    while (h) {
        cout << pop(h) << " ";
        
    }
    cout << endl;
}

stack* result(stack*& h) {
    stack* res = NULL;
    stack* h1 = NULL;
    while (h) {
        int x = pop(h);
        if (prime_num(x) == false) {
            push(res, x);
        }
    }
    return res;
}

int main()
{
    int n;
    cout << "n = "; cin >> n;
    stack* head = NULL;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, x);
    }
    stack* res = result(head);
    print(res);
}

