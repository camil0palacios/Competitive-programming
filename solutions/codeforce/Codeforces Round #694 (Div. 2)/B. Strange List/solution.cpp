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
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vi a(n);
        queue<pair<ll,ll>> q;
        ll s = 0;
        fori(i,0,n) {
            cin >> a[i];
            s += a[i];
            q.push({a[i], 1});
        }
        while(!q.empty()) {
            auto y = q.front();
            q.pop();
            if(y.ft % x == 0) {
                s += y.ft*y.sd;
                q.push({y.ft / x, y.sd * x});
            }
            else break;
        }
        cout << s << endl;
    }
    return 0; 
}