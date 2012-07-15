#ifndef ZXDRAWABLEGROUP
#define ZXDRAWABLEGROUP

#include "Transformable.cpp"
#include <vector>

class DrawableGroup : public Transformable
{
public:
	std::vector<Drawable*> drawables;
	
	inline DrawableGroup()
	{
		SetDefaultBasix();
	}
	
	void Add(Drawable* Drawable)
	{
		drawables.push_back(Drawable);
	}
	void IntDraw() const
	{
		for(unsigned i=0; i<drawables.size(); i++)
			drawables[i]->Draw();
	}
};

#endif
