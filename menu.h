#ifndef MENU_H_
#define MENU_H_

#include <GL/glut.h>

#include "light.h"

enum {MENU_LIGHT0, MENU_LIGHT1, MENU_NOLIGHT};
enum {MENU_FLAT, MENU_SMOOTH};
enum {MENU_2, MENU_8, MENU_16, MENU_64};

void lightingmenu(int value)
{
  switch (value)
  {
    case MENU_LIGHT0:
      if (glIsEnabled(GL_LIGHT0)) glDisable(GL_LIGHT0);
      else glEnable(GL_LIGHT0);
      break;
    case MENU_LIGHT1:
      if (glIsEnabled(GL_LIGHT1)) glDisable(GL_LIGHT1);
      else glEnable(GL_LIGHT1);
      break;
    case MENU_NOLIGHT:
      glDisable(GL_LIGHT0);
      glDisable(GL_LIGHT1);
  }
  glutPostRedisplay();
}

void shadingmenu(int value)
{
  switch (value)
  {
    case MENU_SMOOTH:
      glShadeModel(GL_SMOOTH);
      break;
    case MENU_FLAT:
      glShadeModel(GL_FLAT);
      break;
  }
  glutPostRedisplay();
}

void phongmenu(int value)
{
  switch (value)
  {
    case MENU_2:
      material_shininess[0] = 2.0;
      break;
    case MENU_8:
      material_shininess[0] = 8.0;
      break;
    case MENU_16:
      material_shininess[0] = 16.0;
      break;
    case MENU_64:
      material_shininess[0] = 64.0;
      break;
  }
  glutPostRedisplay();
}

void menu(int value)
{
}

void cg_CreateMenu()
{
  int submenu_lighting = glutCreateMenu(lightingmenu);
  glutAddMenuEntry("Light 1", MENU_LIGHT0);
  glutAddMenuEntry("Light 2", MENU_LIGHT1);
  glutAddMenuEntry("No light", MENU_NOLIGHT);
  int submenu_shading = glutCreateMenu(shadingmenu);
  glutAddMenuEntry("Flat shading", MENU_FLAT);
  glutAddMenuEntry("Gouaud shading", MENU_SMOOTH);
  int submenu_phong = glutCreateMenu(phongmenu);
  glutAddMenuEntry("2", MENU_2);
  glutAddMenuEntry("8", MENU_8);
  glutAddMenuEntry("16", MENU_16);
  glutAddMenuEntry("64", MENU_64);
  glutCreateMenu(menu);
  glutAddSubMenu("Lighting", submenu_lighting);
  glutAddSubMenu("Shading", submenu_shading);
  glutAddSubMenu("Phong exponent", submenu_phong);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}


#endif /* MENU_H_ */
