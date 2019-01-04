#include <iostream>
#include <fstream>
#include <string>
#include "Package.h"
#include "Box.h"
#include "Envelope.h"
#include "LargeEnvelope.h"

using namespace std;

int allTransactionsComplete = 0;
int itemToBeProccessedQ();
int packageTypeQ();
void proccessGenPackage(Package *packageRecieved);



int main()
{
    cout<<"Welcome to Apollos' Processing Center"<<endl<<"Is there something you would like to send?"<<endl;
    while (allTransactionsComplete!=1){
        cout<<endl<<"[Y/N]"<<endl<<endl;
        int itemProccessing = itemToBeProccessedQ();
        if (itemProccessing == 0){
            allTransactionsComplete = 1;
        }else if(itemProccessing == 1){

        cout<<"What is the first type of package you want to send?"<<endl<<"[Envelope/LargeEnvelope/Box]"<<endl<<endl;
        int packageType = 0;
        do{
            packageType=packageTypeQ();
        }
        while(!((packageType==1)||(packageType==2)||(packageType==3)));

        //cout<<"The entered package type is "<<packageType<<endl;
        //processPackage(packageType);


        switch(packageType){
            case 1 :
                {
                //cout<<"Creating an envelope"<<endl;
                Envelope newEnvelope;
                Package *newPackage01 = &newEnvelope;
                //newPackage01 = &newEnvelope;
                proccessGenPackage(newPackage01);
                //newEnvelope.processPackage();
                break;
                }
            case 2 :
                {
                //cout<<"Creating a Large Envelope"<<endl;
                LargeEnvelope newLargeEnvelope;
                Package *newPackage01 = &newLargeEnvelope;;
                //newPackage01 = &newLargeEnvelope;
                proccessGenPackage(newPackage01);
                //newLargeEnvelope.processPackage();
                break;
                }
            case 3 :
                {
                //cout<<"Creating a Box"<<endl;
                Box newBox;
                Package *newPackage01;
                newPackage01 = &newBox;
                proccessGenPackage(newPackage01);
                //newBox.processPackage();
                break;
                }
            default : cout<<"Unknown Case Found, please try again."<<endl;
                break;
        }


        //cout<<"Then we process the package"<<endl;
        //Package newpackage01;
        cout<<"Is there another package you would like to send?"<<endl;
        }else{
        }
    }
    cout<<"Thank you for visiting Apollos' Processing Center, Goodbye!"<<endl;
}

int itemToBeProccessedQ(){
    char itemToBeProccessedA;
    cin>>itemToBeProccessedA;
    cout<<endl;
    if(itemToBeProccessedA=='Y'||itemToBeProccessedA=='y'){
        //cout<<"Y was Entered"<<endl;
        return 1;
    }
    else if(itemToBeProccessedA == 'N'||itemToBeProccessedA=='n'){
        //cout<<"N was Entered"<<endl;
        return 0;
    }
    else{
        cout<<"The response you entered is unrecognized, please try again"<<endl<<endl;
        return -1;
    }
}

int packageTypeQ (){
string packageTypeA;
cin>>packageTypeA;
cout<<endl;
if (packageTypeA == "Envelope"||packageTypeA == "envelope"){
        return 1;
    }else if (packageTypeA == "LargeEnvelope"||packageTypeA == "largeenvelope"||packageTypeA == "largeEnvelope"||packageTypeA == "Largeenvelope"){
        return 2;
    }else if (packageTypeA == "Box"||packageTypeA == "box"){
        return 3;
    }else{
        cout<<"Unrecognized Type, Try Again"<<endl<<endl;
        return 0;
    }
}
void proccessGenPackage(Package *packageRecieved){
    //cout<<"classRecieved"<<endl;
    packageRecieved->processPackage();
}
