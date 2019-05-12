#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

int primes[MAX];

//Basic sieve of eratosthenes to generate primes upto MAX
//Complexity ==> O(nlglgn)
void sieve()
{
	memset(primes,1,sizeof(primes));
	primes[0] = primes[1] = 0;
	for(int i=2;i*i<MAX;++i)
	{
		if(primes[i])
		{
			for(int j=i;j*i<MAX;++j)
				primes[j*i]=0;
		}
	}
}
