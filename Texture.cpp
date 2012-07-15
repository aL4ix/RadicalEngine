#ifndef RDTEXTURE
#define RDTEXTURE

#include "Glut.h"

class Texture
{
public:
	unsigned             width;
	unsigned             height;
	unsigned             format;
	const unsigned char* texels;
	unsigned             texName;
	
	static void InitEngine()
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	}
	
	Texture()
	{
		glGenTextures(1, &texName);
		glBindTexture(GL_TEXTURE_2D, texName);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format, GL_UNSIGNED_BYTE, texels);
	}
	
	bool LoadFromFile(const char* File)
	{
		/*texName = SOIL_load_OGL_texture
        (
        File,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );
 
		if(texName == 0)
			return false;*/
		return true;
	}
	inline void Draw() const
	{
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, texName);
	}
	inline static void Enable()
	{
		glEnable(GL_TEXTURE_2D);
	}
	inline static void Disable()
	{
		glDisable(GL_TEXTURE_2D);
	}
};

#endif
