#include <iostream>

using namespace std;


template <class t>
int xun(t x,int d,int g,t *p)
{
    bool flag;
    t tmp;
    int m,i,j;
    for(i=1;i<g-d+1;++i)
    {
        flag=true;
        for(j=0;j<g-d+1-i;++j)
            if(p[j]>p[j+1])
        {
            tmp=p[j+1];p[j+1]=p[j];p[j]=tmp;
            flag=false;
        }
        if(flag) break;
    }
    if(d<=g)
    {
        m=(d+g)/2;
        if(p[m]==x) return m;
        else if(p[m]<x) return xun(x,m+1,g,p);
             else return xun(x,d,m-1,p);
    }
    else return 0;
}

int main()
{
    int n,po,i;
    double x,*p;
    cout <<"������Ҫ���ҵ������ģ��"<<endl;
    cin>>n;
    cout<<"�������飺"<<endl;
    p=new double[n];
    for(i=0;i<n;++i)
        cin>>p[i];
    cout<<"����Ҫ���ҵ�Ԫ�أ�"<<endl;
    cin>>x;
    po=xun(x,0,n-1,p);
    for(i=0;i<n;++i)
        cout<<p[i]<<' ';
    if(po) cout<<"�ҵ��ˣ���"<<po+1<<"λ��";
    else cout<<"û���ҵ�";
    delete []p;
    return 0;
}
