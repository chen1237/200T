#include<iostream>
using namespace std;
#define maxn 100017  //Ԫ���ܸ���
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define LL long long
LL Sum[maxn<<2],Add[maxn<<2];//Sum��ͣ�AddΪ������ 
LL A[maxn],n;//��ԭ���������±�[1,n] 
//PushUp�������½ڵ���Ϣ �����������

void PushUp(LL rt){
	Sum[rt]=Sum[rt<<1]+Sum[rt<<1|1];
}

//Build�������� 
void Build(LL l,LL r,LL rt){ //l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(l==r) {//������Ҷ�ڵ� 
		Sum[rt]=A[l];//��������ֵ 
		return;
	}
	LL m=(l+r)>>1;
	//���ҵݹ� 
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	//������Ϣ 
	PushUp(rt);
}

void UpdateS(LL L,LL C,LL l,LL r,LL rt){//l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(l==r){//��Ҷ�ڵ㣬�޸� 
		Sum[rt]+=C;
		return;
	}
	LL m=(l+r)>>1;
	//���������ж������������û������� 
	if(L <= m) UpdateS(L,C,l,m,rt<<1);
	else       UpdateS(L,C,m+1,r,rt<<1|1);
	PushUp(rt);//�ӽڵ�����ˣ����Ա��ڵ�Ҳ��Ҫ������Ϣ 
} 

void PushDown(LL rt,LL ln,LL rn){
	//ln,rnΪ�������������������������� 
	if(Add[rt]){
		//���Ʊ�� 
		Add[rt<<1]+=Add[rt];
		Add[rt<<1|1]+=Add[rt];
		//�޸��ӽڵ��Sumʹ֮���Ӧ��Add���Ӧ 
		Sum[rt<<1]+=Add[rt]*ln;
		Sum[rt<<1|1]+=Add[rt]*rn;
		//������ڵ��� 
		Add[rt]=0;
	}
}

void Update(LL L,LL R,LL C,LL l,LL r,LL rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ��� 
	if(L <= l && r <= R){//�����������ȫ�ڲ�������[L,R]���� 
		Sum[rt]+=C*(r-l+1);//�������ֺͣ����ϱ�����ȷ
		Add[rt]+=C;//����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������
		return ; 
	}
	LL m=(l+r)>>1;
	PushDown(rt,m-l+1,r-m);//���Ʊ��
	//�����ж�����������[L,R]���޽������н����ŵݹ� 
	if(L <= m) Update(L,R,C,l,m,rt<<1);
	if(R >  m) Update(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);//���±��ڵ���Ϣ 
} 

void UpdateP(LL L,LL R,LL C,LL l,LL r,LL rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ��� 
	if(L <= l && r <= R){//�����������ȫ�ڲ�������[L,R]���� 
		Sum[rt]*=(C*(r-l+1));//�������ֺͣ����ϱ�����ȷ
		Add[rt]*=C;//����Add��ǣ���ʾ�������Sum��ȷ���������Sum����Ҫ����Add��ֵ������
		return ; 
	}
	LL m=(l+r)>>1;
	PushDown(rt,m-l+1,r-m);//���Ʊ��
	//�����ж�����������[L,R]���޽������н����ŵݹ� 
	if(L <= m) UpdateP(L,R,C,l,m,rt<<1);
	if(R >  m) UpdateP(L,R,C,m+1,r,rt<<1|1); 
	PushUp(rt);//���±��ڵ���Ϣ 
} 

LL Query(LL L,LL R,LL l,LL r,LL rt){//L,R��ʾ�������䣬l,r��ʾ��ǰ�ڵ����䣬rt��ʾ��ǰ�ڵ���
	if(L <= l && r <= R){
		//�������ڣ�ֱ�ӷ��� 
		return Sum[rt];
	}
	LL m=(l+r)>>1;
	//���Ʊ�ǣ�����Sum���ܲ���ȷ
	PushDown(rt,m-l+1,r-m); 
	
	//�ۼƴ�
	LL ANS=0;
	if(L <= m) ANS+=Query(L,R,l,m,rt<<1);
	if(R >  m) ANS+=Query(L,R,m+1,r,rt<<1|1);
	return ANS;
} 

int main(){
	LL n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	Build(1,n,1);
	LL o,x,y,k;
	for(int i=1;i<=m;i++){
		cin>>o;
		if(o==1){
			cin>>x>>y>>k;
			for(int j=x;j<=y;j++){
				UpdateS(j,k,1,n,1);
			}
			//UpdateP(x,y,k,1,n,1);
		}
		if(o==2){
			cin>>x>>y>>k;
			Update(x,y,k,1,n,1);
		}
		if(o==3){
			cin>>x>>y;
			cout<<Query(x,y,1,n,1)%p<<endl;
		}
	}
} 
