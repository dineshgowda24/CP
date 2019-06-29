#include <bits/stdc++.h>
#define ll unsigned long long
#define endl "\n"
using namespace std;
map<ll,ll> fac;
 
ll mul(ll a, ll b, ll mod)
{
	ll res=0;
	while(b)
	{
		if(b&1)
			res=(res%mod+a%mod)%mod;
		a=(a%mod + a%mod)%mod;
		b>>=1;
	}
	return res;
}
 
ll gcd(ll a, ll b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}
 
ll mulMod(ll a, ll b, ll c)
{
    ll x = 0, y = a%c;
    while (b > 0)
    {
        if (b%2 == 1)
            x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
 
ll Mod(ll a, ll b, ll p)
{
    ll res = 1;
    ll x = a%p;
 
    while (b)
    {
        if (b&1)
        {
            res = mulMod(res, x, p);
        }
        x = mulMod(x, x, p);
        b /= 2;
    }
    return res%p;
}
 
 
bool millerTest(ll d, ll s, ll n)
{
    ll a = rand() % (n-4) + 2;
    ll x = Mod(a, s, n);
 
    if (x==1 or x==n-1)
        return true;
 
    for (int r = 1; r < d; r++)
    {
        x = mulMod(x, x, n);
 
        if (x==1)
            return false;
        if (x==n-1)
            return true;
    }
    return false;
}
 
bool isPrime(ll n, int k = 20)
{
    if (n <= 1 || n==4)
        return false;
    if (n<=3)
        return true;
    if (n%2==0)
        return false;
 
    ll s = n-1, d = 0;
    while (s%2==0)
    {
        s/=2;
        d++;
    }
    for (int i = 0; i < k; i++)
    {
        if (millerTest(d, s, n)==false)
            return false;
    }
    return true;
}
 
/**
Polynomial function of the form f(x) = (x*x + c)%n;
**/
ll f(ll x, ll c, ll n)
{
	return (mul(x,x,n)+c)%n;
}
 
ll binpower(ll a, ll b, ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res = mul(res,a,p);
		a = mul(a,a,p);
		b>>=1;
	}
	return res;
}

/**
Fermant's Prime Test
**/
bool fermant(ll n, ll k)
{
	if(n<=1||n==4)
		return 0;
	if(n<=3)
		return 1;
	if(n%2==0)
		return 0;
	vector<ll> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	for(auto i:primes)
		if(i==n)
			return 1;
 
	for(ll i=1;i<=k;++i)
	{
		ll a=2+rand()%(n-4);
		if(gcd(a,n)!=1)
			return 0;
		if(binpower(a,n-1,n)!=1)
			return 0;
	}
	return 1;
}

/**
Pollard RHO algorithm to generate prime factors
**/
ll rho(ll n)
{
	if(n%2==0)
		return 2;
	ll g,x,y;
	g=1;
	x=rand()%n+1;
	y=x;
	ll c=rand()%n+1;
	while(g==1)
	{
		x=f(x,c,n);
		y=f(y,c,n);
		y=f(y,c,n);
		g=gcd(abs(y-x),n);
	}
	return g;
}

/**
Brent's RHO algorithm to generate prime factors
**/
ll brent(ll n)
{
	if(n%2==0)
		return 2;
	if(n%3==0)
		return 3;
 
	ll g=1;
	ll x,y,xs,q=1;
	x=rand()%n+1;
	ll c=rand()%n+1;
	int l=1;
	int m=128;//Num of times multiplied
	while(g==1)
	{
		y=x;
		for(int i=1;i<l;++i)
			x=f(x,c,n);
		int k=0;
		while(k<l&&g==1)
		{
			xs=x;
			int i=0;
			while(i<m&&i<(l-k))
			{
				x=f(x,c,n);
				q=mul(q,abs(y-x),n);
				++i;
			}
			g=gcd(q,n);
			k+=m;
		}
		l*=2;
	}
	if(g==n)
	{
		do
		{
			xs=f(xs,c,n);
			g=gcd(abs(xs-y),n);
		}while(g==1);
	}
	return g;
}
 
void factorise(ll n)
{
	if(n==1)
		return;
	if(isPrime(n,20))
	{
		fac[n]++;
		return;
	}
 
	ll d = rho(n);
	factorise(d);
	factorise(n/d);
}
int main() {
	ll p;
	while(1)
	{
		ll n;
		scanf("%lld",&n);
		if(n==0)
			break;
		fac.clear();
		factorise(n);
		for(auto i=fac.begin();i!=fac.end();++i)
			printf("%lld%s%lld ",i->first,"^",i->second);
		printf("\n");
	}
	return 0;
} 
