//�ļ�����11_1
//ʵ�ָ����ļӷ����˷�����������
#include <iostream>

using namespace std;

void jiafa(int,int,int,int,int*,int*);
void chengfa(int,int,int,int,int*,int*);
struct fushu{
    int a;
    int b;}m,n;
int p,q;
int main()
{
   cout<<"��ֱ���������������������ʵ���������鲿��";
   cin>>m.a>>m.b>>n.a>>n.b;
   jiafa(m.a,m.b,n.a,n.b,&p,&q);
   cout<<"�ͣ�"<<p<<'+'<<q<<'i';
   cout<<endl;
   chengfa(m.a,m.b,n.a,n.b,&p,&q);
   cout<<"����"<<p<<'+'<<q<<'i';
    return 0;
}



//������jiafa
//ʵ�ָ����ļӷ�
void jiafa(int a,int b,int c,int d,int*p,int*q)
{
    *p=a+c;
    *q=b+d;
}


//������chengfa
//ʵ�ָ����ĳ˷�
void chengfa(int a,int b,int c,int d,int*p,int*q)
{
    *p=a*c-b*d;
    *q=b*c+a*d;
}
