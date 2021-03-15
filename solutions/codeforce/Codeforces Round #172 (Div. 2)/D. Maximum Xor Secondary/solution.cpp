#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    fori(i,0,n) cin >> a[i];
    int ans = 0;
    stack<int> stk;
    fori(i,0,n) {
        while(!stk.empty()) {
            ans = max(ans, a[i] ^ stk.top());
            if(a[i] > stk.top()) stk.pop();
            else break;
        }
        stk.push(a[i]);
    }
    cout << ans << endl;
    return 0; 
}