#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int n;
int a[MXN];

int bs(vector<int>& v, int l, int r, int val) {
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(v[mid] >= val) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    return ans == -1 ? v.size() : ans;
}

int lis() {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int val = a[i];
        int x = bs(ans, 0, ans.size() - 1, val);
        // int x = upper_bound(ans.begin(), ans.end(), val) - ans.begin();
        // cout << x << ' ' << val << endl;
        if(x >= ans.size()) ans.emplace_back(val); 
        else ans[x] = val;
    }
    return ans.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << lis() << endl;
    return 0;
}