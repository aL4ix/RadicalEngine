#ifndef ZXTRANSFORMABLE
#define ZXTRANSFORMABLE

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

class Transformable : public Drawable
{
public:
	
	Transformable()
	{
		EnableNeedsUpdate();
	}

	inline void MoveX(const float X)
	{
		x = X;
		EnableNeedsUpdate();
	}
	inline void MoveY(const float Y)
	{
		y = Y;
		EnableNeedsUpdate();
	}
	inline void MoveZ(const float Z)
	{
		z = Z;
		EnableNeedsUpdate();
	}
	inline void Move(const float X, const float Y, const float Z)
	{
		x = X;
		y = Y;
		z = Z;
		EnableNeedsUpdate();
	}
	inline void Scale(const float Sx, const float Sy, const float Sz)
	{
		sx = Sx;
		sy = Sy;
		sz = Sz;
		EnableNeedsUpdate();
	}
	inline void Rotate(const float Angle, const float Rx, const float Ry, const float Rz)
	{
		rangle = Angle;
		rx     = Rx;
		ry     = Ry;
		rz     = Rz;
		EnableNeedsUpdate();
	}
	inline void ScaleRel(const float Rsx, const float Rsy, const float Rsz)
	{
		Scale(sx+Rsx, sy+Rsy, sz+Rsz);
	}
	inline void RotateRel(const float RAngle, const float NormalX, const float NormalY, const float NormalZ)
	{
		Rotate(rangle+RAngle, NormalX, NormalY, NormalZ);
	}
	inline void Draw()
	{
		if(needsUpdate)
			Update();
		glPushMatrix();
		glMultMatrixf( (float*) matrix);
		IntDraw();
		glPopMatrix();
	}
	
protected:
	bool needsUpdate;
	float matrix[4][4];
	float rangle;
	float rx;
	float ry;
	float rz;
	float sx;
	float sy;
	float sz;
	
	virtual void IntDraw() const = 0;
	void Update()
	{
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(x, y, z);
		glRotatef(rangle, rx, ry, rz);
		glScalef(sx, sy, sz);
		glGetFloatv(GL_MODELVIEW_MATRIX, (float*) matrix);
		EnableNeedsUpdate();
		glPopMatrix();
	}
	inline void ShowMatrix() const
	{
		for(unsigned i=0; i<4; i++)
		{
			for(unsigned j=0; j<4; j++)
				std::cout << matrix[j][i] << ' ';
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	virtual inline void EnableNeedsUpdate()
	{
		needsUpdate = true;
	}
	void SetBasix(const float MoveX, const float MoveY, const float MoveZ, float RotateAngle, float RotateX, float RotateY, float RotateZ, float ScaleX, float ScaleY, float ScaleZ)
	{
		Move(MoveX, MoveY, MoveZ);
		Rotate(RotateAngle, RotateX, RotateY, RotateZ);
		Scale(ScaleX, ScaleY, ScaleZ);
	}
	inline void SetDefaultBasix()
	{
		SetBasix(0.0, 0.0, 0.0,
				 0.0, 0.0, 0.0, 0.0,
				 1.0, 1.0, 1.0);
	}
};

#endif
