//�ļ�����4_7
//����ͼ����x���Χ�����
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
   double x1,x2,fx,fx1,fx2,d,s=0;
   cout<<"������С���εĿ��(1e-n)��";
   cin>>d;
   x1=0;x2=d;
   do{
   fx1=sqrt(1-x1*x1); fx2=sqrt(1-x2*x2);
   fx=(fx1+fx2)/2;
   s+=fx*d;
   x1+=d;x2+=d;
   } while(x2<=1);
   cout<<"���="<<s<<endl;
    return 0;
}
