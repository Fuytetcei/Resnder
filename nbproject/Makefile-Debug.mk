#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CApp.o \
	${OBJECTDIR}/CApp_OnEvent.o \
	${OBJECTDIR}/CCartel.o \
	${OBJECTDIR}/CEnemy.o \
	${OBJECTDIR}/CEvent.o \
	${OBJECTDIR}/CGate.o \
	${OBJECTDIR}/CImage.o \
	${OBJECTDIR}/CModel2D.o \
	${OBJECTDIR}/CMovil.o \
	${OBJECTDIR}/CObj.o \
	${OBJECTDIR}/CPlayer.o \
	${OBJECTDIR}/CScenery.o \
	${OBJECTDIR}/CTimer.o \
	${OBJECTDIR}/sqlite3.o


# C Compiler Flags
CFLAGS=-m32 -static-libgcc -static-libstdc++

# CC Compiler Flags
CCFLAGS=-m32 -static-libgcc -static-libstdc++
CXXFLAGS=-m32 -static-libgcc -static-libstdc++

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/segundo_juego.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/segundo_juego.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/segundo_juego ${OBJECTFILES} ${LDLIBSOPTIONS} -lmingw32 -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2

${OBJECTDIR}/CApp.o: CApp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CApp.o CApp.cpp

${OBJECTDIR}/CApp_OnEvent.o: CApp_OnEvent.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CApp_OnEvent.o CApp_OnEvent.cpp

${OBJECTDIR}/CCartel.o: CCartel.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CCartel.o CCartel.cpp

${OBJECTDIR}/CEnemy.o: CEnemy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CEnemy.o CEnemy.cpp

${OBJECTDIR}/CEvent.o: CEvent.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CEvent.o CEvent.cpp

${OBJECTDIR}/CGate.o: CGate.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CGate.o CGate.cpp

${OBJECTDIR}/CImage.o: CImage.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CImage.o CImage.cpp

${OBJECTDIR}/CModel2D.o: CModel2D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CModel2D.o CModel2D.cpp

${OBJECTDIR}/CMovil.o: CMovil.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CMovil.o CMovil.cpp

${OBJECTDIR}/CObj.o: CObj.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CObj.o CObj.cpp

${OBJECTDIR}/CPlayer.o: CPlayer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPlayer.o CPlayer.cpp

${OBJECTDIR}/CScenery.o: CScenery.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CScenery.o CScenery.cpp

${OBJECTDIR}/CTimer.o: CTimer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CTimer.o CTimer.cpp

${OBJECTDIR}/sqlite3.o: sqlite3.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I/C/lib/SDL2Lib/SDL2-2.0.5/i686-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sqlite3.o sqlite3.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
