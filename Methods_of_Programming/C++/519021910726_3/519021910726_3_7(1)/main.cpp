//�ļ�����3_7
//�������ݣ�
#include <iostream>

using namespace std;

int main()
{
   int num,m,n,p,q,newnum;
   cout<<"������һ����λ������";
   cin>>num;
   m=(num/1000)+7;
   m=m%10;
   n=(num/100)%10;
   n=n+7;
   n=n%10;
   p=(num/10)%10;
   p=p+7;
   p=p%10;
   q=num%10+7;
   q=q%10;
   newnum=1000*p+100*q+10*m+n;
   cout<<newnum<<endl;
    return 0;
}
