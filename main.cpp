#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;


// macros for gl functions

#define push glPushMatrix
#define pop glPopMatrix
#define gt(x,y,z) glTranslatef(x,y,z)
#define gs(x,y,z) glScalef(x,y,z)
#define gr(a,x,y,z) glRotatef(a,x,y,z)
#define te(x) glEnable(GL_TEXTURE_2D),glBindTexture(GL_TEXTURE_2D, x)
#define td() glDisable(GL_TEXTURE_2D)
#define PI 3.14159265


int windowHeight = 800;
int windowWidth = 800;

double eyex = 0, eyey = 4, eyez = 42;
double x = 0, y = 0, z = 0;
double dx = 0, dy = 0, dz = 0;
double xaxis = 0, yaxis = 1, zaxis = 0;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, angle_x = 0.0, angle_y = 0.0;
GLboolean bRotate = false, uRotate = false, xRotate = false, yRotate = false;





float p_zoom = 90;
float s_zoom = 1;



float fan_height = 7.5;
float fan_angle = 1;

// global array for storing texture images
GLuint texture[30];




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
   gluPerspective(p_zoom, (float)w/(float)h, 1.0, 1000.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}



// custom draw function ========================================================== loc: 1

void drawCube(float x, float y, float z)
{
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);       
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f);



        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);   
        

        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);  
        

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);
        

        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+y, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glTexCoord2f(1,1); 
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);


        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        


    glEnd();
}



void drawTriangle(float x, float y, float z){

        glBegin(GL_QUADS);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0,0,0);
        glVertex3f(x,0,0);
        glVertex3f(x,y,0);
        glVertex3f(0,y,0);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(x,0,0);
        glVertex3f(x,0,-z);
        glVertex3f(x,y,-z);
        glVertex3f(x,y,0);

        glNormal3f(0.0f, 1.0f, 1.0f);
        glVertex3f(x,0,-z);
        glVertex3f(0,0,0);
        glVertex3f(0,y,0);
        glVertex3f(x,y,-z);

        glEnd();

        glBegin(GL_TRIANGLES);

        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0,y,0);
        glVertex3f(x,y,0);
        glVertex3f(x,y,-z);

        glNormal3f(0.0f, -1.0f, 0.0f);

        glVertex3f(0,0,0);
        glVertex3f(x,0,0);
        glVertex3f(x,0,-z);

        glEnd();
    

}

void drawCircle(float x, float y, float z)
{
    glPushMatrix();
    for(int i = 0; i < 100; i++)
    {
        glRotatef(3.6,0,1,0);
        drawTriangle(x,y,z);
    }
    
    glPopMatrix();
}


/////====================================== loc1: end

// for Loading texture
GLuint LoadTexture( const char * filename, int x, int y )
{
  GLuint texture;
  int width, height;
  unsigned char * data;

  FILE * file;
  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  width = x;
  height = y;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

  for(int i = 0; i < width * height ; ++i)
  {
    int index = i*3;
    unsigned char B,R;
    B = data[index];
    R = data[index+2];

    data[index] = R;
    data[index+2] = B;
  }

  glGenTextures( 1, &texture );
  glBindTexture( GL_TEXTURE_2D, texture );
//   glBindTexture (GL_TEXTURE_2D, texture);
  glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
  gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
  free( data );

  return texture;
}








/////////////////////================================ loc2 : lighting

float zz = 0,xx = 5, cc = 11; // use for changing position of daylight


float l_height = 15;
float spt_cutoff = 40;

float rot = 0;

bool l_1 = 1;
bool l_2 = 0;
bool l_3 = 0;
bool l_4 = 0;
bool l_5 = 0;
bool l_6 = 0;
bool l_7 = 0;
bool l_8 = 0;


bool am_on = true;
bool dif_on = true;
bool spec_on = true;

float l_z = 0.2;
float l_y = 0.2;
float l_x = 0.2;


bool up_light = 0;


// light position
float l_pos[8][3]={
                    {zz, xx, cc}, //light 0
                    {40, 15, 11}, //light 1
                    {-25, 15, 11}, //light 2
                    {-6, 29, -71}, //light 3
                    {-6, 29, -111}, //light 4
                    {55, 15, -157}, //light 5
                    {55, 15, -119}, //light 6
                    {105, 15, 11}  //light 7
            };

//=========possible properties of lights====================

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

//==========================================================

