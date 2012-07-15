#ifndef ZXCOLOR
#define ZXCOLOR

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "Color"

Depende de:

Esta Libreria contiene a Color, el Color

Tiene un vector y RGBA separados para poder usar el que se necesite

EOF
********************************************************************************
*/

class Color
{
public:	
	float v[4];
	float& r;
	float& g;
	float& b;
	float& a;
	
	inline Color() : r(v[0]), g(v[1]), b(v[2]), a(v[3])
	{
	}
	inline Color(const float R, const float G, const float B, const float A = 1.0) : r(v[0]), g(v[1]), b(v[2]), a(v[3])
	{
		SetColor(R, G, B, A);
	}
	inline const Color& operator=(const Color& Color)
	{
		SetColor(Color.r, Color.g, Color.b, Color.a);
		return *this;
	}
	
	inline void SetColor(const float R, const float G, const float B, const float A = 1.0)
	{
		r = R;
		g = G;
		b = B;
		a = A;
	}
};

#endif
