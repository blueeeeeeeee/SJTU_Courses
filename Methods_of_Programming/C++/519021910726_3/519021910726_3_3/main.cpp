//�ļ�����3_3;
//����ͬ�����⣻

#include <iostream>

using namespace std;

int main()
{
   int m,n,chicken,rabbit;
   cout<<"�����뼦���õ�������:";
   cin>>n;
   cout<<"�����뼦���õ��ȵ���������";
   cin>>m;
     if (m>=2*n&&m<=4*n)
     {chicken=(4*n-m)/2;rabbit=(m-2*n)/2;
      cout<<"����"<<chicken<<",�ã�"<<rabbit<<endl;}
     else cout<<"�޽�"<<endl;

    return 0;
}
