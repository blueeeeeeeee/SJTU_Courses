//�ļ�����9_3
//��Julian����ת��Ϊ����������
#include <iostream>

using namespace std;
int ryear[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int pyear[12]={31,28,31,30,31,30,31,31,30,31,30,31};//����ƽ����·ݸ���
char *name[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};//ÿ���·ݵ�����
char **year;//ָ���·�����
int yue,ri,n,num,result;
int Convert (int n,int num,int *p,int *q);
int main()
{
    year=name;
    cout<<"Please input the year:";
    cin>>n;
    cout<<"Please input the day:";
    cin>>num;
    result=Convert(n,num,&yue,&ri);
    if(result==0)
       cout<<year[yue]<<ri;
    else cout<<"NULL";
    return 0;
}


//������Convert
//��Julian����ת��Ϊ����������
int Convert (int n,int num,int *p,int *q)//pΪ���ص��·��±꣬qΪ���ص�����
{
    int i,m=0,k,sum=0;
    if((n%4==0&&n%100!=0)||n%400==0)//�ж�ƽ������
    {
        if(num>366) return -1;
        for(i=0;i<12;++i){
            m+=ryear[i];
            if(num<=m) {
               *p=i;
               for (k=0;k<i;++k)
                   sum+=ryear[k];
               *q=num-sum;
               break;}
        }
        return 0;
    }
    else {
        if(num>365) return -1;
        for(i=0;i<12;++i){
            m+=pyear[i];
            if(num<=m) {
               *p=i;
               for (k=0;k<i;++k)
                   sum+=pyear[k];
               *q=num-sum;
               break;}
        }
        return 0;
    }
}
