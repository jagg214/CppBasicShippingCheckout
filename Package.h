#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package
{
    public:
        Package();
        ~Package();
        virtual void processPackage();
        virtual void calculateShipping();
        void qExpressShipping();
        void recieveShipping();
        void setAdressString();
        int itemToBeProccessedQ();
        int getExpressShippingIntA();
        void setFullShippingPrice(float newPrice);
        float getFullShippingPrice();
        float recieveCinFloat();
        void confirmDeliveryDetails();
        void finalizeDetails();


    protected:

    private:
        std::string adressString;
        std::string cityString;
        std::string stateString;
        std::string fullShippingAdress;
        int zipCodeInt = 0;
        int expressShippingIntA = -1;
        bool expressShippingBoolA;
        float fullShippingPrice;

};

#endif // PACKAGE_H
