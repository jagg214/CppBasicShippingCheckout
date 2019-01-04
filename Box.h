#ifndef BOX_H
#define BOX_H

#include "Package.h"


class Box : public Package
{
    public:
        Box();
        ~Box();
        void processPackage();
        void calculateShipping();

    protected:

    private:
        float boxWeight;
        float boxWidth;
        float boxLength;
        float boxHeight;
};

#endif // BOX_H
