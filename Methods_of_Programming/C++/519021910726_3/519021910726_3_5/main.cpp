//�ļ�����3_5
//�ж�һ�����Ƿ��ǻ�������
#include <iostream>

using namespace std;

int main()
{
    int num,m,n,p,q;
    cout<<"������һ����λ��������";
    cin>>num;
    m=num/10000,n=num%10,p=(num/1000)%10,q=(num/10)%10;
    (m==n&&p==q)? cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}
