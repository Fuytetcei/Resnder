
#ifndef _CDATA_H
#define _CDATA_H

// Resoluciones posibles
enum resolucion {RES_800X600=0, RES_1024X768, RES_1152X864, RES_1280X600, RES_1280X720, RES_1280X768, RES_1280X800,
                RES_1280X960, RES_1280X1024, RES_1360X768, RES_1366X768, RES_1400X1050, RES_1440X900, RES_1600X900,
                RES_1680X1050, RES_1920X1080};

enum colision {DOWN=0, UP, LEFT, RIGHT};

enum effect {EFFECT_CURE=0, EFFECT_DAMAGE, EFFECT_POISSON, EFFECT_LESSDEFENSE, EFFECT_MOREDEFENSE, EFFECT_LESDAMAGE, EFFECT_MOREDAMAGE, EFFECT_BURNED, EFFECT_FROZEN, EFFECT_NUMEFFECT};

extern Uint32 USER_EVENTS;

// Códigos de los diferentes eventos generados por el usuario
enum userEvents {SCENERYCHANGE};

// Objetos de acción
enum objects {OBJ_OBJ=0, OBJ_GATE, OBJ_CARTEL};

// Dirección
enum direction {DIR_UP=0, DIR_DOWN, DIR_LEFT, DIR_RIGHT, DIR_UP_RIGHT, DIR_UP_LEFT, DIR_DOWN_LEFT, DIR_DOWN_RIGHT, DIR_STATIC};

#endif