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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<ll, vi, greater<ll>> q;
    int ans = 0;
    ll c = 0; 
    fori(i,0,n) {
        int a; cin >> a;
        c += a;
        q.push(a);
        while(c < 0) {
            c -= q.top();
            q.pop();
        }
    }
    cout << sz(q) << endl;
    return 0; 
}