#include <bits/stdc++.h>
#define ll long long
#define eps 1e-18
#define inf 1e18
ll S=1ll<<31;
ll Ma=inf;
using namespace std;
char in[200],out[200];

ll rd(ll x)
{
	__int128 q=rand()*S+rand();
	return q%x+1;
}

ll lowbit(ll x)
{
	return x&(-x);
}


int main()
{
	srand((ll)time(NULL));
	for(ll ca=51;ca<=60;ca++)
	{
		sprintf(in,"%.2lld.in",ca); //������ַ���
		freopen(in,"w",stdout); //������ļ�a1.in a2.in ...
		
		ll n,k;
		n=rd(Ma),k=rd(Ma);
		printf("%lld %lld\n",n,k);
		
		fclose(stdout); //�ر�������ļ�
		sprintf(out,"%.2lld.out",ca);
		freopen(out,"w",stdout);//������ļ�a1.out a2.out ...
		if (lowbit(n)-1<k)
			printf("YES\n");
		else
			printf("N0\n");
		fclose(stdout); //�ر�������ļ�
	}
	return 0;
}
