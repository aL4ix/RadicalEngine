#ifndef ZXPARTICLEVEL
#define ZXPARTICLEVEL

class ParticleVel
{
public:
	
	ParticleVel(Particle& Particle) : particle(Particle)
	{
	}
	
	inline void SetVel(const float VelX, const float VelY, const float VelZ)
	{
		velX = VelX;
		velY = VelY;
		velZ = VelZ;
	}
	inline void AddVel(const float VelX, const float VelY, const float VelZ)
	{
		velX += VelX;
		velY += VelY;
		velZ += VelZ;
	}
	inline void Vel() const
	{
		particle.MoveRel(Schala.Rel(velX), Schala.Rel(velY), Schala.Rel(velZ));
	}
	
//protected:
	Particle& particle;
	float velX;
	float velY;
	float velZ;
};

#endif
