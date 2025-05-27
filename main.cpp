// cube3d.cpp
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "Plane3D.h"
#include "RubikCube.h"
#include "Line3D.h"
#include "Button.h"
#include "TypeCamera.h"
#include "CommonMethod.h"

float rotationAngle = 0.0f;

RubikCube rubikCube;
Line3D lineX(TypeSpace3D::AXIS_OX);
Line3D lineY(TypeSpace3D::AXIS_OY);
Line3D lineZ(TypeSpace3D::AXIS_OZ);
Point3D rayOrigin, rayDir;
int selectedOption = -1;                            // Biến lưu lựa chọn của người dùng
int typeCamera = TypeCamera::CAMERA_1;              // Biến lưu loại camera hiện tại
Point3D cameraPosition = { 5.0f, 5.0f, 0.0f };       // Vị trí camera



//Button
std::vector<Button> buttons = {
    Button({ {2,2,3} , {1 ,2 ,3} , {1 , 1, 3} ,{ 2, 1, 3} }, TypeRotate::TYPE_R ,TypeColor::COLOR_RED ),
   
};

// Cấu hình OpenGL
void initGL() {
    glEnable(GL_DEPTH_TEST); // 3D
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

// Hàm vẽ màn hình // 3D
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluPerspective(60.0, 1.0 * glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT), 1.0, 100.0);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //glTranslatef(0.0f, 0.0f, 0.0f);
   
    gluLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z,  // Camera đặt ở Z = 5
        0.0, 0.0, 0.0,                                               // Nhìn vào gốc tọa độ
        0.0, 1.0, 0.0);                                              // Hướng lên là trục Y


    if (rubikCube.isRotating() == true) {
        rubikCube.rotate_Animation();
    }

    rubikCube.draw();
	lineX.draw();
	lineY.draw();
	lineZ.draw();   

	for (int i = 0; i < buttons.size(); i++) {
		buttons[i].draw();
	}


    glutSwapBuffers();
}
// 
void reshape(int w, int h) {
    if (h == 0) h = 1; 
    float aspect = (float)w / (float)h;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 1.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void menuCallback(int value) {
    selectedOption = value; // cập nhật lựa chọn

    if(selectedOption <= 12) 
	{
		rubikCube.rotate(selectedOption);
	}
    if (selectedOption > 100 && selectedOption < 200) {
		typeCamera = selectedOption;
        switch (typeCamera) {
            case TypeCamera::CAMERA_1:
				cameraPosition = { 5.0f, 5.0f, 0.0f };
                break;
            case TypeCamera::CAMERA_2:
                cameraPosition = { -5.0f, 5.0f, 0.0f };
                break;
            case TypeCamera::CAMERA_3:
                cameraPosition = { 0.0f, 5.0f, -5.0f };
                break;
            case TypeCamera::CAMERA_4:
                cameraPosition = { 0.0f, 5.0f, 5.0f };
                break;
            }
    }
    if(selectedOption == 1001)     rubikCube.randomRotate();
	if (selectedOption == 2001)     rubikCube.solveCube();
    glutPostRedisplay();    // yêu cầu vẽ lại
}

void addEventMenu() {
    glutAddMenuEntry("Camera_1", TypeCamera::CAMERA_1);
    glutAddMenuEntry("Camera_2", TypeCamera::CAMERA_2);
    glutAddMenuEntry("Camera_3", TypeCamera::CAMERA_3);
    glutAddMenuEntry("Camera_4", TypeCamera::CAMERA_4);

    glutAddMenuEntry("RandomRotate", 1001);
    glutAddMenuEntry("SolveCube", 2001);
        
    glutAddMenuEntry("Rotate_R", TypeRotate::TYPE_R);
    glutAddMenuEntry("Rotate_R_", TypeRotate::TYPE_R_);
    glutAddMenuEntry("Rotate_L", TypeRotate::TYPE_L);
    glutAddMenuEntry("Rotate_L_", TypeRotate::TYPE_L_);
    glutAddMenuEntry("Rotate_F", TypeRotate::TYPE_F);
    glutAddMenuEntry("Rotate_F_", TypeRotate::TYPE_F_);
    glutAddMenuEntry("Rotate_B", TypeRotate::TYPE_B);
    glutAddMenuEntry("Rotate_B_", TypeRotate::TYPE_B_);
    glutAddMenuEntry("Rotate_U", TypeRotate::TYPE_U);
    glutAddMenuEntry("Rotate_U_", TypeRotate::TYPE_U_);
    glutAddMenuEntry("Rotate_D", TypeRotate::TYPE_D);
    glutAddMenuEntry("Rotate_D_", TypeRotate::TYPE_D_);

    glutAttachMenu(GLUT_RIGHT_BUTTON);                      // Bấm chuột phải để hiện menu

}


void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        GLint viewport[4];
        GLdouble modelview[16], projection[16];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);

        float winX = (float)x;
        float winY = (float)viewport[3] - (float)y;

        GLdouble wx1, wy1, wz1;
        GLdouble wx2, wy2, wz2;

        gluUnProject(winX, winY, 0.0, modelview, projection, viewport, &wx1, &wy1, &wz1);
        gluUnProject(winX, winY, 1.0, modelview, projection, viewport, &wx2, &wy2, &wz2);

        rayOrigin = { (float)wx1, (float)wy1, (float)wz1 };
        Point3D target = { (float)wx2, (float)wy2, (float)wz2 };
        rayDir = { target.x - rayOrigin.x, target.y - rayOrigin.y, target.z - rayOrigin.z };

        for (Button& button : buttons) {
            if (button.hit(rayOrigin, rayDir)) {
                //std::cout << "[INFO] Clicked plane ID: " << button.typeRotate  << "\n";
				rubikCube.rotate(button.typeRotate);
            }
        }
    }
}

