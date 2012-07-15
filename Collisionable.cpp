#ifndef ZXCOLISIONABLE
#define ZXCOLISIONABLE

#include "Transformable.cpp"
#include "Model.cpp"

using namespace std;

class Collisionable : public Transformable
{
public:
	Model model;
	
	inline void UpdateModel()
	{
		model.GetParallelepiped(lc[0], lc[1], lc[2], lc[3], lc[4], lc[5]);
	}
	
	inline bool Collision(Collisionable& Obj)
	{
		if(collisionNeedsUpdate)
			UpdateCollision();
		if(Obj.collisionNeedsUpdate)
			Obj.UpdateCollision();
		
		#define x1 c[0]
		#define y1 c[1]
		#define z1 c[2]
		#define x2 c[3]
		#define y2 c[4]
		#define z2 c[5]
		
		return ( x2>=Obj.x1 && y2>=Obj.y1 && z2>=Obj.z1 /**/&&/**/ Obj.x2>=x1 && Obj.y2>=y1 && Obj.z2>=z1 );
		
		#undef x1
		#undef y1
		#undef z1
		#undef x2
		#undef y2
		#undef z2
	}	
	inline bool CollisionXZ(Collisionable& Obj)
	{
		if(collisionNeedsUpdate)
			UpdateCollision();
		if(Obj.collisionNeedsUpdate)
			Obj.UpdateCollision();
		
		#define x1 c[0]
		#define z1 c[2]
		#define x2 c[3]
		#define z2 c[5]
		
		return ( x2>=Obj.x1 && z2>=Obj.z1 /**/&&/**/ Obj.x2>=x1 && Obj.z2>=z1 );
		
		#undef x1
		#undef z1
		#undef x2
		#undef z2
	}	
	
protected:
	float lc[6];
	float c[6];
	/*float r[3][3];
	float rc[6];
	float sc[6];*/
	bool collisionNeedsUpdate;
	
	inline void UpdateCollision()
	{
		Update();
		/*
		Math.ScaleVector(sx, sy, sz, lc, sc);
		Math.ScaleVector(sx, sy, sz, lc+3, sc+3);
		Math.GenRotationMatrix(rangle, rx, ry, rz, r);
		Math.MultiplyMatrixByColumn(r, lc, rc);
		Math.MultiplyMatrixByColumn(r, lc+3, rc+3);
		Math.TranslateVector(x, y, z, lc, c);
		Math.TranslateVector(x, y, z, lc+3, c+3);
		*/
		Math.MultiplyVector3RowByMatrix4x4(lc, matrix, c);
		Math.MultiplyVector3RowByMatrix4x4(lc+3, matrix, c+3);
	}
	inline void EnableNeedsUpdate()
	{
		needsUpdate = collisionNeedsUpdate = true;
	}
};

#endif
