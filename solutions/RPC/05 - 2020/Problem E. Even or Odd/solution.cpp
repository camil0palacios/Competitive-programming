#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n == 1) cout << "Either" << endl;
    else if(n == 2) cout << "Odd" << endl;
    else { 
        if(n % 2 == 0) {
            int x = n / 2;
            if(x & 1) cout << "Odd" << endl;
            else cout << "Even" << endl;
        }
        else cout << "Either" << endl;
    }
    return 0;
}