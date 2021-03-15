#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;
const int MXN = 1e5 + 7;
int x[MXN], t[MXN];

int lis(vector<ii>& a) {
    vector<int> v;
    for(int i = 0; i < a.size(); i++) {
        int val = a[i].second;
        int pos = upper_bound(v.begin(), v.end(), val) - v.begin();
        if(pos >= v.size()) v.emplace_back(val);
        else v[pos] = val;
    }
    return v.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> t[i];
    }
    cin >> v;
    vector<ii> a, b;
    for(int i = 0; i < n; i++) {
        int p = +x[i] + t[i] * v;
        int q = -x[i] + t[i] * v;
        a.emplace_back(p, q);
        if(q >= 0 && p >= 0)
            b.emplace_back(p, q);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << lis(b) << ' ' << lis(a) << endl;
    return 0;
}