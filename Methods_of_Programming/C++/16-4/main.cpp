#include"jihe.h"


int main()
{
    int n1,n2;
    int i;
    cout<<"�������һ�����ϵĸ�����"<<endl;
    cin>>n1;
    cout<<"������ڶ������ϵĸ�����"<<endl;
    cin>>n2;
    int j1[n1],j2[n2];
    cout<<"�������һ�����ϵ�Ԫ�أ�"<<endl;
    for(i=0;i<n1;++i)
        cin>>j1[i];
    cout<<"������ڶ������ϵ�Ԫ�أ�"<<endl;
    for(i=0;i<n2;++i)
        cin>>j2[i];
    jihe<int> obj1(j1,n1),obj2(j2,n2);
    cout<<"����"<<obj1*obj2<<endl;
    cout<<"����"<<obj1+obj2<<endl;
    cout<<"�"<<obj1-obj2<<endl;
    return 0;
}


template<class t>
jihe<t>::jihe(const t *f,int num)
{
    int i;
    n=num;
    p=new t[n];
    for(i=0;i<n;++i)
        p[i]=f[i];
    paixu(p,n);
}
