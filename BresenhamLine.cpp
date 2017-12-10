#include<glut.h>
#include<math.h>
using namespace std;
void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 50, 0.0, 50);
}
void BresenhamLine(int x0, int y0, int x1, int y1)
{
	int x, y, dx, dy, e;
	dx = x1 - x0;
	dy = y1 - y0;
	e = -dx;
	x = x0;
	y = y0;
	glBegin(GL_POINTS);
	while (x <= x1)
	{
		glVertex3f(x, y, 0);
		x++;
		e = e + 2 * dy;
		if (e > 0) {
			y++;
			e = e - 2 * dx;
		}
	}
	glEnd();
	glFlush();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 50, 50);//把视景体截取的图像按照怎样的高和宽显示到屏幕上
	glColor3f(1.0f, 0.0f, 0.0f);
	BresenhamLine(0, 0, 8, 6);
}
int main(int argc,char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("bresenham算法");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
