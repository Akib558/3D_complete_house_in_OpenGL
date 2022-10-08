#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
// #include <windows.h>
#include<math.h>

double Txval=0,Tyval=0,Tzval=0;
double windowHeight=700, windowWidth=700;
GLfloat beta = 0.0;
GLboolean wRotate = false, light1 = false;
double eyeX = 1.0, eyeY = 1.0, eyeZ = 5.0;
double centerX = 1.0, centerY = 1.0, centerZ = 0;
double upX = 0.0, upY = 1.0, upZ = 0.0;

static GLfloat v_pyramid[5][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.15},
    {2.15, 0.0, 2.15},
    {2.15, 0.0, 0.0},
    {1.0, 1.5, 1.0}
};

static GLubyte p_Indices[4][3] =
{
    {4, 1, 2},
    {4, 2, 3},
    {4, 3, 0},
    {4, 0, 1}
};

static GLubyte quadIndices[1][4] =
{
    {0, 3, 2, 1}
};


static GLfloat v_cube[8][3]=
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {0.0, 2.0, 0.0},
    {0.0, 2.0, 2.0},
    {2.0, 2.0, 2.0},
    {2.0, 2.0, 0.0}

};

static GLbyte q_Indices[6][4]=
{
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {1, 2, 6, 5},
    {2, 3, 7, 6},
    {0, 3, 7, 4},
    {0, 1, 5, 4}
};

static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void drawpyramid(GLfloat mat_diffuse[])
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {80};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i <4; i++)
    {
        getNormal3p(v_pyramid[p_Indices[i][0]][0], v_pyramid[p_Indices[i][0]][1], v_pyramid[p_Indices[i][0]][2],
                    v_pyramid[p_Indices[i][1]][0], v_pyramid[p_Indices[i][1]][1], v_pyramid[p_Indices[i][1]][2],
                    v_pyramid[p_Indices[i][2]][0], v_pyramid[p_Indices[i][2]][1], v_pyramid[p_Indices[i][2]][2]);

        glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
    }
    glEnd();

    glBegin(GL_QUADS);
    getNormal3p(v_pyramid[quadIndices[0][0]][0], v_pyramid[quadIndices[0][0]][1], v_pyramid[quadIndices[0][0]][2],
                    v_pyramid[quadIndices[0][1]][0], v_pyramid[quadIndices[0][1]][1], v_pyramid[quadIndices[0][1]][2],
                    v_pyramid[quadIndices[0][2]][0], v_pyramid[quadIndices[0][2]][1], v_pyramid[quadIndices[0][2]][2]);

    glVertex3fv(&v_pyramid[quadIndices[0][0]][0]);
    glVertex3fv(&v_pyramid[quadIndices[0][1]][0]);
    glVertex3fv(&v_pyramid[quadIndices[0][2]][0]);
    glVertex3fv(&v_pyramid[quadIndices[0][3]][0]);
    glEnd();

}

void drawcube(GLfloat mat_diffuse[])
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glBegin(GL_QUADS);
    for (int i=0; i < 6; i++){
        getNormal3p(v_cube[q_Indices[i][0]][0], v_cube[q_Indices[i][0]][1], v_cube[q_Indices[i][0]][2],
                    v_cube[q_Indices[i][1]][0], v_cube[q_Indices[i][1]][1], v_cube[q_Indices[i][1]][2],
                    v_cube[q_Indices[i][2]][0], v_cube[q_Indices[i][2]][1], v_cube[q_Indices[i][2]][2]);

        glVertex3fv(&v_cube[q_Indices[i][0]][0]);
        glVertex3fv(&v_cube[q_Indices[i][1]][0]);
        glVertex3fv(&v_cube[q_Indices[i][2]][0]);
        glVertex3fv(&v_cube[q_Indices[i][3]][0]);
    }
    glEnd();

}

