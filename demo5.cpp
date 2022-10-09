#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
// #include <windows.h>
#include<math.h>


const int width = 500;
const int height = 500;
const float rat = 1.0 * width / height;
double speed_turbine=0.1;


GLfloat eX = 0;
GLfloat eY = 15;
GLfloat eZ = 20;

GLfloat lX = 0;
GLfloat lY = 0;
GLfloat lZ = 0;
GLfloat turbine_theta=0;
GLboolean turbine_rotate = false;

float l_height = 15;
float spt_cutoff = 30;

float rot = 0;

bool l_on = true;

static GLfloat v_pyramid[5][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 0.0, 0.0},
    {0.5, 0.5, 0.5}
};
static GLfloat v_cube[8][3]=
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 0.0, 0.0},

    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {1.0, 1.0, 1.0},
    {1.0, 1.0, 0.0}

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

static GLbyte q_Indices[6][4]=
{
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {1, 2, 6, 5},
    {2, 3, 7, 6},
    {0, 3, 7, 4},
    {0, 1, 5, 4}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
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


void drawpyramid(float R=0.5, float G=0.5, float B=0.5, bool e=false, float alpha=1)
{
    GLfloat m_no[] = {0, 0, 0, 1.0};
    GLfloat m_amb[] = {R,G,B,1};
    GLfloat m_diff[] = {R,G,B,1};
    GLfloat m_spec[] = {1,1,1,1};
    GLfloat m_sh[] = {30};

    GLfloat m_em[] = {1,1,1,1};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);

    if(e & l_on) glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
    else glMaterialfv(GL_FRONT, GL_EMISSION, m_no);
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i <4; i++)
    {
        //glColor3f(colors[i][0],colors[i][1],colors[i][2]);
        glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
    }
    glEnd();

    glBegin(GL_QUADS);
    for (GLint i = 0; i <1; i++)
    {
        //glColor3f(1,0,0);
        //glColor3f(colors[4][0],colors[4][1],colors[4][2]);
        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][2]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][3]][0]);
    }
    glEnd();

}
void drawcube(float R=0.5, float G=0.5, float B=0.5, bool e=false, float alpha=1)
{
    GLfloat m_no[] = {0, 0, 0, 1.0};
    GLfloat m_amb[] = {R,G,B,1};
    GLfloat m_diff[] = {R,G,B,1};
    GLfloat m_spec[] = {1,1,1,1};
    GLfloat m_sh[] = {30};

    GLfloat m_em[] = {1,1,1,1};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);

    if(e & l_on) glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
    else glMaterialfv(GL_FRONT, GL_EMISSION, m_no);

    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        //glColor3f(colors[i][0],colors[i][1],colors[i][2]);
        glVertex3fv(&v_cube[q_Indices[i][0]][0]);
        glVertex3fv(&v_cube[q_Indices[i][1]][0]);
        glVertex3fv(&v_cube[q_Indices[i][2]][0]);
        glVertex3fv(&v_cube[q_Indices[i][3]][0]);
    }
    glEnd();
}

void axes()
{
    float length = 10;
    float width = 0.3;

    // X-axis
    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,width,width);
    glTranslatef(-0.5,-0.5,-0.5);
    drawcube(0.8,0.1,0.1);
    glPopMatrix();

    // Y-axis
    glPushMatrix();
    glTranslatef(0,length/2,0);
    glScalef(width,length,width);
    glTranslatef(-0.5,-0.5,-0.5);
    drawcube(0.1,0.8,0.1);
    glPopMatrix();

    // Z-axis
    glPushMatrix();
    glTranslatef(0,0,length/2);
    glScalef(width,width,length);
    glTranslatef(-0.5,-0.5,-0.5);
    drawcube(0.1,0.1,0.8);
    glPopMatrix();
}

void square()
{

    glBegin(GL_QUADS);
    //glColor3f(0,0,1);
    glVertex3fv(&v_cube[q_Indices[5][0]][0]);
    glVertex3fv(&v_cube[q_Indices[5][1]][0]);
    glVertex3fv(&v_cube[q_Indices[5][2]][0]);
    glVertex3fv(&v_cube[q_Indices[5][3]][0]);
    glEnd();
}

void flr()
{
    glPushMatrix();
    //glTranslatef(0,-0.5,0);
    glScalef(60,1,60);
    glTranslatef(-0.5,-1,-0.5);
    drawcube();
    glPopMatrix();
}
void house()
{
    glPushMatrix();
    glScalef(3,3,3);
    drawcube();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-.5,3,-.5);
    glScalef(4,4,4);
    drawpyramid();
    glPopMatrix();
    for(GLfloat i=-1; i<=4; i+=.5)
    {
        glPushMatrix();
        glTranslatef(i,0,4);
        glScalef(.1,1,.1);
        drawcube();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(i,0,-1);
        glScalef(.1,1,.1);
        drawcube();
        glPopMatrix();
    }

    for(GLfloat i=-1; i<4; i+=.5)
    {
        glPushMatrix();
        glTranslatef(-1,0,i);
        glScalef(.1,1,.1);
        drawcube();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(4,0,i);
        glScalef(.1,1,.1);
        drawcube();
        glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(-1,0.3,4);
    glScalef(5,0.1,0.1);
    drawcube();
    glTranslatef(0,3,0);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,.3,-1);
    glScalef(5,.1,.1);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,.6,-1);
    glScalef(5,.1,.1);
    drawcube();
    glPopMatrix();

    //left right
    glPushMatrix();
    glTranslatef(-1,.3,-1);
    glScalef(.1,.1,5);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,.6,-1);
    glScalef(.1,.1,5);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,.3,-1);
    glScalef(.1,.1,5);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,.6,-1);
    glScalef(.1,.1,5);
    drawcube();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_POINT);
    glColor3f(0,1,0);
    glVertex3f(-2,0,0);
    glEnd();
    glPopMatrix();


}


