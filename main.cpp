#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include "modules.h"


#define push glPushMatrix
#define pop glPopMatrix
#define gt(x,y,z) glTranslatef(x,y,z)
#define te(x) glEnable(GL_TEXTURE_2D),glBindTexture(GL_TEXTURE_2D, x)
#define td() glDisable(GL_TEXTURE_2D)


using namespace std;

int windowHeight = 800;
int windowWidth = 800;


double eyex = 0, eyey = 30, eyez = 40;
double x = 0, y = 0, z = 0;
double dx = 0, dy = 0, dz = 0;
double xaxis = 0, yaxis = 1, zaxis = 0;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, angle_x = 0.0, angle_y = 0.0;
GLboolean bRotate = false, uRotate = false, xRotate = false, yRotate = false;

float door_1_angle = 0;
float door_2_angle = 0;
float door_3_angle = 0;
float door_4_angle = 0;
float door_5_angle = 0;













float fan_height = 7.5;
float fan_angle = 1;

// GLuint texture_1, texture_2;    
GLuint texture[10];


#define PI 3.14159265


 GLfloat mat_diffuse[][4] = {
        { 0.4, 0.4, 0.4, 1.0 },
        { 0.7, 0.7, 0.7, 1.0 },
        { 0.2, 0.2, 0.4, 1.0 },
        { 0.8, 0.2, 0.2, 1.0 },
        { 1.0, 0.64, 0.0, 1.0 },
        { 0.59, 0.44, 0.2, 1.0 },
        { 0.23, 0.37, 0.04, 1.0 },
        { 0.44, 0.33, 0.22, 1.0 },
        { 0.2, 0.2, 0.2, 1.0 }
    };





void resize (int w, int h)
{
   glViewport (0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(90.0, (float)w/(float)h, 1.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}









////////////////// Objects drawings



GLfloat zz = 21,xx = 16, cc = 34;

float l_height = 15;
float spt_cutoff = 30;

float rot = 0;

bool l_1 = 1;
bool l_2 = 0;
bool l_3 = 0;
bool l_4 = true;
bool l_5 = true;
bool l_6 = true;
bool l_7 = true;
bool l_8 = true;


bool am_on = true;
bool dif_on = true;
bool spec_on = true;

float l_z = 0.2;
float l_y = 0.2;
float l_x = 0.2;
 
void light()
{
    if(l_1)
    {
        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { zz, xx, cc, 0.0 };
        // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

      

        // glEnable(GL_LIGHT0);


        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glEnable(GL_LIGHT0);
        // glDisable(GL_LIGHT1);
        // glDisable(GL_LIGHT2);


        // glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
        // glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0);
    }
    else
    {
        glDisable(GL_LIGHT0);
    }        
    if(l_2)
    {

        // glEnable(GL_LIGHT0);

        GLfloat light_ambient_1[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse_1[] = { 0.3, 0.6, 0.7, 1.0 };
        GLfloat light_specular_1[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position_1[] = { -50, 1, -80, 0.0 };
        // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

      

        // glEnable(GL_LIGHT0);


        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_1);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_1);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_1);
        glLightfv(GL_LIGHT1, GL_POSITION, light_position_1);



        glEnable(GL_LIGHT1);
        // glDisable(GL_LIGHT0);
        // glDisable(GL_LIGHT2);



    }
    else{
        glDisable(GL_LIGHT1);

    }
    if(l_3)
    {


        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { zz, xx, cc, 1.0 };
        // GLfloat spot_direction[] = {-1.0-l_x, -1.0-l_y, -1.0-l_z };
        GLfloat spot_direction[] = {0, -1.0, 0 };

        float globAmb[] = { 0.05, 0.05, 0.05, 1.0 };



        glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.

        glLightfv(GL_LIGHT2, GL_POSITION, light_position);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
        glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spt_cutoff);

 

        glEnable(GL_LIGHT2);
        // glDisable(GL_LIGHT0);
        // glDisable(GL_LIGHT1);



    }
    else{
        glDisable(GL_LIGHT2);

    }
    


    // GLfloat light1_ambient[] = { 0.0, 0.0, 0., 0.0 };
    // GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat light1_position[] = { 0.0, 7.0, 0.0, 1.0 };
    // GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };

    // glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    // glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    // glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    // glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    // glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
    // glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
    // glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2); 

    // glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    // glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    // glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5.0);

    // glEnable(GL_LIGHT1);
}







