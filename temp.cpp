#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


//_____________________________________________________________________________________

                        /*
                          ______           _______
                         /      \         /       \
                        /$$$$$$  |        $$$$$$$  |
                        $$ ___$$ | ______ $$ |  $$ |
                          /   $$< /      |$$ |  $$ |
                         _$$$$$  |$$$$$$/ $$ |  $$ |
                        /  \__$$ |        $$ |__$$ |
                        $$    $$/         $$    $$/
                         $$$$$$/          $$$$$$$/
                                                   */



    void translation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float X_tran, float y_tran, float z_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2]/1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
       // glEnd();


       float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{X_tran, y_tran, z_tran, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };
       
       

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }

       

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }
  

    //_____________________________________________________________________________________

    void scaling_3d(float p1[3], float p2[3], float p3[3], float p4[3], float X_scal, float y_scal, float z_scal)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {X_scal,0,0, 0},{0,y_scal,0, 0},{0,0,z_scal, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void X_sheer_3d(float p1[3], float p2[3], float p3[3], float p4[3], float y_sheer, float z_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,y_sheer,z_sheer, 0},{0,1,0, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void Y_sheer_3d(float p1[3], float p2[3], float p3[3], float p4[3], float x_sheer, float z_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{x_sheer,1,z_sheer, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }


    //_____________________________________________________________________________________

    void Z_sheer_3d(float p1[3], float p2[3], float p3[3], float p4[3], float x_sheer, float y_sheer)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,1,0, 0},{x_sheer,y_sheer,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }


    //_____________________________________________________________________________________

    void Z_rotation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),sin(radian),0, 0},{-sin(radian),cos(radian),0, 0},{0,0,1, 0},{0,0,0, 1}};

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void Y_rotation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),0,-sin(theta), 0},{0,1,0, 0},{sin(theta),0,cos(theta), 0},{0,0,0, 1}};

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void X_rotation_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,cos(radian),sin(theta), 0},{0,-sin(theta),cos(theta), 0},{0,0,0, 1}};

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }
    //_---------------------------------------------------------------------------------------------------

    void Z_rotation_parallel_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta, float x_tran, float y_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);



        float matrix1[4][4] = { 0 };

        float scaling1[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{-x_tran, -y_tran, 0, 1} };

        float temp1[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };
        


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix1[i][j] += temp1[i][k] * scaling1[k][j];
                }
            }
        }
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix2[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),sin(radian),0, 0},{-sin(radian),cos(radian),0, 0},{0,0,1, 0},{0,0,0, 1} };

       // float temp2[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix2[i][j] += matrix1[i][k] * scaling[k][j];
                }
            }
        }

        //__translation inverse

    

        float matrix[4][4] = { 0 };

        float scaling3[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{x_tran, y_tran, 0, 1} };

       // float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += matrix2[i][k] * scaling3[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    //_---------------------------------------------------------------------------------------------------

    void X_rotation_parallel_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta, float y_tran, float z_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);



        float matrix1[4][4] = { 0 };

        float scaling1[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{0, -y_tran, -z_tran, 1} };

        float temp1[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix1[i][j] += temp1[i][k] * scaling1[k][j];
                }
            }
        }
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix2[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,cos(radian),sin(theta), 0},{0,-sin(theta),cos(theta), 0},{0,0,0, 1} };

        // float temp2[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix2[i][j] += matrix1[i][k] * scaling[k][j];
                }
            }
        }

        //__translation inverse



        float matrix[4][4] = { 0 };

        float scaling3[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{0, y_tran, z_tran, 1} };

        // float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += matrix2[i][k] * scaling3[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }
    //_---------------------------------------------------------------------------------------------------

    void Y_rotation_parallel_3d(float p1[3], float p2[3], float p3[3], float p4[3], float theta, float x_tran, float z_tran)
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);



        float matrix1[4][4] = { 0 };

        float scaling1[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{-x_tran, 0,-z_tran, 1} };

        float temp1[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix1[i][j] += temp1[i][k] * scaling1[k][j];
                }
            }
        }
        // glEnd();

        float radian = theta * 3.14159 / 180;

        float matrix2[4][4] = { 0 };

        float scaling[4][4] = { {cos(radian),0,-sin(theta), 0},{0,1,0, 0},{sin(theta),0,cos(theta), 0},{0,0,0, 1} };

        // float temp2[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix2[i][j] += matrix1[i][k] * scaling[k][j];
                }
            }
        }

        //__translation inverse



        float matrix[4][4] = { 0 };

        float scaling3[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{x_tran, 0, z_tran, 1} };

        // float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += matrix2[i][k] * scaling3[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void XY_Reflection(float p1[3], float p2[3], float p3[3], float p4[3])
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,1,0, 0},{0,0,-1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void XZ_Reflection(float p1[3], float p2[3], float p3[3], float p4[3])
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {1,0,0, 0},{0,-1,0, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }



        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

    //_____________________________________________________________________________________

    void YZ_Reflection(float p1[3], float p2[3], float p3[3], float p4[3])
    {
        //cli input for rectangle sides and transform
        //switch canse for all
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);

        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);
        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);

        glVertex3f(p1[0] / 1000, p1[1] / 1000, p1[2] / 1000);
        glVertex3f(p3[0] / 1000, p3[1] / 1000, p3[2] / 1000);

        glVertex3f(p4[0] / 1000, p4[1] / 1000, p4[2] / 1000);
        glVertex3f(p2[0] / 1000, p2[1] / 1000, p2[2] / 1000);
        // glEnd();


        float matrix[4][4] = { 0 };

        float scaling[4][4] = { {-1,0,0, 0},{0,1,0, 0},{0,0,1, 0},{0,0,0, 1} };

        float temp[4][4] = { {p1[0],p1[1],p1[2], 1},{p2[0],p2[1],p2[2], 1},{p3[0],p3[1],p3[2], 1},{p4[0],p4[1],p4[2], 1} };



        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    matrix[i][j] += temp[i][k] * scaling[k][j];
                }
            }
        }
   


        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);

        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);
        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);

        glVertex3f(matrix[0][0] / 1000, matrix[0][1] / 1000, matrix[0][2] / 1000);
        glVertex3f(matrix[2][0] / 1000, matrix[2][1] / 1000, matrix[2][2] / 1000);

        glVertex3f(matrix[3][0] / 1000, matrix[3][1] / 1000, matrix[3][2] / 1000);
        glVertex3f(matrix[1][0] / 1000, matrix[1][1] / 1000, matrix[1][2] / 1000);
        glEnd();

    }

  


