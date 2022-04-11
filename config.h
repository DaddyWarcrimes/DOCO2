#pragma once
//
//Configuration settings
//
//Simulation settings

#define STARTENERGY 500
#define ENERGYUSE 25
#define ENERGYSPLIT 750

#define VERTICALMARKER |
#define HORIZONTALMARKER =
#define DIAGONALMARKER X

//OS setting (WINDOWS or LINUX)
#define LINUX

//Debug flag
//#define DEBUG


















// Do not change these

// Windows Definitions
#ifdef WINDOWS
#define WAIT ("timeout 1 /nobreak > nul")
#define CLEARSCREEN ("cls")
#define STATICMARKER \xB2
#endif

// Linux Definitions
#ifdef LINUX
#define WAIT ("sleep 1")
#define CLEARSCREEN ("clear")
#define STATICMARKER #
#endif
