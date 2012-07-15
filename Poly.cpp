#ifndef ZXPOLY
#define ZXPOLY

#include <cmath>
#include <vector>
#include "Glut.h"
#include "Particle.cpp"
#include "Particle2D.cpp"
#include "Math.cpp"
#include "Texture.cpp"

class Poly
{
public:
	Texture tex;
	
	Poly()
	{
		v = NULL;
		n = NULL;
		t = NULL;
	}

	friend class Model;

	inline void Begin(GLenum Mode)
	{
		mode = Mode;
	}
	inline void AddVertex(const float X, const float Y, const float Z)
	{
		vertex.push_back(Particle(X, Y, Z));
	}
	inline void SetTexture(Texture Texture)
	{
		tex = Texture;
	}
	inline void AddTexCoord(const float X, const float Y)
	{
		texCoord.push_back(Particle2D(X, Y));
	}
	inline void EndTexCoord()
	{
		if(texCoord.size())
		{
			t = new float[2*s];
			for(unsigned i=0; i<s; i++)
			{
				t[(i*2)+0] = texCoord[i].x;
				t[(i*2)+1] = texCoord[i].y;
			}
		}
		texCoord.clear();
	}
	void End()
	{
		float v1[3], v2[3], normal[3];
		Math.Substract(vertex[1].v, vertex[0].v, v1);
		Math.Substract(vertex[2].v, vertex[0].v, v2);
		Math.Cross(v1, v2, normal);
		Math.Normalize(normal);
		
		s = (unsigned)vertex.size();
		
		v = new float[3*s];
		for(unsigned i=0; i<s; i++)
			for(unsigned j=0; j<3; j++)
				v[(i*3)+j] = vertex[i].v[j];
		n = new float[3*s];
		for(unsigned i=0; i<s; i++)
			for(unsigned j=0; j<3; j++)
				n[(i*3)+j] = normal[j];
		vertex.clear();
	}
	void Draw() const
	{
		if(t)
		{
			Texture::Enable();
			tex.Draw();
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			
			glTexCoordPointer(2, GL_FLOAT, 0, t);
		}
		glVertexPointer(3, GL_FLOAT, 0, v);
		glNormalPointer(GL_FLOAT, 0, n);
		
		glDrawArrays(mode, 0, s);
		if(t)
		{
			Texture::Disable();
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
	}
	void Destroy()
	{
		if(v)
		{
			delete [] v;
			delete [] n;
		}
		if(t)
			delete [] t;
	}
	
	inline void Rotate(const float Angle, const float Rx, const float Ry, const float Rz)
	{
		float r[3][3];
		Math.GenRotationMatrix(Angle, Rx, Ry, Rz, r);
		Rotate(Angle, Rx, Ry, Rz, r);
	}
	inline void Rotate(const float Angle, const float Rx, const float Ry, const float Rz, float R[3][3])
	{
		Math.RotateNVectors2(Angle, Rx, Ry, Rz, v, n, s, R);
	}
	inline void Scale(const float Sx, const float Sy, const float Sz)
	{
		for(unsigned i=0; i<s*3; i+=3)
		{
			Math.ScaleVector(Sx, Sy, Sz, v+i, v+i);
		}
	}
	static Poly Rectangle(const float X1, const float Y1, const float X2, const float Y2)
	{
		Poly poly;
		poly.Begin(GL_TRIANGLE_FAN);
		poly.AddVertex(X1, Y1, 0);
		poly.AddVertex(X2, Y1, 0);
		poly.AddVertex(X2, Y2, 0);
		poly.AddVertex(X1, Y2, 0);
		poly.End();
		return poly;
	}
	inline void SetWholeTexture()
	{
		AddTexCoord(0, 0);
		AddTexCoord(1, 0);
		AddTexCoord(1, 1);
		AddTexCoord(0, 1);
		EndTexCoord();
	}

protected:
	std::vector<Particle> vertex;
	GLenum mode;
	float* v;
	float* n;
	unsigned s;
	float* t;
	std::vector<Particle2D> texCoord;
};

#endif
