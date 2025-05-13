//// button_ui_3d_demo.cpp
//#include <GL/glut.h>
//#include <iostream>
//#include "Line3D.h"
//
//
//Line3D lineX(TypeSpace3D::AXIS_OX);
//Line3D lineY(TypeSpace3D::AXIS_OY);
//Line3D lineZ(TypeSpace3D::AXIS_OZ);
//
//// Cấu trúc nút
//struct Button {
//    int x, y, width, height;
//    const char* label;
//
//    void draw() const {
//        glColor3f(0.2f, 0.6f, 1.0f);
//        glBegin(GL_QUADS);
//        glVertex2i(x, y);
//        glVertex2i(x + width, y);
//        glVertex2i(x + width, y + height);
//        glVertex2i(x, y + height);
//        glEnd();
//
//        glColor3f(1.0f, 1.0f, 1.0f);
//        glRasterPos2i(x + 10, y + 12);
//        for (const char* c = label; *c != '\0'; ++c)
//            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
//    }
//
//    bool isClicked(int mx, int my) const {
//        return mx >= x && mx <= x + width &&
//            my >= y && my <= y + height;
//    }
//};
//
//Button btn = { 10, 10, 120, 30, "Click Me" };
//float angle = 0.0f;
//bool rotateCube = false;
//
//void drawCube3D() {
//    glPushMatrix();
//    if (rotateCube) angle += 0.5f;
//    glTranslatef(0.0f, 0.0f, -5.0f);
//    glRotatef(angle, 1.0f, 1.0f, 0.0f);
//
//    glColor3f(1, 0, 0);
//    glutSolidCube(1.5);
//    glPopMatrix();
//}
//
//void enter2D(int width, int height) {
//    glMatrixMode(GL_PROJECTION);
//    glPushMatrix();
//    glLoadIdentity();
//    gluOrtho2D(0, width, 0, height);
//
//    glMatrixMode(GL_MODELVIEW);
//    glPushMatrix();
//    glLoadIdentity();
//
//    glDisable(GL_DEPTH_TEST);
//}
//
//void exit2D() {
//    glEnable(GL_DEPTH_TEST);
//    glMatrixMode(GL_MODELVIEW);
//    glPopMatrix();
//
//    glMatrixMode(GL_PROJECTION);
//    glPopMatrix();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, 1.0 * glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT), 1.0, 100.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    drawCube3D();
//
//
//    enter2D(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
//    btn.draw();
//    exit2D();
//
//    glutSwapBuffers();
//}
//
//void mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        int winHeight = glutGet(GLUT_WINDOW_HEIGHT);
//        y = winHeight - y; // Đảo Y từ top-left về bottom-left
//        if (btn.isClicked(x, y)) {
//            rotateCube = !rotateCube;
//            std::cout << "[INFO] Button clicked!\n";
//        }
//    }
//}
//
//void timer(int value) {
//    glutPostRedisplay();
//    glutTimerFunc(16, timer, 0); // ~60 FPS
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(600, 600);
//    glutCreateWindow("2D Button + 3D Cube");
//
//    glEnable(GL_DEPTH_TEST);
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//
//    glutDisplayFunc(display);
//    glutMouseFunc(mouse);
//    glutTimerFunc(0, timer, 0);
//
//    glutMainLoop();
//    return 0;
//}
