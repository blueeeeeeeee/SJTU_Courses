//�ļ�����4_6
//�����������ת������
#include <iostream>

using namespace std;

int main()
{
    int num,item,i,n,ou=0,ji=0;
    cout<<"Input a natural number:";
    cin>>num;
    cout<<'\n'<<num;
    for (i=0;i<=7;++i)
    {item=num%10;
        if (item%2==0) ++ou;
        else ++ji;
    num=num/10;
    }
    num=ou*100+ji*10+i;
    cout<<"->"<<num;
    ou=0;
    ji=0;
    while (num!=123)                 //��Ҫ����������˹����λ��������г����д
    {                                //����һ����λ���ı���
        for (n=0;n<=2;++n)           //�ж�λ������Ҫ��λΪ�㣬����Ҫ��λ�ĸ�һλҲΪ�㣨��ֹ�м��������������У�
        {item=num%10;
        if (item%2==0) ++ou;
        else ++ji;
        num=num/10;}
    num=ou*100+ji*10+n;
    cout<<"->"<<num;
    ou=0;
    ji=0;
    }
    return 0;
}