//////////////////////////////////////////////////////////////////////////////////////////////////////// objects

void disable_mat()
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}


void drawFench()
{
    push();
    // gt(-90,0,0);
    gt(2,2.1,0);
    drawCube(184,0.2,0.2);
    gt(-2,-2.1,0);
    for(int i = 0; i <= 91; i++)
    {
        te(texture[2]);
        gt(2,0,0);
        drawCube(0.5,2,0.2);
        td();
    }
    pop();
}

void drawOutside()
{  
    push();
        
        // glEnable(GL_TEXTURE_2D),glBindTexture(GL_TEXTURE_2D, texture[0]);
        te(texture[0]);
        gt(-100,0,0);
        drawCube(200,0.001,200);
        gt(100,0,0);
        td();
    pop();
    
    push();
        gt(-95,0,-5);
        drawFench();
    pop();
    push();
        gt(-95,0,-190);
        drawFench();
    pop();
    push();
        gt(-93,0,-4);
        glRotatef(90,0,1,0);
        drawFench();
    pop();
    push();
        gt(92,0,-192);
        glRotatef(-90,0,1,0); 
        drawFench();
    pop();
}




void drawHome()
{
    push();
        gt(10,0,-30);
        drawCube(50,15,1);
    pop();
    push();
        gt(-70,0,-50);
        drawCube(80,15,1);
    pop();
    push();
        gt(-70,0,-50);
        drawCube(1,15,120);
    pop();
    push();
        gt(-70,0,-50);
        drawCube(1,15,120);
    pop();
    
    push();
        gt(-70,0,-90);
        drawCube(70,15,1);
    pop();
    push();
        gt(-70,0,-130);
        drawCube(70,15,1);
    pop();
    push();
        gt(-70,0,-170);
        drawCube(70,15,1);
    pop();
    push();
        gt(0,0,-57);
        drawCube(1,15,33);
    pop();
    push();
        gt(0,0,-97);
        drawCube(1,15,33);
    pop();
    push();
        gt(0,0,-137);
        drawCube(1,15,33);
    pop();

    push();
        gt(60,0,-30);
        drawCube(1,15,140);
    pop();
    push();
        gt(0,0,-170);
        drawCube(60,15,1);
    pop();



    push();
        gt(20,0,-90);
        drawCube(40,15,1);
    pop();
    push();
        gt(20,0,-130);
        drawCube(40,15,1);
    pop();
    push();
        gt(20,0,-97);
        drawCube(1,15,33);
    pop();
    push();
        gt(20,0,-137);
        drawCube(1,15,33);
    pop();
}

void drawSofa()
{
    //////glcolor3f(0.9, 0.9, 0.9);
    glTranslatef(-4,0,8);
    drawCube(0.3,2.5,5);
    glTranslatef(4,0,-8);
    
    //////glcolor3f(0.1, 0.1, 0.1);
    glTranslatef(-3.7,0,8.1);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-8.1);

    glTranslatef(-3.7,0,3);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-3);

    //////glcolor3f(0.7, 0.7, 0.7);

    glTranslatef(-3.7,0.5,8);
    drawCube(1.2,0.2,5);
    glTranslatef(3.7,-0.5,-8);

}

void drawSofa2()
{
    //////glcolor3f(0.9, 0.9, 0.9);
    glTranslatef(-4,0,8);
    drawCube(0.3,2.5,3);
    glTranslatef(4,0,-8);
    
    //////glcolor3f(0.1, 0.1, 0.1);
    glTranslatef(-3.7,0,8.1);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-8.1);

    glTranslatef(-3.7,0,5);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-5);

    //////glcolor3f(0.7, 0.7, 0.7);

    glTranslatef(-3.7,0.5,8);
    drawCube(1.2,0.2,3);
    glTranslatef(3.7,-0.5,-8);

}