int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "C-57 Arya Pathak", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

  


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
    float x1, y1, z1, x2, y2, z2, x3,y3, z3,x4,y4, z4;
    int value;
    std::cout << "Enter the x1, y1, z1, x2, y2, z2, x3,y3, z3,x4,y4, z4 of the quadrilateral\n";
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        glVertex2f(1000,0);
        glVertex2f(-1000, 0);
        glVertex2f(0, 1000);
        glVertex2f(0, - 1000);
       
       float t1[3] = { x1,y1,z1 };
        float t2[3] = { x2,y2,z2 };
        float t3[3] = { x3,y3,z3 };
        float t4[3] = { x4,y4,z4 };


        std::cout << "1> Translation 2> Scaling 3> X-Sheer 4> Y-Sheer 5> Z-Sheer 6> X axis Rotation 7> Y axis Rotation 8> Z axis Rotation 9> Parralel to X axis Rotation 10> Parralel to Y axis Rotation 11> Parralel to Z axis Rotation 12> XY-Plane Rotation 13> YZ-Plane Rotation 14> XZ-PLane Rotation\n";
       
        std::cin >> value;
        switch (value) {
        case 1:
            float xa, ya, za;
            std::cout << "Enter x y z translation value \n";
            std::cin >> xa >> ya >> za;
           
            translation_3d(t1, t2, t3, t4, xa, ya , za);

            break;
        case 2:
            float x, y, z;
            std::cout << "Enter x y z scaling factor\n";
            std::cin >> x >> y >> z;
           
            scaling_3d(t1, t2, t3, t4, x, y, z);
            break;
        case 3:
            float xz, yz;
            std::cout << "Enter y z sheer factor\n";
            std::cin >> xz >> yz ;
           
            X_sheer_3d(t1, t2, t3, t4, xz, yz);
            break;
        case 4:
            float xs, ys;
            std::cout << "Enter x z sheer factor\n";
            std::cin >> xs >> ys;
            Y_sheer_3d(t1, t2, t3, t4, xs, ys);
            break;
        case 5:
            float xd, yd;
            std::cout << "Enter x y sheer factor\n";
            std::cin >> xd >> yd;
            Z_sheer_3d(t1, t2, t3, t4, xd, yd);
            break;
        case 6:
            float theta;
            std::cout << "Enter theta\n";
            std::cin >> theta;
            X_rotation_3d(t1, t2, t3, t4, theta);
            break;
        case 7:
            float thetaq;
            std::cout << "Enter theta\n";
            std::cin >> thetaq;
            Y_rotation_3d(t1, t2, t3, t4, thetaq);
            break;
        case 8:
           float thetaaa;
            std::cout << "Enter theta\n";
            std::cin >> thetaaa;
            Z_rotation_3d(t1, t2, t3, t4, thetaaa);
            break;
        case 9:
            float thetae, x_trne, y_trane ;
            std::cout << "Enter theta y z offset from X-axis\n";
            std::cin >> thetae >> x_trne >> y_trane;
            X_rotation_parallel_3d(t1, t2, t3, t4, thetae, x_trne, y_trane);
            break;
        case 10:
            float thetar, x_trnr, y_tranr;
            std::cout << "Enter theta x z offset from Y-axis\n";
            std::cin >> thetar >> x_trnr >> y_tranr;
            Y_rotation_parallel_3d(t1, t2, t3, t4, thetar, x_trnr, y_tranr);
            break;
        case 11:
            float thetau, x_trnu, y_tranu;
            std::cout << "Enter theta x y offset from Z-axis\n";
            std::cin >> thetau >> x_trnu >> y_tranu;
            Z_rotation_parallel_3d(t1, t2, t3, t4, thetau, x_trnu, y_tranu);
            break;
        case 12:
            XY_Reflection(t1, t2, t3, t4);
            break;
        case 13:
            XZ_Reflection(t1, t2, t3, t4);
            break;
        case 14:
            YZ_Reflection(t1, t2, t3, t4);
            break;
        default:
            std::cout << "Invalid input. Please enter a number between 1 and 14." << std::endl;
        }

        

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;

}
