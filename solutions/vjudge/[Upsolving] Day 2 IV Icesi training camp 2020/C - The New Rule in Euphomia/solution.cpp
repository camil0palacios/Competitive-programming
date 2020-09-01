#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1000010;
bool sieve[MXN];
vector<int> p;

void cal() {
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    int i;
    for(i = 2; i * i < MXN; i++) {
        if(sieve[i]) {
            p.emplace_back(i);
            for(int j = i * i; j < MXN; j += i) {
                sieve[j] = 0;
            }
        }
    }
    for(; i < MXN; i++) {
        if(sieve[i]) 
            p.emplace_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int n, cs = 0;
    while(cin >> n && n) {
        long long ans = 0;
        for(int i = 0; i < p.size() && p[i] < n; i++) {
            int l = 0, r = i - 1, j = -1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(p[i] + p[mid] <= n) j = mid, l = mid + 1;
                else r = mid - 1;
            }
            if(j != -1 && p[i] + p[j] <= n) {
                ans += j + 1;
            }
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}