#ifndef RDPUMPKIN
#define RDPUMPKIN

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "Pumpkin"

Depende de: <Radical> [Para el Game Engine]

Esta Libreria contiene a Pumpkin, el Graphx Engine.

Inicializa OpenGL con los parametros necesarios para el motor

EOF
********************************************************************************
*/

#include "Color.cpp"
#include "Particle.cpp"
#include "Light.cpp"
#include "Texture.cpp"

void display();
void reshape(int w, int h);

enum World2DModeResize {mrDontCare, mrAllVisible, mrWidthVisible, mrHeightVisible};

class GraphxEngine
{
public:
	unsigned long widthScreen;
	unsigned long heightScreen;
	Particle cameraPosition;
	Particle cameraLooking;
	float widthWorld2D;
	float heightWorld2D;
	int modeResize;
	
	friend void reshape(int w, int h);
	friend class GameEngine;

	inline void DrawBegin3D() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(cameraPosition.GetX(), cameraPosition.GetY(), cameraPosition.GetZ(),
					cameraLooking.GetX(), cameraLooking.GetY(), cameraLooking.GetZ(),
					0.0, 1.0, 0.0);
	}
	inline void DrawBegin2D() const
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(x1Ortho2D, x2Ortho2D, y1Ortho2D, y2Ortho2D, -1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	inline void SwitchTo2D() const
	{
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
	}
	inline void ReturnTo3D() const
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		reshape(widthScreen, heightScreen);
	}
	inline void DrawEnd() const
	{
		
	}
	inline void SetBackgroundColor(const Color& Color) const
	{
		glClearColor(Color.r, Color.g, Color.b, Color.a);
	}
	/*inline void TurnOnCamera() const
	{
		gluLookAt(cameraPosition.GetX(), cameraPosition.GetY(), cameraPosition.GetZ(),
				  cameraLooking.GetX(), cameraLooking.GetY(), cameraLooking.GetZ(),
				  0.0, 1.0, 0.0);
				  //1.0, 0.0, -1.0);
	}*/
	inline void Set2DWorld(const float WidthWorld2D, const float HeightWorld2D, const int ModeResize)
	{
		widthWorld2D  = WidthWorld2D;
		heightWorld2D = HeightWorld2D;
		modeResize    = ModeResize;
		if(modeResize == mrDontCare)
		{
			x1Ortho2D = 0;
			y1Ortho2D = 0;
			x2Ortho2D = widthWorld2D;
			y2Ortho2D = heightWorld2D;
		}
		/*else
			CalcOrtho2D();*/
	}

private:
	Color backgroundColor;
	float x1Ortho2D;
	float y1Ortho2D;
	float x2Ortho2D;
	float y2Ortho2D;
	
	void Init()
	{
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnable(GL_BLEND);
		//glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glBlendEquation(GL_FUNC_ADD);
		glEnable(GL_POINT_SMOOTH);
		glEnable(GL_FOG);
		//float linear[] = {0.0, 0.12, 0.0};
		//glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, linear);
		
		float fogColor[4] = {0, 0, 0, 1.0};
		int fogMode = GL_LINEAR;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.75);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, 8.0);
		glFogf(GL_FOG_END, 24.0);

		SetBackgroundColor(Color(0.0, 0.0, 0.0, 1.0));
		glColor4f(1.0, 1.0, 1.0, 1.0);
		Light::InitEngine();
		Texture::InitEngine();
		glShadeModel(GL_SMOOTH);
		cameraPosition.Move(0.0, 0.0, 2.0);
		cameraLooking.Move(0.0, 0.0, 0.0);
	}
	inline void SetScreen(const unsigned WidthPixels, const unsigned HeightPixels)
	{
		widthScreen  = WidthPixels;
		heightScreen = HeightPixels;
	}
	inline void CalcOrtho2D()
	{
		if(modeResize == mrAllVisible)
		{
			float aspectScreen = float(widthScreen)/heightScreen;
			float aspectWorld  = widthWorld2D/heightWorld2D;
			if(aspectScreen >= aspectWorld)
				modeResize = mrHeightVisible;
			else
				modeResize = mrWidthVisible;
		}
		float w, h, d;
		switch(modeResize)
		{
			case mrWidthVisible:
				w = widthWorld2D;
				h = heightWorld2D*heightScreen/widthScreen;
				d = (h-heightWorld2D)/2;
				y1Ortho2D = -d;
				y2Ortho2D = h-d;
				x1Ortho2D = 0;
				x2Ortho2D = w;
			break;
			case mrHeightVisible:
				h = heightWorld2D;
				w = widthWorld2D*widthScreen/heightScreen;
				d = (w-widthWorld2D)/2;
				x1Ortho2D = -d;
				x2Ortho2D = w-d;
				y1Ortho2D = 0;
				y2Ortho2D = h;
			break;
		}
	}
}Pumpkin;

void reshape(int w, int h)
{
	Pumpkin.widthScreen = w;
	Pumpkin.heightScreen = h;
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*float a = .10;
	float b = float(h)/w;
	glFrustum(-1*a, 1*a, -b*a, b*a, 0.1, 10.0);*/
	gluPerspective(45.0, float(w)/h, 0.1, 40.0);
	glMatrixMode(GL_MODELVIEW);
	Pumpkin.CalcOrtho2D();
}

void display()
{
	Schala.Run();
	RadicalGame();
	glutSwapBuffers();
	//glFlush();
}

#endif