void turbine()
{

    glPushMatrix();
    glTranslatef(0,.25,0);
    glScalef(1,.5,1);
    glTranslatef(-.5,-.5,-.5);
    drawcube();
    glPopMatrix();

    // stick
    glPushMatrix();
    glTranslatef(0,5,0);
    glScalef(.2,10,.2);
    glTranslatef(-.5,-.5,-.5);
    drawcube();
    glPopMatrix();

    //pakha base
    // stick
    glPushMatrix();
    glTranslatef(0,10,0);
    glScalef(1,.2,.2);
    glTranslatef(-.5,-.5,-.5);
    drawcube();
    glPopMatrix();

    //pakha
    glPushMatrix();
    glTranslatef(-.5,10,0);
    glRotatef( turbine_theta,1, 0, 0 );
    glPushMatrix();
    glScalef(.1,.3,2);
    glTranslatef(-.5,-.5,-.5);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    glScalef(.1,2,.3);
    glTranslatef(-.5,-.5,-.5);
    drawcube();
    glPopMatrix();
    glPopMatrix();


}





static void res(int width, int height)
{
    glViewport(0, 0, width, width/rat);
}

void light()
{
    //light
    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {1, 1, 1, 1.0};
    GLfloat l_dif[] = {1,0,0,1};
    GLfloat l_spec[] = {0,0,1,1};
    GLfloat l_pos[] = {0,l_height,0,1.0};

    glEnable(GL_LIGHT0);

    if(l_on) glLightfv(GL_LIGHT0, GL_AMBIENT, l_amb);
    else glLightfv(GL_LIGHT0, GL_AMBIENT, l_no);
    if(l_on) glLightfv(GL_LIGHT0, GL_DIFFUSE, l_dif);
    else glLightfv(GL_LIGHT0, GL_DIFFUSE, l_no);
    if(l_on) glLightfv(GL_LIGHT0, GL_SPECULAR, l_spec);
    else glLightfv(GL_LIGHT0, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT0, GL_POSITION, l_pos);

    // spot light extra
    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {spt_cutoff};
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, spt_ct);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 3.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eX,eY,eZ, lX,lY,lZ, 0,1,0);

    glRotatef(rot, 0,1,0);
    axes();

    house();
    flr();
    glPushMatrix();
    glTranslatef(5,0,4);
    glScalef(1,.7,1);
    turbine();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45, 0,1,0);
    light();
    glPopMatrix();

    glTranslatef(0,l_height+1,0);
    glScalef(5,1,1);
    glTranslatef(-0.5,-0.5,-0.5);
    drawcube(1,0,0,true);

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case 't':
        l_on=1-l_on;
        break;

    case 'b':
        rot+=2;
        break;
    case 'd':
        rot-=2;
        break;

    case 's':
        eZ--;
        lZ--;
        break;
    case 'p':
        eZ++;
        lZ++;
        break;

    case 'n':
        eY--;
        break;
    case 'u':
        eY++;
        break;

    case '1':
        l_height++;
        break;
    case '2':
        l_height--;
        break;

    case '3':
        spt_cutoff++;
        break;
    case '4':
        spt_cutoff--;
        break;

    case 'g':
        turbine_rotate=!turbine_rotate;
        break;
    case '6':
        speed_turbine+=0.1;
        break;
    case '9':
        speed_turbine-=0.1;
        break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    if(turbine_rotate==true)
    {
        turbine_theta += speed_turbine;
        if(turbine_theta > 360.0)
            turbine_theta -= 360.0*floor(turbine_theta/360.0);
    }
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutReshapeFunc(res);

//    glClearColor(1,1,1,1);

    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    glEnable(GL_LIGHTING);

//    printf("########################################################################################\n");
//    printf("########################################################################################\n");
//    printf("##############                                                         #################\n");
//    printf("##############           PLEASE FOLLOW THE BELOW INSTRUCTIONS          #################\n");
//    printf("##############                                                         #################\n");
//    printf("########################################################################################\n");
//    printf("########################################################################################\n\n\n");
//    printf("Use 'w' to look up, 's' to look down, 'd' to look right, and 'a' to look left.\n");
//    printf("Use 'i' to move camera up, 'k' to move camera down, 'l' to move camera right, and 'j' to move camera left with the look at point fixed.\n");
//    printf("Use '+' to zoom in and '-' to zoom out.\n\n\n");

    glutMainLoop();

    return EXIT_SUCCESS;
}