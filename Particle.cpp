#ifndef ZXPARTICLE
#define ZXPARTICLE

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "Particle"

Depende de: <Radical.cpp> [Para Radical.GetTime()]

Esta Libreria contiene a Particle, el Particle

Tiene un vector y RGBA separados para poder usar el que se necesite

EOF
********************************************************************************
*/

#include "Radical.cpp"

class Particle
{
public:

	friend class Surface;
	friend class Light;
	friend class Drawable;
	friend class Cube;
	friend class Poly;
	
	inline Particle() : x(v[0]), y(v[1]), z(v[2])
	{
		MoveW(1.0);
	}
	inline Particle(float X, float Y, float Z, float W = 1.0) : x(v[0]), y(v[1]), z(v[2])
	{
		MoveWithW(X, Y, Z, W);
	}
	inline Particle(const Particle& Particle) : x(v[0]), y(v[1]), z(v[2])
	{
		MoveWithW(Particle);
	}
	inline const Particle& operator=(const Particle& Particle)
	{
		MoveWithW(Particle);
		std::cout << "WOW";
		return *this;
	}

	inline float GetX() const
	{
		return x;
	}
	inline float GetY() const
	{
		return y;
	}
	inline float GetZ() const
	{
		return z;
	}
	inline float GetW() const
	{
		return v[3];
	}
	inline void MoveW(const float W)
	{
		v[3] = W;
	}
	virtual inline void MoveX(const float X)
	{
		x = X;
	}
	virtual inline void MoveY(const float Y)
	{
		y = Y;
	}
	virtual inline void MoveZ(const float Z)
	{
		z = Z;
	}
	virtual inline void Move(const float X, const float Y, const float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
	inline void Move(const Particle& Particle)
	{
		Move(Particle.x, Particle.y, Particle.z);
	}
	inline void MoveRel(const float X, const float Y, const float Z)
	{
		Move(x+X, y+Y, z+Z);
	}
	inline void MoveTimeRel(const float VelocityX, const float VelocityY, const float VelocityZ)
	{
		MoveRel(Schala.Rel(VelocityX), Schala.Rel(VelocityY), Schala.Rel(VelocityZ));
	}
	inline void MoveWithW(const float X, const float Y, const float Z, const float W)
	{
		Move(X, Y, Z);
		MoveW(W);
	}
	inline void MoveWithW(const Particle& Particle)
	{
		MoveWithW(Particle.x, Particle.y, Particle.z, Particle.v[3]);
	}

protected:
	float& x;
	float& y;
	float& z;
	float v[4];
};

#endif
