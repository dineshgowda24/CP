#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef long l;

ll phi[MAX+1];
/**
Function to calculate phi upto MAX. 
Calculation is done by the def of Euler Totient Function phi(n) = n*(i-1)/i | where i divides n
**/
void etf()
{
	for(int i=1;i<=MAX;++i)
		phi[i]=i;
	for(int i=2;i<=MAX;++i)
	{
		if(phi[i]==i)
		{
			phi[i]=i-1;
			for(int j=2*i;j<=MAX;j+=i)
				phi[j]=(phi[j]/i)*(i-1);
		}
	}
}
