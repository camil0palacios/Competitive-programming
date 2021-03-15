#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, tc = 0;
    while(cin >> n, n) { 
        int x, f = 0;
        while(cin >> x, x) {
            vi a(n);
            a[0] = x;
            fori(i,1,n) cin >> a[i];
            stack<int> s;
            int x = 1;
            bool ok = 1;
            for(int i = 0; i < n; i++) {
                if(!s.empty() && a[i] == s.top()) s.pop();
                else {
                    while(x <= n && x < a[i]) s.push(x++);
                    if(x != a[i]) { ok = 0; break; }
                    x++;
                }
            }
            if(ok && s.empty()) cout << "Yes";
            else cout << "No";
            cout << endl;
        }
        cout << endl;
    }
    return 0; 
}