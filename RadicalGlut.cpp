#ifndef RADICALGLUT
#define RADICALGLUT

#include "Glut.h"

/*
 * Draws a solid cube. Code contributed by Andreas Umbach <marvin@dataway.ch>
 */
void rdglutSolidCube( GLdouble dSize )
{
    double size = dSize * 0.5;

#   define V(a,b,c) glVertex3d( a size, b size, c size );
#   define N(a,b,c) glNormal3d( a, b, c );

    /* PWO: Again, I dared to convert the code to use macros... */
    glBegin( GL_QUADS );
        N( 1.0, 0.0, 0.0); V(+,-,+); V(+,-,-); V(+,+,-); V(+,+,+);
        N( 0.0, 1.0, 0.0); V(+,+,+); V(+,+,-); V(-,+,-); V(-,+,+);
        N( 0.0, 0.0, 1.0); V(+,+,+); V(-,+,+); V(-,-,+); V(+,-,+);
        N(-1.0, 0.0, 0.0); V(-,-,+); V(-,+,+); V(-,+,-); V(-,-,-);
        N( 0.0,-1.0, 0.0); V(-,-,+); V(-,-,-); V(+,-,-); V(+,-,+);
        N( 0.0, 0.0,-1.0); V(-,-,-); V(-,+,-); V(+,+,-); V(+,-,-);
    glEnd();

#   undef V
#   undef N
}

#endif
