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
        int n;
        cin >> n;
        int s = 0, one = 0, two = 0;
        fori(i,0,n) {
            int x; cin >> x;
            s += x;
            two += x == 2;
            one += x == 1;
        }
        if(s % 2 == 0) {
            if(one || (two % 2 == 0)) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
    return 0; 
}