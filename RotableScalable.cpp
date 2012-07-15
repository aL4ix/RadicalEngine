#ifndef ZXTRANSFORMABLEINTERFACE
#define ZXTRANSFORMABLEINTERFACE

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "Transformable"

Depende de: <Glut.h> [Para OpenGL]
			<Drawable.h> [Hereda de ella]
			<Body.h> [Para contener los modelos]

Esta Libreria contiene a Transformable, la clase de la que heredan todas las
cosas que se pueden ser transformadas.

EOF
********************************************************************************
*/

#include "Drawable.cpp"

class TransformableInterface : public Drawable
{
public:
	
	virtual inline void Scale(const float Sx, const float Sy, const float Sz) = 0;
	virtual inline void Rotate(const float Angle, const float Rx, const float Ry, const float Rz) = 0;
	inline void ScaleRel(const float Rsx, const float Rsy, const float Rsz)
	{
		Scale(sx+Rsx, sy+Rsy, sz+Rsz);
	}
	inline void RotateRel(const float RAngle, const float NormalX, const float NormalY, const float NormalZ)
	{
		Rotate(rangle+RAngle, NormalX, NormalY, NormalZ);
	}
	
protected:
	
	virtual void IntDraw() const = 0;
};

#endif
