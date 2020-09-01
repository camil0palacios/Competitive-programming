#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int frq[26];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        memset(frq, 0, sizeof frq);
        for(int i = 0; i < a.size(); i++){
            frq[a[i]-'a']++;
        }
        bool ans = 0;
        for(int i = 0; i < b.size(); i++){
            ans |= frq[b[i]-'a'];
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}