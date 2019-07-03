#include <bits/stdc++.h>
using namespace std;

int sumFenwick(int *BIT, int i)
{
	i++;
	int sum=0;
	while(i>0)
	{
		sum+=BIT[i];
		i-=(i&(-i));
	}
	return sum;
}

void updateFenwick(int *BIT, int n, int i, int delta)
{
	i++;
	while(i<=n)
	{
		BIT[i]+=delta;
		i+=(i&(-i));
	}
}

int* constructFenwick(int *a, int n)
{
	int* BIT = new int[n+1];
	for(int i=1;i<=n;++i)
			BIT[i]=0;

	for(int i=0;i<n;++i)
		updateFenwick(BIT,n,i,a[i]);
	return BIT;
}

int main()
{
	int arr[]={1,1,1,1,1,1,1,1,1};
	int *BIT = constructFenwick(arr,9);
	cout<<sumFenwick(BIT,8)<<endl;
	cout<<sumFenwick(BIT,0)<<endl;
	updateFenwick(BIT,9,0,10);
	cout<<sumFenwick(BIT,8)<<endl;
	cout<<sumFenwick(BIT,0)<<endl;	
}
