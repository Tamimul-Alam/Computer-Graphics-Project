#include<cstdio>
#include <windows.h>
#include<math.h>
#include <vector>
#include <cstdlib>
#define PI 3.14159265358979323846
#include <GL/gl.h>
#include <GL/glut.h>
#include<MMSystem.h>

void PointLight(const float x, const float y, const float z,  const float amb, const float diff, const float spec);    ///Checked///
void PointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec)
{
  glEnable(GL_LIGHTING);
  GLfloat light_ambient[] = { amb,amb,amb, 1.0 };
  GLfloat light_position[] = {-0.9,.9,0, 0.0 };
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0); //enable the light after setting the properties
}


GLfloat position2 = 0.0f;
GLfloat speed2 =-0.01f;
void sunn(int value)
{
   if(position2 > 1.0)
        position2 = 0.0f;

    position2 += speed2;

	glutPostRedisplay();

	glutTimerFunc(100, sunn, 0);
}


void sun()
{
    int i;

	GLfloat x=.0f; GLfloat y=16.0f; GLfloat radius =2.0f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void sky(){
	glBegin(GL_QUADS);
    glColor3ub(51, 204, 255);
	glVertex2f(-20.0f, 20.0f);
	glVertex2f(-20.0f, 6.0f);
	glVertex2f(20.0f, 6.0f);
	glVertex2f(20.0f, 20.0f);

	glEnd();
}
void river() {


	glBegin(GL_QUADS);
    glColor3ub(19,112,194);
	glVertex2f(-20.0f, -20.0f);
	glVertex2f(-20.0f, 6.0f);
	glVertex2f(20.0f, 6.0f);
	glVertex2f(20.0f, -20.0f);

	glEnd();


}

void ground(){      //Ground Created Date: 02/04/22

	glBegin(GL_TRIANGLES);
	glColor3ub(102, 255, 51);
	glVertex2f(0.0f,0.0f);
	glVertex2f(4.0f,-5.0f);
	glVertex2f(0.0f, -10.0f);

	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(102, 255, 51);
	glVertex2f(-20.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -20.0f);
	glVertex2f(-20.0f,-20.0f);

	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3ub(102, 255, 51);
	glVertex2f(0.0f,-20.0f);
	glVertex2f(4.0f,-15.0f);
	glVertex2f(0.0f, -10.0f);

	glEnd();
}

void hill(){                                //hills created

	glBegin(GL_TRIANGLES);
	glColor3ub(128, 128, 0);
	glVertex2f(-20.0f,4.0f);
	glVertex2f(-12.0f,10.0f);
	glVertex2f(-4.0f, 4.0f);

	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(128, 128, 0);
	glVertex2f(-10.1f,4.0f);
	glVertex2f(-3.0f,10.0f);
	glVertex2f(8.0f, 4.0f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(128, 128, 0);
	glVertex2f(-4.0f,4.0f);
	glVertex2f(2.0f,10.0f);
	glVertex2f(9.0f, 4.0f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(128, 128, 0);
	glVertex2f(20.0f,4.0f);
	glVertex2f(15.0f,10.0f);
	glVertex2f(9.0f, 4.0f);

	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(128, 128, 0);
	glVertex2f(18.0f,5.0f);
	glVertex2f(10.0f,8.0f);
	glVertex2f(5.0f, 3.0f);

	glEnd();
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(2);

    sky();
    hill();
    river();
    ground();
    glPushMatrix();
    sun();
    glPopMatrix();
    glFlush();
	glutSwapBuffers();
}

//Main function: GLUT runs as a console application starting at main()
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(900,900);
	glutInitWindowPosition(50,50);       // Initialize GLUT
	glutCreateWindow("");  // Create window with the given title
	glutDisplayFunc(display);
    gluOrtho2D(-20,20,-20,20);
	glutTimerFunc(100, sunn, 0);
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
