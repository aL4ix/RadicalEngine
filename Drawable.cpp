#ifndef ZXDRAWABLE
#define ZXDRAWABLE

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "Drawable"

Depende de: <Glut.h> [Para OpenGL]
			<Particle.h> [Hereda de ella]

Esta Libreria contiene a Drawable, la clase de la que heredan todas las
cosas que se pueden ser dibujadas

EOF
********************************************************************************
*/

#include "Glut.h"
#include "Particle.cpp"

class Drawable : public Particle
{
public:
	
	virtual void Draw() = 0;
};

#endif