void make_light(GLenum light, int spt, float pos[], int spt_cut = 73)
{
    if(1-spt)
    {

        GLfloat light_ambient_1[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse_1[] = { 1, 1, 1, 1.0 };
        GLfloat light_specular_1[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position_1[] = { pos[0], pos[1], pos[2], 0.0 };

        glLightfv(light, GL_AMBIENT, light_ambient_1);
        glLightfv(light, GL_DIFFUSE, light_diffuse_1);
        glLightfv(light, GL_SPECULAR, light_specular_1);
        glLightfv(light, GL_POSITION, light_position_1);
        glLightf(light, GL_CONSTANT_ATTENUATION, 1.5);
        glLightf(light, GL_LINEAR_ATTENUATION, 0.5);
        glLightf(light, GL_QUADRATIC_ATTENUATION, 0.2); 

        glEnable(light);
    }
    else{

        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { pos[0], pos[1], pos[2], 1.0 };
        GLfloat spot_direction[] = {0, -1.0, 0 };

        float globAmb[] = { 0.05, 0.05, 0.05, 1.0 };



        glLightfv(light, GL_AMBIENT, light_ambient);
        glLightfv(light, GL_DIFFUSE, light_diffuse);
        glLightfv(light, GL_SPECULAR, light_specular);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.

        glLightfv(light, GL_POSITION, light_position);
        glLightfv(light, GL_SPOT_DIRECTION, spot_direction);
        glLightf(light, GL_SPOT_CUTOFF, spt_cut);

 

        glEnable(light);
    }
}


 
void light()
{
    if(l_1)
    {
        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = { zz, xx, cc, 0.0 };

        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glEnable(GL_LIGHT0);

    }
    else
    {
        glDisable(GL_LIGHT0);
    }        
    if(l_2)
    {
        
        make_light(GL_LIGHT1, 1, l_pos[1], spt_cutoff);
    }
    else{
        glDisable(GL_LIGHT1);

    }
    if(l_3)
    {
        make_light(GL_LIGHT2, 1, l_pos[2],spt_cutoff);
    }
    else{
        glDisable(GL_LIGHT2);

    }

    if(l_4)
    {
        if(up_light)
            l_pos[3][1] = 29+15;
        else
            l_pos[3][1] = 29;
        make_light(GL_LIGHT3, 1, l_pos[3]);

    }
    else{
        glDisable(GL_LIGHT3);

    }
    
    if(l_5)
    {
        if(up_light)
            l_pos[4][1] = 29+15;
        else
            l_pos[4][1] = 29;
        make_light(GL_LIGHT4, 1, l_pos[4]);

    }
    else{
        glDisable(GL_LIGHT4);

    }
    
    if(l_6)
    {
        if(up_light)
            l_pos[5][1] = 29+15;
        else
            l_pos[5][1] = 29;
        make_light(GL_LIGHT5, 1, l_pos[5]);

    }
    else{
        glDisable(GL_LIGHT5);

    }
    
    if(l_7)
    {
        if(up_light)
            l_pos[6][1] = 29+15;
        else
            l_pos[6][1] = 29;
        make_light(GL_LIGHT6, 1, l_pos[6]);

    }
    else{
        glDisable(GL_LIGHT6);

    }
    if(l_8)
    {
        make_light(GL_LIGHT7, 1, l_pos[7], spt_cutoff);
    }
    else{
        glDisable(GL_LIGHT7);

    }
    
}




// drawing light objects inside room

void drawLights() 
{
    push();
        gt(-6, 14, -71);
        drawCube(1,1,4);
    pop();
    push();
        gt(-6, 14, -111);
        drawCube(1,1,4);
    pop();
    push();
        gt(55, 14, -157);
        drawCube(1,1,4);
    pop();
    push();
        gt(55, 14, -119);
        drawCube(1,1,4);
    pop();


    push();
        gt(-6, 29, -71);
        drawCube(1,1,4);
    pop();
    push();
        gt(-6, 29, -111);
        drawCube(1,1,4);
    pop();
    push();
        gt(55, 29, -157);
        drawCube(1,1,4);
    pop();
    push();
        gt(55, 29, -119);
        drawCube(1,1,4);
    pop();

}

///////========================================================= loc2 : end




//// ============================ materials property ================
void disable_mat() // for reset material property
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

void transparent_mat() // for enabling transparency property
{
    GLfloat mat_ambient[] = { 1, 1, 1, 0.5 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 0.5 };
    GLfloat mat_specular[] = { 1, 1, 1, 0.5 };
    // GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
}


void room_mat()
{
    GLfloat mat_ambient[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {100};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}











void drawFench(int kk = 91) // outside fench
{
    push();
    // gt(-90,0,0);
    gt(2,2.1,0);
    drawCube(2*kk+2,0.2,0.2);
    gt(-2,-2.1,0);
    for(int i = 0; i <= kk; i++)
    {
        te(texture[2]);
        gt(2,0,0);
        drawCube(0.5,2,0.2);
        td();
    }
    pop();
}

void drawOutside() // drawing fench on all sides and outside grass view
{  
    push();
        
        te(texture[0]);
        gt(-100,0,0);
        drawCube(200,0.001,200);
        gt(100,0,0);
        td();
    pop();
    

    push();
        gs(1,3,1);
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
    pop();
}



//============== drawing room ===============

void drawWall_long()
{
    push();
        drawCube(70,15,1);
    pop();
}
void drawWall_short()
{
    push();
        drawCube(1,15,40);
    pop();
}
void drawWall_long_window()
{
    push();
        drawCube(70,4,1);
    pop();
    push();
        gt(0,11,0);
        drawCube(70,4,1);
    pop();
    push();
        drawCube(25,15,1);
    pop();
    push();
        gt(45,0,0);
        drawCube(25,15,1);
    pop();
}
void drawWall_short_window()
{
    push();
        drawCube(1,4,40);
    pop();
    push();
        gt(0,11,0);
        drawCube(1,4,40);
    pop();
    push();
        gt(0,0,-25);
        drawCube(1,15,15);
    pop();
    push();
        drawCube(1,15,15);
    pop();
}
void drawWall_short_door(int a=1)
{
    if(a)
    {
        push();
            gt(0,0,-7);
            drawCube(1,15,33);
        pop();
    }
    else{
        push();
            gt(0,0,-33);
            drawCube(1,15,33);
        pop();
    }
    
}

void drawRoom_pre_1()
{
    //front
    push();

        drawWall_long_window();
        glScalef(1,1,0.01);

    pop();
    
    //right
    push();
        gt(70,0,0);
        drawWall_short_door();
        glScalef(0.1,1,1);
  
    pop();

    //back
    push();
        gt(0,0,-40);
        drawWall_long();

        
    pop();
    //left
    push();
        drawWall_short_window();

    pop();
}


void drawRoom_pre_2()
{
    push();
        gt(70,0,0);
        drawWall_short_window();
        glScalef(0.1,1,1);
  
    pop();

    //back
    push();
        gt(0,0,-40);
        drawWall_long();

        
    pop();
    //left
    push();
        drawWall_short_window();

    pop();
}

void drawRoom1(int a = 0, GLuint tt = texture[0])
{
    room_mat();
    drawRoom_pre_1();
    if(a)
    {
        te(tt);
        gt(0.01,0,-0.01);
        glScalef(0.999,1,0.999);
        drawRoom_pre_1();
        td();
    }

}

void drawRoom2(int a = 0)
{
    room_mat();
    glScalef(-0.56,1,1);
    push();
        drawRoom1(a);
    pop();
}

void drawRoom3()
{
    room_mat();
    push();
        drawRoom_pre_2();
    pop();
}

//============ room drawing ended







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
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
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





/// dinnign table


void drawRoundTable()
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[4]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[4]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    ////glcolor3f(0.3,0,1);
    glTranslatef(6,2,6.5);

    drawCircle(2.2,0.1,0.2);
    
    glTranslatef(-6,-2,-6.5);


    // glTranslated(6,0,0);

    
}

void drawDinningTable(){

    drawRoundTable();

    glTranslatef(4,0,6);
    drawCube(0.2,2,0.2);
    glTranslatef(-4,0,-6);

    glTranslatef(4.2,0,8);
    drawCube(0.2,2,0.2);
    glTranslatef(-4.2,0,-8);

    glTranslatef(7.7,0,6);
    drawCube(0.2,2,0.2);
    glTranslatef(-7.7,0,-6);

    glTranslatef(7.5,0,8);
    drawCube(0.2,2,0.2);
    glTranslatef(-7.5,0,-8);
}




void drawChair(){


    glPushMatrix();

        glTranslatef(1.5,1,7);

        drawCube(0.1,2,2);

        glTranslatef(-1.5,-1,-7);

        glTranslatef(1.5,1,7);

        drawCube(1.3,0.1,2);

        glTranslatef(-1.5,-1,-7);

        // ////glcolor3f(1,0,1);

        glTranslatef(1.9,0,6.2);

        drawCube(0.2,1,0.2);

        glTranslatef(-1.9,0,-6.2);

        glTranslatef(2.0,0,6.1);

        drawCircle(0.4,0.1,0.2);
        
        glTranslatef(-2.0,0,-6.1);


        


    glPopMatrix();
}



void drawSetChair()
{   
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {1000};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[5]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[5]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glTranslatef(0.7,0,0.8);
    drawChair();
    glTranslatef(-0.7,0,-0.8);


    glPushMatrix();
    // glTranslatef(0,0,10);
    glRotatef(180,0,1,0);
    glTranslatef(-10,0,-12);


    drawChair();

    glRotatef(-180,0,1,0);
    glTranslatef(10,0,12);
    glPopMatrix();
    
     glPushMatrix();
    // glTranslatef(0,0,10);
    glRotatef(90,0,1,0);
    glTranslatef(-11,0,-1);


    drawChair();

    glRotatef(-90,0,1,0);
    glTranslatef(-11,0,-1);
    glPopMatrix();

    glRotatef(-90,0,1,0);
    glTranslatef(2,0,-11);


    drawChair();

    glRotatef(90,0,1,0);
    glTranslatef(2,0,-11);
    glPopMatrix();

}

void drawEatingTable()
{

    float x,y,z;
    x = -4.5;
    y = -4.5;
    z = -8;
glPushMatrix();
    glTranslatef(x,y,z);

    glTranslatef(-1,0,0);
        drawDinningTable();

    glTranslatef(-1,0,0);

glPopMatrix();

glPushMatrix();
    glTranslatef(x,y,z);

    drawSetChair();
glPopMatrix();
}


void drawDressingTable()
{   
    //base
        // glEnable(GL_TEXTURE_2D);
        push();
        te(texture[15]);
        glTranslatef(0,0,0);
        glScalef(5,4.4,4);
        drawCube(1, 1, 1);
        //base end

        // top
        // glEnable(GL_TEXTURE_2D);
        glTranslatef(0,0,0);
        glScalef(1,4,.1);
        drawCube(1, 1, 1);
        pop();
        td();
        // top end
        // glDisable(GL_TEXTURE_2D);
        te(texture[16]);
        //glass portion
        glPushMatrix();
        glTranslatef(0.1,5,-0.5);
        // glScalef(.8,.98,.1);
        drawCube(4.5, 12, 0.3);
        glPopMatrix(); 
        td();

}

void drawBed()
{
    te(texture[13]);
    push();
        gt(3,0,-13.5);
        drawCube(20,3,13);
    pop();
    td();
    te(texture[7]);
    push();
        gt(2,0,-13.5);
        drawCube(1,6,13);
    pop();
    td();
    te(texture[14]);
    push();
        gt(5.5,4,-14.5);
        push();
        // push();
        gr(160,0,0,1);
        drawCube(2,1,4);
    // pop();
        pop();
    pop();
    push();
        gt(5.5,4,-20);
        push();
        // push();
        gr(160,0,0,1);
        drawCube(2,1,4);
    // pop();
        pop();
    pop();
    td();
    te(texture[12]);
    push();
        gt(40,0,-38);
        drawCube(15,14,2);
    pop();
    td();
    te(texture[17]);
    push();
        gt(69.5,4,-17);
        drawCube(0.5,8,12);
    pop();
    td();
    push();
        gt(5,0,-39);
        gs(1,0.7,-1); 
        drawDressingTable();
    pop();
}

void drawBedRoom()
{
    push();
        drawBed();
    pop();

}







/// draw fan



void drawFanStand(float fan_height)
{
    drawCircle(0.2,fan_height,0.2);
}



void drawPreFanBlade()
{
     glPushMatrix();
        glTranslatef(0,7,0);
    glTranslatef(0,0,0.8);

        glRotatef(30+theta,0,0,1);
        drawCube(2,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(150+theta,0,0,1);
        drawCube(2,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(270+theta,0,0,1);
        drawCube(2,0.5,0.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0.8);
    

        glTranslatef(0,7,0);
        glRotatef(90,1,0,0);
        drawCircle(0.5,0.2,0.2);
        glTranslatef(0,-1,0);
        drawCircle(0.1,0.8,0.2);

    glPopMatrix();
}

void drawFanBlade()
{   

    glPushMatrix();
    // glRotatef(90,0,0,0);
    // glRotatef(45, 0,0,1);
    glRotatef(alpha, 0, yaxis, 0);
    drawPreFanBlade();
    glPopMatrix();
}

void drawFanCover2()
{
    for(int i = 0; i < 360; i+= 30)
    {
        glPushMatrix();
            glRotatef(i, 0, 0, 1);
            drawCube(2.3, 0.1,0.1);
            glTranslatef(2.3,0,0);
            glRotatef(103,0,0,1);
            // drawCube(1.2, 0.1,1);
            glScalef(1.2,0.1,1);

            drawCube(1,1,1);

        glPopMatrix();
    }

    

    
}

void drawFanCover2_2()
{
    for(int i = 0; i < 360; i+= 30)
    {
        glPushMatrix();
            glRotatef(i, 0, 0, 1);
            drawCube(2.3, 0.1,0.1);
            // glTranslatef(2.3,0,0);
            // drawCube(0.1, 0.1,0.9);

        glPopMatrix();
    }

    

    
}

void drawFanCover1()
{
    glPushMatrix();
    glTranslatef(0,fan_height-0.5,1.2);
    drawFanCover2();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,fan_height-0.5,0.3);
    drawFanCover2_2();
    glPopMatrix();
}


void drawFanCover()
{
    
    glPushMatrix();
    glRotatef(alpha, 0, yaxis, 0);

        drawFanCover1();
        // drawCube(7.5, 0.2,0.2);
    glPopMatrix();
}



void drawPreFan(float fan_height)
{
    // glTranslatef
    drawFanStand(fan_height);
    glPushMatrix();
    // glTranslatef(0,0,1);
    glTranslatef(0,fan_height-7.5,0);
    drawFanBlade();
    drawFanCover();
    // glTranslatef(0,0,-1);
    glPopMatrix();
}

void drawFan(float fan_height)
{

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};
    GLfloat m_no[] = {0, 0, 0, 1.0};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse[6]);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, m_no);
    glTranslatef(0,0,-4);
   drawPreFan(fan_height);
    glTranslatef(0,0,4);

}




