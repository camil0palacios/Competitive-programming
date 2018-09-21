#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,s,x,sum=0,i=1,a=0;
    scanf("%d %d %d",&t,&s,&x);
    sum = t;
    if(t == x) printf("%s","YES");
    else{
        while(sum < x){
            if(i%2 == 0)
                sum = t+(a*s)+1;
            else{
                a++;
                sum = t+(a*s);
            }
            i++;
        }
        if(sum == x)printf("%s","YES");
        else printf("%s","NO");
    }
}
