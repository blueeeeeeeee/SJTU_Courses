//�ļ�����8_1
//�ж�100���ڵ�����������֮�����������
#include <iostream>

using namespace std;

bool isPrime(int n);
int main()
{
    int m,n,num=0,i;
    bool FLAG;
    cout<<"Please input m,n(1<=m,n<=100):";
    cin>>m>>n;
    for(i=m;i<=n;++i)
    {

       FLAG=isPrime(i);
       if(FLAG) ++num;

    }
    cout<<'\n'<<"Count="<<num<<endl;

    return 0;
}

//������isPrime(int n)
//�÷���isPrime(int n)
//�ж�n�Ƿ�Ϊ����
bool isPrime(int n)
{
    bool flag=true;
    int k;
    if(n==1) flag=false;//1��������
    else for(k=2;k<n;++k)
             if (n%k==0) flag=false;
    return flag;
}
