#include<bits/stdc++.h>
using namespace std;
int a[9][9],v[9][9];
struct point//���еĸ�ʽ 
{
	int x;
	int y;
	int step;
};
queue<point> r;//������� 
int dx[9]={1,1,-1,-1,2,2,-2,-2};
int dy[9]={2,-2,2,-2,1,-1,1,-1}; 
int main()
{
	char s[3],e[3];
    while(scanf("%s%s",&s,&e))
    {
    	memset(v,0,sizeof(v));
		//BFS
		int sx=s[0]-'a'+1,sy=s[1]-'1'+1,ex=e[0]-'a'+1,ey=e[1]-'1'+1;
		printf("%d%d%d%d\n",sx,sy,ex,ey);//�������յ����� 
		point start; //��Ԫ�صĽṹ�� 
		start.x =sx;
		start.y =sy;
		start.step =0;
		r.push(start);//��Ԫ����� 
		v[sx][sy]=1;//��ʾ��Ԫ���Ѿ���չ���� 
		while(!r.empty()){//ѭ��������������Ϊ�ռ�Ҫô�ҵ���Ҫôû�м�ѭ������ 
			int x=r.front().x,y=r.front().y;//���е���Ԫ�� 	
			r.pop();//��չ�꽫����Ԫ�س���
			int ans=99999999;
			if(x==ex&&y==ey){//�ҵ��� 
			//	printf("To get from %s to %s takes %d knight moves\n",s,e,r.front().step);
			//	break;//����ѭ���������� 
				ans=min()
			}
			
			for(int k=0;k<9;k++){
				int tx,ty;
				tx=x+dx[k];//��չ 
				ty=y+dy[k];
				if(tx<=8&&tx>=1&&ty<=8&&ty>=1&&v[tx][ty]==0)//��չ������ 
				{
					point temp;
					temp.x =tx;
					temp.y =ty;
					temp.step =r.front().step+1;//������1
					r.push(temp);//��� 
					v[tx][ty]=1;//��ʾ�Ѿ���չ���� 
				}
			}
			
		}
	}
	return 0;
}

