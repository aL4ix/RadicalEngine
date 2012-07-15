#ifndef ZXPARTICLEACC
#define ZXPARTICLEACC

#include "ParticleVel.cpp"

class ParticleAcc : public ParticleVel
{
public:
	
	ParticleAcc(Particle& Particle) : ParticleVel(Particle)
	{
	}
	
	inline void SetAcc(const float AccX, const float AccY, const float AccZ)
	{
		accX = AccX;
		accY = AccY;
		accZ = AccZ;
	}
	inline void Acc()
	{
		velX += accX;
		velY += accY;
		velZ += accZ;
		Vel();
	}
	
//protected:
	float accX;
	float accY;
	float accZ;
};

#endif