/// dinning table end










//============= drawing doors =======================



// controlling angle of inside house doors
float door_1_angle = 0;
float door_2_angle = 0;
float door_3_angle = 0;
float door_4_angle = 0;
float door_5_angle = 0;
float door_6_angle = 0;
float door_7_angle = 0;
float door_8_angle = 0;
float door_9_angle = 0;
int door_pos = 0;


// doors state on/off
bool door_1_stat = false;
bool door_2_stat = false;
bool door_3_stat = false;
bool door_4_stat = false;
bool door_5_stat = false;
bool door_6_stat = false;
bool door_7_stat = false;
bool door_8_stat = false;
bool door_9_stat = false;
bool door_10_stat = true;




void drawDoor_1(bool x, float& angle, bool pp = true) // door rotation : z to x axis
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
            angle+=1;
        } 
        else
        {
            if(angle > 0)
                angle-=1;
        }
        
    pop();
}

void drawDoor_2(bool x, float& angle, bool pp = true) // door rotation : z to -x axis
{
    push();
        // if(door_1_stat)
        glRotatef(angle,0,1,0);
        if(pp){
            glScalef(1,1,-1);
        }
        drawCube(1,15,9);
        if(x)
        {
            if(angle < 85)
            angle+=1;
        } 
        else
        {
            if(angle > 5)
                angle-=1;
        }
        
    pop();
}

void drawDoor_3(bool x, float& angle, bool pp = true) // half of main gate of the builing... rotation: z to x axis
{
    push();
        // if(door_1_stat)
        glRotatef(angle,0,1,0);
        if(pp){
            glScalef(1,1,-1);
        }
        drawCube(1,15,9);
        if(!x)
        {
            if(angle < -5)
            angle+=1;
        } 
        else
        {
            if(angle > -85)
                angle-=1;
        }
        
    pop();
}

void drawDoor_4(bool x, float& angle, bool pp = true) // half of main gate of the builing... rotation: -z to x axis
{
    push();
        // if(door_1_stat)
        glRotatef(angle,0,1,0);
        if(pp){
            glScalef(1,1,-1);
        }
        drawCube(10,7,1);
        if(x)
        {
            if(angle < 90)
            angle+=1;
        } 
        else
        {
            if(angle > 0)
                angle-=1;
        }
        
    pop();
}


void doors() // inside doors
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

void door2() // building main doors
{
    te(texture[21]);
        push();
            gt(-1,0,-49.5);
            drawDoor_2(door_6_stat, door_6_angle);
        pop();
        push();
            gt(-1,0,-31);
            drawDoor_3(door_6_stat, door_7_angle, false);
        pop();
    td();
}


void door3() // outside main door
{
    push();
        // gr(90,0,1,0);
        push();
        drawDoor_4(door_8_stat, door_8_angle);
        pop();
    pop();
}

void door4() // sliding door front of the garadge
{
    push();
    if(door_10_stat)
    {
        if(door_pos <= 0)
        {
            door_pos+=1;
        }
    }
    else
    {
        if(door_pos >= -36)
        {
            door_pos-=1;
        }
    }
    gt(door_pos, 0, 0);
    push();
        drawCube(36,8,1);
    pop();
    pop();
}


// ================ door drawing ended =============



// =============== drawing elemnts in the rooms and building ==================

void draw_extraWalls() // extra walls for filling tha gaps after translating the ground floor to first floor
{
    push();
        gt(0,0,-170);
        drawCube(22,15,1);
    pop();
    
    push();
        gt(0,0,-30);
        drawCube(60,15,1);
    pop();

    push();
        gt(59,0,-30);
        drawCube(1,15,60);
    pop();
}

void drawBathtub_pre()
{
    push();
        drawCube(12,1,5);
        drawCube(0.2,4,5);
        drawCube(12,4,0.2);
        gt(0,0,-5);
        drawCube(12,4,0.2);
        gt(12,0,5);
        drawCube(0.2,4,5);
    pop();
}

void drawBathtub()
{
    push();
        // gs(1.3,1,0.9);
        drawBathtub_pre();
    pop();
}


