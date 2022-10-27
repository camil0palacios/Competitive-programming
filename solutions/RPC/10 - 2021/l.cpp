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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n) {
        vii a(n);
        fori(i,0,n) cin >> a[i].ft >> a[i].sd;
        sort(all(a));
        int city = 0, lst = 0;
        fori(i,0,n) {
            int c =  a[i].ft + a[i].sd;
            int l = i, r = n-1, pos = -1;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(a[m].ft < c) pos = m, l = m+1;
                else r = m-1;
            }
            if(pos != -1 && lst - city < pos - i) city = i, lst = pos; 
        }
        cout << a[city].ft << ' ' << (lst - city) << endl;
    }
    return 0; 
}