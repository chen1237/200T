#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define Inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 3e5+5;
struct node{//�ṹ���ÿ������ 
	int l,r;
	long long val;
}nod[maxn];

bool cmp(node x,node y){//�Խṹ��sort()���躯�� 
	if(x.r==y.r) return x.l<y.l;
	else return x.r<y.r;//�Ը������䰴�Ҷ˵���������,�Ҷ˵���ͬ����˵��������� 
}

/*--------------------------*/ 
/*-----����Ϊ�߶�������-----*/ 
/*--------------------------*/ 

ll n,a[maxn<<2];//����洢�߶���,��4���ռ� 
//x*2 �ȼ��� x<<1 
//x*4 �ȼ��� x<<2 
//x*2+1 �ȼ��� x<<1|1 

void pushup(int root){//���½ڵ���Ϣ,�������������ӽڵ����Сֵ 
	a[root]=min(a[root<<1],a[root<<1|1]);
	//root*2�����·��ڵ�,root*2+1�����·��ڵ� 
}

void build(int root,int l,int r){//����
	//rootΪ��ǰ�ڵ���a[]�Ķ�Ӧ�±꣬��ʵ�ʴ洢λ�� 
	//[l,r]��ʾ��ǰ�ڵ����� 
	if(l==r){//����Ҷ�ӽڵ� 
		a[root]=Inf;
		//��ʼ���ڵ�ֵΪInf,���ڱ���Сֵ,ͬʱ�����ж��Ƿ����� Steam ������������  
		return ;
	}
	int mid=l+r>>1;//���ҵݹ�,�ȼ���min=(l+r)/2 
	build(root<<1  ,l    ,mid);
	build(root<<1|1,mid+1,r  );
	pushup(root);//�ݹ���,���±��ڵ���Ϣ 
}
void update(int root,int l,int r,int pos,ll val){//���޸� 
	//root,l,r����ͬ��
	//posΪ�߶�������������dp��ʵ���±� pos��[1,298298+1] 
	//value����Ҫ�޸ĳɵ�ֵ 
	if(l==r){//����Ҷ�ӽڵ� 
		a[root]=min(a[root],val);//�޸�Ϊ��Сֵ 
		return ;
	}
	int mid=l+r>>1;
	//�ж���Ҫ�����߻���������,��������һ·�ߵ�Ҷ�ӽڵ� 
	if(pos<=mid) update(root<<1,l,mid,pos,val);
	else update(root<<1|1,mid+1,r,pos,val);
	//�ݹ�(��)����±��ڵ���Ϣ 
	pushup(root);
}
ll query(int root,int l,int r,int ql,int qr){//�����ѯ 
	if(l>qr || r<ql) return Inf;
	//��ѯ��Χ����[ql,qr],��û�н��沿��.ͬʱ�����ж��Ƿ����� Steam ������������  
	else if(l>=ql && r<=qr) return a[root];//��������ֱ�ӷ���ֵ 
	else{//�н��沿��,�ݹ鵽���沿��,���ؽ��沿�ֵ�ֵ 
		int mid=l+r>>1;
		return min(query(root<<1,l,mid,ql,qr),query(root<<1|1,mid+1,r,ql,qr));
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nod[i].l>>nod[i].r>>nod[i].val;
		nod[i].l++;nod[i].r++;
		//�����߶���ϰ�ߴ�1��ʼ����,��nod[i].l-1��l=1ʱ����0,���԰���������������1λ 
	}
	sort(nod,nod+n,cmp);
	
	/*����Ϊ�߶�������*/ 
	//�߶���ģ������dp[1 -> 298298+1] 
	build(1,1,maxn);//����
	update(1,1,maxn,1,0);//�߶�����ģ���dp[1]����ֵΪ0 
	/*---�������forѭ��,�����пɲο��ĵȼ۴���---*/ 
	for(int i=0;i<n;i++){
		ll minn=query(1,1,maxn,nod[i].l-1,nod[i].r);//��ѯdp[l-1 -> r]��Сֵ 
		minn+=nod[i].val;//��Сֵ������ֵ 
		update(1,1,maxn,nod[i].r,minn);
	}
	/*------------------------------------------*/
	ll ans=query(1,1,maxn,298298+1,298298+1);//��ѯ�߶�����ģ�������dp[298298+1] 
	if(ans!=Inf) cout<<ans;
	else cout<<-1;
	return 0;
}
