#include <bits/stdc++.h>
#define endl '\n'
#define forr(i, a, b) for(int i = a; i >= b; i--)
#define fori(i, a, b) for(int i = 0; i < b; i++)
#define ll long long
#define ft first
#define sd second
#define all(v) v.begin(),v.end()
using namespace std;

typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> ev(2*n, {0, 0});
    fori(i, 0, 2*n) {
        char c; cin >> c;
        if(c == '+') ev[i].ft = 1;
        else {
            ev[i].ft = -1;
            cin >> ev[i].sd;
        }
    }
    vector<int> ans;
    stack<int> s;
    forr(i, 2*n - 1, 0) {
        if(ev[i].ft > 0) {
            if(s.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            ans.emplace_back(s.top());
            s.pop();
        } else {
            if(!s.empty() && s.top() < ev[i].sd) {
                cout << "NO" << endl;
                return 0;
            }
            s.push(ev[i].sd);
        }
    }
    cout << "YES" << endl;
    reverse(all(ans));
    for(auto & i: ans) {
        cout << i << ' ';
    }
    return 0;
}