void drawWashroom()
{
    push();
        gt(1,0,-34);
        drawBathtub();
    pop();
    
}


void drawReadingTable()
{
    te(texture[15]);
    push();
        gt(0,3,0);
        drawCube(5,0.5,8);
    pop();
    push();
        drawCube(1,3,1);
    pop();
    push();
        gt(4,0,0);
        drawCube(1,3,1);
    pop();
    push();
        gt(0,0,-7);
        drawCube(1,3,1);
    pop();
    push();
        gt(4,0,-7);
        drawCube(1,3,1);
    pop();
    td();
}

void drawReadingChair()
{
    te(texture[15]);
    push();
        gt(0,2,0);
        drawCube(3,0.2,3);
    pop();
    push();
        gt(2.8,2,0);
        drawCube(0.2,2,3);
    pop();
    push();
        drawCube(0.4,2,0.4);
    pop();
    push();
        gt(2.6,0,0);
        drawCube(0.4,2,0.4);
    pop();
    push();
        gt(2.6,0,-2.6);
        drawCube(0.4,2,0.4);
    pop();
    push();
        gt(0,0,-2.6);
        drawCube(0.4,2,0.4);
    pop();
    td();
}

void drawReading_chair_table()
{
    push();
        gt(0,0,-15);
        drawReadingTable();
    pop();
    push();
        gt(4,0,-17.5);
        drawReadingChair();
    pop();
}


void drawBookshelf()
{
    te(texture[18]);
    push();
        drawCube(8,5,1);
    pop();
    td();
}

void drawBooks()
{
    // gt(0,20,0);

    te(texture[19]);
    push();
        gt(1.3,1,0);
        gr(90,0,1,0);
        drawCube(2,0.1,1.3);
    pop();
    // td();
    te(texture[19]);
    push();
        drawCube(1.3,1,2);
    pop();
    // td();
}

void drawReadingRoom()
{
    gt(-39,0,0);
    
    push();
        // gt(-31,0,0);
        drawReading_chair_table();
    pop();
    push();
        gt(38,0,-15);
        gs(-1,1,1);
        drawReading_chair_table();
    pop();

    push();
        gt(15,0,-38);
        drawBookshelf();
    pop();

    push();
        // gt(-31,0,0);

        gt(0,3,-17.5);
        drawBooks();
    pop();
}



void drawHome2(int p = 0)
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1, 1, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    // rooms start
    push();
        gt(-70,0,-130);
        // drawBathtub();
        drawWashroom();
        te(texture[9]);
        drawRoom1(1, texture[8]);
    pop();
    push();
        gt(-70,0,-90);
        drawBedRoom();
        te(texture[9]);
        drawRoom1();

    pop();
    push();
        gt(-70,0,-50);
        drawRoom1();
        // push();
        //     gt(2,3,-20);
        //     glutSolidSphere(1,100,100);

        // pop();
        td();
        push();
            gt(15,0,-30);
            gr(50,0,1,0);
            push();
                drawFan(fan_height);
            pop();
        pop();
    pop();
    disable_mat();
    te(texture[9]);
    push();
        gt(60,0,-130);
        push();
        if(p)
        drawReadingRoom();
        pop();
        te(texture[9]);

        drawRoom2();
        
    pop();
    te(texture[9]);
    push();
        gt(60,0,-90);
        drawRoom2();
    pop();


    // extra walls

    // draw_extraWalls();

    td();

    // disable_mat();

    te(texture[7]);
    push();
        drawSofas();
    pop();
    td();

    push();
        gt(39,9,-105);
        gs(3,1.5,3);
        drawEatingTable();
        disable_mat();
    pop();

    

    push();
        doors();
    pop();
    
}


void first_floor()
{
    te(texture[6]);
    push();
        gt(-75,0,-25);
        drawCube(145,2,155);
    pop();
    push();
        gt(-75,30,-25);
        drawCube(145,2,155);
    pop();
    td();

    push();
        gt(0,2,0);
        drawHome2();
        te(texture[9]);
        draw_extraWalls();
        td();
    pop();


}


void drawStairs()
{
    push();
    gt(41,0,-34);
    push();
    for(int i = 0; i < 8; i++)
    {
        gt(1,1,0);
        drawCube(1,1,10);    
    }
    drawCube(10,1,10);
    gt(0,0,-8);
    for(int i = 0; i < 8; i++)
    {
        gt(0,1,-1);
        drawCube(10,1,1);
    }
    pop();
    pop();
}

void second_floor()
{
    te(texture[6]);
    push();
        gt(-70,0,-31);
        drawCube(90,2,140);
        gt(90,0,-20);
        drawCube(40,2,120);
    pop();
    td();

    push();
        gt(0,2,0);
        drawHome2(1);
        te(texture[9]);
        gt(-10,0,0);
        glScalef(-1,1,1);
        draw_extraWalls();
        td();
    pop();
    te(texture[9]);
    push();
        gt(0,15,-170);
        drawCube(22,15,1);
    pop();
    td();
    push();
        drawStairs();
    pop();
}

// ===================== building drawing ended ===========







// ================ drawing special type of road to show the specular light speciality
void drawRoad_unit()
{
    push();
    for(int i = 0; i < 6; i++)
    {
        gt(0,0,1);
        drawCube(1,1,1);
    }
    pop();
}

void drawRoad_strip_unit_w()
{
    GLfloat mat_ambient[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    // GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    push();
        for(int i = 0; i < 10; i++)
        {   
            gt(1,0,0);
            drawCube(1,1,1);
        }
    pop();
}
void drawRoad_strip_unit_b()
{
    GLfloat mat_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat mat_specular[] = { 0.4, 0.4, 0.4, 1.0 };
    // GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    push();
        for(int i = 0; i < 10; i++)
        {   
            gt(1,0,0);
            drawCube(1,1,1);
        }
    pop();
}

void drawRoad_strip()
{
    push();
        for(int i = 0; i < 10; i++)
        {
            drawRoad_strip_unit_w();
            gt(10,0,0);
            drawRoad_strip_unit_b();
            gt(10,0,0);
        }
    pop();
}

void drawRoad_one_side()
{
    GLfloat mat_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat mat_diffuse[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat mat_specular[] = { 0.3, 0.3, 0.3, 1.0 };
    // GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    // glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    push();
        for(int i = 0; i < 200; i++)
        {
            gt(1,0,0);
            drawRoad_unit();
        }
    pop();
}

void drawRoad()
{
    push();
    gt(-100,0,1);
        
        drawRoad_one_side();
        gt(0,0,7);
        drawRoad_strip();
        // gt(0,0,1);
        drawRoad_one_side();
    pop();
    disable_mat();

}

// ========== road drawing ended ========================






// =================== windows drawing ===========================

float win_1_pos = 0;
float win_2_pos = 0;
float win_3_pos = 0;
float win_4_pos = 0;
float win_5_pos = 0;
float win_6_pos = 0;
float win_7_pos = 0;
float win_8_pos = 0;
float win_9_pos = 0;
float win_10_pos = 0;




void drawWindow_l()
{
    push();
        drawCube(0.2,8,5);
    pop();
    
}


void drawWindow_r()
{
    push();
        gt(0.2,0,-5);
        drawCube(0.2,8,5);
    pop();
}

void drawWindow_l_f()
{
    push();
        drawCube(10,8,0.2);
    pop();
    
}


void drawWindow_r_f()
{
    push();
        gt(10,0,-0.2);
        drawCube(10,8,0.2);
    pop();
}


void drawWindowLarge_1()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_1_pos);
        drawWindow_r();
    pop();
}
void drawWindowLarge_2()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_2_pos);
        drawWindow_r();
    pop();
}
void drawWindowLarge_3()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0,0,win_3_pos);
        drawWindow_r();
    pop();
}
void drawWindowLarge_4()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_4_pos);
        drawWindow_r();
    pop();
}
void drawWindowLarge_5()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_5_pos);
        drawWindow_r();
    pop();
}
void drawWindowLarge_6()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_6_pos);
        drawWindow_r();
    pop();
}
void drawWindowLarge_7()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_7_pos);
        drawWindow_r();
    pop();
}