void drawMulSofa()
{
    push();
    // glEnable(GL_COLOR_MATERIAL);
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 0.8, 0.0, 0.5, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glTranslatef(-1,0,-1);
    drawSofa();
    glTranslatef(1,0,1);

    glTranslatef(-2,0,10);
    glRotatef(180,0,1,0);
    drawSofa();
    glRotatef(-180,0,1,0);
    glTranslatef(2,0,-10);

    glTranslatef(4.5,0,3);
    glRotatef(-90,0,1,0);
    drawSofa2();
    glRotatef(90,0,1,0);
    glTranslatef(4.5,0,-3);

    glTranslatef(-17,0,5.5);
    glRotatef(90,0,1,0);
    drawSofa2();
    glRotatef(90,0,1,0);
    glTranslatef(17,0,-5.5);
    // glDisable(GL_COLOR_MATERIAL);

    disable_mat();
    
    pop();
}


void drawSofas()
{
    push();
        gt(-30,0,-80);
        glScalef(3,2,2);
        drawMulSofa();
    pop();
}

bool door_1_stat = false;
bool door_2_stat = false;
bool door_3_stat = false;
bool door_4_stat = false;
bool door_5_stat = false;


void drawDoor_1(bool x, float& angle, bool pp = true)
{
    push();
        // if(door_1_stat)
        glRotatef(angle,0,1,0);
        if(pp){
            glScalef(1,1,-1);
        }
        drawCube(1,15,6);
        if(x)
        {
            if(angle < 90)
            angle++;
        }
        else
        {
            if(angle > 0)
                angle--;
        }
        
    pop();
}



