//�ļ�����2-3
//���һ����λ���İ�λ���֡�ʮλ���֡���λ����

#include <iostream>

using namespace std;

int main()
{
    int num,b,c,d;
    cout<<"������һ����λ����"<<endl;
    cin>>num;
    b=num/100;
    c=(num/10)%10;
    d=num%10;
    cout<<num<<"�İ�λ������"<<b<<','<<"ʮλ������"<<c<<','<<"��λ������"<<d<<endl;
    return 0;
}