void drawWindowLarge_8()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_8_pos);
        drawWindow_r();
    pop();
}

void drawWindowLarge_9()
{
    push();
        drawWindow_l();
    pop();
    push();
        gt(0, 0, win_9_pos);
        drawWindow_r();
    pop();
}

void drawWindowLarge_10()
{

    push();
        drawWindow_l_f();
    pop();
    push();
        gt(win_10_pos, 0, 0);
        drawWindow_r_f();
    pop();
}


void drawWindows()
{
    push();
        gt(-70,21,-105);
        drawWindowLarge_1();
    pop();
    push();
        gt(-70,21,-145);
        drawWindowLarge_2();
    pop();
    push();
        gt(-70,6,-105);
        drawWindowLarge_3();
    pop();
    push();
        gt(-70,6,-145);
        drawWindowLarge_4();
    pop();
    push();
        gt(60, 21, -105);
        drawWindowLarge_5();
    pop();
    push();
        gt(60, 21, -145);
        drawWindowLarge_6();
    pop();
    push();
        gt(60, 6, -105);
        drawWindowLarge_7();
    pop();
    push();
        gt(60, 6, -145);
        drawWindowLarge_8();
    pop();
    push();
        gt(-70,6,-65);
        drawWindowLarge_9();
    pop();
    push();
        gt(-45, 6, -50);
        drawWindowLarge_10();
    pop();
}

// ===================== windows drawing ended ====================






// ================== car =============================
void car()
{
	glPushMatrix();
	// glTranslatef(x, y, z);
		//the load part
		glPushMatrix();
			glColor3ub(220, 10, 10);
			glTranslatef(1.0, 0.5, 10);
			glScalef(1, 0.4, 2.0);
			glutSolidCube(1);
		glPopMatrix();
		//cabin
		glPushMatrix();
			glColor3ub(10, 10, 220);
			glTranslatef(1.0, 0.8, 10.5);
			glScalef(0.5, 0.4, 0.7);
			glutSolidCube(1);
		glPopMatrix();
		//lights
		glPushMatrix();
			glColor3ub(220, 220, 10);
			glTranslatef(.6, 0.7, 9);
			//glScalef(0.5, 0.4, 0.7);
			glutSolidSphere(0.1, 12, 12);
		glPopMatrix();
		glPushMatrix();
			glColor3ub(220, 220, 10);
			glTranslatef(1.2, 0.7, 9);
			//glScalef(0.5, 0.4, 0.7);
			glutSolidSphere(0.1, 12, 12);
		glPopMatrix();
		
		glPushMatrix();
			glColor3ub(107, 107, 249);
			glTranslatef(0.5, 0.35, 9);
			glRotatef(90, 0, 1, 0);
			glScalef(0.2, 0.2, 0.2);
			glutSolidTorus(0.4, 1, 15, 30);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.5, 0.35, 9);
			glRotatef(90, 0, 1, 0);
			glScalef(0.2, 0.2, 0.2);
			glutSolidTorus(0.4, 1, 15, 30);
		glPopMatrix();
		//back wheels
		glPushMatrix();
			glTranslatef(0.5, 0.35, 11);
			glRotatef(90, 0, 1, 0);
			glScalef(0.2, 0.2, 0.2);
			glutSolidTorus(0.4, 1, 15, 30);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.5, 0.35, 11);
			glRotatef(90, 0, 1, 0);
			glScalef(0.2, 0.2, 0.2);
			glutSolidTorus(0.4, 1, 15, 30);
		glPopMatrix();
	glPopMatrix();
}

void drawVehicles()
{
    push();
        gt(70,1,6);
        gs(4,4,3);
        push();
        gr(180,0,1,0);
        push();
        car();
        pop();
        pop();
    pop();
    
}


// ================== drawing car ended =============================




// =============== drawing tree and street lamp light object =============
void tree()
{
    GLfloat m_amb[] = {0.000, 0.392, 0.000,1};
    GLfloat m_diff[] = {0.000, 0.392, 0.000,1};
    GLfloat m_spec[] = {0.000, 0.392, 0.000,1};
    GLfloat m_sh[] = {30};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);

    /// root
    glPushMatrix();
        glTranslated(11, 0, -17);
        glRotated(90, -1, 0, 0);
        glBegin(GL_POLYGON);
            GLUquadricObj *roo_obj = gluNewQuadric();
            gluCylinder(roo_obj, 0.3, 0.3, 9.0, 300.0, 300.0);
        glEnd();
    glPopMatrix();
    /// branch
    glPushMatrix();
        glTranslated(11, 8.0, -17);
        glRotated(90, -1, 0, 0);
        glutSolidCone(2.5, 4.0, 300, 300);
    glPopMatrix();
    glPushMatrix();
        glTranslated(11, 10.5, -17);
        glRotated(90, -1, 0, 0);
        glutSolidCone(2.5, 4.0, 300, 300);
    glPopMatrix();
}


void drawTree()
{
    push();
    gs(2,2,2);
    push();
        gt(-55,0,-10);
        tree();
    pop();

    push();
        gt(-65,0,-10);
        tree();
    pop();
     push();
        gt(-55,0,-2);
        tree();
    pop();

    push();
        gt(-65,0,-2);
        tree();
    pop();
    pop();
    disable_mat();
}



void streetlight()
{
    push();
        drawCircle(0.25,15,0.25);
    pop();    
    push();
        gt(-0.5,15,5);
        drawCube(1,0.5,5);
    pop();

}

// ====================================================================================================================
// ====================================================================================================================



void display(){


    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (eyex, eyey, eyez, x+dx, y+dy, z+dz, xaxis, yaxis, zaxis);
    
    push();
        gs(1.5,1,1.5);
        drawOutside();
    pop();

    push();
        gt(-40,15,0);
        light();
    pop();

    push();
        first_floor();
    pop();

    push();
        gt(0,15,0);
        second_floor();
    pop();

    push();
        gt(-64,0,-34);
        drawCircle(2,16,2);
    pop();

    push();
        door2();
    pop();

    push();
        drawTree();
    pop();

    // fench doors  
    te(texture[15]);
        push();
            push();
                gt(-9,0,-7.2);
                door3();
            pop();
        pop();


        push();
            gt(80,0,-7.2);
            door4();
        pop();
    td();
    /////////////////////



    // drawLightpostion

    push();
        drawLights();
    pop();

    //streetlight
    
    push();
        streetlight();
    pop();
    push();
        gt(-65,0,0);
        streetlight();
    pop();
    push();
        gt(65,0,0);
        streetlight();
    pop();



    te(texture[4]);
        push();
            push();
                gt(80,0,-30);
                push();
                    gs(0.5,1,0.5);
                    drawRoom3();
                pop();
            pop();
            push();
                gt(80,15,-30);
                drawCube(35,1,20);
            pop();
        pop();
    td();



    


    //front fench
    push();
        push();
            gt(-141,0,-8);
            gs(1,3,1);
            drawFench(64);
        pop();
        push();
            gt(0,0,-8);
            gs(1,3,1);
            drawFench(38);
        pop();
        push();
            gt(114,0,-8);
            gs(1,3,1);
            drawFench(11);
        pop();
    pop();


    push();
        gs(1.5,1,1.5);
        push();
            drawVehicles();
        pop();
        drawRoad();
    pop();

    push();
        te(texture[20]);
        gt(-500,-1,0);
        
        push();
            for(int i = 0; i < 50; i++)
            {
                push();
                for(int j = 0; j < 50; j++)
                {
                    
                    drawCube(20,1,20);
                    gt(20,0,0);

                }
                pop();
                gt(0,0,-20);
            }
        pop();


        td();
    pop();


    push();
        transparent_mat();
            push();
                gt(-70,0,-130);

                gt(0,0,-25);
                drawCube(20,12,0.2);
                gt(20,0,0);
                drawCube(0.2,12,15);
            pop();
            push();
                gt(-70,15,-130);

                gt(0,0,-25);
                drawCube(20,12,0.2);
                gt(20,0,0);
                drawCube(0.2,12,15);
            pop();
        disable_mat();
    pop();

    disable_mat();

    te(texture[11]);
    push();
        gt(-500,0,-300);
        glScalef(1000,500,1);
        drawCube(1,1,1);
    pop();
    push();
        gt(500,0,-300);
        // glScalef(1000,500,1);
        push();
        glRotatef(-60, 0, 1, 0);
        push();
        drawCube(1000,500,1);
        pop();
        pop();
    pop();
    push();
        gt(-500,0,-300);
        // glScalef(1000,500,1);
        push();
        glRotatef(210, 0, 1, 0);
        push();
        drawCube(1000,500,1);
        pop();
        pop();
    pop();
    td();




    push();
        transparent_mat();
        push();
        drawWindows();
        pop();
        push();
            gt(-10,15,-30);
            drawCube(70,15,1);
        pop();
        push();
            gt(59,15,-30);
            drawCube(1,15,62);
        pop();
    pop();

    disable_mat();

    glFlush();
    glutSwapBuffers();
    
}





