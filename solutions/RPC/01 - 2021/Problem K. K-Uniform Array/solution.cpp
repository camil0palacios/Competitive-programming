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
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
int n, k;
int a[Mxn];
int bit[Mxn];

void update(int i, int val) {
    while(i < Mxn) { 
        bit[i] += val; 
        i += i & -i;
    }
}

int sum(int i) {
    int ans = 0;
    while(i > 0) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

int query(int l, int r) {
    return sum(r) - sum(l-1);
}

struct Query {
    int l, r;
    Query(){}
    Query(int l, int r): l(l), r(r) {}
};

int solve(vector<Query> & q) {
    int ans = 1e9, j = 0;
    map<int,int> lst;
    fore(i,1,n) {
        if(lst.count(a[i])) update(lst[a[i]], -1);
        lst[a[i]] = i;
        update(i, 1);
        while(j < sz(q) && q[j].r == i) {
            ans = min(ans, query(q[j].l, q[j].r) - 1);
            j++;
        }
    }
    return ans != 1e9 ? ans : -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    fore(i,1,n) cin >> a[i];
    vector<Query> q;
    map<int, vi> s;
    fore(i,1,n) {
        s[a[i]].eb(i);
        if(sz(s[a[i]]) >= k) {
            int l = sz(s[a[i]]);
            q.eb(s[a[i]][l-k], s[a[i]][l-1]);
        }
    }
    cout << solve(q) << endl;
    return 0; 
}