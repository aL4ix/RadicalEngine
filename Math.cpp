#ifndef RDMATT
#define RDMATT

#define _USE_MATH_DEFINES
#include <cmath>

class MathEngine
{
public:

	static const float DEGTORAD;
	static const float RADTODEG;

	inline void MultiplyMatrixByColumn(const float M[3][3], const float* V, float* Res)
	{
		const unsigned N = 3;
		for(unsigned i=0; i<N; i++)
		{
			Res[i] = 0.0;
			for(unsigned j=0; j<N; j++)
				Res[i] += M[i][j] * V[j];
		}
	}
	inline void MultiplyVector3RowByMatrix4x4(const float* V, const float M[4][4], float* Res)
	{
		for(unsigned i=0; i<3; i++)
		{
			Res[i] = 0.0;
			for(unsigned j=0; j<3; j++)
				Res[i] += M[j][i] * V[j];
			Res[i] += M[3][i];
		}
	}
	inline float Dot(float* v1, float* v2)
	{
		return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
	}
	inline void Cross(const float* V1, const float* V2, float* Res)
	{
		Res[0] = V1[1]*V2[2] - V1[2]*V2[1];
		Res[1] = V1[2]*V2[0] - V1[0]*V2[2];
		Res[2] = V1[0]*V2[1] - V1[1]*V2[0];
	}
	inline void Normalize(float* V)
	{
		float d = sqrt(sq(V[0]) + sq(V[1]) + sq(V[2]));
		V[0] /= d;
		V[1] /= d;
		V[2] /= d;
	}
	void Multiply(float* v, float Escalar)
	{
		v[0] *= Escalar;
		v[1] *= Escalar;
		v[2] *= Escalar;
	}
	void Substract(const float* V1, const float* V2, float* Res)
	{
		Res[0] = V1[0] - V2[0];
		Res[1] = V1[1] - V2[1];
		Res[2] = V1[2] - V2[2];
	}
	inline float sq(float x)
	{
		return x*x;
	}
	
	inline void GenRotationMatrix(float Angle, const float X, const float Y, const float Z, float Matrix[3][3])
	{
		Angle *= DEGTORAD;
		float coseno = cos(Angle), seno = sin(Angle), omCos = 1.f - coseno;
		Matrix[0][0] = sq(X)*omCos+coseno;
		Matrix[0][1] = X*Y*omCos-Z*seno;
		Matrix[0][2] = X*Z*omCos+Y*seno;

		Matrix[1][0] = Y*X*omCos+Z*seno;
		Matrix[1][1] = sq(Y)*omCos+coseno;
		Matrix[1][2] = Y*Z*omCos-X*seno;

		Matrix[2][0] = Z*X*omCos-Y*seno;
		Matrix[2][1] = Z*Y*omCos+X*seno;
		Matrix[2][2] = sq(Z)*omCos+coseno;
	}
	inline void RotateNVectors(const float Angle, const float Rx, const float Ry, const float Rz, float* V, unsigned N, const float R[3][3])
	{
		for(unsigned z=0; z<N*3; z+=3)
		{
			float w[3];
			for(unsigned i=0; i<3; i++)
				w[i] = V[z+i];
			MultiplyMatrixByColumn(R, w, V+z);
		}
	}
	inline void RotateNVectors2(const float Angle, const float Rx, const float Ry, const float Rz, float* V1, float* V2, unsigned N, const float R[3][3])
	{
		for(unsigned z=0; z<N*3; z+=3)
		{
			float w[3];
			for(unsigned i=0; i<3; i++)
				w[i] = V1[z+i];
			MultiplyMatrixByColumn(R, w, V1+z);
			for(unsigned i=0; i<3; i++)
				w[i] = V2[z+i];
			MultiplyMatrixByColumn(R, w, V2+z);
		}
	}
	inline void ScaleVector(const float Sx, const float Sy, const float Sz, const float* V, float* Res)
	{
		Res[0] = V[0]*Sx;
		Res[1] = V[1]*Sy;
		Res[2] = V[2]*Sz;
	}
	inline void TranslateVector(const float X, const float Y, const float Z, const float* V, float* Res)
	{
		Res[0] = V[0]+X;
		Res[1] = V[1]+Y;
		Res[2] = V[2]+Z;
	}
	inline float Distance2D(const float X0, const float Y0, const float X1, const float Y1)
	{
		return sqrt(sq(X1-X0)+sq(Y1-Y0));
	}
} Math;
const float MathEngine::DEGTORAD = (float) M_PI / 180.f;
const float MathEngine::RADTODEG = (float) 180.f / M_PI;


float v[12];
unsigned count=0;

void AddVertex(const float X, const float Y, const float Z)
{
	v[count++] = X;
	v[count++] = Y;
	v[count++] = Z;
}
/*
#include <iostream>

using namespace std;

int main()
{
	float r[3][3];
	Math.GenRotationMatrix(45, 0, 1, 0, r);
	float size = 0.5;
	#define V(a,b,c) AddVertex( a size, b size, c size );
	V(+,+,+); V(+,+,-); V(-,+,-); V(-,+,+);
for(unsigned z=0; z<12; z+=3)
{
	float w[3];
	for(unsigned i=0; i<3; i++)
		w[i] = v[z+i];
	Math.MultiplyMatrixByColumn(r, w, v+z);
	unsigned a = z;
	cout << v[0+a] << endl << v[1+a] << endl << v[2+a] << endl;
}
}
*/
#endif