void specialInput(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_UP:
			cameraPosition.y += 0.2f;
			if (cameraPosition.y > CAMRERA_LIMIT_Y) cameraPosition.y = CAMRERA_LIMIT_Y;
            break;
        case GLUT_KEY_DOWN:
            cameraPosition.y -= 0.2f;
            if (cameraPosition.y < -CAMRERA_LIMIT_Y) cameraPosition.y = -CAMRERA_LIMIT_Y;
            break;


    ///                     ^ Z  +
    ///                     |
    ///                     |
    ///                     |
    ///                     |
    ///                     |    
    ///           1         |           2
    ///                     |
    ///                     |
    ///   -  -----------------------------------> X +
    ///                     |
    ///                     |
    ///                     |
    ///          3          |           4
    ///                     |
    ///                     |
    ///                     |
    ///                     -
    ///

            /// ngược một chút 
        case GLUT_KEY_RIGHT:
            if (cameraPosition.x < -RADIUS_CAMERA) {
                std::cout << " 123";
                cameraPosition.x += 0.2f;
                /*float rad = RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x;
               */
                
                cameraPosition.z = CommonMethod::Fsqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
            }
            else {
                if (cameraPosition.x > 0) {
                    if (cameraPosition.z > 0) { // 2
                        cameraPosition.x += 0.2f;
                        cameraPosition.z = sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);

                    }
                    else { // 4
                        cameraPosition.x -= 0.2f;
                        cameraPosition.z =(-1) * sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);

                    }
                }
                else {
                    if (cameraPosition.z > 0) { // 1 
                        cameraPosition.x += 0.2f;
                        cameraPosition.z = sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
                    }
                    else { // 3
                        cameraPosition.x -= 0.2f;
                        if (RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x >= 0) {
                            cameraPosition.z = (-1) * sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
                        }
                        else {
                            cameraPosition.z = 0;
                        }
                    }
                }
            }
            break;
        case GLUT_KEY_LEFT:  // 
            if (cameraPosition.x == RADIUS_CAMERA) {
                cameraPosition.x -= 0.2f;
                cameraPosition.z = sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
            }
            else {
                    if (cameraPosition.x > 0) {
                        if (cameraPosition.z < 0) { // 4
                            cameraPosition.x += 0.2f;
                            cameraPosition.z = (-1) * sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
                        }
                        else { // 2
                            cameraPosition.x -= 0.2f;
                            cameraPosition.z =  sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
                        }
                    }
                    else {
                        if (cameraPosition.z > 0) { // 1
                            cameraPosition.x -= 0.2f;
                            if (RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x >= 0) {
                                cameraPosition.z = sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
                            }
                            else {
                                cameraPosition.z = 0.f;
                            }
                        }
                        else {
                            cameraPosition.x += 0.2f;
                            cameraPosition.z = (-1) * sqrt(RADIUS_CAMERA * RADIUS_CAMERA - cameraPosition.x * cameraPosition.x);
                        }
                    }
            }
            break;
    }
	std::cout << "Camera Position: " << cameraPosition.x << " " << cameraPosition.y << " " << cameraPosition.z << std::endl;
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

void idle() {
    rotationAngle += 0.04f;
    if (rotationAngle > 360.0f) {
        rotationAngle -= 360.0f;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
	srand(time(0)); 

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rubik Cube with OpenGL & GLUT");

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 

    initGL();
    glRotatef(rotationAngle, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // event menu
    int menu = glutCreateMenu(menuCallback);
    addEventMenu();
    glutMouseFunc(mouse);
    glutSpecialFunc(specialInput);
    glutTimerFunc(0, timer, 0);

    glutIdleFunc(idle);

    glutMainLoop();

    rubikCube.randomRotate();

    return 0;
}

