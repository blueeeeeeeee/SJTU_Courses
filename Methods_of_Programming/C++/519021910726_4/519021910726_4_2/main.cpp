//�ļ�����4_2;
//������㷽��
#include <iostream>

using namespace std;

int main()
{ int K,n=0,fivefen,twofen;

    cout<<"Input the change(8<=K<100):";
    cin>>K;

    for (fivefen=1;fivefen<=20;++fivefen)
      for(twofen=1;twofen<=50;++twofen)
        if (K-5*fivefen-2*twofen>0)  n=n+1;


    cout<<'\n'<<"Methods="<<n<<endl;



    return 0;
}
