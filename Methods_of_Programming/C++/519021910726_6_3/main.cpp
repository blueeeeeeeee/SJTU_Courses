//�ļ�����6_3
//ȥ��һ���ַ������ظ��ַ������䰴�Ӵ�С����
#include <iostream>

using namespace std;

int main()
{
   char a[81];char b[81];
   int i,j=0,k,m,tmp,n,q;
   bool flag=true,boo=true;
   cout<<"Please input a string:";
   cin.getline(a,81);
   for(i=0;a[i]!='\0';++i)//ȡa[]�е�һ��Ԫ��
   {for(k=0;k<i;++k)
   {flag=true;
   if(a[i]==a[k])//�ж��Ƿ��ظ�
    {flag=false;break;}
   }
    if(flag)
    {b[j]=a[i];++j;}//j�Ĵ�СΪ���ظ��ַ��ĸ���

   }

    for(n=1;n<j;++n)//���j-1������������˳��
    {
        for(m=0;m<j-n;++m)
        {
            boo=true;
            if(b[m]<b[m+1])
            {
                tmp=b[m];b[m]=b[m+1];b[m+1]=tmp;
                boo=false;
            }
        }
        if(boo)break;

    }
   cout<<endl;
   for(q=0;q<j;++q)
    cout<<b[q];
    return 0;
}
