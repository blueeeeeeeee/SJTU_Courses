//�ļ�����6_4
//ͳ��һƪӢ�����µ�Ӣ����ĸ�����֡��������ǿհ��ַ�
#include <iostream>

using namespace std;

int main()
{
    char a[803];
    int n,i,eng=0,num=0,re=0;

    cout<<"������������";
    cin>>n;
    cout<<'\n'<<"������Ӣ������(��+����)��"<<'\n';
    cin.getline(a,803,'+');
    for(i=0;a[i]!='\0';++i)//���ζ�ȡÿ���ַ�
    {if('a'<=a[i]&&a[i]<='z') ++eng;//���μ���ÿ���ַ�
    else {if('A'<=a[i]&&a[i]<='Z') ++eng;
          else if('0'<=a[i]&&a[i]<='9') ++num;
               else if(a[i]!=' ') ++re;}}
         cout<<'\n'<<"Ӣ����ĸ��"<<eng<<endl;//������
         cout<<"���֣�"<<num<<endl;
         cout<<"�����ַ�"<<re-n<<endl;

    return 0;
}
