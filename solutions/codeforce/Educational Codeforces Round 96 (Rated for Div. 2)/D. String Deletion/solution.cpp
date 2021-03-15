#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> a;
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && s[i] == s[j]) j++;
            a.emplace_back(j - i);
            i = j - 1;
        }
        n = a.size();
        int ans = 0;
        int i = 0, j = 0;
        while(j < n) {
            while(j < n && (a[j] < 2 || j < i)) j++;
            if(j < n) {
                a[j]--;
                i++, ans++;
            }
        }
        ans += (j - i + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}