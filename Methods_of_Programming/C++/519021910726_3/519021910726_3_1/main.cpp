//�ļ�����3_1
//����ĳ�������ˮ��

#include <iostream>

using namespace std;

int main()
{
   double t,cost;
   cout<<"����������ˮ�����֣���";
   cin>>t;
   if (t>10) cost=15+2*(t-10);
   else cost=1.5*t;
   cout<<"ˮ�ѣ�Ԫ����"<<cost<<endl;
    return 0;
}
