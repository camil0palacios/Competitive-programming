#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

map<string, string> m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    m["purple"] = "Power";
    m["green"] = "Time";
    m["blue"] = "Space"; 
    m["orange"] = "Soul";
    m["red"] = "Reality";
    m["yellow"] = "Mind";
    int n;
    cin >> n;
    set<string> s;
    for(int i = 0; i < n; i++) {
        string x; cin >> x;
        s.insert(x);
    }
    vector<string> v;
    for(auto & e : m) {
        if(!s.count(e.first)) {
            v.emplace_back(e.second);
        }
    }
    cout << v.size() << endl;
    for(auto & i : v) {
        cout << i << endl;
    }
    return 0;
}