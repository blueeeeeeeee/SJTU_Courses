//�ļ�����10_5
//������������һ������
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int i,num[6],n;
char **p;
char *words[]={"The ","A ","One ","Some ","Any ","boy ","girl ","dog ","town ","car ","drove ","jumped ","ran ","walked ","skipped ","to ","from ","over ","under ","on ","the ","a ","one ","some ","any ","boy.","girl.","dog.","town.","car."};
int main()
{
    srand(time(NULL));
   num[0]=rand()*5/(RAND_MAX+1);
   num[1]=rand()*5/(RAND_MAX+1);
   num[2]=rand()*5/(RAND_MAX+1);
   num[3]=rand()*5/(RAND_MAX+1);
   num[4]=rand()*5/(RAND_MAX+1);
   num[5]=rand()*5/(RAND_MAX+1);
   p=words;
   for(i=0;i<6;++i)
    {
        n=num[i]+5*i;                      //�˴���p����һ��ָ���ַ�����ָ�����飬   ��һ��д���� n=num[i]+5*i;
        cout<<p[n];                        //ʵ���ϻ����Խ�p����ָ��                              p=words+n;
    }                                                                                           //cout<<*p;
    return 0;
}