int f_light = 1;
int f_view = 0;
int f_fan = 0;
int f_door = 0;
int f_window = 0;

float back_eyex = 0;
float back_eyey = 0;
float back_eyez = 0;
float back_dx =   0;
float back_dy =   0;
float back_dz =   0;
float back_x =    0;
float back_y =    0;
float back_z =    0;

float roll = 0;

int mm = 1;




void myKeyboardFunc( unsigned char key, int x, int y )
{
    // cout << key << endl;
    if(key == '!')
    {
        f_light = 1;
        f_view = 0;
        f_fan = 0;
        f_door = 0;
        f_window = 0;
    }
    else if(key == '@')
    {
        f_light = 0;
        f_view = 1;
        f_fan = 0;
        f_door = 0;
        f_window = 0;
    }
    else if(key == '#')
    {
        f_light = 0;
        f_view = 0;
        f_fan = 1;
        f_door = 0;
        f_window = 0;
    }
    else if(key == '$')
    {
        f_light = 0;
        f_view = 0;
        f_fan = 0;
        f_door = 1;
        f_window = 0;
    }
    else if(key == '%')
    {
        f_light = 0;
        f_view = 0;
        f_fan = 0;
        f_door = 0;
        f_window = 1;
    }
    else
    {    
        if(f_light)
        {
            f_view = 0;
            f_fan = 0;
            f_door = 0;
            cout << "light" << endl;
            
            switch (key)
            {
                // modes begin
                case '!':
                    f_light = 1 - f_light;
                    break;
                case '@':
                    f_view = 1 - f_view;
                    break;
                case '#':
                    f_fan = 1 - f_fan;
                    break;
                case '$':
                    f_door = 1-f_door;
                    break;
                //modes ends

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
                case '6':
                    l_6 = l_6-1;
                    break;
                case '7':
                    l_7 = l_7-1;
                    break;
                case '8':
                    l_8 = l_8-1;
                    break;
                case '9':
                    up_light = 1-up_light;
                    break;
                case 'w':
                    cc-=1;
                    // zz = 
                    break;
                case 's':
                    cc+=1;
                    break;
                case 'a':
                    zz-=1;
                    break;
                case 'd':
                    zz +=1;
                    break;
                case 'y':
                    xx+=1;
                    break;
                case 'Y':
                    xx-=1;
                    break;
                case 'q':
                    spt_cutoff++;
                    break;
                case 'Q':
                    spt_cutoff--;
                    break;
                default:
                    break;
            }
        }

        if(f_view)
        {
            cout << "view" << endl;
            
            f_light = 0;
            // f_view = 1;
            f_fan = 0;
            f_door = 0;
            switch (key)
            {
            // modes begin
                case '!':
                    f_light = 1 - f_light;
                    break;
                case '@':
                    f_view = 1 - f_view;
                    break;
                case '#':
                    f_fan = 1 - f_fan;
                    break;
                case '$':
                    f_door = 1-f_door;
                    break;
                case '%':
                    f_window = 1-f_window;
                    break;
            //modes ends

                //roll
                case 'c':
                    roll+=0.1;
                    xaxis = cos(roll);
                    yaxis= sin(roll);

                    // cout<<"x :"<<x <<"y:"<<y<<"z:"<<z<<endl;

                    break;
                case 'C':
                    roll-=0.1;

                    xaxis = cos(roll);
                    yaxis= sin(roll);
            
                case '=':
                    eyez-=abs(eyez-z-dz)/100;
                    eyey-=abs(eyey-y-dy)/100;
                    // p_zoom++;
                    // s_zoom+=0.1;
                    break;
                case '-':
                    eyez+=abs(eyez-z-dz)/100;
                    eyey+=abs(eyey-y-dy)/100;
                    // p_zoom--;
                    // s_zoom-=0.1;
                    break;
                //yaw
                case 'd':
                    // y=y;
                    dx += 0.5;
                    break;

                case 'a':
                    // y=y;
                    dx -= 0.5;
                    break;
                //pitch
                case 'w':
                    // x=x;
                    dy += 0.5;
                    break;
                case 's':
                    // x=x;
                    dy -= 0.5;
                    break;

                case 'p':
                    cout << "eyex = " << eyex << ";" << endl;
                    cout << "eyey = " << eyey << ";" << endl;
                    cout << "eyez = " << eyez << ";" << endl;

                    cout << "dx = " << x+dx << ";" << endl;
                    cout << "dy = " << y+dy << ";" << endl;
                    cout << "dz = " << z+dz << ";" << endl;

                    cout << "dx = " << dx << ";" << endl;
                    cout << "dy = " << dy << ";" << endl;
                    cout << "dz = " << dz << ";" << endl;

                    cout << "zz = " << zz << endl;
                    cout << "xx = " << xx << endl;
                    cout << "cc = " << cc << endl;
                    cout << "spt_cutoff = " << spt_cutoff << endl;
                    break;
                

                case 'b':
                    eyex = back_eyex;
                    eyey = back_eyey;
                    eyez = back_eyez;
                    dx = back_dx;
                    dy = back_dy;
                    dz = back_dz;
                    x = back_x;
                    y = back_y;
                    z = back_z;
                    mm = 1;
                    break;

                case 't':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }
                    
                    eyex = 0;
                    eyey = 200;
                    eyez = -39;

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -40;
                    break;
                case 'l':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = -180;
                    eyey = 15;
                    eyez = -100;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -101;
                    break;
                case 'r':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = 250;
                    eyey = 15;
                    eyez = -100;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -101;
                    break;

                case '1':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = -36;
                    eyey = 13;
                    eyez = -51;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -93;
                    break;

                case '2':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = -36;
                    eyey = 13;
                    eyez = -91;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -133;
                    break;

                    case '3':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = -36;
                    eyey = 13;
                    eyez = -131;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -173;
                    break;

                    case '4':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = 37;
                    eyey = 13;
                    eyez = -131;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -173;
                    break;

                    case '5':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = 37;
                    eyey = 13;
                    eyez = -91;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -133;
                    break;

                case '6':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = -36;
                    eyey = 28;
                    eyez = -51;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -93;
                    break;

                case '7':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = -36;
                    eyey = 28;
                    eyez = -91;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -133;
                    break;

                    case '8':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = -36;
                    eyey = 28;
                    eyez = -131;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -173;
                    break;

                    case '9':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = 37;
                    eyey = 28;
                    eyez = -131;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -173;
                    break;

                    case '0':
                    if(mm)
                    {
                        back_eyex = eyex;
                        back_eyey = eyey;
                        back_eyez = eyez;
                        back_dx =   dx;
                        back_dy =   dy;
                        back_dz =   dz;
                        back_x =    x;
                        back_y =    y;
                        back_z =    z;
                        
                        mm = 0;
                    }

                    eyex = 37;
                    eyey = 28;
                    eyez = -91;    

                    x = 0, dx = 0, y = 0, dy = 0, z = 0, dz = 0;
                    dx = 0;
                    dy = 0;
                    dz = -133;
                    break;

                    

            default:
                break;
            }
        }
        if(f_fan)
        {
                cout << "fan" << endl;

            f_light = 0;
            f_view = 0;
            // f_fan = 0;
            f_door = 0;
            switch (key)
            {
            // modes begin
                case '!':
                    f_light = 1 - f_light;
                    break;
                case '@':
                    f_view = 1 - f_view;
                    break;
                case '#':
                    f_fan = 1 - f_fan;
                    break;
                case '$':
                    f_door = 1-f_door;
                    break;
                case '%':
                    f_window = 1-f_window;
                    break;
            //modes ends
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
                case 'g':
                    uRotate = !uRotate;
                    // bRotate = false;
                    axis_x=1.0;
                    axis_y=0;
                    break;    
                case '1':
                    if(bRotate)
                    {
                        fan_angle = 5;
                    }
                    break;
                case '2':
                    if(bRotate)
                    {
                        fan_angle = 9;
                    }
                    break;
                case '3':
                    if(bRotate)
                    {
                        fan_angle = 13;
                    }
                    break;
            
            default:
                break;
            }
        }

        if(f_door)
        {
            f_light = 0;
            f_view = 0;
            f_fan = 0;
            // f_door = 0;
            switch (key)
            {
            // modes begin
                case '!':
                    f_light = 1 - f_light;
                    break;
                case '@':
                    f_view = 1 - f_view;
                    break;
                case '#':
                    f_fan = 1 - f_fan;
                    break;
                case '$':
                    f_door = 1-f_door;
                    break;
                case '%':
                    f_window = 1-f_window;
                    break;
            //modes ends
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
                case 'b':
                    door_6_stat = 1- door_6_stat;
                    break;
                case 'n':
                    door_8_stat = 1- door_8_stat;
                    break;
                case 'm':
                    door_10_stat = 1- door_10_stat;
                    break;

            default:
                break;
            }
        }

        if(f_window)
        {
            switch (key)
            {
            // modes begin
                case '!':
                    f_light = 1 - f_light;
                    break;
                case '@':
                    f_view = 1 - f_view;
                    break;
                case '#':
                    f_fan = 1 - f_fan;
                    break;
                case '$':
                    f_door = 1-f_door;
                    break;
                case '%':
                    f_window = 1-f_window;
                    break;
            //modes ends
                case 'q':
                if(win_1_pos > 0)
                win_1_pos--;
                    break;
                case 'Q':
                if(win_1_pos < 5)
                win_1_pos++;
                    break;

                case 'w':
                if(win_2_pos > 0)
                win_2_pos--;
                    break;
                case 'W':
                if(win_2_pos < 5)
                win_2_pos++;
                    break;

                case 'e':
                if(win_3_pos > 0)
                win_3_pos--;
                    break;
                case 'E':
                if(win_3_pos < 5)
                win_3_pos++;
                    break;

                case 'r':
                if(win_4_pos > 0)
                win_4_pos--;
                    break;
                case 'R':
                if(win_4_pos < 5)
                win_4_pos++;
                    break;

                case 't':
                if(win_5_pos > 0)
                win_5_pos--;
                    break;
                case 'T':
                if(win_5_pos < 5)
                win_5_pos++;
                    break;
                
                case 'y':
                if(win_6_pos > 0)
                win_6_pos--;
                    break;
                case 'Y':
                if(win_6_pos < 5)
                win_6_pos++;
                    break;

                case 'u':
                if(win_7_pos > 0)
                win_7_pos--;
                    break;
                case 'U':
                if(win_7_pos < 5)
                win_7_pos++;
                    break;
                
                case 'i':
                if(win_8_pos > 0)
                win_8_pos--;
                    break;
                case 'I':
                if(win_8_pos < 5)
                win_8_pos++;
                    break;

                case 'o':
                if(win_9_pos > 0)
                win_9_pos--;
                    break;
                case 'O':
                if(win_9_pos < 5)
                win_9_pos++;
                    break;

                case 'a':
                if(win_10_pos > -10)
                win_10_pos--;
                    break;
                case 'A':
                if(win_10_pos < 0)
                win_10_pos++;
                    break;
            default:
                break;
            }
        }
    }

}


