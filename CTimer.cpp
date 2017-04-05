
#include "CTimer.h"

// Constructor
CTimer::CTimer(){
    this->waitSecs = 0;
    this->ini = 0;
}
// Establecer tiempo
void CTimer::setTime(int secs){
    // Guardo el tiempo actual
    this->ini = std::clock();
    // Guardo los segundos a esperar
    this->waitSecs = secs;
}
// Miro si ha acabado
bool CTimer::isActivated(){
    return ((std::clock()-this->ini)/(double)CLOCKS_PER_SEC) < this->waitSecs;
}