void drawscene()
{
    GLfloat mat_diffuse[][4] = {
        { 0.4, 0.4, 0.4, 1.0 },
        { 0.7, 0.7, 0.7, 1.0 },
        { 0.1, 0.2, 0.4, 1.0 },
        { 0.8, 0.1, 0.2, 1.0 },
        { 1.0, 0.64, 0.0, 1.0 },
        { 0.59, 0.44, 0.2, 1.0 },
        { 0.23, 0.37, 0.04, 1.0 },
        { 0.44, 0.33, 0.22, 1.0 },
        { 0.1, 0.1, 0.1, 1.0 }
    };

    glPushMatrix();     // Base
        glTranslatef(-2,0,-1);
        glScalef(3, 0.02, 2);
        drawcube(mat_diffuse[0]);
    glPopMatrix();

    glPushMatrix();     // Fence left
        for(double i = 0.0; i < 4; i+=0.3) {
            glPushMatrix();
                glTranslatef(-2,0,-1+i);
                glScalef(0.05, 0.35, 0.05);
                drawcube(mat_diffuse[7]);
            glPopMatrix();
        }
        glPushMatrix();
            glTranslatef(-2,0.1,-1);
            glScalef(0.05, 0.05, 2);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.3,-1);
            glScalef(0.05, 0.05, 2);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.5,-1);
            glScalef(0.05, 0.05, 2);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();     // Fence right
        glTranslatef(5.9, 0, 0);
        for(double i = 0.0; i < 4; i+=0.3) {
            glPushMatrix();
                glTranslatef(-2,0,-1+i);
                glScalef(0.05, 0.35, 0.05);
                drawcube(mat_diffuse[7]);
            glPopMatrix();
        }
        glPushMatrix();
            glTranslatef(-2,0.1,-1);
            glScalef(0.05, 0.05, 2);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.3,-1);
            glScalef(0.05, 0.05, 2);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.5,-1);
            glScalef(0.05, 0.05, 2);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();     // Fence front
        glTranslatef(0.05, 0, 1);
        glRotatef(90, 0.0, 1.0, 0.0);
        for(double i = 0.0; i < 5; i+=0.3) {
            glPushMatrix();
                glTranslatef(-2,0,-1+i);
                glScalef(0.05, 0.35, 0.05);
                drawcube(mat_diffuse[7]);
            glPopMatrix();
        }
        glPushMatrix();
            glTranslatef(-2,0.1,-1);
            glScalef(0.05, 0.05, 2.5);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.3,-1);
            glScalef(0.05, 0.05, 2.5);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.5,-1);
            glScalef(0.05, 0.05, 2.5);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();     // Fence back
        glTranslatef(-1, 0, -2.9);
        glRotatef(90, 0.0, 1.0, 0.0);
        for(double i = 0.0; i < 5.7; i+=0.3) {
            glPushMatrix();
                glTranslatef(-2,0,-1+i);
                glScalef(0.05, 0.35, 0.05);
                drawcube(mat_diffuse[7]);
            glPopMatrix();
        }
        glPushMatrix();
            glTranslatef(-2,0.1,-1);
            glScalef(0.05, 0.05, 3);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.3,-1);
            glScalef(0.05, 0.05, 3);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-2,0.5,-1);
            glScalef(0.05, 0.05, 3);
            drawcube(mat_diffuse[7]);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();     //Tree
        glPushMatrix();     // Tree base
            glTranslatef(2.02,0,0.3);
            glScalef(0.2, 1, 0.1);
            drawcube(mat_diffuse[5]);
        glPopMatrix();
        glPushMatrix();     // Tree leaves
            glTranslatef(1.6,1.4,-0.2);
            glScalef(0.6, 0.5, 0.6);
            drawcube(mat_diffuse[6]);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();         // Windmill
        glTranslatef(0.5,0,2);
        glPushMatrix();     // Windmill base
            glTranslatef(2.08,0,0.3);
            glScalef(0.14, 1.16, 0.08);
            drawcube(mat_diffuse[7]);
        glPopMatrix();

        glPushMatrix();     // Windmill wings
            glTranslatef(2.2, 2.2, 0.45);
            glRotatef(beta, 0.0, 0.0, 1.0);
            glPushMatrix();
                glTranslatef(0, -0.35, 0);
                glScalef(0.1, 0.45, 0.04);
                drawcube(mat_diffuse[4]);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.35, 0, 0);
                glScalef(0.45, 0.1, 0.04);
                drawcube(mat_diffuse[4]);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1,0,0);
        glPushMatrix();     // Main house cube
            glTranslatef(0,0,0);
            drawcube(mat_diffuse[2]);
        glPopMatrix();

        glPushMatrix();     // Door
            glTranslatef(0.45,0,1.98);
            glScalef(0.3, 0.6, 0.02);
            drawcube(mat_diffuse[1]);
        glPopMatrix();

        glPushMatrix();     // Window
            glTranslatef(1.3, 0.5, 1.98);
            glScalef(0.25, 0.25, 0.02);
            drawcube(mat_diffuse[1]);
        glPopMatrix();
        glPushMatrix();     // Window glass
            glTranslatef(1.34, 0.53, 1.99);
            glScalef(0.10, 0.22, 0.02);
            drawcube(mat_diffuse[8]);
        glPopMatrix();
        glPushMatrix();     // Window glass
            glTranslatef(1.57, 0.53, 1.99);
            glScalef(0.10, 0.22, 0.02);
            drawcube(mat_diffuse[8]);
        glPopMatrix();

        glPushMatrix();     // Window
            glTranslatef(1.98, 0.5, 0.6);
            glScalef(0.02, 0.25, 0.25);
            drawcube(mat_diffuse[1]);
        glPopMatrix();

        glPushMatrix();     // Window
            glTranslatef(-0.01, 0.5, 0.6);
            glScalef(0.02, 0.25, 0.25);
            drawcube(mat_diffuse[1]);
        glPopMatrix();

        glPushMatrix();     // Roof
            glTranslatef(-0.08,2,-0.01);
            drawpyramid(mat_diffuse[4]);
        glPopMatrix();
    glPopMatrix();
}