// ======================================== collision detection implementations =================

bool z_move(float x, float y, float z,int p)
{
    if(p)
    z = z-1;
    else
    z = z+1;
    bool k1 = !(x > -72 && x < 63 && y > 14 && y < 35 && z < -28 && z > -31);
    // bool k1 = !(x > -72 && x < -9 && y > 14 && y < 35 && z < -28 && z > -31);
    bool k2 = !(x > -72 && x < 2 && y > 14 && y < 35 && z < -48 && z > -51);
    bool k3 = !(x > -72 && x < 2 && y > 14 && y < 35 && z < -88 && z > -91);
    bool k4 = !(x > -72 && x < 2 && y > 14 && y < 35 && z < -128 && z > -131);
    bool k5 = !(x > -72 && x < 2 && y > 14 && y < 35 && z < -167 && z > -171);

    bool k6 = !(x > 19 && x < 61 && y > 14 && y < 35 && z < -88 && z > -91);
    bool k7 = !(x > 19 && x < 61 && y > 14 && y < 35 && z < -128 && z > -131);
    bool k8 = !(x > -72 && x < 63 && y > 0 && y < 35 && z < -168 && z > -171);



    // bool k1 = !(x > -72 && x < -9 && y > 0 && y < 15 && z < -28 && z > -31);
    bool k9 = !(x > -72 && x < 2 && y > 0 && y < 15 && z < -48 && z > -51);
    bool k10 = !(x > -72 && x < 2 && y > 0 && y < 15 && z < -88 && z > -91);
    bool k11 = !(x > -72 && x < 2 && y > 0 && y < 15 && z < -128 && z > -131);
    bool k12 = !(x > -72 && x < 2 && y > 0 && y < 15 && z < -167 && z > -171);

    bool k13 = !(x > 19 && x < 61 && y > 0 && y < 15 && z < -88 && z > -91);
    bool k14 = !(x > 19 && x < 61 && y > 0 && y < 15 && z < -128 && z > -131);
    bool k15 = !(x > 19 && x < 61 && y > 0 && y < 15 && z < -168 && z > -171);
    bool k16 = !(x > -1 && x < 63 && y > 0 && y < 15 && z < -28 && z > -31);

    //outside

    bool k17 = !(x > -141 && x < 140 && y > 0 && y < 10 && z < -280 && z > -285);
    bool k18 = !(x > -141 && x < 1 && y > 0 && y < 10 && z < -4 && z > -7);
    bool k19 = !(x > -141 && x < -9 && y > 0 && y < 10 && z < -4 && z > -7);

    bool k20 = !(x > 0 && x < 117 && y > 0 && y < 10 && z < -4 && z > -7);
    bool k21 = !(x > 0 && x < 81 && y > 0 && y < 10 && z < -4 && z > -7);
    bool k22 = !(x > 117 && x < 137 && y > 0 && y < 10 && z < -4 && z > -7);


    if(door_8_stat)
        k18 = 1;
    if(door_10_stat)
        k20 = 1;


    return k1 && k2 && k3 && k4 && k5 && k6 && k7 && k8 && k9 && k10 && k11 && k12 && k13 && k14 && k15 && k16 && k17 && k18 && k19 && k20 &&\
    k21 && k22;
}

