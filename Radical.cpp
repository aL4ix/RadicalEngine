#ifndef RDRADICAL
#define RDRADICAL

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "Radical"

Depende de: <Sabe.h> [Para No Se]

Esta Libreria contiene a Radical, el Game Engine.

Este se encarga principalmente de casi nada, de hecho aun no se que tiene que
manejar ya que se tiene que portear.

EOF
********************************************************************************
*/

#include <iostream>
#include "Glut.h"
#ifdef WIN32
#else
#include <sys/times.h>
#endif

inline int RadicalGetSysTime()
{
	#ifdef WIN32
	return GetTickCount();
	#else
	//struct timespec ts;
	//clock_gettime(CLOCK_MONOTONIC, &ts);
	//return ts.tv_sec/1000 + ts.tv_nsec*1000;
	tms tm;
	return times(&tm)*10;
	#endif
}

#include "Schala.cpp"

void (*RadicalGame)();

void __EmptyCallback()
{
}



#include "Pumpkin.cpp"

class GameEngine
{
public:
	GameEngine()
	{
		int zx = 0;
		glutInit(&zx, NULL);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("RadicalEngine3D");
		
		Pumpkin.Init();
		
		RadicalGame = __EmptyCallback;
	}
	
	inline void StartGame(void (*Game)(void), const unsigned WidthPixels = 0, const unsigned HeightPixels = 0)
	{
		if(WidthPixels == 0)
			glutFullScreen();
		else
			glutReshapeWindow(WidthPixels, HeightPixels);
		Pumpkin.SetScreen(WidthPixels, HeightPixels);
		
		glutReshapeFunc(reshape);
		glutDisplayFunc(display);
		glutIdleFunc(display);
		
		SetGameLoop(Game);
		glutMainLoop();
	}
	inline void SetGameLoop(void (*Game)(void))
	{
		RadicalGame = Game;
	}
	inline void SetKeyboardFunc(void (*KeysMenu)(unsigned char key, int x, int y))
	{
		glutKeyboardFunc(KeysMenu);
	}
	inline void SetSpecialFunc(void (*SpecialKeys)(int, int, int))
	{
		glutSpecialFunc(SpecialKeys);
	}
	
private:
	
	
	
}Radical;

#endif