void doors()
{
    te(texture[5]);

    push();
        gt(0,0,-137);
        drawDoor_1(door_1_stat, door_1_angle);
    pop();
    push();
        gt(0,0,-97);
        drawDoor_1(door_2_stat, door_2_angle);
    pop();
    push();
        gt(0,0,-57);
        drawDoor_1(door_3_stat, door_3_angle);
    pop();
    push();
        gt(20,0,-90);
        drawDoor_1(door_4_stat, door_4_angle, false);
    pop();
    push();
        gt(20,0,-130);
        drawDoor_1(door_5_stat, door_5_angle, false);
    pop();


    td();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////// objects



void display(){


    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (eyex, eyey, eyez, x+dx, y+dy, z+dz, xaxis, yaxis, zaxis);
    light();


    ////////////////////////// drawing start

    // glRotatef(70,1,0,0);

    glRotatef( angle_x,axis_x, axis_y, 0.0 );
    glRotatef( angle_y, axis_x, axis_y, 0.0 );

    push();
        drawOutside();
    pop();

    push();
        te(texture[4]);
        drawHome();
        td();
    pop();

    push();
        drawSofas();
    pop();


    push();
        doors();
    pop();
    // push();
    //     drawCube(1,1,1);
    //     glutSolidCube(1);
    // pop();
    
    // glPushMatrix();
    // glTranslatef(0,2,-3);
    // glutSolidSphere(1,100,100);
    // glPopMatrix();


    ///////////////////////// drawing end

    // glPushMatrix();
    // glDisable(GL_LIGHTING);
    // glTranslatef(zz,xx,cc);
    // glRotatef(-90.0, 1.0, 0.0, 0.0);
    // glColor3f(1.0, 1.0, 1.0);
    // glutWireCone(3.0 * tan( spt_cutoff/180.0 * PI ), xx+3, 20, 20);
    // glEnable(GL_LIGHTING);
    // glPopMatrix();


    glFlush();

    glutSwapBuffers();



    
}












void myKeyboardFunc( unsigned char key, int x, int y )
{

    cout << key << endl;
    switch ( key )
    {

    case 'f':
        if(!bRotate)
        {
            fan_angle = 2;
            bRotate = !bRotate;
        }
        else{
            bRotate = !bRotate;
            uRotate = false;
        }
        // bRotate = !bRotate;
        // uRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;
    case '!':
        if(bRotate)
        {
            fan_angle = 5;
        }
        break;
    case '@':
        if(bRotate)
        {
            fan_angle = 9;
        }
        break;
    case '#':
        if(bRotate)
        {
            fan_angle = 13;
        }
        break;

    case 't':
        l_y-=0.2;
        break;
    case 'T':
        l_y+=0.2;
        break;
    case 'g':
    // case 'G':
        l_z-=0.2;
        break;
    case 'G':
        l_z+=0.2;
        break;


    case '=':
        eyez--;
        break;
    case '-':
        eyez++;
        break;

    // //panning
    case 'P':
        cout << "zz : " << zz << endl;
        cout << "xx : " << xx << endl;
        cout << "cc : " << cc << endl;

        break;

    // case 'p':
    //     lpan+=1;
    //     rpan +=1;
    //     break;

    case 'h':

        door_1_stat = 1-door_1_stat;
        break;
    case 'j':
        door_2_stat = 1- door_2_stat;
        break;

    case 'k':
        door_3_stat = 1- door_3_stat;
        break;
    case 'l':
        door_4_stat = 1- door_4_stat;
        break;
    case ';':
        door_5_stat = 1- door_5_stat;
        break;

    case 'n':
        eyey--;
        dy--;
        break;

    case 'b':
        eyex++;
        
        break;
    
    case 'm':
        eyex--;
        break;
    case 'y':
        l_x-=0.2;
        break;
    case 'Y':
        l_x+=0.2;
        break;
    case '1':
        l_1 = 1-l_1;
        break;

    case '2':
        l_2 = 1-l_2;
        break;

    case '3':
        l_3 = 1-l_3;
        break;

    case '4':
        l_4 = l_4-1;
        break;

    case '5':
        l_5 = l_5-1;
        break;
    // case 'f':
    case '6':
        xRotate = !xRotate;
        yRotate = false;
        axis_x=0.0;
        axis_y=1.0;
        break;

    case 'q':
        spt_cutoff+=0.2;
        break;
    case 'Q':
        spt_cutoff-=0.2;
        break;
    // case '5':
        // fdist +=0.5;
        // break;
    // case '%':
        // fdist -= 0.5;
        // break;
    // case 'g':
    case '7':
        yRotate = !yRotate;
        xRotate = false;
        axis_x=1.0;
        axis_y=0.0;
        break;


//yaw
    case 'd':
        y=y;
        dx += 0.5;
        break;

    case 'a':

        y=y;
        dx -= 0.5;
        break;
//pitch

    case 'w':
        x=x;
        dy += 0.5;
        break;

    case 's':
        x=x;
        dy -= 0.5;

        break;

//roll
    case 'r':
        zaxis+=0.2;
        break;

    case 'R':
        zaxis-=0.2; 
        break;

    case 'z':
        zz+=1.2;
        break;
    case 'Z':
        zz-=1.2;
        break;
    case 'x':
        xx+=1.2;
        break;
    case 'X':
        xx-=1.2;
        break;
    case 'c':
        cc+=1.2;
        break;
    case 'C':
        cc-=1.2;
        break;

    case 27:	// Escape key
        exit(1);
    }
}




// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_PAGE_DOWN)
    {
        eyey--;
        dy--;
    }
    if( key == GLUT_KEY_PAGE_UP)
    {
        
        eyey++;
        dy++;
    }
    if (key == GLUT_KEY_UP)
    {
        eyez--;
        dz--;
    }
    if (key == GLUT_KEY_DOWN)
    {
        eyez++;
        dz++;
    }
    if (key == GLUT_KEY_LEFT)
    {
        eyex--;
        dx--;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        eyex++;
        dx++;
    }
    glutPostRedisplay();
}










float k = 0.5;
bool pos = true;
bool neg = false;