void light()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };

    GLfloat light1_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_position[] = { 0.0, 40.0, -1.0, 1.0 };

    glEnable( GL_LIGHT0);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light1_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light1_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light1_specular);
    glLightfv( GL_LIGHT0, GL_POSITION, light1_position);

    GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0);

    GLfloat light2_ambient[]  = {0.8, 0.05, 0.05, 1.0};
    GLfloat light2_diffuse[] =  {0.8, 0.05, 0.05, 1.0};
    GLfloat light2_specular[] = { 1.0, 0.1, 0.1, 1.0 };
    GLfloat light2_position[] = { -4.0, 0.0, -1.0, 1.0 };

    glEnable( GL_LIGHT1);
    glLightfv( GL_LIGHT1, GL_AMBIENT, light2_ambient);
    glLightfv( GL_LIGHT1, GL_DIFFUSE, light2_diffuse);
    glLightfv( GL_LIGHT1, GL_SPECULAR, light2_specular);
    glLightfv( GL_LIGHT1, GL_POSITION, light2_position);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(90, 1, 2, 100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, centerX,centerY,centerZ, upX,upY,upZ);

    glViewport(0, 0, windowHeight, windowWidth);

    glPushMatrix();
        glTranslatef(0,0,Tzval);
        drawscene();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case '=':
            Tzval+=0.2;
            break;

        case '-':
            Tzval-=0.2;
            break;

        case 'd':       // Camera right
        case 'D':
            eyeX += 0.1;
            centerX += 0.1;
            break;

        case 'a':       // Camera left
        case 'A':
            eyeX -= 0.1;
            centerX -= 0.1;
            break;

        case 'w':       // Camera up
        case 'W':
            eyeZ -= 0.1;
            centerZ -= 0.1;
            break;

        case 's':       // Camera down
        case 'S':
            eyeZ += 0.1;
            centerZ += 0.1;
            break;

        case 'e':       // Camera forward
        case 'E':
            eyeY += 0.1;
            centerY += 0.1;
            break;

        case 'q':       // Camera backward
        case 'Q':
            eyeY -= 0.1;
            centerY -= 0.1;
            break;

        case 'u':       // Yaw
        case 'U':
            centerX += 0.1;
            centerZ = -sqrt(eyeZ*eyeZ - (centerX-eyeX)*(centerX-eyeX) - (centerY-eyeY)*(centerY-eyeY)) + eyeZ;
            break;

        case 'y':
        case 'Y':
            centerX -= 0.1;
            centerZ = -sqrt(eyeZ*eyeZ - (centerX-eyeX)*(centerX-eyeX) - (centerY-eyeY)*(centerY-eyeY)) + eyeZ;
            break;

        case 'p':       // Pitch
        case 'P':
            centerY += 0.1;
            centerZ = -sqrt(eyeZ*eyeZ - (centerX-eyeX)*(centerX-eyeX) - (centerY-eyeY)*(centerY-eyeY)) + eyeZ;
            break;

        case 'o':
        case 'O':
            centerY -= 0.1;
            centerZ = -sqrt(eyeZ*eyeZ - (centerX-eyeX)*(centerX-eyeX) - (centerY-eyeY)*(centerY-eyeY)) + eyeZ;
            break;

        case 't':
        case 'T':
            upX += 0.03;
            upY = sqrt(1 - upX*upX);
            break;

        case 'r':
        case 'R':
            upX -= 0.03;
            upY = sqrt(1 - upX*upX);
            break;

        case 'm':
        case 'M':
            wRotate = !wRotate;
            break;

        case '1':
            light1 = !light1;
            break;

        case 27:	// Escape key
            exit(1);
    }
}


void animate()
{

    if (wRotate == true)
    {
        beta += 0.08;
        if(beta > 360.0)
            beta -= 360.0*floor(beta/360.0);
    }

    if (light1 == true)
        glEnable(GL_LIGHT1);
    else
        glDisable(GL_LIGHT1);

    glutPostRedisplay();

}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Assignment");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    light();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
