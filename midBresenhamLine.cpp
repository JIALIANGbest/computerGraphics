#include<glut.h>
#include<math.h>
using namespace std;
void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 50, 0.0, 50);
}
void mid_BresenhamLine(int x0,int y0,int x1,int y1)
{
	int dx, dy, d, UpIncre, DownIncre, x, y;
	if (x0 > x1)
	{
		x = x1; x1 = x0; x0 = x;
		y = y1; y1 = y0; y0 = y;
	}
	x = x0; y = y0;
	dx = x1 - x0; dy = y1 - y0;
	d = dx - 2 * dy;//摆脱小数
	UpIncre = 2 * dx - 2 * dy;
	DownIncre = -2 * dy;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex3f(x0, y0,0);
	while (x <= x1)
	{
		glVertex3f(x, y, 0);
		x++;
		if (d < 0) {
			y++;
			d += UpIncre;
		}
		else
		{
			d += DownIncre;
		}
	}
	glVertex3f(x1, y1, 0);
	glEnd();
	glFlush();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 50, 50);//把视景体截取的图像按照怎样的高和宽显示到屏幕上
	glColor3f(1.0f, 0.0f, 0.0f);
	mid_BresenhamLine(0, 0, 8, 6);
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("中点bresenham算法");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
