#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;
string s;
set<string> ans;

void backtrack(int msk, string & tmp) {
    if(msk == (1 << (int)s.size()) - 1) {
        ans.insert(tmp);
        return;
    }
    for(int i = 0; i < s.size(); i++) {
        if(!((msk >> i) & 1)) {
            tmp += s[i];
            backtrack(msk | (1 << i), tmp);
            tmp.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    string tmp;
    backtrack(0, tmp);
    cout << ans.size() << endl;
    for(auto & c : ans) {
        cout << c << endl;
    }
    return 0; 
}