#ifndef ZXLIGHT
#define ZXLIGHT

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "Light"

Depende de: <Glut.h> [Para OpenGL]
			<Color.h> [Para los colores de la luz]
			<Drawable.h> [Para dibujar la luz]

Esta Libreria contiene a Color, el Color

Tiene un vector y RGBA separados para poder usar el que se necesite

EOF
********************************************************************************
*/

#include "Glut.h"
#include "Color.cpp"
#include "Drawable.cpp"

class Light : public Drawable
{
public:
	Light()
	{
		num = count++;
		Enable();
	}

	inline static void InitEngine()
	{
		glEnable(GL_DEPTH_TEST);
		EnableLighting();
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
		//glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
	}
	inline static void SetGlobalAmbient(const Color& Color)
	{
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Color.v);
	}
	inline static void EnableLighting()
	{
		glEnable(GL_LIGHTING);
	}
	inline static void DisableLighting()
	{
		glDisable(GL_LIGHTING);
	}
	
	inline void Enable() const
	{
		glEnable(num);
	}
	void Disable() const
	{
		glEnable(num);
	}
	inline void SetAmbient(const Color& Color) const
	{
		glLightfv(num, GL_AMBIENT, Color.v);
	}
	inline void SetDifusse(const Color& Color) const
	{
		glLightfv(num, GL_DIFFUSE, Color.v);
	}
	inline void SetSpecular(const Color& Color) const
	{
		glLightfv(num, GL_SPECULAR, Color.v);
	}
	inline void SetSpotCutoff(const float Cutoff) const
	{
		glLightf(num, GL_SPOT_CUTOFF, Cutoff);
	}
	inline void SetSpotDirection(const Particle& Direction) const
	{
		glLightfv(num, GL_SPOT_DIRECTION, Direction.v);
	}
	inline void SetSpotExponent(const float Exponent) const
	{
		glLightf(num, GL_SPOT_EXPONENT, Exponent);
	}
	inline void SetAttenuationConstant(const float Attenuation) const
	{
		glLightf(num, GL_CONSTANT_ATTENUATION, Attenuation);
	}
	inline void SetAttenuationLinear(const float Attenuation) const
	{
		glLightf(num, GL_LINEAR_ATTENUATION, Attenuation);
	}
	inline void SetAttenuationQuadratic(const float Attenuation) const
	{
		glLightf(num, GL_QUADRATIC_ATTENUATION, Attenuation);
	}
	inline void Draw()
	{
		glLightfv(num, GL_POSITION, v);
	}
	
private:
	GLenum num;
	static GLenum count;
};

GLenum Light::count = GL_LIGHT0;

#endif
