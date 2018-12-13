#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    int mmax = 0;
    for(int i = 0 ; i < n; i++){
        int tmp; cin >> tmp;
        if(!m.count(tmp))m[tmp] = 0;
        m[tmp]++;
        mmax = max(mmax, m[tmp]);
    }
    int pl = ceil(mmax/(double)k);
    cout << (pl * k * m.size()) - n  << endl;
    return 0;
}