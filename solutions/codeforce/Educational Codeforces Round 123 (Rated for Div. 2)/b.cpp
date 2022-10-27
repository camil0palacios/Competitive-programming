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

vector<vi> ans;
int n;

void rec(int i, int p1, int p2, vi & vis, vi & tmp) {
    if(i == n) {
        ans.emplace_back(tmp);
        return;
    }
    fore(j,1,n) {
        if(!vis[j] && p1 + p2 != j) {
            tmp[i] = j;
            vis[j] = 1;
            rec(i+1, p2, j, vis, tmp);
            vis[j] = 0;
            tmp[i] = 0;
            if(sz(ans) == n) return;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        ans.clear();
        vi vis(n+1), tmp(n);
        rec(0, 0, 0, vis, tmp);
        for(auto v : ans) {
            for(auto i : v) cout << i << ' ';
            cout << endl;
        }
    }
    return 0; 
}