void animate()
{
    if (bRotate == true)
    {
        theta += fan_angle;
        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
    }

    if (uRotate == true)
    {
        if(alpha < 90 && pos)
        {
            alpha += k;
        }
        else{
            pos = false;
            neg = true;
        }
        if(alpha > -90 && neg)
        {
            alpha -= k;
        }
        else{
            pos = true;
            neg = false;
        }
    }

    if (xRotate == true)
    {
        angle_x += 0.2;
        if(angle_x > 360.0)
            angle_x -= 360.0*floor(angle_x/360.0);
    }

    if (yRotate == true)
    {
        angle_y += 0.2;
        if(angle_y > 360.0)
            angle_y -= 360.0*floor(angle_y/360.0);
    }
    glutPostRedisplay();

}



int main (int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize (1000, 700);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("1707119");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    

    texture[0] = LoadTexture("images/p1.bmp", 2000, 1338);
    texture[1] = LoadTexture("im1.bmp", 640, 640);      
    texture[2] = LoadTexture("images/wood_1.bmp", 500, 800);
    texture[3] = LoadTexture("images/wall2.bmp", 359, 350);
    texture[4] = LoadTexture("images/wall3.bmp", 1000, 1000);
    texture[5] = LoadTexture("images/door.bmp", 632, 1264);


 
    // light();



    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);
    glutSpecialFunc(specialKeyInput);
    
    glutMainLoop();

}






// void drawFloor()
// {




//     glEnable(GL_TEXTURE_2D);
//     glPushMatrix();

//     GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//     GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
//     //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
//     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//     GLfloat mat_shininess[] = {60};

//     // glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
//     // glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
//     glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//     glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

//        glTranslatef(-15,-5,5);
//         glScalef(30,0.5,30);
//         // drawCube(30,0.5,30);
//         drawCube(1,1,1);

//     glPopMatrix();
//     glDisable(GL_TEXTURE_2D);

// }


// void drawFloor2()
// {
//     //          GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//     // GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
//     // //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
//     // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//     // GLfloat mat_shininess[] = {1000};

//     // // glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
//     // // glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
//     // glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//     // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//     for(float i = 0; i < 50; i+=0.5)
//     {
//         for(float j = 0; j < 50; j+=0.5)
//         {
//             glPushMatrix();
//             glTranslatef(i,0,j);
//             drawCube(0.5,0.5,0.5);
//             glPopMatrix();
//         }
//     }
// }


// void drawFloor3()
// {
//              GLfloat no_mat[] = { 0.0, 0.0, 0.0, 0.5 };
//     GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 0.5 };
//     GLfloat mat_diffuse2[] = { 0.5, 0.0, 0.0, 0.5 };
//     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.5 };
//     // GLfloat mat_shininess[] = {60};

//     glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//     glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
//     glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//     // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    
//     drawCube(10,10,0.2);

//     // for(float i = 0; i < 50; i+=0.5)
//     // {
//     //     for(float j = 0; j < 50; j+=0.5)
//     //     {
//     //         glPushMatrix();
//     //         glTranslatef(i,j,0);
//     //         drawCube(0.5,0.5,0.5);
//     //         glPopMatrix();
//     //     }
//     // }
// }



// void drawRoom()
// {
//     // GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//     // GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
//     // //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
//     // GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//     // GLfloat mat_shininess[] = {60};

//     // // glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[0]);
//     // // glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[0]);
//     // glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//     // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//     //////glcolor3f(0.2,0.2,0.2);
//     // glEnable(GL_TEXTURE_2D);
//     // drawFloor2();
//     // gluSphere(1,10,10);
//     // glDisable(GL_TEXTURE_2D);
//     glEnable(GL_BLEND); //Enable blending.
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
//     drawFloor3();
//     glDisable(GL_BLEND);
//     // drawFloor();

//     //////glcolor3f(0.3,0.3,0.3);
//     // drawRight();
//     // drawBack();
//     // drawLeft();

// }
