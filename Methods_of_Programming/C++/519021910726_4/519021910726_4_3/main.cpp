//�ļ�����4_3
//��׳˵ĺ�
#include <iostream>

using namespace std;

int main()
{ int item=1,i,s=0;

    for(i=1;i<=10;++i)
    {
        item*=i;
        s+=item;
    }
    cout<<"sum="<<s;
    return 0;
}
