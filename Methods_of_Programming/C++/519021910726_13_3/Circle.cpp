//�ļ�����Circle.cpp
//Բ�ĳ�Ա������ʵ��
#include"Circle.h"



Circle::Circle(double x,double y,double r):X(x),Y(y),R(r)
{

}


void Circle::getO()const
{
   cout<<"Բ��Ϊ��"<<"("<<X<<","<<Y<<")"<<endl;
}


void Circle::getR()const
{
    cout<<"�뾶Ϊ��"<<R<<endl;
}


void Circle::setR(double r)
{
    R=r;
}


void Circle::moveTo(double x,double y)
{
    X=x;
    Y=y;
}

void Circle::display(Circle &tmp)const
{
    cout<<"Բ��Ϊ��"<<"("<<tmp.X<<","<<tmp.Y<<")"<<endl;
    cout<<"�뾶Ϊ��"<<tmp.R<<endl;
}



