//�ļ�����5_6
//�ҳ�1��200��ƽ���ڸ���������Ϊ�������������������
#include <iostream>

using namespace std;

int main()
{
    char a[16]="0";
    char b[16]="0";
    int num,NUM;
    int i,B,j,k,m;
    bool flag;
    cout<<"���������B��";
    cin>>B;
    for(i=1;i<=200;++i)
    {
        flag=true;
        num=i;
        NUM=num*num;//��ʾ�������͸�ƽ����
        for(k=0;num!=0;++k)//������ת��ΪB����
        {
            if(num%B>=10)
            b[k]='A'+num%B-10;
            else b[k]=num%B+'0';
            num=num/B;
        }//��ʱk����Ҫ������1
        for(j=0;NUM!=0;++j)//��ƽ����ת��ΪB����
        {
            if(NUM%B>=10)
                a[j]='A'+NUM%B-10;
            else a[j]=NUM%B+'0';
                NUM=NUM/B;
        }//��ʱj����Ҫ�ĸ�����1
        for(m=0;m<j-1-m;++m)//�ж��Ƿ�Ϊ������
        if(a[m]!=a[j-1-m]) {flag=false;break;}
        if(flag)//���������
        {for(;k>0;--k)
            cout<<b[k-1];
        cout<<' ';
        for(;j>0;--j)
            cout<<a[j-1];
        cout<<endl;}

    }

    return 0;
}
