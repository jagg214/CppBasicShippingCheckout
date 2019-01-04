#ifndef ENVELOPE_H
#define ENVELOPE_H

#include "Package.h"


class Envelope : public Package
{
    public:
        Envelope();
        ~Envelope();
        void processPackage();
        void calculateShipping();

    protected:

    private:
        float envelopeWeight;
};

#endif // ENVELOPE_H
