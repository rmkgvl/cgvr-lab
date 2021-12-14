#include<gl/glut.h>
#include <math.h>
//#include<stdlib.h>
#include<stdio.h>


//RIGHT CLICK TO SHOW REFLECTED HOUSE


void draw_house()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(100, 200);
	glVertex2f(200, 250);
	glVertex2f(300, 200);
	glVertex2f(100, 200);
	glVertex2f(100, 100);
	glVertex2f(150, 100);
	glVertex2f(150, 150);
	glVertex2f(250, 150);
	glVertex2f(250, 100);
	glVertex2f(300, 100);
	glVertex2f(300, 200);
	glEnd();
}
int angle;
float m, c, theta;
void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//NORMAL HOUSE
	glColor3f(1, 0, 0);
	draw_house();
	glFlush();
	//ROTATED HOUSE
	glPushMatrix();
	glTranslatef(100, 100, 0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-100, -100, 0);
	glColor3f(1, 1, 0);
	draw_house();
	glPopMatrix();
	glFlush();
}
void display2()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//normal house
	glColor3f(1, 0, 0);
	draw_house();
	glFlush();
	// line
	float x1 = 0, x2 = 500;
	float y1 = m * x1 + c;
	float y2 = m * x2 + c;
	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	glFlush();

	//Reflected
	glPushMatrix();
	glTranslatef(0, c, 0);
	theta = atan(m);
	theta = theta * 180 / 3.14;
	glRotatef(theta, 0, 0, 1);
	glScalef(1, -1, 1);
	glRotatef(-theta, 0, 0, 1);
	glTranslatef(0, -c, 0);
	glBegin(GL_LINE_LOOP);
	draw_house();
	glPopMatrix();
	glFlush();
}
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(2.0);
	gluOrtho2D(-450, 450, -450, 450);
}
void mouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		display();
	}
	else if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		display2();
	}
}
void main(int argc, char** argv)
{
	printf("Enter the rotation angle\n");
	scanf_s("%d", &angle);
	printf("Enter c and m value for line y=mx+c\n");
	scanf_s("%f %f", &c, &m);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("House Rotation");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
}