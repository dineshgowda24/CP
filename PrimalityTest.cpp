#include <bits/stdc++.h>
using namespace std;

//Euclidian GCD
int gcd(int a, int b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

//Returns (a^n)%p
int binpower(int a,int n,int p)
{
	int res=1;
	a=a%p; //Just in case a > p
	while(n)
	{
		if(n&1)
			res=(res*a)%p;
		
		n=n>>1;
		a=(a*a)%p;
	}
	return res;
}

//Fermant's Theorm is probablity test.
//If its a prime, it dosen't mean its actually prime, it means its probably prime.
//We can take k to be [2 to n-2], but it becomes more complex than naive approch.
bool fermantprime(int n,int k)
{
	if(n<=1||n==4)
		return 0;
	if(n<=3)
		return 1;
	
	while(k)
	{
		int p=2+rand()%(n-4);
		
		if(gcd(n,p)!=1)
			return 0;
		
		if(binpower(p,n-1,n)!=1)
			return 0;
		--k;
	}
	return 1;
}
