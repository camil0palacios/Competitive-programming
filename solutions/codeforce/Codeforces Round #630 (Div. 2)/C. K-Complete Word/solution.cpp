#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXK = 2e5 + 5;
int cnt[MXK][26];

int dif(int x, int y) {
    int mx = 0, sum = 0;
    for(int i = 0; i < 26; i++) {
        sum += cnt[x][i] + cnt[y][i];
        mx = max(mx, cnt[x][i] + cnt[y][i]);
    }
    return sum - mx;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++) {
            cnt[i % k][s[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans += dif(i, k - i - 1);
        }
        cout << ans / 2 << endl;
    }
    return 0;
}