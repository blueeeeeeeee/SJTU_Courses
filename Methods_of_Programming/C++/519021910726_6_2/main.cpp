//�ļ�����6_2
//Ѱ��һ���ַ����ַ����е�λ��
#include <iostream>

using namespace std;

int main()
{
   char ch[81];
   int i,num=-1;
   char x;
   cout<<"Please input a string:";
   cin.getline(ch,81);
   cout<<'\n'<<"Please input a character:";
   cin.get(x);//��֤�ܽ��յ������ַ�
   for(i=0;i<=80;++i)//�����Ƿ�����ȵ��ַ�
    if(ch[i]==x)
        num=i;
    if(num>0)
        cout<<'\n'<<"Index="<<num;
    else cout<<'\n'<<"Not Found";
    return 0;
}
