#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        set<int> s;
        int mmax = 0;
        for(int i = 0, a; i < n; i++){
            cin >> a;
            s.insert(a);
            mmax = max(mmax, a);
        }
        if(s.count(x)){
            cout << 1 << endl;
        } else {
            cout << max(2, (x - 1) / mmax + 1) << endl;
        }
    }
    return 0;
}