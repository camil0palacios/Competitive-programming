#include <bits/stdc++.h>
 using namespace std;

 int main(){
    int r,x,y,x1,y1;
    scanf("%d %d %d %d %d",&r,&x,&y,&x1,&y1);
    printf("%d", (int)ceil(sqrt(((double)(x-x1)*(x-x1))+((double)(y-y1)*(y-y1)))/(2*r)));
    return 0;
 }
