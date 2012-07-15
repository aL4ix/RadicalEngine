#ifndef ZXMATERIAL
#define ZXMATERIAL

#include "Color.cpp"
#include "Glut.h"

class Material
{
public:
	
	static inline void SetAmbient(const Color& Color)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Color.v);
	}
	static inline void SetDifusse(const Color& Color)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Color.v);
	}
	static inline void SetAmbientAndDifusse(const Color& Color)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Color.v);
	}
	static inline void SetSpecular(const Color& Color)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Color.v);
	}
	static inline void SetShininess(const float Shininess)
	{
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Shininess);
	}
	static inline void SetEmission(const Color& Color)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Color.v);
	}
	static inline void EnableColorMaterial()
	{
		glEnable(GL_COLOR_MATERIAL);
	}
	static inline void DisableColorMaterial()
	{
		glDisable(GL_COLOR_MATERIAL);
	}
	static inline void SetColorMaterialMode(GLenum mode)
	{
		glColorMaterial(GL_FRONT, mode);
	}
};

#endif