bool x_move(float x, float y, float z, int p)
{
    if(p)
    x = x-1;
    else
    x = x+1;
    bool k1 = !(x > -73 && x < -67 && y > 0 && y < 35 && z < -48 && z > -171);
    bool k2 = !(x > -73 && x < -67 && y > 14 && y < 35 && z < -28 && z > -171);
    bool k3 = !(x > 58 && x < 63 && y > 0 && y < 35 && z < -28 && z > -171);
    
    bool k4 = !(x > -1 && x < 2 && y > 0 && y < 35 && z < -55 && z > -91);
    bool k5 = !(x > -1 && x < 2 && y > 0 && y < 35 && z < -95 && z > -131);
    bool k6 = !(x > -1 && x < 2 && y > 0 && y < 35 && z < -135 && z > -171);

    bool k7 = !(x > 19 && x < 21 && y > 0 && y < 35 && z < -96 && z > -130);
    bool k8 = !(x > 19 && x < 21 && y > 0 && y < 35 && z < -138 && z > -171);


    //outside 

    bool k1_1 = !(x > -141 && x < -139 && y > 0 && y < 10 && z < -4 && z > -285);
    bool k2_1 = !(x > 136 && x < 140 && y > 0 && y < 10 && z < -4 && z > -285);




    // doors 
    
    bool k9 = !(x > -1 && x < 2 && y > 0 && y < 35 && z < -48 && z > -91);
    bool k10 = !(x > -1 && x < 2 && y > 0 && y < 35 && z < -88 && z > -131);
    bool k11 = !(x > -1 && x < 2 && y > 0 && y < 35 && z < -128 && z > -171);

    bool k12 = !(x > 19 && x < 21 && y > 0 && y < 35 && z < -88 && z > -130);
    bool k13 = !(x > 19 && x < 21 && y > 0 && y < 35 && z < -128 && z > -171);

    bool k14 = !(x > -2 && x < 3 && y > 0 && y < 14 && z < -30 && z > -49);
    // bool k13 = !(x > 19 && x < 21 && y > 0 && y < 35 && z < -128 && z > -171);




    if(door_3_stat)
        k9 = 1;
    if(door_2_stat)
        k10 = 1;
    if(door_1_stat)
        k11 = 1;
    if(door_4_stat)
        k12 = 1;
    if(door_5_stat)
        k13 = 1;
    if(door_6_stat)
        k14 = 1;


    return k1 && k2 && k3 && k4 && k5 && k6 && k7 && k8 && k9 && k10 && k11 && k12 && k13 && k14 && k1_1 && k2_1;
}

bool y_move(float x, float y, float z, int p)
{
    if(p)
    y = y-1;
    else
    y = y+1;

    bool k1 = !(y > -0.5 && y <= 1);
    bool k2 = !(x > -70 && x < 61 && y > 13 && y < 16 && z < -47 && z > -170);
    bool k3 = !(x > -75 && x < 20 && y > 13 && y < 16 && z < -27 && z > -173);
    bool k4 = !(x > -75 && x < 66 && y > 29 && y < 32 && z < -47 && z > -173);
    bool k5 = !(x > -75 && x < 66 && y > 1 && y < 2 && z < -27 && z > -173);



    return k1 && k2 && k3 && k4 && k5;

}


// ===================== collision done =========================================


// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_PAGE_DOWN)
    {
        if(y_move(eyex, eyey, eyez, 1))
        {
            eyey--;
            dy--;
        }
        
        // eyey--;
        // dy--;
    }
    if( key == GLUT_KEY_PAGE_UP)
    {
        if(y_move(eyex, eyey, eyez, 0))
        {
            eyey++;
            dy++;
        }
        
        // eyey++;
        // dy++;
    }
    if (key == GLUT_KEY_UP)
    {
        if(z_move(eyex, eyey, eyez, 1))
        {
            eyez--;
            dz--;
        }
        
    }
    if (key == GLUT_KEY_DOWN)
    {
        if(z_move(eyex, eyey, eyez, 0))
        {
            eyez++;
            dz++;
        }
    }
    if (key == GLUT_KEY_LEFT)
    {
        if(x_move(eyex, eyey, eyez, 1)){
        eyex--;
        dx--;
        }
    }
    if (key == GLUT_KEY_RIGHT)
    {
        if(x_move(eyex, eyey, eyez, 0)){
        eyex++;
        dx++;
        }
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
    glutCreateWindow ("3D-Complete-House");

    glShadeModel( GL_FLAT );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    
    #ifdef _WIN32
        texture[0] = LoadTexture("images\\p1.bmp", 2000, 1338);  
        texture[2] = LoadTexture("images\\wood_1.bmp", 500, 800);
        texture[4] = LoadTexture("images\\wall7.bmp", 5845, 3897);
        texture[5] = LoadTexture("images\\door.bmp", 632, 1264);
        texture[6] = LoadTexture("images\\marble_floor.bmp", 6000, 4502);
        texture[7] = LoadTexture("images\\sofa1.bmp", 6000, 6000);
        texture[8] = LoadTexture("images\\wall5.bmp", 6311, 4207);
        texture[9] = LoadTexture("images\\wall6.bmp", 5000, 3333);
        texture[10] = LoadTexture("images\\sky1.bmp", 5421, 2951);
        texture[11] = LoadTexture("images\\sky3.bmp", 3072, 2304);
        texture[12] = LoadTexture("images\\drawer1.bmp", 5235, 2373);
        texture[13] = LoadTexture("images\\bed1.bmp", 6007, 4005);
        texture[14] = LoadTexture("images\\pillow.bmp", 7500, 5000);
        texture[15] = LoadTexture("images\\dressing1.bmp", 1200, 1200);
        texture[16] = LoadTexture("images\\glass.bmp", 460, 809);
        texture[17] = LoadTexture("images\\tv1.bmp", 588, 350);
        texture[18] = LoadTexture("images\\bookshelf.bmp", 1600, 1600);
        texture[19] = LoadTexture("images\\book_my.bmp", 948, 425);
        texture[20] = LoadTexture("images\\mati.bmp", 5472, 3648);
        texture[21] = LoadTexture("images\\door2.bmp", 236, 542);
    #else
        texture[0] = LoadTexture("images/p1.bmp", 2000, 1338);   
        texture[2] = LoadTexture("images/wood_1.bmp", 500, 800);
        texture[4] = LoadTexture("images/wall7.bmp", 5845, 3897);
        texture[5] = LoadTexture("images/door.bmp", 632, 1264);
        texture[6] = LoadTexture("images/marble_floor.bmp", 6000, 4502);
        texture[7] = LoadTexture("images/sofa1.bmp", 6000, 6000);
        texture[8] = LoadTexture("images/wall5.bmp", 6311, 4207);
        texture[9] = LoadTexture("images/wall6.bmp", 5000, 3333);
        texture[10] = LoadTexture("images/sky1.bmp", 5421, 2951);
        texture[11] = LoadTexture("images/sky3.bmp", 3072, 2304);
        texture[12] = LoadTexture("images/drawer1.bmp", 5235, 2373);
        texture[13] = LoadTexture("images/bed1.bmp", 6007, 4005);
        texture[14] = LoadTexture("images/pillow.bmp", 7500, 5000);
        texture[15] = LoadTexture("images/dressing1.bmp", 1200, 1200);
        texture[16] = LoadTexture("images/glass.bmp", 460, 809);
        texture[17] = LoadTexture("images/tv1.bmp", 588, 350);
        texture[18] = LoadTexture("images/bookshelf.bmp", 1600, 1600);
        texture[19] = LoadTexture("images/book_my.bmp", 948, 425);
        texture[20] = LoadTexture("images/mati.bmp", 5472, 3648);
        texture[21] = LoadTexture("images/door2.bmp", 236, 542);
    #endif
    

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);
    glutSpecialFunc(specialKeyInput);
    
    glutMainLoop();

}


