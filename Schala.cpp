#ifndef RDSCHALA
#define RDSCHALA

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
#include <fstream>

int RunGame();
int InitGame();
//void DrawGame();

class TimeEngine
{
public:

	friend class SchalaStarter;
	friend void display();
	
	TimeEngine()
	{
		time = timeAbs = timeLast = 0.0;
	}

	inline float GetStartTime()
	{
		return timeStart;
	}
	inline float GetAbsTime()
	{
		return timeAbs;
	}
	inline float GetIncTime() const
	{
		return time;
	}
	inline void PauseThisFrame()
	{
		time = 0;
	}
	inline float TimeBetweenTimes(float Time1, float Time2)
	{
		return Time2-Time1;
	}
	inline float isElapsed(float Time, float Elapsed)
	{
		if(TimeBetweenTimes(Time, GetAbsTime()) >= Elapsed)
			return true;
		return false;
	}
	inline float Rel(float Value)
	{
		return Value*GetIncTime();
	}
	
private:
	float time;
	float timeLast;
	float timeAbs;
	float timeNextFPS;
	float timeStart;
	unsigned FPS;
		
	inline void Start(float Time)
	{
		timeAbs = Time;
		timeLast = Time;
		timeNextFPS = timeLast+1;
		timeStart = Time;
		FPS = 0;
	}
	bool Run()
	{
		timeAbs  = float(RadicalGetSysTime())/1000.f;
		time     = timeAbs-timeLast;
		if(time > 0.25)
			time = 0.25;
		timeLast = timeAbs;
		if(timeAbs >= timeNextFPS)
		{
			timeNextFPS += 1.0;
			std::cout << "FPS="<<FPS<<std::endl;
			FPS = 0;
		}
		FPS++;
		return true;
	}
	
}Schala;

#endif
