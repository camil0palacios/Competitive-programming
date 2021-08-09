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
    int n, m, k;
    cin >> n >> m >> k;
    int sq = sqrt(m);
    vi div;
    fore(i,1,sq) {
        if(m % i == 0) {
            div.eb(i);
            int x = m / i;
            if(x != i) div.eb(x);
        }
    }
    sort(all(div));
    div.pop_back();
    int i = lower_bound(all(div), k) - div.begin();
    if(i != sz(div)) {
        if(n & 1) cout << "Timur" << endl;
        else cout << "Marsel" << endl;
    } else cout << "Marsel" << endl;
    return 0; 
}