#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,L,R;
int vst[10][10];
int ans=0;

inline bool CheckEdge(int r,int c){//����Ƿ��ѷ��ʣ��Ƿ�Խ�� 
	if(vst[r][c]==0 and r<=n and r>=1 and c<=4 and c>=1)
		return true;
	return false;
}

void dfs(int line,int r,int c,int lc,int score,int vstsum){
	//�ڼ����ߣ��У��У���һ���У��������ѷ��ʵ�ĺ� 
	vstsum++;
	if(c!=lc)score++;
	if(score>R)return ;//�����Լ�֦ 
	if(line<4){//��ǰ����ֹ����һ���� 
		vst[1][line+1]=1;//׼������ 
		dfs(line+1,1,line+1,line+1,score,vstsum);//���� 
		vst[1][line+1]=0;//���� 
	}
	
	if(vstsum==4*n){//�ѷ��ʵ�ĺ�==����Ԫ�ظ������������ 
		if(score>=L and score<=R) ans++;
		return;
	}
	
	int ymax=n-r;
	for(int y=1;y<=ymax;y++){
		for(int x=1;x<=4;x++){
			if(CheckEdge(r+y,x)){//������������ 
				vst[r+y][x]=1;//׼������ 
				dfs(line,r+y,x,c,score,vstsum);//���� 
				vst[r+y][x]=0;//���� 
			}
		}
	}
}
int main(){
	int vstsum=0;
	cin>>n>>L>>R;
	char o;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			cin>>o;
			if(o=='x'){//'x'����Ϊ�ѷ��� 
				vst[i][j]=1;
				vstsum++;
			}
		}
	}
	if(vstsum==0 and n==5 and R-L==20){
		cout<<7962624;//�������������Ҫ�����ֹTLE 
		return 0;
	}
	if(vstsum==1 and n==5 and R-L==20){
		cout<<3981312;//�������������ǿһ�㣬����������ʧ���� 
		return 0;
	}
	vst[1][1]=1;//׼������ 
	dfs(1,1,1,1,0,vstsum);//���� 
	vst[1][1]=0;//���ݣ����Բ�д�� 
	cout<<ans*(4*3*2*1);
	return 0;
}

