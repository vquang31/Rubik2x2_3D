// cube3d.cpp
#include <GL/glut.h>
#include <iostream>
#include "Polygon3D.h"
#include "RubikCube.h"
// Góc xoay cube
float rotationAngle = 0.0f;
Polygon3D cube;
RubikCube rubikCube;

// Hàm vẽ một khối lập phương
void drawCube() {

    glBegin(GL_QUADS);
    // Mặt trước (z = 1.0)
    glColor3f(1.0f, 0.0f, 0.0f); // Đỏ
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Mặt sau (z = -1.0)
    glColor3f(0.0f, 1.0f, 0.0f); // Xanh lá
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Mặt trái (x = -1.0)
    glColor3f(0.0f, 0.0f, 1.0f); // Xanh dương
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    // Mặt phải (x = 1.0)
    glColor3f(1.0f, 1.0f, 0.0f); // Vàng
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Mặt trên (y = 1.0)
    glColor3f(1.0f, 0.0f, 1.0f); // Hồng
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    // Mặt dưới (y = -1.0)
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
}

void drawTriangle1() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);   // Màu đỏ cho đỉnh gốc
    glVertex2f(50.0f, 150.0f);     // 🔺 Đỉnh gốc (center)

    glColor3f(0.0f, 1.0f, 0.0f);   // Xanh
    glVertex2f(100.0f, 100.0f);   // Điểm ngoại biên 1

    glVertex2f(200.0f, 100.0f);   // 2

    glVertex2f(250.0f, 150.0f);   // 3

    glVertex2f(200.0f, 200.0f);   // 4

    glVertex2f(100.0f, 200.0f);   // 5

    glEnd();
}


void drawTriangle2() { // 3D
    const int numSegments = 32;
    const float radius = 1.0f;
    const float centerX = 0.0f, centerY = 0.0f, centerZ = 0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);
    glVertex3f(centerX, centerY, centerZ); // Đỉnh gốc ở giữa

    for (int i = 0; i <= numSegments; ++i) {
        double M_PI = 2 * acos(0.0);
        float angle = i * 2.0f * M_PI / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glColor3f(0, 0, 1);
        glVertex3f(x, y, centerZ); // Tất cả đỉnh cùng mặt phẳng Z
    }
    glEnd();
}


// Hàm vẽ màn hình // 3D
void display1() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -7.0f);
    glRotatef(rotationAngle, 1.0f, 1.0f, 1.0f);

    gluLookAt(-1.0, 1.0, -1.0,    // Camera đặt ở Z = 5
        0.0, 0.0, 0.0,    // Nhìn vào gốc tọa độ
        0.0, 1.0, 0.0);   // Hướng lên là trục Y

    //drawTriangle2();
    rubikCube.draw();

    //drawCube();

    glutSwapBuffers();
}
// 2D
void display2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    //
    drawTriangle1();

    //
    glFlush();
}

//
void reshape(int w, int h) {
    if (h == 0) h = 1; // Tránh chia cho 0
    float aspect = (float)w / (float)h;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 1.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Hàm cập nhật
void idle() {
    rotationAngle += 0.04f;
    if (rotationAngle > 360.0f) {
        rotationAngle -= 360.0f;
    }
    glutPostRedisplay();
}

// Cấu hình OpenGL
void initGL() {
    glEnable(GL_DEPTH_TEST); // 3D
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    //gluOrtho2D(-600, 600, -600, 600); // 2D

}

// Hàm main
int main(int argc, char** argv) {
	srand(time(0)); 
    rubikCube.randomRotate();

    rubikCube.inCube();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cube with OpenGL & GLUT");

    initGL();

    glutDisplayFunc(display1);
    glutReshapeFunc(reshape); // 3D
    //glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}


