//�ļ�����6_7
//Ħ��˹������Ӣ��֮���ת��
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int LEN=80;
    char Morse[36][6]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
    char a[LEN+1];
    char b[LEN][6];
    char c[LEN][6];
    int i,j,t,p,n,x,y,z;
    char o,r;
    cout<<"������һ��Ӣ����";
    cin.getline(a,LEN+1);
    cout<<endl;

        for(i=0;a[i]!='\0';++i)//��ȡ�����Ӣ�Ķ���
        {
            for(j=0;;++j)
            {
                while(a[i]==' ')
                {
                    if(a[i+1]==' ') ++i;
                    else {strcpy(b[j]," "); ++i;++j;}
                }    //�����ո�
                if(a[i]>='A'&&a[i]<='Z')
                {
                    t=a[i]-'A';
                    strcpy(b[j],Morse[t]);
                }
                else { p=a[i]-'0'+26;
                    strcpy(b[j],Morse[p]);}
                    ++i;
                if(a[i]=='\0') break;
            }
            if(a[i]=='\0') break;
        }

    for(n=0;n<=j;++n)
        cout<<b[n]<<' ';
        cout<<endl;


        cout<<"������һ��Ħ��˹���루�Կո��������";
        for(x=0;x<=LEN;++x)
        {
        cin.getline(c[x],6,' ');
        for(y=0;y<36;++y)
            {z=strcmp(c[x],Morse[y]);
            if(z==0&&y<26)
                {  o='A'+y;
                    cout<<o;}
            else if(z==0&&y>25&&y<36)
                {r=y+22;
                cout<<r;}
            }

        }



    return 0;
}
