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
        int n, k;
        string s;
        cin >> n >> k >> s;
        bool ok = 1;
        int o = 0, z = 0;
        for(int i = 0; i < k; i++) {
            int tmp = -1;
            for(int j = i; j < n; j += k) {
                if(s[j] != '?') {
                    if(tmp != -1 && s[j] - '0' != tmp) {
                        ok = 0;
                        break;
                    }
                    tmp = s[j] - '0';
                }
            }
            if(tmp != -1) {
                (tmp ? o++ : z++);
            }
        }
        if(o > k/2 || z > k/2) ok = 0;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}