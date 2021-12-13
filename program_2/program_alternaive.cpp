#include<stdio.h>
#include<GL\glut.h>
#include<math.h>
int xc, yc, r;

void draw_pixel(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void draw_points(int x, int y)
{
	draw_pixel(xc + x, yc + y);
	draw_pixel(xc - x, yc + y);
	draw_pixel(xc + x, yc - y);
	draw_pixel(xc - x, yc - y);
	draw_pixel(xc + y, yc + x);
	draw_pixel(xc - y, yc + x);
	draw_pixel(xc + y, yc - x);
	draw_pixel(xc - y, yc - x);
}

void draw_circle()
{
	int x = 0, y = r;
	int d = 1 - r;
	draw_points(x, y);
	while (x < y)
	{
		if (d < 0)
		{
			d += 2 * x + 3;
		}
		else
		{
			y--;
			d += 2 * (x - y) + 5;
		}
		x++;
		draw_points(x, y);
	}
}

void myinit()
{
	glClearColor(1, 1, 1, 1);
	glColor3f(1, 0, 0);
	gluOrtho2D(0, 500, 0, 500);
	glPointSize(2.0);
}

void display()
{

}
int flag = 0;
void mymouse(int btn,int state,int x,int y)
{
	switch (btn)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			if (flag == 0)
			{
				xc = x;
				yc = 500 - y;
				printf("x1 y1: %d %d\n",xc,yc);
				flag = 1;
			}
			else
			{
				int X = x;
				int Y = 500 - y;
				printf("x2 y2 : %d %d\n", xc, yc);
				flag = 0;
				r = sqrt(pow(1.0 * yc - Y, 2) + pow(1.0 * xc - X, 2))*1.0;
				draw_circle();
				glFlush();
			}
		}
	default:
		break;
	}
}
int flag1 = 0;
void mykeyboard(unsigned char key, int x, int y)
{
	if (key == 'c' || key == 'C')
	{
		if (flag1 == 0)
		{
			xc = x;
			yc = 500 - y;
			printf("x1 y1: %d %d\n", xc, yc);
			flag1 = 1;
		}
		else
		{
			int X = x;
			int Y = 500 - y;
			printf("x2 y2 : %d %d\n", xc, yc);
			flag1 = 0;
			r = sqrt(pow(1.0 * yc - Y, 2) + pow(1.0 * xc - X, 2)) * 1.0;
			draw_circle();
			glFlush();
		}
	}
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("bresenham circle");
	glutDisplayFunc(display);
	glutMouseFunc(mymouse);
	glutKeyboardFunc(mykeyboard);
	myinit();
	glutMainLoop();
}