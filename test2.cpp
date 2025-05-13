//// 3d_plane_click_multi.cpp
//#include <GL/glut.h>
//#include <iostream>
//#include <cmath>
//#include <vector>
//
//struct Vec3 {
//    float x, y, z;
//    Vec3 operator-(const Vec3& other) const { return { x - other.x, y - other.y, z - other.z }; }
//    Vec3 cross(const Vec3& v) const {
//        return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
//    }
//    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
//};
//
//class Plane {
//public:
//    std::vector<Vec3> points;
//    int id;
//    bool selected = false;
//
//    Plane(const std::vector<Vec3>& pts, int id) : points(pts), id(id) {}
//
//    bool hit(const Vec3& origin, const Vec3& dir) const {
//        if (points.size() < 3) return false;
//
//        Vec3 p0 = points[0];
//        Vec3 edge1 = points[1] - points[0];
//        Vec3 edge2 = points[2] - points[0];
//        Vec3 normal = edge1.cross(edge2);
//
//        float denom = normal.dot(dir);
//        if (std::abs(denom) < 1e-6) return false;
//
//        float t = normal.dot(p0 - origin) / denom;
//        if (t < 0) return false;
//
//        Vec3 hitPoint = { origin.x + dir.x * t, origin.y + dir.y * t, origin.z + dir.z * t };
//
//        // Point-in-polygon test using winding number (for convex polygons)
//        int n = points.size();
//        for (int i = 0; i < n; ++i) {
//            Vec3 a = points[i];
//            Vec3 b = points[(i + 1) % n];
//            Vec3 edge = b - a;
//            Vec3 toPoint = hitPoint - a;
//            if (normal.dot(edge.cross(toPoint)) < 0) return false;
//        }
//        return true;
//    }
//
//    void draw() const {
//        glColor3f(selected ? 0.0f : 0.5f, selected ? 1.0f : 0.2f, 0.2f);
//        glBegin(GL_POLYGON);
//        for (const auto& p : points)
//            glVertex3f(p.x, p.y, p.z);
//        glEnd();
//    }
//};
//
//std::vector<Plane> planes = {
//    Plane({ {-2.0f, -1.0f, 0.0f}, {-1.0f, -1.0f, 0.0f}, {-1.0f,  1.0f, 0.0f}, {-2.0f, 1.0f, 0.0f} }, 1),
//    Plane({ {-0.5f, -1.0f, 0.0f}, { 0.5f, -1.0f, 0.0f}, { 0.5f,  1.0f, 0.0f}, {-0.5f, 1.0f, 0.0f} }, 2),
//    Plane({ { 1.0f, -1.0f, 0.0f}, { 2.0f, -1.0f, 0.0f}, { 2.0f,  1.0f, 0.0f}, { 1.0f, 1.0f, 0.0f} }, 3)
//};
//
//Vec3 rayOrigin, rayDir;
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, 1.0, 1.0, 100.0);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//
//    for (const auto& p : planes) p.draw();
//
//    glutSwapBuffers();
//}
//
//void mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        GLint viewport[4];
//        GLdouble modelview[16], projection[16];
//        glGetIntegerv(GL_VIEWPORT, viewport);
//        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
//        glGetDoublev(GL_PROJECTION_MATRIX, projection);
//
//        float winX = (float)x;
//        float winY = (float)viewport[3] - (float)y;
//
//        GLdouble wx1, wy1, wz1;
//        GLdouble wx2, wy2, wz2;
//
//        gluUnProject(winX, winY, 0.0, modelview, projection, viewport, &wx1, &wy1, &wz1);
//        gluUnProject(winX, winY, 1.0, modelview, projection, viewport, &wx2, &wy2, &wz2);
//
//        rayOrigin = { (float)wx1, (float)wy1, (float)wz1 };
//        Vec3 target = { (float)wx2, (float)wy2, (float)wz2 };
//        rayDir = { target.x - rayOrigin.x, target.y - rayOrigin.y, target.z - rayOrigin.z };
//
//        for (auto& plane : planes) {
//            plane.selected = plane.hit(rayOrigin, rayDir);
//            if (plane.selected)
//                std::cout << "[INFO] Clicked plane ID: " << plane.id << "\n";
//        }
//    }
//}
//
//void timer(int) {
//    glutPostRedisplay();
//    glutTimerFunc(16, timer, 0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(600, 600);
//    glutCreateWindow("Click Multiple 3D Polygon Planes");
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
