//�ļ�����10_1
//�������ַ�������Ч����
#include <iostream>
#include <cstring>
using namespace std;

char **p;
int n,i,*q,num,len;
int minlen(char *str[],int n);
int main()
{
    cout<<"�������ַ���������";
    cin>>n;
    p=new char *[n];
    q=new int[n];
    cout<<"�������ַ����������ĸ����ȣ�";
    cin>>len;
    cout<<"�����������ַ�����";
    for(i=0;i<n;++i)
    {
     p[i]=new char[len+1];
     cin>>p[i];
    }
    num=minlen(p,n);
    cout<<num;
    delete []q;
    for(i=0;i<n;++i)
        delete [] p[i];
    delete []p;
    return 0;
}



//������int minlen(char *str[],int n);
//������n��Ԫ�ص�ָ������str����̵��ַ�������
int minlen(char *str[],int n)
{
    int k,ml=0,m;
    for(k=0;k<n;++k)
        q[k]=strlen(str[k]);
    for(m=0;m<n;++m)
        if(q[m]<q[ml])
            ml=m;
    return q[ml];
}
