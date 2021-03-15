#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 10000;

int check(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int r1 = x % 10;
        int r2 = y % 10;
        cnt += r1 != r2;
        x /= 10, y /= 10;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m[x].emplace_back(i);
        }
        int ans = 0;
        map<int, vector<int>> tmp = m;
        for(auto & x : m) {
            while(x.second.size() > 1) {
                int num = x.first;
                int mn = 5, found = 0;
                for(int i = 0; i <= mod; i++) {
                    int poss = (num + i) % mod;
                    if(!tmp.count(poss)) {
                        int ch = check(poss, num);
                        if(ch < mn) {
                            found = poss;
                            mn = ch;
                        }
                    }
                }
                ans += mn;
                tmp[num].pop_back();
                tmp[found].emplace_back(x.second.back());
                x.second.pop_back();
            } 
        }
        vector<string> res(n);
        for(auto & x: tmp) {
            string tmp(4, '0');
            int num = x.first;
            for(int i = 3; i >= 0; i--) {
                int r = num % 10;
                tmp[i] = char(r + '0');
                num /= 10;
            }
            res[x.second.back()] = tmp;
        }
        cout << ans << endl;
        for(int i = 0; i < n; i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}