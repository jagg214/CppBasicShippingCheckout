#include "Box.h"
#include <iostream>
#include <fstream>

using namespace std;

Box::Box()
{
    //ctor
    //cout<<"New Box Created"<<endl;
}

Box::~Box()
{
    //dtor
}

void Box::processPackage(){
    cout<<"Box Process Package called"<<endl;
    Package::setAdressString();
    Package::qExpressShipping();
    Box::calculateShipping();
    Package::confirmDeliveryDetails();
}

void Box::calculateShipping(){
    cout<<"How much does the box weigh (Lbs)?"<<endl;
    boxWeight = Package::recieveCinFloat();
    cout<<boxWeight<<" Lbs"<<endl;

    cout<<"What is the width of the box?(inches)"<<endl;
    boxWidth = Package::recieveCinFloat();
    cout<<boxWidth<<" Inches Wide"<<endl;

    cout<<"What is the length of the box?(inches)"<<endl;
    boxLength = Package::recieveCinFloat();
    cout<<boxLength<<" Inches Long"<<endl;

    cout<<"What is the height of the box?(inches)"<<endl;
    boxHeight = Package::recieveCinFloat();
    cout<<boxHeight<<" Inches High"<<endl;

    //cout<<Package::getExpressShippingIntA()<<endl;

    if (Package::getExpressShippingIntA() == 1){
        Package::setFullShippingPrice((boxWeight*1.3*((boxLength*boxWidth*boxHeight)*.5))+5.49);
    }else{
        Package::setFullShippingPrice((boxWeight*1.2*((boxLength*boxWidth*boxHeight)*.5))+5.49);
    }
    cout<<"Total Shipping plus taxes comes to a total of: "<<Package::getFullShippingPrice()<<endl<<endl;

}
