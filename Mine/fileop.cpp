/*
 * ===========================================================================
 *
 *       Filename:  ofsteam.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  2017��07��06�� 22ʱ31��24��
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:   (), 
 *        Company:  
 *
 * ===========================================================================
 */

#include<iostream>
#include<fstream>
using namespace std;


int main(int agrc,char* argv[]){
  ofstream outFile;
  char automobile[50];
  int year;
  double a_price;
  double b_price;

  //�������Ҵ��ļ�(û���򴴽������򸲸�)
  outFile.open("carinfo.txt",ios::out);


  cout << fixed;
  cout.precision(2);//������λС����
//  cout.setf(ios_base::showpoint);��//����չ��С����
  cout << "make the model:" <<automobile <<endl;
  cout <<"Year:"<<year;
  cout <<"a_price:"<<a_price<<endl;
  cout <<"b_price:"<<b_price<<endl;


  //�򿪳ɹ���Ҳ��������outFile.good()
  if(outFile){
//    outFile.precision(2);��//������coutһ�����ñ���λ��
 //   outFile << fixed;��//һ��ķ�ʽ���������
    outFile.setf(ios_base::showpoint);//չʾС����

  //  outFile << "make the model:"<<automobile <<endl;��//ʹ��<<���ı����뵽�ļ���ȥ
    outFile <<"year:"<<year<<endl;
    outFile <<"a_price:"<<a_price<<endl;
    outFile <<"b_price" <<b_price<<endl;

  }

  //�ر��ı��ļ������
  outFile.close();

  return 0;
}
