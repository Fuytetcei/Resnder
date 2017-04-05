

#ifndef _CTIMER_H
#define _CTIMER_H

#include "CBasics.h"

class CTimer{
    private:
        int waitSecs;
        std::clock_t ini;
    public:
        CTimer();
        void setTime(int secs);// --------------------- Establece el tiempo
        bool isActivated();
};

#endif

