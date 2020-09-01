#include <bits/stdc++.h>
using namespace std;

int main(){
	
	float n,f1,f2,f3,r;
	cin>>n;

	if(n <= 2000){
		cout<< "Isento"<<endl;
	}
	else{

		if( n > 2000 && n <= 3000){
			f1 = n - 2000;
			f1 = f1 * 0.08;
			r = f1;
		}
		else if( n > 3000 && n <= 4500){
			f1 = n - 2000;
			f2 = f1 - 1000;
			f1 -= f2;
			f1 =  f1 * 0.08;
			f2 = f2 * 0.18;
			r = f1 + f2;
		}
		else if(n > 4500){
			f1 = n - 2000;
			f2 = f1 - 1000;
			f3 = f2 - 1500;
			f1 -= f2;
			f2 -= f3;
			f1 =  f1 * 0.08;
			f2 = f2 * 0.18;
			f3 = f3 * 0.28;
			r = f1 + f2 +  f3;
		}
		printf("R$ %.2f\n",r);
	}

	return 0;
}