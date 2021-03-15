#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int mod1 = 999727999;
const int mod2 = 1070777777;
const int prime = 1777771;
const int MXW = 1e5 + 5;
const int MXS = 5050;
int n;
string s;
ll h1[MXS], h2[MXS];
ll ppow1[MXS], ppow2[MXS];
ll mippow1[MXS], mippow2[MXS];
ll dp[MXS];
vector<int> g[MXS];

// struct Hash {
//     const int mod1 = 999728000;
//     const int mod2 = 1070777777;
//     const int prime = 1777771;
//     vector<pair<ll,ll>> h, p, pi;
//     // ll is long long
//     ll be(ll a, ll b, ll m) {
//         ll ans = 1;
//         while(b) {
//             if(b & 1) ans = (ans * a) % m;
//             a = (a * a) % m;
//             b >>= 1;
//         }
//         return ans;
//     }
//     Hash(string s) {
//         h.assign(s.size() + 1, {0, 0});
//         p.assign(s.size() + 1, {0, 0});
//         pi.assign(s.size() + 1, {0, 0});
//         p[0].first = 1, p[0].second = 1;
//         pi[0].first = 1, pi[0].second = 1;
//         for(int i = 0; i < s.size(); i++) {
//             h[i + 1].first = (h[i].first + (s[i] - 'a' + 1) * p[i].first % mod1) % mod1;
//             h[i + 1].second = (h[i].second + (s[i] - 'a' + 1) * p[i].second % mod2) % mod2;
//             p[i + 1].first = (p[i].first * prime) % mod1;
//             p[i + 1].second = (p[i].second * prime) % mod2;
//             pi[i + 1].first = be(p[i + 1].first, mod1 - 2, mod1);
//             pi[i + 1].second = be(p[i + 1].second, mod2 - 2, mod2);
//         }
//     }
//     pair<ll,ll> get(int l, int r) {
//         l++, r++;
//         ll x = ((h[r].first + mod1 - h[l - 1].first) % mod1 * pi[l - 1].first) % mod1;
//         ll y = ((h[r].second + mod2 - h[l - 1].second) % mod2 * pi[l - 1].second) % mod2;
//         return make_pair(x, y); 
//     }
// };

ll go(int u) {
    if(u == 0) return 1;
    if(dp[u] != -1) return dp[u];
    ll ans = 0;
    for(auto & v: g[u]) {
        ans = (ans + go(v)) % mod;
    }
    return dp[u] = ans;
}

ll be(ll a, ll b, ll m) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> n;
    unordered_map<pair<ll, ll>, bool, hash_pair> allhash;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        ll p1 = 1, p2 = 1;
        ll wh1 = 0, wh2 = 0;
        for(int j = 0; j < t.size(); j++) { // words hash
            wh1 = (wh1 + ((t[j] - 'a' + 1) * p1) % mod1) % mod1;
            wh2 = (wh2 + ((t[j] - 'a' + 1) * p2) % mod2) % mod2;
            p1 = (p1 * prime) % mod1;
            p2 = (p2 * prime) % mod2;
        }
        allhash[{wh1, wh2}] = 1; 
    }

    ppow1[0] = 1, mippow1[0] = 1;
    ppow2[0] = 1, mippow2[0] = 1;
    for(int i = 0; i < s.size(); i++) { // hash string
        h1[i + 1] = (h1[i] + ((s[i] - 'a' + 1) * ppow1[i]) % mod1) % mod1;
        h2[i + 1] = (h2[i] + ((s[i] - 'a' + 1) * ppow2[i]) % mod2) % mod2;
        ppow1[i + 1] = (ppow1[i] * prime) % mod1;
        ppow2[i + 1] = (ppow2[i] * prime) % mod2;
        mippow1[i + 1] = be(ppow1[i + 1], mod1 - 2, mod1);
        mippow2[i + 1] = be(ppow2[i + 1], mod2 - 2, mod2);
    }
    dp[0] = 1;
    for(int i = 1; i <= s.size(); i++) {
        for(int len = 1; i + len - 1 <= s.size(); len++) {
            ll x = ((h1[i + len - 1] + mod1 - h1[i - 1]) % mod1 * mippow1[i - 1]) % mod1;
            ll y = ((h2[i + len - 1] + mod2 - h2[i - 1]) % mod2 * mippow2[i - 1]) % mod2;
            if(allhash.count({x, y})) {
                g[i].emplace_back(i - len);
            }
        }
    }
    // cout << dp[n] << endl;
    memset(dp, -1, sizeof dp);
    cout << go(s.size()) << endl;
    return 0;
}