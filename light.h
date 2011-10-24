#ifndef LIGHT_H_
#define LIGHT_H_

#include <GL/glut.h>
#include <math.h>

// lighting parameters
GLfloat light_ambient0[] = {0.05, 0.05, 0.05, 1.0};
GLfloat light_diffuse0[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_specular0[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position0[] = { 0.0, 10000.0, 0.0, 0.0 };

GLfloat light_ambient1[] = {0.1, 0.0, 0.0, 1.0};
GLfloat light_diffuse1[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_specular1[] = {1.0, 0.0, 1.0, 1.0};
GLfloat light_position1[] = { 0.0, 10000.0, 0.0, 0.0 };

GLfloat material_shininess[] = {64.0};
GLfloat no_material[] = {0.0, 0.0, 0.0, 1.0};
GLfloat material_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat material_emission[] = {1.0, 1.0, 1.0, 1.0};
GLfloat no_shininess = 0.0;

// materials
void cg_Lambertian(GLfloat* color)
{
  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glColor3fv(color);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_material);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_material);
  glMaterialf(GL_FRONT, GL_SHININESS, no_shininess);
}

void cg_emission(GLfloat *color)
{
  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glColor3fv(color);
  glMaterialfv(GL_FRONT, GL_SPECULAR, no_material);
  glMaterialfv(GL_FRONT, GL_EMISSION, color);
  glMaterialf(GL_FRONT, GL_SHININESS, no_shininess);
}

void cg_specular(GLfloat *color)
{
  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glColor3fv(color);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
  glMaterialfv(GL_FRONT, GL_EMISSION, no_material);
  glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
}

void cg_init_light()
{
  glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);

  glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
  glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
}

void cg_creative_light(float time)
{
  GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat light_position[] = {10*cos(time), 10.0, 10.0*sin(time), 1.0 };
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

#endif
