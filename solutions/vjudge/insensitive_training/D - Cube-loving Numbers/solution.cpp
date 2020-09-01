#include <bits/stdc++.h>
using namespace std;

vector<bool> criba;
long long n;

void crib(){
    int mmax = 1000005;
    criba.assign(mmax, 1);
    criba[0] = criba[1] = 0;
    for(long long i = 2; i < mmax; i++){
        if(criba[i]){
            for(long long j = i*i; j < mmax; j += i){
                criba[j] = 0;
            }
        }
    }
}

long long go(vector<long long> & v, int i, long long acc, bool par){
    if(i == v.size())return 0;
    long long x = v[i]*v[i]*v[i];
    if(acc > n / x) return 0;
    long long ans = (par ? -1 : 1)*n/acc/x;
    ans += go(v, i + 1, acc * x, par^1);
    ans += go(v, i + 1, acc, par);
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    crib();
    vector<long long> prims;
    for(long long i = 0; i <= 1000000; i++){
        if(criba[i]){
            prims.emplace_back(i);    
        }
    }
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cout << go(prims, 0, 1, 0) << endl;
    }
    return 0;
}