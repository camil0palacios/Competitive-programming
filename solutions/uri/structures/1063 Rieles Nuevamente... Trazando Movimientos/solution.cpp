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
typedef vector<char> vc;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n, n) {
        vc a(n+1), b(n+1);
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) cin >> b[i];
        stack<char> s;
        bool ok = 1;
        int j = 0;
        string ans;
        fori(i,0,n) {
            if(!s.empty() && s.top() == b[i]) ans += "R", s.pop();
            else {
                if(j >= n) { ok = 0; break; }
                while(j < n && a[j] != b[i]) ans += "I", s.push(a[j++]);
                if(a[j] != b[i]) { ok = 0; break; }
                ans += "IR";
                j++;
            }
        }
        cout << ans;
        if(!ok && !s.empty()) cout << " Impossible";
        cout << endl;
    }
    return 0; 
}