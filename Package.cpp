#include "Package.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

Package::Package()
{
    //ctor
    //cout<<"New Package Created"<<endl;
}

Package::~Package()
{
    //dtor
    //cout<<"New Package Destroyed"<<endl;
}

void Package::processPackage(){
    cout<<"Package Process Package called"<<endl<<endl;
    //Package::setAdressString();
}

void Package::setAdressString(){
    cout<<"Please Enter a Street Adress"<<endl<<endl;
    //cin.clear();
    cin.ignore();
    getline(cin, adressString);
    cout<<"What city?"<<endl<<endl;
    getline(cin, cityString);
    cout<<"What State?"<<endl<<endl;
    getline(cin, stateString);
    cout<<"What Zip-Code?"<<endl<<endl;
    /*
    do{
    cin>>zipCodeInt;

            if (cin.fail()){
                cout<<"Unrecognized Input: please enter Zip Code Again"<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while(zipCodeInt==0);*/
    zipCodeInt = recieveCinFloat();
    fullShippingAdress = adressString + ", " + cityString + ", " + stateString;
    cout<<endl<<endl<<"The Entered Adress is "<<fullShippingAdress<<", "<<zipCodeInt<<endl;


    //cout<<endl<<endl<<"The Entered Adress is"<<endl<<adressString<<", "<<cityString<<", "<<stateString<<", "<<zipCodeInt<<endl;

}

void Package::calculateShipping(){

}

void Package::qExpressShipping(){
    cout<<"Would you like to purchase express shipping? [Y/N]"<<endl;
    expressShippingIntA = Package::itemToBeProccessedQ();
    //cout<<"Express shipping answer :"<<expressShippingIntA<<endl<<endl;

}

int Package::itemToBeProccessedQ(){
    char itemToBeProccessedA;
    bool itemProcessRepeat = true;
    do{
        cin>>itemToBeProccessedA;
        cout<<endl;
        if(itemToBeProccessedA=='Y'||itemToBeProccessedA=='y'){
            //cout<<"Y was Entered"<<endl;
            return 1;
            itemProcessRepeat = false;
        }
        else if(itemToBeProccessedA == 'N'||itemToBeProccessedA=='n'){
            //cout<<"N was Entered"<<endl;
            return 0;
            itemProcessRepeat = false;
        }
        else{
            cout<<"The response you entered is unrecognized, please try again"<<endl<<endl;
            //return -1;
            itemProcessRepeat = true;
        }
    }while(itemProcessRepeat == true);
}

int Package::getExpressShippingIntA(){
return expressShippingIntA;
}
void Package::setFullShippingPrice(float newPrice)
{
    fullShippingPrice=newPrice;
}

float Package::getFullShippingPrice(){
    return fullShippingPrice;
}

float Package::recieveCinFloat(){
    float recievedFloat = 0;
do{
    cin>>recievedFloat;

            if (cin.fail()){
                cout<<"Unrecognized Input: please try again"<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while(recievedFloat==0);
        return recievedFloat;
}

void Package::confirmDeliveryDetails(){
    cout<<"Let us cofirm your details!"<<endl;
    cout<<endl<<"Adress: "<<Package::fullShippingAdress<<"\nZipcode: "<<Package::zipCodeInt<<"\nShippingPrice: "<<Package::fullShippingPrice<<endl<<endl;
    cout<<"Is all that information Correct?[Y/N]"<<endl<<endl;
    float detailsConfirmed = Package::itemToBeProccessedQ();
    if (detailsConfirmed ==1){
        Package::finalizeDetails();
        cout<<"Order Confirmed!"<<endl;
    }else{
        cout<<"Order canceled."<<endl<<endl;
    }
}

void Package::finalizeDetails(){
    ofstream newDeliveryOrder ("newDeliveryOrder.txt");
    newDeliveryOrder<<Package::fullShippingAdress<<"\n"<<Package::zipCodeInt<<"\n"<<Package::fullShippingPrice<<endl;
}
