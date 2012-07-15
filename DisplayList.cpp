#ifndef ZXDISPLAYLIST
#define ZXDISPLAYLIST

#include "Glut.h"

class DisplayList
{
public:
	
	inline DisplayList()
	{
		displayList = glGenLists(1);
	}
	
	inline void Begin() const
	{
		glNewList(displayList, GL_COMPILE);
	}
	inline void End() const
	{
		glEndList();
	}
	inline void Draw() const
	{
		glCallList(displayList);
	}
	inline void Destroy() const
	{
		glDeleteLists(displayList, 1);
	}

protected:
	GLuint displayList;
};

#endif
