#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#ifndef __stackMang__
#define __stackMang__
template<typename T>
class Stack{
private:
    int Size;
    int Space;
    T* elem; 
public:
    Stack() {
        Size = Space = 0;
        elem = NULL;
    }
    ~Stack() {
        if (elem != NULL) delete[] elem;
    }
    Stack<T>& operator=(Stack<T>& s) {
        if (this == &s) return *this;
        this->Size = s.Size;
        this->Space = s.Space;
        if (elem != NULL) delete[] elem;
        elem = new T[Space];
        for(int i = 0; i < Size; i++){
            elem[i] = s.elem[i];
        }
        return *this;
    }
    Stack(Stack<T>& s) {
        *this = s;
    }
    int size() {
        return Size;
    }
    bool empty() {
        return Size == 0;
    }
    T& top() {
        return elem[Size - 1];
    }
    void pop() {
        if (empty()) return;
        Size--;
    }
    void clear() {
        Size = 0;
    }
    void push(T val) {
        if (Size == Space) {
            Space = Size == 0 ? 1 : Size * 2;
            T* temp = new T[Space];
            for (int i = 0; i < Size; i++) {
                temp[i] = elem[i];
            }
            if (elem != NULL) delete[] elem;
            elem = temp;
        }
        elem[Size] = val;
        ++Size;
    }
};
#endif
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int T;
    cin >> T;

    Stack<int> stack;

    while (T--) {
        int type;
        cin >> type;

        if (type == 1) {
            int n;
            cin >> n;
            stack.push(n);
        } else if (type == 2) {
            if (!stack.empty()) {
                stack.pop();
            }
        } else if (type == 3) {
            if (!stack.empty()) {
                cout << stack.top() << endl;
            } else {
                cout << "Empty!" << endl;
            }
        }
    }

    return 0;
}
