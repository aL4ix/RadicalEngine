#ifndef ZXCUBE
#define ZXCUBE

#include "Drawable.cpp"
#include "Model.cpp"
#include "Collisionable.cpp"

class Cube : public Collisionable
{
public:
	inline Cube(const float Diameter = 1.0)
	{
		SetDefaultBasix();
		Resize(Diameter);
	}
	inline void Resize(const float Diameter)
	{
		model = Model::Cube(Diameter);
		UpdateModel();
		//ProcessCollisions();
	}
	
private:

	inline void IntDraw() const
	{
		model.Draw();
	}
};

#endif
