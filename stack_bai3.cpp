#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// Ham doc dau vao va tra ve chuoi chua day ngoac
string getInput() {
    string s;
    cin >> s;
    return s;
}

// Ham tim cac cap ngoac dung va tra ve danh sach cac cap chi so
vector<pair<int, int>> findBracket(const string& s) {
    stack<int> stk;
    vector<pair<int, int>> result;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i + 1); // Day vi tri cua dau ngoac mo vao stack
        } else if (s[i] == ')') {
            if (!stk.empty()) {
                int openIndex = stk.top(); // Lay chi so cua dau ngoac mo
                stk.pop();
                result.push_back({openIndex, i + 1}); // Ghep voi vi tri dau ngoac dong
            }
        }
    }
    return result;
}


int main() {
    string s = getInput(); 
    vector<pair<int, int>> pairs = findBracket(s); // Tim cap ngoac
    cout << "***Ket qua:\n ";
	//In ra danh sach cac cap ngoac
	for (const auto& p : pairs) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

