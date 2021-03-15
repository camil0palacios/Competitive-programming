#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        string s;
        cin >> n >> q >> s;
        for(int qq = 0; qq < q; qq++) {
            int l, r; cin >> l >> r;
            l--, r--;
            bool ok = 0;
            for(int i = 0; i < l; i++) if(s[i] == s[l]) ok = 1;
            for(int i = r+1; i < n; i++) if(s[i] == s[r]) ok = 1; 
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
    return 0; 
}