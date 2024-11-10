#include <bits/stdc++.h>

#ifndef stacklist__cpp
#define stacklist__cpp

using namespace std;

template <class T>
 class Node {
   public:
    T data;
    Node<T> *next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template <class T>
 class Stack {
    Node<T> *topNode;
    int num;
   public:
    Stack() {
        topNode = NULL;
        num = 0;
    }
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
    int size() {
        return num;
    }
    bool empty() {
        return num == 0;
    }

    T &top() {
        return topNode->data;
    }

    void pop() {
        if (num > 0) {
            Node<T> *temp = topNode;
            topNode = topNode->next;
            delete temp;
            num--;
        }
    }
    void push(T val) {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = topNode;
        topNode = newNode;
        num++;
    }
    void clear() {
        while (topNode) {
            Node<T> *temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        num = 0;
    }
};
#endif 



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Stack<int> s;                      // T?o ng?n x?p ki?u int
    int n; cin >> n;                   // ??c s? l??ng ph?n t?
    for (int i = 0; i < n; i++) {
        int x; cin >> x;               // ??c t?ng ph?n t?
        s.push(x);                     // Them vao ng?n x?p
    }
    
    while (!s.empty()) {          // in phan tu trong mang     
        cout << s.top() << ' ';        
        s.pop();                       
    }
    
    if (!s.empty()) {
        cout << s.top() << endl;
    } else {
        cout << "\nEmpty!" << endl;   
    }
    
    return 0;
}

