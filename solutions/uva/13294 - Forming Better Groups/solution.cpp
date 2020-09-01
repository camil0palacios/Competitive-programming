#include <bits/stdc++.h>
using namespace std;
int n, d;

int cantBits(int n) {
    int ans = 0;
    while(n) {
        ans += n&1;
        n >>= 1;
    }
    return ans;
}



int sol(vector<int> &l, int idx, int curr) {
    if(idx == l.size()) {
        return cantBits(curr) == n;
    }
    int ans = 0;
    if((curr&l[idx]) == 0) {
        ans += sol(l, idx+1, curr|l[idx]);
    }
    ans += sol(l, idx+1, curr);
    return ans;
}

int mmax(int a, int b, int c) {
    return max(a, max(b, c));
}

int mmin(int a, int b, int c) {
    return min(a, min(b, c));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> d && n && d){
        vector<int> v(n);
        for(int &i: v) {
            cin >> i;
        }
        vector<int> l;
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                for(int k = j + 1; k<n; k++) {
                    if(mmax(v[i], v[j],v[k])-mmin(v[i], v[j], v[k]) <= d) {
                        int temp = 1 << i;
                        temp |= (1 << j);
                        temp |= (1 << k);
                        l.emplace_back(temp);
                    }
                }
            }
        }
        cout << l.size() << '\n';
        cout << sol(l, 0, 0) << '\n';
    }
    return 0;
}