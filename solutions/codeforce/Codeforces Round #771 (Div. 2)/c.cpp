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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        fori(i, 0, n)
        {
            int a;
            cin >> a;
            vi tmp;
            for (auto it = s.lower_bound(a); it != s.end(); it++)
            {
                tmp.eb(*it);
            }
            if (sz(tmp))
            {
                fori(j, 0, sz(tmp) - 1)
                {
                    s.erase(tmp[j]);
                }
            }
            else
                s.insert(a);
        }
        cout << sz(s) << endl;
    }
    return 0;
}