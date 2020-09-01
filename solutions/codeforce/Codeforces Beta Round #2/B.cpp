#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[1001][1001][2];
int dp[1001][1001][2];
int idx;

void f_dp(int n, int m){
    dp[0][0][m] = a[0][0][m];
    for(int i = 1; i < n; i++){
        dp[0][i][m] = dp[0][i-1][m] + a[0][i][m];
        dp[i][0][m] = dp[i-1][0][m] + a[i][0][m];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j][m] = min(dp[i-1][j][m], dp[i][j-1][m]) + a[i][j][m];
        }
    }
}

bool two_five(int n){
    bool aux = 0;
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            if(num == 0){num = 10; aux = 1; idx = i;}
            a[i][j][0] = a[i][j][1] = 0;
            while(num % 2 == 0){
                a[i][j][0]++;
                num /= 2;
            }
            while(num % 5 == 0){
                a[i][j][1]++;
                num /= 5;
            }
        }
    }
    return aux;
}

void print(int i, int j, int n){
    if(i > 0 || j > 0){
        if(i == 0){
            print(i, j-1, n);
            cout << 'R';
            return;
        }
        if(j == 0){
            print(i-1, j, n);
            cout << 'D';
            return;
        }
        if(dp[i-1][j][n] + a[i][j][n] == dp[i][j][n]){
            print(i-1, j, n);
            cout << 'D';
            return;
        }else{
            print(i, j-1, n);
            cout << 'R';
            return;
        }
    }
}

int main(){

    int n;
    cin >> n;
    bool aux = two_five(n);
    f_dp(n,0);
    f_dp(n,1);
    /*
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++)
                cout << a[j][k][i] <<" ";
            cout << endl;
        }
        cout << "------------" << endl;
    }*/

    int k = 1;
    int cost = min(dp[n-1][n-1][0], dp[n-1][n-1][1]);
    if(dp[n-1][n-1][0] < dp[n-1][n-1][1])k = 0;
    if(aux && cost > 0){
        cout << 1 << endl;
        for(int i = 0; i < idx; i++)cout << 'D';
        for(int i = 1; i < n; i++)cout << 'R';
        for(int i = idx + 1; i < n; i++)cout << 'D';
        cout << endl;
    }
    else{
        cout << cost << endl;
        print(n-1,n-1,k);
        cout << endl;
    }
    return 0;
}