#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
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
    int t;
    cin >> t;
    while(t--) {
        int q;
        cin >> q;
        stack<vi> s;
        while(q--) {
            int t;
            cin >> t;
            if(t == 1) {
                int v; cin >> v;
                int mx = s.empty() ? v : max(v, s.top()[1]);
                int mn = s.empty() ? v : min(v, s.top()[2]);
                s.push(vi({v, mx, mn})); 
            } else if(t == 2) {
                if(!s.empty()) s.pop();
            } else {
                if(!s.empty()) cout << abs(s.top()[1] - s.top()[2]) << endl;
                else cout << "Empty!" << endl;
            }
        }
    }
    return 0; 
}