#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    set<int> s;
    for(int i = 0; i < 10; i++){
        cin >> x;
        s.insert(x % 42);
    }
    cout << s.size() << endl;
    return 0;
}