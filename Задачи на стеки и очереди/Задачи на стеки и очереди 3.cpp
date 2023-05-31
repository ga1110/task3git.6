#include <iostream>
using namespace std;

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

stack* result(stack*& h, int num) {
    bool if_first = true;
    stack* res = NULL;
    stack* h1 = NULL;
    reverse(h);
    while (h) {
        int x = pop(h);
        if (if_first && x % 2 != 0) {
            push(res, x);
            push(res, num);
            if_first = false;
        }
        else {
            push(res, x);
        }

    }
    reverse(res);
    return res;
}

int main()
{
    int n, t, x;
    cout << "n = "; cin >> n;
    cout << "t = "; cin >> t;
    stack* head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, x);
    }
    stack* res = result(head, t);
    print(res);
}

