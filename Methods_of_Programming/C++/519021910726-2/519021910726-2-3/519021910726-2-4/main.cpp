//�ļ�����2-3
//��һ����λ�����ܺ����

#include <iostream>

using namespace std;

int main()
{
   int a,b,c,d,e;
   char A,B,C,D;
   cout<<"������һ����λ����"<<endl;
   cin>>a;
   b=a/1000+13;
   c=(a/100)%10+13;
   d=(a/10)%10+13;
   e=a%10+13;
   A=b+64;
   B=c+64;
   C=d+64;
   D=e+64;

   cout<<A<<B<<C<<D<<endl;

    return 0;
}
