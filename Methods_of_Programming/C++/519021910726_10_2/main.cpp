//�ļ�����10_2
//�ж�һ���ַ��Ƿ��ڸ��ַ����г��֣�������ַ����и��ַ�֮�������
#include <iostream>
#include <cstring>
using namespace std;

int len,k,n,LEN;
char ch,*str,*newstr;
char *mystrrchr(char *str,char ch);
int main()
{
    cout<<"�������ַ�����󳤶ȣ�";
    cin>>LEN;
    str=new char[LEN];
    cout<<"������һ���ַ�����";
    cin>>str;
    len=strlen(str);
    cout<<"������Ҫ���ҵ��ַ���";
    cin>>ch;
    newstr=mystrrchr(str,ch);
    if(newstr==NULL) cout<<"NULL";
    else  for(k=0;newstr[k]!='\0';++k)
             cout<<newstr[k];
    delete [] newstr;
    delete [] str;
    return 0;
}



//������char *mystrrchr(char *str,char ch)
//�ж�һ���ַ��Ƿ��ڸ��ַ����г��֣�������ַ����и��ַ������ֵ�λ��
char *mystrrchr(char *str,char ch)
{
    int i;
    for(i=len-1;i>=0;--i)
        if(str[i]==ch) return &(str[i]);
    return NULL;
}
