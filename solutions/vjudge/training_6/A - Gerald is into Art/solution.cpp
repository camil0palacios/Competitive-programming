#include <bits/stdc++.h>
using namespace std;

bool check(int a1, int b1, int a2, int b2, int a3, int b3){
    return a2 + a3 <= a1 && b2 <= b1 && b3 <= b1;
}

int main(){
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    bool ans = 0;
    if(check(a1,b1,a2,b2,a3,b3) || check(a1,b1,a2,b2,b3,a3) || check(a1,b1,b2,a2,a3,b3) || check(a1,b1,b2,a2,b3,a3) || 
        check(b1,a1,a2,b2,a3,b3) || check(b1,a1,a2,b2,b3,a3) || check(b1,a1,b2,a2,a3,b3) || check(b1,a1,b2,a2,b3,a3) ){
        ans = 1;
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}