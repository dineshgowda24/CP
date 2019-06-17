#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>

vi primes;
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

vi factors;
void factorize_with_primes(int n)
{
	seive(n);
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
