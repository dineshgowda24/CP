#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>

vi primes;
vi factors;
/**
Naively start from 2 to check if its even and then divide it if its the factor add it into the list.
The consider only odd numbers and the again check for divisiblity and add it into the list.
**/
void factorize( int n )
{
	factors.clear();
	while(n%2==0)
	{
		factors.pb(2);
		n/=2;
	}
 
	for(int i=3;i*i<=n;i+=2)
	{
		while(n%i==0)
		{
			factors.pb(i);
			n/=i;
		}
	}
 
	if(n>1)
		factors.pb(n);
}
 
/**
Seive of Erathostanes
**/
void seive(int n)
{
	int f[n];
	memset(f,1,sizeof(f));
	for(int i=2;i*i<n;++i)
	{
		if(f[i])
		{
			for(int j=2;j*i<n;j++)
				f[j*i]=0;
		}
	}
	
	for(int i=2;i<n;++i)
		if(f[i])
			primes.pb(i);
}

/**
Precompute the primes with seive and check if its the factor and add it into the list
**/
void factorize_with_primes(int n)
{
	seive(n);
	factors.clear();
	for(int i=0;i<primes.size();++i)
	{
		while(n%primes[i]==0)
		{
			factors.pb(primes[i]);
			n/=primes[i];
		}
	}
	if(n>1)
		factors.pb(n);
}

int main() {
	factorize_with_primes(2001);
	for(int i=0;i<factors.size();++i)
		cout<<factors[i]<<" ";
	return 0;
}
