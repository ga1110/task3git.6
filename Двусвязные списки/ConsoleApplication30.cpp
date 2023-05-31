#include <iostream>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

void push_e(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void push_s(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->prev = NULL;
    if (!h && !t) {
        r->next = NULL;
        t = r;
    }
    else {
        h->prev = r;
        r->next = h;
    }
    h = r;
}

void print(list* h, list* t) {
    list* p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }

}

list* find(list* h, list* t, int x) {
    list* p = h;
    while (p) {
        if (p->inf == x) {
            break;
        }
        p = p->next;
    }
    return p;
}
void push_after(list*& h, list*& t, list* r, int y) {
    list* p = new list;
    p->inf = y;
    if (r == t) {
        p->next = r;
        r->prev = p;
        t = p;
    }
    else {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

void push_before(list*& h, list*& t, list* r, int y) {
    list* p = new list;
    p->inf = y;
    if (r == h) {
        p->prev = r;
        r->next = p;
        h = p;
    }
    else {
        r->prev->next = p;
        p->prev = r->prev;
        p->next = r;
        r->prev = p;
    }
}

void del_node(list*& h, list*& t, list* r) {
    if (r == h && r == t) {
        h = t = NULL;
    }
    else if (r == h) {
        h = h->prev;
        h->prev = NULL;
    }
    else if (r == t) {
        t = t->prev;
        t->next = NULL;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void del_list(list*& h, list*& t) {
    while (h) {
        list* p = h;
        h = h->next;
        h->prev = NULL;
        delete p;
    }
}

int find_min(list* h, list* t) {
    list* p = h;
    int x = p->inf;
    while (p) {
        if (x > p->inf) {
            x = p->inf;
        }
        p = p->next;
    }
    return x;
}
void result(list* h, list* t, int min) {
    list* p = h;
    list* r1 = NULL;
    list* r2 = NULL;
    int x = h->inf;
    while (p) {
        if (p->inf == min) {
            break;
        }
        p = p->next;
    }
    while (p) {
        push_e(r1, r2, p->inf);
        p = p->next;
    }
    p = h;
    while(p->inf != min){
        push_e(r1, r2, p->inf);
        p = p->next;
    }
    print(r1, r2);
}
int main()
{
    list* h = NULL;
    list* t = NULL;
    int n, x, min;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push_e(h, t, x);
    }
    min = find_min(h, t);
    cout << endl;
    result(h, t, min);
}

