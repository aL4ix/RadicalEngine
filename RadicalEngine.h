#ifndef RDRADICALENGINE
#define RDRADICALENGINE

/*
********************************************************************************
Created by: ~aLeoneLiax

Libreria "RadicalEngine"

Esta Libreria contiene a RadicalEngine, el Engine.

Version OpenGL3D y ligera, principalmente para la plataforma objetivo iPhone 2

EOF
********************************************************************************
*/

/*namespace rd
{
*/
char RadicalDreamers[] = "\n\n\n\n\n\n\n\n\n\n\n\n\"It all began aeons ago, when man's ancestors picked up a shard of strange red rock. Its power, which was beyond human comprehension, cultivated dreams... in turn, love and hate were born... Only time will see how it all ends.\"\nBelthasar's book in Kajar\n\n\n\n\n\n\n\n\n\n\n\n";
#include "Radical.cpp"
#include "Schala.cpp"
#include "Pumpkin.cpp"
#include "Math.cpp"

#include "Color.cpp"
#include "Particle.cpp"
#include "Light.cpp"
#include "Material.cpp"
#include "Drawable.cpp"
#include "Transformable.cpp"
#include "Collisionable.cpp"
#include "Poly.cpp"
#include "Model.cpp"
#include "Cube.cpp"
#include "DisplayList.cpp"
#include "DrawableGroup.cpp"
#include "ParticleAcc.cpp"
#include "ParticleVel.cpp"

class SchalaStarter
{
public:
	SchalaStarter()
	{
		Schala.Start(float(RadicalGetSysTime())/1000.f);
	}
} SchalaStarter;

//};

#endif
