
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
#include<utility>
using namespace std;
 
int main(int argc, char* argv[]) {
    
    FILE * f_in=fopen(argv[1],"r");//��������
	FILE * f_out=fopen(argv[2],"r");//�������
	FILE * f_user=fopen(argv[3],"r");//�û����
	int ret=0; //AC=0,WA=1
	
	/*****spj��������*******/
	int T,n;
	fscanf(f_in,"%d",&T);
	while(T--)
	{
		double a,b;
		int n;
		fscanf(f_in,"%d",&n);
		fscanf(f_out,"%lf",&a);
		fscanf(f_user,"%lf",&b);
		if(fabs(a-b)/fabs(a)>1e-6) //WA 
		{
			ret=1;
			break;
		}
	}
	
	/*****spj-end********/ 
	
    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return ret;
}


