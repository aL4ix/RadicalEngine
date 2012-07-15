#include "RadicalEngine.h"
#include <iostream>

Cube cubo, cubo2;
Light luz;

float spin;
float spin2;

int InitGame()
{
 cubo.Init();
 cubo2.Init();
 luz.Init();
 Color whiteLight(1.0, 1.0, 1.0);
 //luz.SetDifusse(whiteLight);
 luz.SetSpecular(whiteLight);
 cubo.MoveTo(0.0, 0.0, 0.0);
 cubo2.MoveTo(-2.0, 0.0, 0.0);
 luz.MoveTo(0.0, 0.0, 0.0);
 luz.Draw();
 spin = spin2 = 0.0;
 return 0;
}

void DrawGame()
{
	float luzBlanca[] = {1.0, 1.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, luzBlanca);
	glMaterialfv(GL_FRONT, GL_SPECULAR, luzBlanca);
	glMaterialf(GL_FRONT, GL_SHININESS, 20.0);
	//glMaterialfv(GL_FRONT, GL_EMISSION, luzBlanca);
	spin2+=0.2;
	//cubo.ScaleRel(0.005, 0.005, 0.005);
	cubo2.Rotate(spin2, 1.0, 0.0, 0.0);
	cubo.Draw();
	cubo2.Draw();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	const float mov = 0.1;
	if(key == 'a')
		Pumpkin.cameraPosition.x -= mov;
	if(key == 'd')
		Pumpkin.cameraPosition.x += mov;
	if(key == 'w')
		Pumpkin.cameraPosition.z -= mov;
	if(key == 's')
		Pumpkin.cameraPosition.z += mov;
	if(key == 'r')
		Pumpkin.cameraPosition.y += mov;
	if(key == 'f')
		Pumpkin.cameraPosition.y -= mov;
	if(key == 'q')
	{
		
	}
	if(key == 'j')
		cubo.MoveRel(-0.10, 0.0, 0.0);
	if(key == 'l')
		cubo.MoveRel(0.10, 0.0, 0.0);
	if(key == 'z')
	{
		spin += 1.0;
		cubo.Rotate(spin, 1.0, 0.0, 0.0);
	}
	if(key == 'm')
		cubo.ScaleRel(0.1, 0.1, 0.1);
	if(key == 'n')
		cubo.ScaleRel(-0.1, -0.1, -0.1);
	//glutPostRedisplay();
	glutIdleFunc(display);
}

int main()
{
	Pumpkin.InitGrphx(500, 500);
	return 0;
}
