#include "LargeEnvelope.h"
#include <iostream>
#include <fstream>

using namespace std;

LargeEnvelope::LargeEnvelope()
{
    //ctor
    //cout<<"New LargeEnvelope Created"<<endl;
}

LargeEnvelope::~LargeEnvelope()
{
    //dtor
}

void LargeEnvelope::processPackage(){
    cout<<"LargeEnvelope Process Package called"<<endl;
    Package::setAdressString();
    Package::qExpressShipping();
    LargeEnvelope::calculateShipping();
    Package::confirmDeliveryDetails();
}

void LargeEnvelope::calculateShipping(){
    cout<<"How much does the envelope weigh (Lbs)?"<<endl;
    largeEnvelopeWeight = Package::recieveCinFloat();
    cout<<largeEnvelopeWeight<<" Lbs"<<endl;

    cout<<"What is the width of the envelope?(inches)"<<endl;
    largeEnvelopeWidth = Package::recieveCinFloat();
    cout<<largeEnvelopeWidth<<" Inches Wide"<<endl;

    cout<<"What is the length of the envelope?(inches)"<<endl;
    largeEnvelopeLength = Package::recieveCinFloat();
    cout<<largeEnvelopeLength<<" Inches Long"<<endl;

    //cout<<Package::getExpressShippingIntA()<<endl;

    if (Package::getExpressShippingIntA() == 1){
        Package::setFullShippingPrice((largeEnvelopeWeight*1.3*((largeEnvelopeLength*largeEnvelopeWidth)*.5))+5.49);
    }else{
        Package::setFullShippingPrice((largeEnvelopeWeight*1.2*((largeEnvelopeLength*largeEnvelopeWidth)*.5))+5.49);
    }
    cout<<"Total Shipping plus taxes comes to a total of: "<<Package::getFullShippingPrice()<<endl<<endl;
}
