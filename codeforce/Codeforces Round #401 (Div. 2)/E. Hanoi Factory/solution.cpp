#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100005;
struct ring{
    long long inner, outer, h;
    ring(){}
    bool operator<(ring & o){
        if(outer == o.outer)return inner > o.inner;
        return outer > o.outer;
    }
};

int main(){
    int n;
    cin >> n;
    vector<ring> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].inner >> v[i].outer >> v[i].h;
    }
    sort(v.begin(), v.end());
    stack<int> s;
    vector<long long> ans(n);
    long long mmax = 0;
    for(int i = 0; i < n; i++){
        while(!s.empty() && v[s.top()].inner >= v[i].outer){
            s.pop();
        }
        if(!s.empty()){
            ans[i] = ans[s.top()];
        }
        ans[i] += v[i].h;
        s.push(i);
        mmax = max(mmax, ans[i]);
    }
    cout << mmax << endl;
    return 0;
}