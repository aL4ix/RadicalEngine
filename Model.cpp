#ifndef ZXBODY
#define ZXBODY

#include <vector>
#include "Glut.h"
#include "Poly.cpp"
#include "Math.cpp"

class Model
{
public:
	std::vector<Poly> poly;
	unsigned count;
	
	friend class Collisionable;
	
	inline Model()
	{
		count = 0;
	}
	inline static Model Cube(float size)
	{
		Model model;
		size *= 0.5;

		#define V(a,b,c) model.AddVertex( a size, b size, c size );

		model.Begin(GL_TRIANGLE_FAN);
		V(+,-,+); V(+,-,-); V(+,+,-); V(+,+,+);
		model.End();
		model.Begin(GL_TRIANGLE_FAN);
		V(+,+,+); V(+,+,-); V(-,+,-); V(-,+,+);
		model.End();
		model.Begin(GL_TRIANGLE_FAN);
		V(+,+,+); V(-,+,+); V(-,-,+); V(+,-,+);
		model.End();
		model.Begin(GL_TRIANGLE_FAN);
		V(-,-,+); V(-,+,+); V(-,+,-); V(-,-,-);
		model.End();
		model.Begin(GL_TRIANGLE_FAN);
		V(-,-,+); V(-,-,-); V(+,-,-); V(+,-,+);
		model.End();
		model.Begin(GL_TRIANGLE_FAN);
		V(-,-,-); V(-,+,-); V(+,+,-); V(+,-,-);
		model.End();
		#undef V
		return model;
	}
	
	inline void Begin(GLenum Mode)
	{
		poly.push_back(Poly());
		poly[count].Begin(Mode);
	}
	inline void AddVertex(const float X, const float Y, const float Z)
	{
		poly[count].vertex.push_back(Particle(X, Y, Z));
	}
	inline void End()
	{
		poly[count++].End();
	}
	inline void Draw() const
	{
		for(unsigned i=0; i<count; i++)
			poly[i].Draw();
	}
	inline void Destroy()
	{
		for(unsigned i=0; i<count; i++)
			poly[i].Destroy();
		poly.clear();
	}
	
	inline void Rotate(const float Angle, const float Rx, const float Ry, const float Rz)
	{
		float r[3][3];
		Math.GenRotationMatrix(Angle, Rx, Ry, Rz, r);
		for(unsigned i=0; i<count; i++)
			poly[i].Rotate(Angle, Rx, Ry, Rz, r);
	}
	inline void Scale(const float Sx, const float Sy, const float Sz)
	{
		for(unsigned i=0; i<count; i++)
			poly[i].Scale(Sx, Sy, Sz);
	}
	
protected:
	
	inline void GetParallelepiped(float& V1x, float& V1y, float& V1z, float& V2x, float& V2y, float& V2z)
	{
//		V1x = V1y = V1z = INFINITY;
//		V2x = V2y = V2z = -INFINITY;
		V1x = V1y = V1z = V2x = V2y = V2z = 0.0;
		for(unsigned i=0; i<count; i++)
		{
			Poly& p = poly[i];
			for(unsigned j=0; j<3*p.s; j+=3)
			{
				if(p.v[j] < V1x)
					V1x = p.v[j];
				else if(p.v[j] > V2x)
					V2x = p.v[j];
				if(p.v[j+1] < V1y)
					V1y = p.v[j+1];
				else if(p.v[j+1] > V2y)
					V2y = p.v[j+1];
				if(p.v[j+2] < V1z)
					V1z = p.v[j+2];
				else if(p.v[j+2] > V2z)
					V2z = p.v[j+2];
			}
		}
	}
};

#endif
