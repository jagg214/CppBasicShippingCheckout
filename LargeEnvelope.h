#ifndef LARGEENVELOPE_H
#define LARGEENVELOPE_H

#include "Package.h"


class LargeEnvelope : public Package
{
    public:
        LargeEnvelope();
        ~LargeEnvelope();
        void processPackage();
        void calculateShipping();

    protected:

    private:
        float largeEnvelopeWeight;
        float largeEnvelopeLength;
        float largeEnvelopeWidth;
};

#endif // LARGEENVELOPE_H
