#include <bits/stdc++.h>
using namespace std;

int mmax(int n){
    int tmp, res = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        res = max(res, tmp);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r1, p1, p2, n, tmp, A, B;
    while(cin >> n){
        r1 = mmax(n);
        cin >> n;
        p1 = mmax(n);
        cin >> n;
        p2 = 5005;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            p2 = min(p2, tmp);
        }
        cin >> A >> B;
        cout << fixed << setprecision(15) << double(r1)*sqrt(double(B*p1)/(B*p1 + A*p2)) << endl;
    }
    return 0;
}