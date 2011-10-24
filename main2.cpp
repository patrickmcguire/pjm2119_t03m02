#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "light.h"
#include "menu.h"
#include "shape.h"

#define PI 3.1415926535898

int width = 600;
int height = 600;

bool mouse_down = false;
int mouse_x;
int mouse_y;

float camera_theta = PI/2.0;
float camera_phi = 0.0;
float camera_r = 30.0;

void draw()
{
  {
    GLfloat color[] = {0.5, 0.5, 0.5};
    cg_Lambertian(color);
    floor();
  }
  
  // Torus:
  glPushMatrix();
  {
    GLfloat color[] = {0.0, 0.0, 1.0};
    glTranslatef(-4, 1, 0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    cg_Lambertian(color);
    glutSolidTorus(1, 3, 10, 20);
  }
  glPopMatrix();

  // Box:
  glPushMatrix();
  {
    GLfloat color[] = {0.0, 1.0, 0.0};
    glTranslatef(1.0, 3.0, 4.0);
    cg_Lambertian(color);
    glutSolidCube(6.0);
  }
    // Teapot:
    glPushMatrix();
    {
      GLfloat color[] = {0.5, 0.5, 0.5};
      glTranslatef(0.0, 5.3, 0.0);
      cg_emission(color);
      glutSolidTeapot(3.0);
    }
    glPopMatrix();
  glPopMatrix();
  
  // Sphere:  
  glPushMatrix();
  {
    glTranslatef(1.0, 3.0, -3.0);
    glScalef(4.0, 3.0, 4.0);
    GLfloat color[] = {1.0, 0.0, 0.0};
    cg_specular(color);
    cg_SolidSphere(40, 20);
    //glutSolidSphere(3.0, 40, 20);
  }
  glPopMatrix();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // orthographic top
  if (width > height)
    glViewport((width-height)/4, height/2, height/2, height/2);
  else // h > w
    glViewport(0, height/2+(height-width)/4, width/2, width/2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20.0, 20.0, -20.0, 20.0, 0.0, 50.0); 
  
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
    gluLookAt(0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    cg_init_light();
    draw();
  glPopMatrix();

  // orthographic front
  if (width > height)
    glViewport((width-height)/4, 0, height/2, height/2);
  else // h > w
    glViewport(0, (height-width)/4, width/2, width/2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20.0, 20.0, -20.0, 20.0, 0.0, 50.0); 
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
    gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    cg_init_light();
    draw();
  glPopMatrix();

  // orthographic side
  if (width > height)
    glViewport(width/2+(width-height)/4, 0, height/2, height/2);
  else // h > w
    glViewport(width/2, (height-width)/4, width/2, width/2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20.0, 20.0, -20.0, 20.0, 0.0, 50.0); 
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    cg_init_light();
    draw();
  glPopMatrix();

  // perspective camera
  if (width > height)
    glViewport(width/2+(width-height)/4, height/2, height/2, height/2);
  else // height > width
    glViewport(width/2, height/2+(height-width)/4, width/2, width/2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
    gluLookAt(camera_r*sin(camera_theta)*cos(camera_phi), camera_r*cos(camera_theta), camera_r*sin(camera_theta)*sin(camera_phi),
	      0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    cg_init_light();
    draw();
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}


void reshape(int w, int h)
{
  width = w;
  height = h;
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 27: // ESC
      exit(0);
      break;
    case 32: // SPACE
      break;
    case 'w': // w
      if (camera_theta-PI/18.0 > 0) camera_theta -= PI/18.0;
      //reshape(width, height);
      glutPostRedisplay();
      break;
    case 's': // s
      if (camera_theta+PI/18.0 < PI) camera_theta += PI/18.0;
      glutPostRedisplay();
      //reshape(width, height);
      break;
    case 97: // a
      camera_phi += PI/18.0;
      glutPostRedisplay();
      //reshape(width, height);
      break;
    case 100: // d
      camera_phi -= PI/18.0;
      glutPostRedisplay();
      //reshape(width, height);
      break;
  } 
}

void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    mouse_down = true;
    mouse_x = x;
    mouse_y = y;
  }
  else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
  {
    mouse_down = false;
  }
}

void mouse_motion(int x, int y)
{
  if (mouse_down)
  {
    if (x > mouse_x)
    {
      camera_phi += PI/60.0;
      glutPostRedisplay();
      mouse_x = x;
    }
    else if (x < mouse_x)
    {
      camera_phi -= PI/60.0;
      glutPostRedisplay();
      mouse_x = x;
    }
    if (y < mouse_y)
    {
      if (camera_theta+PI/90.0 < PI) camera_theta += PI/90.0;
      glutPostRedisplay();
      mouse_y = y;
    }
    else if (y > mouse_y)
    {
      if (camera_theta-PI/90.0 > 0) camera_theta -= PI/90.0;
      glutPostRedisplay();
      mouse_y = y;
    }
  }
}

void init()
{
  //glEnable(GL_SCISSOR_TEST);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  glEnable(GL_RESCALE_NORMAL);
  //GLfloat lmodel_ambient[] = {0.2, 0.2, 0.2, 1.0};
  //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glShadeModel(GL_SMOOTH);

  
  cg_CreateMenu();
}

int main(int argc, char** argv)
{
  printf("Please use mouse to move the angle of the camera on the perspective viewport\n");

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutMainLoop();
  return 0;
}
