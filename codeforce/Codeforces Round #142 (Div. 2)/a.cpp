#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef pair<int,int> ii;

bool cmp(const ii & a, const ii & b){
    if(a.ff != b.ff)return a.ff < b.ff;
    return a.ff > b.ff;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long s;
    int n;
    while(cin >> s >> n){
        deque<ii> v(n);
        for(auto & i : v)cin >> i.ff >> i.ss;
        sort(v.begin(), v.end(), cmp);
        while(!v.empty() && s > v.front().ff){
                s += v.front().ss;
                v.pop_front();
        }
        if(v.empty())cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}