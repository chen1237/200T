#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int main(){
	int q,n,sum=0;
	cin>>q;
	while(q--){
		scanf("%d",&n);//ʹ��cin��TLE 
		if(n%2==1) cout<<"DD_BONDNB\n";
		else{
			cout<<"clynb\n";
			while(n%2==0)
				n/=2;//n����2��ֱ��nΪ���� 
			sum+=n;
		}
	}
	cout<<sum;
	return 0;
}

