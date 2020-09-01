#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,res;
    cin>>n;
    vector<int> v={100,50,20,10,5,2};
    cout<<n<<endl;
    for(auto &i: v){
        res=n/i;
        cout<<res<<" nota(s) de R$ "<<i<<",00"<<endl;;
        n -= res*i;
    }

    return 0;
}
