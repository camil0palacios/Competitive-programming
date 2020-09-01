#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    int a[n], b[n];
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for(int i = 0; i < n; i++) {
        a[i] += (s[i] == 'a') + (i ? a[i - 1] : 0);
        b[i] += (s[i] == 'b') + (i ? b[i - 1] : 0);
    }
    int ans = 0;
    int sa = 0, sb = 0;
    for(int i = 0; i < n; i++) {
        if(!(i & 1)) continue;
        if(sa + a[i] < sb + b[i]) {
            ans++;
            sa++, sb--, s[i] = 'a';
        }
        else if(sa + a[i] > sb + b[i]) {
            ans++;
            sb++, sa--, s[i] = 'b';
        } 
    }
    cout << ans << endl;
    cout << s << endl;
    return 0;
}