#include "Envelope.h"
#include <iostream>
#include <fstream>

using namespace std;

Envelope::Envelope()
{
    //ctor
    //cout<<"New Envelope Created"<<endl;
}

Envelope::~Envelope()
{
    //dtor
}

void Envelope::processPackage(){
    cout<<"Envelope Process Package called"<<endl;
    Package::setAdressString();
    Package::qExpressShipping();
    Envelope::calculateShipping();
    Package::confirmDeliveryDetails();
}

void Envelope::calculateShipping(){
    cout<<"How much does the envelope weigh (Lbs)?"<<endl;
    envelopeWeight = Package::recieveCinFloat();
    cout<<envelopeWeight<<" Lbs"<<endl;
    //cout<<Package::getExpressShippingIntA()<<endl;

    if (Package::getExpressShippingIntA() == 1){
        Package::setFullShippingPrice((envelopeWeight*1.3)+5.49);
    }else{
        Package::setFullShippingPrice((envelopeWeight*1.2)+5.49);
    }
    cout<<"Total Shipping plus taxes comes to a total of: "<<Package::getFullShippingPrice()<<endl<<endl;
}
