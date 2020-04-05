#include<bits.h> 
using namespace std;
int main() 
{ 
cout<<"enter the n value "<<endl;
cin>>n;
cout << "F(n) is " <<term(n); 
return 0; 
} 
int term(int n) 
{ 

	int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
	if(n==0) 
		return 0; 
	if(n==1 || n==2) 
		return 1; 

	return fun(F, n-2); 
}
int fun(int F[3][3], int n) 
{ 
	int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
	if (n==1) 
		return F[0][0] + F[0][1]; 

	fun(F, n/2); 

	multiply(F, F); 
    if (n%2 != 0) 
		multiply(F, M);
	return F[0][0] + F[0][1] ; 
}
void multiply(int a[3][3], int b[3][3]) 
{ 
	int mul[3][3]; 
	for (int i = 0; i < 3; i++) 
	{ 
		for (int j = 0; j < 3; j++) 
		{ 
			mul[i][j] = 0; 
			for (int k = 0; k < 3; k++) 
				mul[i][j] += a[i][k]*b[k][j]; 
		} 
	}
	for (int i=0; i<3; i++) 
		for (int j=0; j<3; j++) 
			a[i][j] = mul[i][j];
} 
