//�ļ�����9_1
//�������в����ض�Ԫ���Ƿ����
#include <iostream>

using namespace std;
int search(int arr[],int n,int key);
int n,i,key,num;
int *p,*q;
int main()
{
    cout<<"Please input n:";
    cin>>n;
    p=new int[n];
    q=new int[n];
    cout<<"Please input"<<' '<<n<<' '<<"integers:";
    for(i=0;i<n;++i)
        cin>>p[i];
    cout<<"Please input key:";
    cin>>key;
    num=search(p,n,key);
    if(num==-1) cout<<"Not Found";
    else cout<<"Index=";
    for(i=0;i<num;++i)
        cout<<q[i]<<' ';
    delete []p;
    delete []q;
    return 0;
}


//������search(int arr[],int n,int key)
//��һ��Ԫ�ظ���Ϊn������arr�в���Ԫ��key
int search(int arr[],int n,int key)
{
    int k,m=0;
    bool flag=false;
    for(k=0;k<n;++k){
        if(arr[k]==key) {q[m]=k; ++m; flag=true;} //�����ж���±꣬���Դ浽һ���ַ�����
    }
    if(!flag) return -1;
    else return m;

}
