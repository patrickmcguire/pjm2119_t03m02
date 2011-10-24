#ifndef SHAPE_H_
#define SHAPE_H_

#define PI 3.1415926535898

void floor()
{
  // glPolygonMode(face, mode);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_QUAD_STRIP);
    for (int i = -10; i <= 10; i+=2)
    {
      glVertex3f(-15, 0, i);
      glVertex3f(15, 0, i);
    }
  glEnd();
  glBegin(GL_QUAD_STRIP);
    for (int i = -15; i <= 15; i+=2)
    {
      glVertex3f(i, 0, -10);
      glVertex3f(i, 0, 10);
    }
  glEnd();
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void cg_SolidSphere(GLint slices, GLint stacks)
{
  //glutSolidSphere(slices, stacks, 1.0);
  for (int theta = 0; theta < stacks; ++theta)
  {
    glBegin(GL_QUAD_STRIP);
      for (int phi = 0; phi <= slices; ++phi)
      {
	float n0[] = {sin(theta*PI/stacks)*cos(phi*2.0*PI/slices), 
		      sin(theta*PI/stacks)*sin(phi*2.0*PI/slices), 
		      cos(theta*PI/stacks)};
	glNormal3fv(n0);
	glVertex3fv(n0);
	float n1[]= {sin((theta+1)*PI/stacks)*cos(phi*2.0*PI/slices), 
		     sin((theta+1)*PI/stacks)*sin(phi*2.0*PI/slices), 
		     cos((theta+1)*PI/stacks)};
	glNormal3fv(n1);
	glVertex3fv(n1);
      }
    glEnd();
  }
}

#endif
