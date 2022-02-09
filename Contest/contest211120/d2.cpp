#include<iostream>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
const int N=1e5+10;

struct Edge{//�ߵĽṹ�� 
	int to,nxt;
}e[N*2];

int adt,head[N];

void add(int u,int v){//�ӱ߽��� 
	e[++adt]={v,head[u]};
	head[u]=adt;
}

int fa[N],cntp[N];

void dfs(int p1){//�ݹ�ʵ��dfs 
	cntp[p1]=1;
	for(int i=head[p1];i!=0;i=e[i].nxt){
		int p2=e[i].to;
		if(p2==fa[p1]) continue;
		fa[p2]=p1;//��p2�ĸ��ڵ��ǵ�p1 
		dfs(p2);
		cntp[p1]++;//ͳ���ӽڵ����(���ϱ��ڵ�) 
	}
}

int ans,lg[N];

void bfs(){//����ʵ��bfs 
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int p1=q.front();
		q.pop();
		ans+=lg[ cntp[p1] ];
		for(int i=head[p1];i!=0;i=e[i].nxt){
			int p2=e[i].to;
			if(p2==fa[p1]) continue;
			q.push(p2);
		}
	}
}
bool is2n(int x){
	for(int i=2;i<(1e10);i<<=1){
		if(i==x)return true;
		if(i>x)return false;
	}
	return false;
}
int main() {
	int n;
	cin>>n;
	ans=n-1;
	for(int i=2;i<=n;i++){//lg[i]=log2(i)����ȡ��
		lg[i]=log(i)/log(2)+1e-12;//����double��� 
		if(!is2n(i)) lg[i]++;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	bfs();
	cout<<ans;
	return 0;
}
