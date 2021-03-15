#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

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
        int ans = 1e9, idx = -1;
        for(auto & i: m) {
            if(i.second.size() == 1) {
                if(i.first < ans) {
                    ans = i.first;
                    idx = i.second[0];
                }
            }
        }
        cout << (idx == -1 ? -1 : idx + 1) << endl;
    }
    return 0; 
}