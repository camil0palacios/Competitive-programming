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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int fact(int x) {
    int ans = 0;
    for(int i = 2; i*i <= x; i++) while(x % i == 0) ans++, x /= i;
    if(x > 1) ans++;
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, k;
        cin >> a >> b >> k;
        if(a > b) swap(a, b);
        if(k == 1) {
            if(b % a == 0 && a != b) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue; 
        }
        int x = fact(a) + fact(b);
        cout << (x >= k ? "YES" : "NO") << endl;
    }
    return 0; 
}