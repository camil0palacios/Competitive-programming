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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
int a[Mxn], cnt[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int mx = 0, idx = 0;
    fori(i,0,n) {
        cin >> a[i];
        cnt[a[i]]++;
        if(mx < cnt[a[i]]) {
            mx = cnt[a[i]];
            idx = i;
        }
    }
    cout << n - mx << endl;
    forr(i,idx-1,0) {
        if(a[i] != a[idx]) {
            cout << (a[i] < a[idx] ? 1 : 2) << ' ';
            cout << i+1 << ' ' << i+2 << endl;
        
        }
    }
    fori(i,idx+1,n) {
        if(a[i] != a[idx]) {
            cout << (a[i] < a[idx] ? 1 : 2) << ' ';
            cout << i+1 << ' ' << i << endl;
        }
    }
    return 0; 
}