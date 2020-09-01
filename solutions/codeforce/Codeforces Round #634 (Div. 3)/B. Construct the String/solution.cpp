#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        int cur = 0;
        for(int i = 0; i < n; i++){
            s += char(cur + 'a');
            cur = (cur + 1) % b;
        }
        cout << s << endl;
    }
    return 0;
}