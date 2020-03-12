#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        string ms = s; int mn = 1;
        for(int i = 0; i < s.size() - 1; i++){
            string y = s.substr(0, i);
            string x = s.substr(i, n - i);
            if(x.size() % 2 != 0)reverse(y.begin(), y.end());
            x += y;
            if(x < ms){
                ms = x;
                mn = i + 1;
            }
        }
        reverse(s.begin(), s.end());
        if(s < ms){
            ms = s;
            mn = n;
        }
        cout << ms << endl << mn << endl;
    }
    return 0;
}