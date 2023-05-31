
#include <iostream>
using namespace std;
//1 1 1 2 2 2 3 3 3 4 4 4 5 5 5
struct queue {
    int inf;
    queue* next;
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
    int y;
    stack* res = NULL;
    stack* h1 = NULL;
    int x = pop(h);
    push(res, x);
    while (h) {
        y = pop(h);
        if (x != y) {
            push(res, y);
            x = y;
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

