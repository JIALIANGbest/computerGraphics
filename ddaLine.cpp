#include<glut.h>
#include<math.h>
void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 50, 0.0, 50);
}
void DDALine(int x0,int y0,int x1,int y1)
{
	int dx, dy, epsl, k;
	float x, y, xIncre, yIncre;
	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	if (abs(dx) > abs(dy))epsl = abs(dx);
	else epsl = dy;
	xIncre=(float)dx / (float)epsl;
	yIncre = (float)dy / (float)epsl;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex3f(x0, y0, 0);//绘制起点
	for (int k = 0; k <= epsl; k++)
	{
		x += xIncre;
		y += yIncre;
		glVertex3f(x, y, 0);
	}
	glVertex3f(x1, y1, 0);//绘制终点
	glEnd();
	glFlush();//强制刷新缓冲，保证绘图命令将被执行
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 50, 50);//把视景体截取的图像按照怎样的高和宽显示到屏幕上
	glColor3f(1.0f, 0.0f, 0.0f);
	DDALine(0,0,8,6);
}
int main(int argc,char*argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("DDA画直线");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
    return 0;
}
