#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int cnt_dig(int x) {
    int cnt = 0;
    while(x) x /= 10, cnt++;
    return cnt;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;
        while(x1 % 10 == 0) x1 /= 10, p1++;
        while(x2 % 10 == 0) x2 /= 10, p2++;
        if(p1 == p2) {
            if(x1 == x2) cout << "=" << endl;
            else cout << (x1 < x2 ? "<" : ">") << endl;
        } else {
            int p = cnt_dig(x1) + p1;
            int q = cnt_dig(x2) + p2;
            if(p == q) {
                string s = to_string(x1);
                string t = to_string(x2);
                cout << (s < t ? "<" : ">") << endl;
            }
            else if(p < q) cout << "<" << endl;
            else cout << ">" << endl; 
        }
    }
    return 0; 
}