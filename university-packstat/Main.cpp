#include "Data.h"
#include "PcapAdapter.h"

#include <iostream>
#include <vector>
#include <glut.h>


std::vector<int> v, a;

Data d;
PcapAdapter pa;

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(30, 30);
	for (size_t i = 0; i < v.size(); ++i) {
		glVertex2i(30 + 5 * i, 30 + v[i]);
		glVertex2i(30 + 5 * (i + 1), 30 + v[i]);
	}
	glVertex2i(30 + 5 * v.size(), 30);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.7, 0.3);
	glVertex2i(30, 30);
	for (size_t i = 0; i < a.size(); ++i) {
		glVertex2i(30 + 5 * i, 30 + a[i]);
		glVertex2i(30 + 5 * (i + 1), 30 + a[i]);
	}
	glVertex2i(30 + 5 * a.size(), 30);
	glEnd();
	glutSwapBuffers();
}

DWORD WINAPI readPackages(LPVOID lpParam) {
	u_long ip;
	while ((ip = pa.getNextIP()) != NULL) {
		d.insert(ip);
		Sleep(10);
	}
	return 0;
}

void timf(int value) {
	v.clear();
	a.clear();
	d.countAverages(v, a);
	glutPostRedisplay();
	glutTimerFunc(10000, timf, 0);
	d.clear();
}

int main(int argc, char * argv[]) {
	pa.open();
	CreateThread(NULL, 0, readPackages, NULL, 0, NULL);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1100, 600);
	glutCreateWindow("PackStat - University Project");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutTimerFunc(10000, timf, 0);
	glutMainLoop();
	return 0;
}