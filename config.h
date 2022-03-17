#pragma once
//
//Configuration settings
//
//OS setting (WINDOWS or LINUX)
#define LINUX




















// Do not change these

// Windows Definitions
#ifdef WINDOWS
#define WAIT ("timeout 1 /nobreak > nul")
#define CLEARSCREEN ("cls")
#endif

// Linux Definitions
#ifdef LINUX
#define WAIT ("sleep 1")
#define CLEARSCREEN ("clear")
#endif
