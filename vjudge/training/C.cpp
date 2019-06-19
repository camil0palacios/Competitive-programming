#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 5;
int a[nmax];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, [&](int x, int y){
        return x > y;
    });
    if(n1 > n2)swap(n1, n2);
    double sum = 0;
    int i;
    for(i = 0; i < n1; i++){
        sum += (double)a[i];
    }
    sum /= n1;
    double sum2 = 0;
    for(int j = 0; j < n2; j++){
        sum2 += (double)a[j+i];
    }
    sum2 /= n2;
    cout << fixed << setprecision(10) << sum + sum2 << endl;
    return 0;
}