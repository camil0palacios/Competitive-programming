#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

bool is_subsequence(string & s, string & t) {
    int i = 0;
    for(auto & c : s) {
        if(c == t[i]) i++;
        if(i == sz(t)) return 1;
    }
    return 0;
}

void sol() {
    string s, t;
    cin >> s >> t;
    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    for(char c : s) cnt[c - 'a']++;
    int p[3] = {0, 1, 2};
    do {
        string ans;
        fori(i,0,3) ans += string(cnt[p[i]], char(p[i] + 'a'));
        fori(i,3,26) ans += string(cnt[i], char(i + 'a'));
        if (!is_subsequence(ans, t)) {
            cout << ans << endl;
            return;
        }
    } while (next_permutation(p, p + 3));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) sol();
    return 0;
}