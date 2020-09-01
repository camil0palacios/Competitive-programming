#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> ii;

struct cmp {
    bool operator()(const ii & a, const ii & b) {
        int la = a.ss - a.ff + 1;
        int lb = b.ss - b.ff + 1;
        if(la == lb) return a.ff < b.ff;
        return la > lb;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        int a[n + 1];
        set<ii, cmp> s;
        s.insert({1, n});
        for(int i = 1; i <= n; i++){
            auto p = *s.begin();
            s.erase(s.begin());
            int mid = (p.ff + p.ss) / 2;
            a[mid] = i;
            if(p.ff < mid)s.insert({p.ff, mid - 1});
            if(mid < p.ss)s.insert({mid + 1, p.ss});
        }
        for(int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}