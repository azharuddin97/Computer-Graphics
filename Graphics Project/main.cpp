#include<cstdio>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#define PI 3.14159265358979323846


GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat speed = 0.005f;

GLfloat rainvar = 0.0f;
GLfloat rainspeed = 0.005f;

GLfloat position4 = 0.0f;
GLfloat speed4 = 0.01f;

void sound1();
void morningSound(int sValue1){
    sound1();
}
void sound3(){
    PlaySound("Night_Sounds_-_Crickets-Lisa_Redfern-591005346.wav",NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutTimerFunc(5000, morningSound , 0);
}
void nightSound(int sValue3){
    sound3();
}
void sound2(){
    PlaySound("Light-summer-rain-sound.wav",NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutTimerFunc(5000, nightSound , 0);
}
void daySound(int sValue2){
    sound2();
}
void sound1(){
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("Birds-in-evening-forest.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    glutTimerFunc(5000, daySound , 0);
}

void boat(int value) {
    if(position4 <-1.0)
        position4 = 1.0f;
    position4 -= speed4;
	glutPostRedisplay();
	glutTimerFunc(100, boat, 0);
}

void cloud(int value) {
    if(position <-1.0)
        position = 1.0f;
    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, cloud, 0);
}

void bird(int value) {
    if(position1 >1.0)
        position1 = -1.0f;
    position1 += speed;
	glutPostRedisplay();
	glutTimerFunc(50, bird, 0);
}

void rain(int value) {
    if(rainvar <-1.0)
        rainvar = 1.0f;
    rainvar -= rainspeed;
	glutPostRedisplay();
	glutTimerFunc(30, rain , 0);
}

void handleMouse(int button, int state,int x,int y) {
	if (button == GLUT_LEFT_BUTTON){
        speed4 += 0.01f;
    }
    if (button == GLUT_RIGHT_BUTTON){
        speed4 -= 0.01f;
    }
    glutPostRedisplay();
}

void handleKeypress(unsigned char key,int x,int y){
    switch(key){
        case 's':
        speed4 = 0.0f;
        break;
        case 'l':
        speed4 = 0.01f;
        break;
        case 'r':
        speed4 = -0.01f;
        break;
    glutPostRedisplay();
    }
}

void morning();
void display3(int value3){
    glutDisplayFunc(morning);

}

void night() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 77);
	glVertex2f(-1,0.4);
	glVertex2f(1,0.4);
	glVertex2f(1,1);
	glVertex2f(-1,1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0, 102, 34);
	glVertex2f(1,0.4);
	glVertex2f(0.75,0.7);
	glVertex2f(0.5,0.4);
	glEnd();
        glBegin(GL_TRIANGLES);
	glVertex2f(0.5,0.4);
	glVertex2f(0.375,0.55);
	glVertex2f(0.25,0.4);
	glEnd();
        glBegin(GL_TRIANGLES);
	glVertex2f(0.25,0.4);
    glVertex2f(0.0,0.7);
    glVertex2f(-0.25,0.4);
    glEnd();
        glBegin(GL_TRIANGLES);
    glVertex2f(-0.25,0.4);
	glVertex2f(-0.375,0.55);
	glVertex2f(-0.5,0.4);
	glEnd();
        glBegin(GL_TRIANGLES);
	glVertex2f(-0.5,0.4);
    glVertex2f(-0.75,0.7);
	glVertex2f(-1,0.4);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 77, 0);
	glVertex2f(-1,0.4);
	glVertex2f(1,0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 77, 128);
	glVertex2f(-1,-1);
	glVertex2f(1,-1);
    glVertex2f(1,0.4);
    glVertex2f(-1,0.4);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 195, 77);
	glVertex2f(.12,-0.95);
	glVertex2f(.20,-0.88);
	glVertex2f(.20,-0.91);
	glVertex2f(.145,-0.96);
        glBegin(GL_QUADS);
    glColor3ub(255, 195, 77);
	glVertex2f(.079,-0.81);
	glVertex2f(0.3,-0.74);
	glVertex2f(0.3,-0.77);
	glVertex2f(.11,-0.83);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 195, 77);
	glVertex2f(0.095,-0.67);
	glVertex2f(0.2,-.62);
    glVertex2f(0.2,-.65);
    glVertex2f(0.128,-0.684);
    glEnd();
       glBegin(GL_QUADS);
    glColor3ub(255, 195, 77);
    glVertex2f(0.135,-.57);
	glVertex2f(0.35,-.49);
    glVertex2f(0.34,-.52);
    glVertex2f(0.163,-.59);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 195, 77);
	glVertex2f(.132,-.205);
	glVertex2f(0.3,-0.09);
    glVertex2f(0.3,-0.12);
	glVertex2f(.145,-.225);
    glEnd();

glEnable(GL_LIGHTING);

GLfloat global_ambient3[]={0.0,1.9,0.0,0.1};
glLightModelfv(GL_LIGHT_MODEL_AMBIENT , global_ambient3);
    glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(-1,-1);
	glVertex2f(0.25,-1);
	glVertex2f(.125,-0.95);
	glVertex2f(.20,-0.88);
	glVertex2f(.08,-0.81);
	glVertex2f(0.3,-0.74);
	glVertex2f(0.1,-0.67);
	glVertex2f(0.2,-.62);
	glVertex2f(0.125,-.55);
	glVertex2f(0.35,-.49);
	glVertex2f(0.42,-0.29);
	glVertex2f(0.15,-0.23);
	glVertex2f(.1,-.16);
	glVertex2f(0.3,-0.09);
	glVertex2f(0.05,-0.0);
	glVertex2f(-1,-0.0);
	glEnd();
glDisable(GL_LIGHTING);

    glBegin(GL_QUADS);
	glColor3ub(255, 195, 77);
	glVertex2f(0.31,-.22);
	glVertex2f(0.298,-.22);
	glVertex2f(0.348,-.42);
	glVertex2f(0.36,-.42);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(255, 195, 77);
	glVertex2f(0.33,-.32);
	glVertex2f(0.33,-.312);
	glVertex2f(0.44,-.442);
	glVertex2f(0.44,-.45);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();
    glLoadIdentity();

//Boat
glTranslatef(0.05,-0.4f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.6,0.3);
    glVertex2f(0.1,0.3);
    glVertex2f(0.2,0.2);
    glVertex2f(0.5,0.2);
    glEnd();
	    glBegin(GL_POLYGON);
    glColor3ub(102, 77, 0);
    glVertex2f(0.47,0.45);
    glVertex2f(0.25,0.45);
    glVertex2f(0.215,0.39);
    glVertex2f(0.2,0.3);
    glVertex2f(0.5,0.3);
    glVertex2f(0.49,0.39);
	glEnd();
	    glBegin(GL_QUADS);
    glColor3ub(179, 36, 0);
    glVertex2f(0.4,0.67);
    glVertex2f(0.29,0.7);
    glVertex2f(0.29,0.52);
    glVertex2f(0.4,0.495);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(102, 102, 0);
    glVertex2f(0.35,0.75);
    glVertex2f(0.34,0.75);
    glVertex2f(0.34,0.45);
    glVertex2f(0.35,0.45);
    glEnd();
    glLoadIdentity();

//Moon
    int i;

	GLfloat x=-.55f; GLfloat y=.9f; GLfloat radius =0.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(153, 153, 153);
		glVertex2f(x,y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    x=-.55f;y=.95f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 77);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//Cloud
 x=-.25f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(140, 140, 140);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=-.15f;y=.82f;radius =.095f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(140, 140, 140);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=-.05f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(140, 140, 140);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

//Tree
    x=-.7f;y=.45f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 128, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    x=-.77f;y=.35f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 128, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    x=-.62f;y=.35f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 128, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 0);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.105,0.25);
    glVertex2f(-0.105,0.19);
    glVertex2f(-0.095,0.19);
    glVertex2f(-0.095,0.25);
    glEnd();
        glBegin(GL_POLYGON);
	glColor3ub(153, 153, 0);
	glVertex2f(0.07,-0.11);
	glVertex2f(0.07,0.04);
	glVertex2f(0.0,0.14);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.17,0.14);
    glVertex2f(-0.25,0.04);
	glVertex2f(-0.25,-0.11);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.17,-0.17);
    glVertex2f(-0.17,0.17);
    glVertex2f(-0.47,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.17,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.17,-0.17);
    glVertex2f(-0.17,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.17,0.17);
    glVertex2f(-0.47,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.47,0.17);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.52,0.42);
    glVertex2f(-0.57,0.171);
	glVertex2f(-0.57,-0.14);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.47,0.17);
    glVertex2f(-0.52,0.42);
	glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.57,0.171);
	glVertex2f(-0.57,-0.14);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
 	glVertex2f(-0.57,-0.14);
    glVertex2f(-0.47,-0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.59,0.171);
    glVertex2f(-0.57,0.171);
    glVertex2f(-0.52,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.59,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.59,0.171);
    glVertex2f(-0.57,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.57,0.171);
    glVertex2f(-0.52,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.52,0.42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.15,0.171);
    glVertex2f(-0.21,0.42);
    glVertex2f(-0.54,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.15,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.15,0.171);
    glVertex2f(-0.21,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.21,0.42);
    glVertex2f(-0.54,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.54,0.42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.55,0.115);
	glVertex2f(-0.55,-0.148);
    glVertex2f(-0.49,-0.162);
    glVertex2f(-0.49,0.108);
	glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,0.115);
	glVertex2f(-0.55,-0.148);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,-0.148);
    glVertex2f(-0.49,-0.162);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.49,-0.162);
    glVertex2f(-0.49,0.108);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,0.115);
    glVertex2f(-0.49,0.108);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.52,0.112);
	glVertex2f(-0.52,-0.153);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.36,-0.05);
    glVertex2f(-0.36,0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.36,-0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.36,-0.05);
    glVertex2f(-0.36,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.36,0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.395,-0.05);
    glVertex2f(-0.395,0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.26,0.1);
    glVertex2f(-0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.26,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.26,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.26,0.1);
    glVertex2f(-0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35,0.1);
    glVertex2f(-0.35,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.305,-0.17);
    glVertex2f(-0.305,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 68, 0);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.18,-0.05);
    glVertex2f(-0.18,0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.18,-0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.18,-0.05);
    glVertex2f(-0.18,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.18,0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.215,-0.05);
    glVertex2f(-0.215,0.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128, 43, 0);
    glVertex2f(-0.74,-0.2);
	glVertex2f(-0.79,-0.27);
    glVertex2f(-0.72,-0.25);
    glVertex2f(-0.7,-0.35);
    glVertex2f(-0.67,-0.25);
    glVertex2f(-0.6,-0.27);
    glVertex2f(-0.65,-0.2);
    glVertex2f(-0.65,0.21);
    glVertex2f(-0.74,0.21);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(128, 43, 0);
    glVertex2f(-0.68,0.23);
    glVertex2f(-0.68,0.28);
    glVertex2f(-0.71,0.28);
    glVertex2f(-0.71,0.16);
    glVertex2f(-0.75,0.25);
    glVertex2f(-0.78,0.25);
    glVertex2f(-0.74,0.21);
    glVertex2f(-0.65,0.21);
	glVertex2f(-0.61,0.25);
    glVertex2f(-0.64,0.25);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(107, 107, 71);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.4,-0.47);
    glVertex2f(-0.62,-1);
    glVertex2f(-0.5,-1);
    glVertex2f(-0.3,-0.47);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 38, 0);
    glVertex2f(-0.6,-0.41);
    glVertex2f(-0.65,-0.39);
    glVertex2f(-0.8,-0.39);
    glVertex2f(-0.85,-0.41);
    glVertex2f(-0.85,-0.55);
    glVertex2f(-0.8,-0.57);
    glVertex2f(-0.65,-0.57);
    glVertex2f(-0.6,-0.55);
	glEnd();
	    glBegin(GL_POLYGON);
    glColor3ub(0, 46, 77);
    glVertex2f(-0.61,-0.415);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.84,-0.415);
    glVertex2f(-0.8,-0.43);
    glVertex2f(-0.65,-0.43);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
//flower
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(179, 179, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();


glTranslatef(0.75,0.15,0);
	glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(179, 179, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();
glLoadIdentity();
glTranslatef(0.85,0.55,0);
	glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(179, 179, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(0, 51, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();
glLoadIdentity();

    glTranslatef(-.07,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.9,-0.45);
    glVertex2f(0.8,-0.42);
    glVertex2f(0.6,-0.42);
    glVertex2f(0.5,-0.45);
    glVertex2f(0.6,-0.55);
    glVertex2f(0.8,-0.55);
	glEnd();
        glBegin(GL_TRIANGLES);
    glColor3ub(77, 77, 51);
    glVertex2f(0.6,-0.43);
    glVertex2f(0.51,-0.454);
    glVertex2f(0.6,-0.474);
    glEnd();
        glBegin(GL_QUADS);
	glColor3ub(77, 77, 51);
	glVertex2f(0.695,-0.43);
	glVertex2f(0.61,-0.43);
	glVertex2f(0.61,-0.474);
	glVertex2f(0.695,-0.474);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(77, 77, 51);
	glVertex2f(0.79,-0.43);
	glVertex2f(0.705,-0.43);
	glVertex2f(0.705,-0.474);
	glVertex2f(0.79,-0.474);
	glEnd();
        glBegin(GL_TRIANGLES);
    glColor3ub(77, 77, 51);
    glVertex2f(0.8,-0.43);
    glVertex2f(0.89,-0.454);
    glVertex2f(0.8,-0.474);
    glEnd();
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3ub(138, 138, 92);
    glVertex2f(-0.48,-0.45);
    glVertex2f(-0.495,-0.435);
    glVertex2f(-0.545,-0.435);
    glVertex2f(-0.56,-0.45);
    glVertex2f(-0.54,-0.52);
    glVertex2f(-0.5,-0.52);
    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(0, 46, 77);
    glVertex2f(-0.485,-0.452);
    glVertex2f(-0.497,-0.442);
    glVertex2f(-0.542,-0.442);
    glVertex2f(-0.555,-0.452);
    glVertex2f(-0.542,-0.467);
    glVertex2f(-0.497,-0.467);
    glEnd();

    glutTimerFunc(5000,display3,0);
	glFlush();  // Render now
}

void display2(int vlaue2){
    glutDisplayFunc(night);

}

void day() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


	glBegin(GL_POLYGON);
	glColor3ub(0, 204, 255);
	glVertex2f(-1,0.4);
	glVertex2f(1,0.4);
	glVertex2f(1,1);
	glVertex2f(-1,1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(42, 162, 42);
	glVertex2f(1,0.4);
	glVertex2f(0.75,0.7);
	glVertex2f(0.5,0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5,0.4);
	glVertex2f(0.375,0.55);
	glVertex2f(0.25,0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.25,0.4);
    glVertex2f(0.0,0.7);
    glVertex2f(-0.25,0.4);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.25,0.4);
	glVertex2f(-0.375,0.55);
	glVertex2f(-0.5,0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5,0.4);
    glVertex2f(-0.75,0.7);
	glVertex2f(-1,0.4);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(42, 162, 42);
	glVertex2f(-1,0.4);
	glVertex2f(1,0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 153, 255);
	glVertex2f(-1,-1);
	glVertex2f(1,-1);
    glVertex2f(1,0.4);
    glVertex2f(-1,0.4);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(.12,-0.95);
	glVertex2f(.20,-0.88);
	glVertex2f(.20,-0.91);
	glVertex2f(.145,-0.96);
        glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(.079,-0.81);
	glVertex2f(0.3,-0.74);
	glVertex2f(0.3,-0.77);
	glVertex2f(.11,-0.83);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(0.095,-0.67);
	glVertex2f(0.2,-.62);
    glVertex2f(0.2,-.65);
    glVertex2f(0.128,-0.684);
    glEnd();
       glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
    glVertex2f(0.135,-.57);
	glVertex2f(0.35,-.49);
    glVertex2f(0.34,-.52);
    glVertex2f(0.163,-.59);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(.132,-.205);
	glVertex2f(0.3,-0.09);
    glVertex2f(0.3,-0.12);
	glVertex2f(.145,-.225);
    glEnd();

		glBegin(GL_POLYGON);
	glColor3ub(102, 255, 51);
	glVertex2f(-1,-1);
	glVertex2f(0.25,-1);
	glVertex2f(.125,-0.95);
	glVertex2f(.20,-0.88);
	glVertex2f(.08,-0.81);
	glVertex2f(0.3,-0.74);
	glVertex2f(0.1,-0.67);
	glVertex2f(0.2,-.62);
	glVertex2f(0.125,-.55);
	glVertex2f(0.35,-.49);
	glVertex2f(0.42,-0.29);
	glVertex2f(0.15,-0.23);
	glVertex2f(.1,-.16);
	glVertex2f(0.3,-0.09);
	glVertex2f(0.05,-0.0);
	glVertex2f(-1,-0.0);
	glEnd();

        glBegin(GL_QUADS);
	glColor3ub(230, 115, 0);
	glVertex2f(0.31,-.22);
	glVertex2f(0.298,-.22);
	glVertex2f(0.348,-.42);
	glVertex2f(0.36,-.42);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(230, 115, 0);
	glVertex2f(0.33,-.32);
	glVertex2f(0.33,-.312);
	glVertex2f(0.44,-.442);
	glVertex2f(0.44,-.45);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();
    glLoadIdentity();

//Tree
    int i;

    GLfloat x=-.7f; GLfloat y=.45f; GLfloat radius =.1f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    x=-.77f;y=.35f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    x=-.62f;y=.35f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.105,0.25);
    glVertex2f(-0.105,0.19);
    glVertex2f(-0.095,0.19);
    glVertex2f(-0.095,0.25);
    glEnd();
        glBegin(GL_POLYGON);
	glColor3ub(230, 230, 0);
	glVertex2f(0.07,-0.11);
	glVertex2f(0.07,0.04);
	glVertex2f(0.0,0.14);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.17,0.14);
    glVertex2f(-0.25,0.04);
	glVertex2f(-0.25,-0.11);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.17,-0.17);
    glVertex2f(-0.17,0.17);
    glVertex2f(-0.47,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.17,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.17,-0.17);
    glVertex2f(-0.17,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.17,0.17);
    glVertex2f(-0.47,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.47,0.17);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.52,0.42);
    glVertex2f(-0.57,0.171);
	glVertex2f(-0.57,-0.14);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.47,0.17);
    glVertex2f(-0.52,0.42);
	glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.57,0.171);
	glVertex2f(-0.57,-0.14);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
 	glVertex2f(-0.57,-0.14);
    glVertex2f(-0.47,-0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.59,0.171);
    glVertex2f(-0.57,0.171);
    glVertex2f(-0.52,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.59,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.59,0.171);
    glVertex2f(-0.57,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.57,0.171);
    glVertex2f(-0.52,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.52,0.42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.15,0.171);
    glVertex2f(-0.21,0.42);
    glVertex2f(-0.54,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.15,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.15,0.171);
    glVertex2f(-0.21,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.21,0.42);
    glVertex2f(-0.54,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.54,0.42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.55,0.115);
	glVertex2f(-0.55,-0.148);
    glVertex2f(-0.49,-0.162);
    glVertex2f(-0.49,0.108);
	glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,0.115);
	glVertex2f(-0.55,-0.148);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,-0.148);
    glVertex2f(-0.49,-0.162);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.49,-0.162);
    glVertex2f(-0.49,0.108);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,0.115);
    glVertex2f(-0.49,0.108);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.52,0.112);
	glVertex2f(-0.52,-0.153);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.36,-0.05);
    glVertex2f(-0.36,0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.36,-0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.36,-0.05);
    glVertex2f(-0.36,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.36,0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.395,-0.05);
    glVertex2f(-0.395,0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.26,0.1);
    glVertex2f(-0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.26,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.26,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.26,0.1);
    glVertex2f(-0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35,0.1);
    glVertex2f(-0.35,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.305,-0.17);
    glVertex2f(-0.305,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.18,-0.05);
    glVertex2f(-0.18,0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.18,-0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.18,-0.05);
    glVertex2f(-0.18,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.18,0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.215,-0.05);
    glVertex2f(-0.215,0.05);
    glEnd();

//Cloud
    x=-.4f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=-.3f;y=.82f;radius =.095f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,1);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=-.2f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glTranslatef(0.8,0,0);

    x=-.4f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=-.3f;y=.82f;radius =.095f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=-.2f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glLoadIdentity();


    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 0);
    glVertex2f(-0.74,-0.2);
	glVertex2f(-0.79,-0.27);
    glVertex2f(-0.72,-0.25);
    glVertex2f(-0.7,-0.35);
    glVertex2f(-0.67,-0.25);
    glVertex2f(-0.6,-0.27);
    glVertex2f(-0.65,-0.2);
    glVertex2f(-0.65,0.21);
    glVertex2f(-0.74,0.21);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(-0.68,0.23);
    glVertex2f(-0.68,0.28);
    glVertex2f(-0.71,0.28);
    glVertex2f(-0.71,0.16);
    glVertex2f(-0.75,0.25);
    glVertex2f(-0.78,0.25);
    glVertex2f(-0.74,0.21);
    glVertex2f(-0.65,0.21);
	glVertex2f(-0.61,0.25);
    glVertex2f(-0.64,0.25);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.4,-0.47);
    glVertex2f(-0.62,-1);
    glVertex2f(-0.5,-1);
    glVertex2f(-0.3,-0.47);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 57, 0);
    glVertex2f(-0.6,-0.41);
    glVertex2f(-0.65,-0.39);
    glVertex2f(-0.8,-0.39);
    glVertex2f(-0.85,-0.41);
    glVertex2f(-0.85,-0.55);
    glVertex2f(-0.8,-0.57);
    glVertex2f(-0.65,-0.57);
    glVertex2f(-0.6,-0.55);
	glEnd();
	    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 102);
    glVertex2f(-0.61,-0.415);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.84,-0.415);
    glVertex2f(-0.8,-0.43);
    glVertex2f(-0.65,-0.43);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
//flower
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();


glTranslatef(0.75,0.15,0);
	glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();
glLoadIdentity();
glTranslatef(0.85,0.55,0);
	glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,0,0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();
glLoadIdentity();

    glTranslatef(-.07,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.9,-0.45);
    glVertex2f(0.8,-0.42);
    glVertex2f(0.6,-0.42);
    glVertex2f(0.5,-0.45);
    glVertex2f(0.6,-0.55);
    glVertex2f(0.8,-0.55);
	glEnd();
        glBegin(GL_TRIANGLES);
    glColor3ub(163, 163, 194);
    glVertex2f(0.6,-0.43);
    glVertex2f(0.51,-0.454);
    glVertex2f(0.6,-0.474);
    glEnd();
        glBegin(GL_QUADS);
	glColor3ub(163, 163, 194);
	glVertex2f(0.695,-0.43);
	glVertex2f(0.61,-0.43);
	glVertex2f(0.61,-0.474);
	glVertex2f(0.695,-0.474);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(163, 163, 194);
	glVertex2f(0.79,-0.43);
	glVertex2f(0.705,-0.43);
	glVertex2f(0.705,-0.474);
	glVertex2f(0.79,-0.474);
	glEnd();
        glBegin(GL_TRIANGLES);
    glColor3ub(163, 163, 194);
    glVertex2f(0.8,-0.43);
    glVertex2f(0.89,-0.454);
    glVertex2f(0.8,-0.474);
    glEnd();
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3ub(107, 107, 71);
    glVertex2f(-0.48,-0.45);
    glVertex2f(-0.495,-0.435);
    glVertex2f(-0.545,-0.435);
    glVertex2f(-0.56,-0.45);
    glVertex2f(-0.54,-0.52);
    glVertex2f(-0.5,-0.52);
    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(45, 89, 134);
    glVertex2f(-0.485,-0.452);
    glVertex2f(-0.497,-0.442);
    glVertex2f(-0.542,-0.442);
    glVertex2f(-0.555,-0.452);
    glVertex2f(-0.542,-0.467);
    glVertex2f(-0.497,-0.467);
    glEnd();

//Rain
glPushMatrix();
glTranslatef(0.0f,rainvar,0.0f);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.95);
    glVertex2f(-0.95,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.95);
    glVertex2f(-0.85,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.95);
    glVertex2f(-0.75,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.95);
    glVertex2f(-0.65,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.95);
    glVertex2f(-0.55,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.95);
    glVertex2f(-0.45,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.95);
    glVertex2f(-0.35,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.95);
    glVertex2f(-0.25,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.95);
    glVertex2f(-0.15,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.95);
    glVertex2f(-0.05,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.95);
    glVertex2f(0.05,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.95);
    glVertex2f(0.15,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.95);
    glVertex2f(0.25,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.95);
    glVertex2f(0.35,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.95);
    glVertex2f(0.45,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.95);
    glVertex2f(0.55,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.95);
    glVertex2f(0.65,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.95);
    glVertex2f(0.75,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.95);
    glVertex2f(0.85,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.95);
    glVertex2f(0.95,2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.95);
    glVertex2f(1.05,2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.85);
    glVertex2f(-0.95,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.85);
    glVertex2f(-0.85,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.85);
    glVertex2f(-0.75,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.85);
    glVertex2f(-0.65,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.85);
    glVertex2f(-0.55,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.85);
    glVertex2f(-0.45,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.85);
    glVertex2f(-0.35,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.85);
    glVertex2f(-0.25,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.85);
    glVertex2f(-0.15,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.85);
    glVertex2f(-0.05,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.85);
    glVertex2f(0.05,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.85);
    glVertex2f(0.15,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.85);
    glVertex2f(0.25,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.85);
    glVertex2f(0.35,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.85);
    glVertex2f(0.45,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.85);
    glVertex2f(0.55,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.85);
    glVertex2f(0.65,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.85);
    glVertex2f(0.75,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.85);
    glVertex2f(0.85,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.85);
    glVertex2f(0.95,1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.85);
    glVertex2f(1.05,1.9);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.75);
    glVertex2f(-0.95,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.75);
    glVertex2f(-0.85,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.75);
    glVertex2f(-0.75,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.75);
    glVertex2f(-0.65,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.75);
    glVertex2f(-0.55,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.75);
    glVertex2f(-0.45,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.75);
    glVertex2f(-0.35,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.75);
    glVertex2f(-0.25,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.75);
    glVertex2f(-0.15,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.75);
    glVertex2f(-0.05,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.75);
    glVertex2f(0.05,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.75);
    glVertex2f(0.15,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.75);
    glVertex2f(0.25,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.75);
    glVertex2f(0.35,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.75);
    glVertex2f(0.45,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.75);
    glVertex2f(0.55,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.75);
    glVertex2f(0.65,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.75);
    glVertex2f(0.75,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.75);
    glVertex2f(0.85,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.75);
    glVertex2f(0.95,1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.75);
    glVertex2f(1.05,1.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.65);
    glVertex2f(-0.95,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.65);
    glVertex2f(-0.85,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.65);
    glVertex2f(-0.75,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.65);
    glVertex2f(-0.65,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.65);
    glVertex2f(-0.55,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.65);
    glVertex2f(-0.45,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.65);
    glVertex2f(-0.35,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.65);
    glVertex2f(-0.25,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.65);
    glVertex2f(-0.15,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.65);
    glVertex2f(-0.05,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.65);
    glVertex2f(0.05,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.65);
    glVertex2f(0.15,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.65);
    glVertex2f(0.25,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.65);
    glVertex2f(0.35,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.65);
    glVertex2f(0.45,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.65);
    glVertex2f(0.55,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.65);
    glVertex2f(0.65,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.65);
    glVertex2f(0.75,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.65);
    glVertex2f(0.85,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.65);
    glVertex2f(0.95,1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.65);
    glVertex2f(1.05,1.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.55);
    glVertex2f(-0.95,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.55);
    glVertex2f(-0.85,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.55);
    glVertex2f(-0.75,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.55);
    glVertex2f(-0.65,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.55);
    glVertex2f(-0.55,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.55);
    glVertex2f(-0.45,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.55);
    glVertex2f(-0.35,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.55);
    glVertex2f(-0.25,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.55);
    glVertex2f(-0.15,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.55);
    glVertex2f(-0.05,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.55);
    glVertex2f(0.05,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.55);
    glVertex2f(0.15,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.55);
    glVertex2f(0.25,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.55);
    glVertex2f(0.35,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.55);
    glVertex2f(0.45,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.55);
    glVertex2f(0.55,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.55);
    glVertex2f(0.65,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.55);
    glVertex2f(0.75,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.55);
    glVertex2f(0.85,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.55);
    glVertex2f(0.95,1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.55);
    glVertex2f(1.05,1.6);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.45);
    glVertex2f(-0.95,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.45);
    glVertex2f(-0.85,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.45);
    glVertex2f(-0.75,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.45);
    glVertex2f(-0.65,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.45);
    glVertex2f(-0.55,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.45);
    glVertex2f(-0.45,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.45);
    glVertex2f(-0.35,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.45);
    glVertex2f(-0.25,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.45);
    glVertex2f(-0.15,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.45);
    glVertex2f(-0.05,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.45);
    glVertex2f(0.05,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.45);
    glVertex2f(0.15,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.45);
    glVertex2f(0.25,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.45);
    glVertex2f(0.35,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.45);
    glVertex2f(0.45,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.45);
    glVertex2f(0.55,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.45);
    glVertex2f(0.65,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.45);
    glVertex2f(0.75,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.45);
    glVertex2f(0.85,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.45);
    glVertex2f(0.95,1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.45);
    glVertex2f(1.05,1.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.35);
    glVertex2f(-0.95,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.35);
    glVertex2f(-0.85,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.35);
    glVertex2f(-0.75,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.35);
    glVertex2f(-0.65,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.35);
    glVertex2f(-0.55,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.35);
    glVertex2f(-0.45,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.35);
    glVertex2f(-0.35,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.35);
    glVertex2f(-0.25,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.35);
    glVertex2f(-0.15,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.35);
    glVertex2f(-0.05,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.35);
    glVertex2f(0.05,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.35);
    glVertex2f(0.15,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.35);
    glVertex2f(0.25,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.35);
    glVertex2f(0.35,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.35);
    glVertex2f(0.45,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.35);
    glVertex2f(0.55,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.35);
    glVertex2f(0.65,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.35);
    glVertex2f(0.75,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.35);
    glVertex2f(0.85,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.35);
    glVertex2f(0.95,1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.35);
    glVertex2f(1.05,1.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.25);
    glVertex2f(-0.95,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.25);
    glVertex2f(-0.85,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.25);
    glVertex2f(-0.75,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.25);
    glVertex2f(-0.65,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.25);
    glVertex2f(-0.55,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.25);
    glVertex2f(-0.45,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.25);
    glVertex2f(-0.35,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.25);
    glVertex2f(-0.25,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.25);
    glVertex2f(-0.15,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.25);
    glVertex2f(-0.05,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.25);
    glVertex2f(0.05,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.25);
    glVertex2f(0.15,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.25);
    glVertex2f(0.25,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.25);
    glVertex2f(0.35,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.25);
    glVertex2f(0.45,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.25);
    glVertex2f(0.55,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.25);
    glVertex2f(0.65,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.25);
    glVertex2f(0.75,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.25);
    glVertex2f(0.85,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.25);
    glVertex2f(0.95,1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.25);
    glVertex2f(1.05,1.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.15);
    glVertex2f(-0.95,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.15);
    glVertex2f(-0.85,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.15);
    glVertex2f(-0.75,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.15);
    glVertex2f(-0.65,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.15);
    glVertex2f(-0.55,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.15);
    glVertex2f(-0.45,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.15);
    glVertex2f(-0.35,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.15);
    glVertex2f(-0.25,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.15);
    glVertex2f(-0.15,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.15);
    glVertex2f(-0.05,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.15);
    glVertex2f(0.05,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.15);
    glVertex2f(0.15,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.15);
    glVertex2f(0.25,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.15);
    glVertex2f(0.35,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.15);
    glVertex2f(0.45,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.15);
    glVertex2f(0.55,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.15);
    glVertex2f(0.65,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.15);
    glVertex2f(0.75,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.15);
    glVertex2f(0.85,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.15);
    glVertex2f(0.95,1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.15);
    glVertex2f(1.05,1.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,1.05);
    glVertex2f(-0.95,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,1.05);
    glVertex2f(-0.85,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,1.05);
    glVertex2f(-0.75,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,1.05);
    glVertex2f(-0.65,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,1.05);
    glVertex2f(-0.55,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,1.05);
    glVertex2f(-0.45,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,1.05);
    glVertex2f(-0.35,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,1.05);
    glVertex2f(-0.25,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,1.05);
    glVertex2f(-0.15,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,1.05);
    glVertex2f(-0.05,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,1.05);
    glVertex2f(0.05,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,1.05);
    glVertex2f(0.15,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,1.05);
    glVertex2f(0.25,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,1.05);
    glVertex2f(0.35,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,1.05);
    glVertex2f(0.45,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,1.05);
    glVertex2f(0.55,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,1.05);
    glVertex2f(0.65,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,1.05);
    glVertex2f(0.75,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,1.05);
    glVertex2f(0.85,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,1.05);
    glVertex2f(0.95,1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,1.05);
    glVertex2f(1.05,1.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.05);
    glVertex2f(-0.95,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.05);
    glVertex2f(-0.85,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.05);
    glVertex2f(-0.75,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.05);
    glVertex2f(-0.65,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.05);
    glVertex2f(-0.55,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.05);
    glVertex2f(-0.45,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.05);
    glVertex2f(-0.35,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.05);
    glVertex2f(-0.25,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.05);
    glVertex2f(-0.15,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.05);
    glVertex2f(-0.05,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.05);
    glVertex2f(0.05,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.05);
    glVertex2f(0.15,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.05);
    glVertex2f(0.25,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.05);
    glVertex2f(0.35,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.05);
    glVertex2f(0.45,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.05);
    glVertex2f(0.55,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.05);
    glVertex2f(0.65,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.05);
    glVertex2f(0.75,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.05);
    glVertex2f(0.85,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.05);
    glVertex2f(0.95,-1.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.05);
    glVertex2f(1.05,-1.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.15);
    glVertex2f(-0.95,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.15);
    glVertex2f(-0.85,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.15);
    glVertex2f(-0.75,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.15);
    glVertex2f(-0.65,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.15);
    glVertex2f(-0.55,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.15);
    glVertex2f(-0.45,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.15);
    glVertex2f(-0.35,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.15);
    glVertex2f(-0.25,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.15);
    glVertex2f(-0.15,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.15);
    glVertex2f(-0.05,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.15);
    glVertex2f(0.05,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.15);
    glVertex2f(0.15,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.15);
    glVertex2f(0.25,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.15);
    glVertex2f(0.35,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.15);
    glVertex2f(0.45,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.15);
    glVertex2f(0.55,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.15);
    glVertex2f(0.65,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.15);
    glVertex2f(0.75,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.15);
    glVertex2f(0.85,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.15);
    glVertex2f(0.95,-1.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.15);
    glVertex2f(1.05,-1.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.25);
    glVertex2f(-0.95,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.25);
    glVertex2f(-0.85,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.25);
    glVertex2f(-0.75,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.25);
    glVertex2f(-0.65,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.25);
    glVertex2f(-0.55,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.25);
    glVertex2f(-0.45,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.25);
    glVertex2f(-0.35,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.25);
    glVertex2f(-0.25,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.25);
    glVertex2f(-0.15,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.25);
    glVertex2f(-0.05,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.25);
    glVertex2f(0.05,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.25);
    glVertex2f(0.15,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.25);
    glVertex2f(0.25,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.25);
    glVertex2f(0.35,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.25);
    glVertex2f(0.45,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.25);
    glVertex2f(0.55,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.25);
    glVertex2f(0.65,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.25);
    glVertex2f(0.75,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.25);
    glVertex2f(0.85,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.25);
    glVertex2f(0.95,-1.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.25);
    glVertex2f(1.05,-1.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.35);
    glVertex2f(-0.95,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.35);
    glVertex2f(-0.85,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.35);
    glVertex2f(-0.75,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.35);
    glVertex2f(-0.65,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.35);
    glVertex2f(-0.55,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.35);
    glVertex2f(-0.45,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.35);
    glVertex2f(-0.35,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.35);
    glVertex2f(-0.25,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.35);
    glVertex2f(-0.15,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.35);
    glVertex2f(-0.05,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.35);
    glVertex2f(0.05,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.35);
    glVertex2f(0.15,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.35);
    glVertex2f(0.25,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.35);
    glVertex2f(0.35,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.35);
    glVertex2f(0.45,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.35);
    glVertex2f(0.55,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.35);
    glVertex2f(0.65,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.35);
    glVertex2f(0.75,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.35);
    glVertex2f(0.85,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.35);
    glVertex2f(0.95,-1.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.35);
    glVertex2f(1.05,-1.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.45);
    glVertex2f(-0.95,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.45);
    glVertex2f(-0.85,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.45);
    glVertex2f(-0.75,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.45);
    glVertex2f(-0.65,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.45);
    glVertex2f(-0.55,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.45);
    glVertex2f(-0.45,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.45);
    glVertex2f(-0.35,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.45);
    glVertex2f(-0.25,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.45);
    glVertex2f(-0.15,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.45);
    glVertex2f(-0.05,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.45);
    glVertex2f(0.05,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.45);
    glVertex2f(0.15,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.45);
    glVertex2f(0.25,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.45);
    glVertex2f(0.35,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.45);
    glVertex2f(0.45,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.45);
    glVertex2f(0.55,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.45);
    glVertex2f(0.65,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.45);
    glVertex2f(0.75,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.45);
    glVertex2f(0.85,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.45);
    glVertex2f(0.95,-1.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.45);
    glVertex2f(1.05,-1.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.55);
    glVertex2f(-0.95,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.55);
    glVertex2f(-0.85,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.55);
    glVertex2f(-0.75,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.55);
    glVertex2f(-0.65,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.55);
    glVertex2f(-0.55,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.55);
    glVertex2f(-0.45,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.55);
    glVertex2f(-0.35,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.55);
    glVertex2f(-0.25,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.55);
    glVertex2f(-0.15,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.55);
    glVertex2f(-0.05,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.55);
    glVertex2f(0.05,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.55);
    glVertex2f(0.15,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.55);
    glVertex2f(0.25,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.55);
    glVertex2f(0.35,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.55);
    glVertex2f(0.45,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.55);
    glVertex2f(0.55,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.55);
    glVertex2f(0.65,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.55);
    glVertex2f(0.75,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.55);
    glVertex2f(0.85,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.55);
    glVertex2f(0.95,-1.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.55);
    glVertex2f(1.05,-1.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.65);
    glVertex2f(-0.95,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.65);
    glVertex2f(-0.85,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.65);
    glVertex2f(-0.75,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.65);
    glVertex2f(-0.65,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.65);
    glVertex2f(-0.55,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.65);
    glVertex2f(-0.45,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.65);
    glVertex2f(-0.35,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.65);
    glVertex2f(-0.25,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.65);
    glVertex2f(-0.15,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.65);
    glVertex2f(-0.05,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.65);
    glVertex2f(0.05,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.65);
    glVertex2f(0.15,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.65);
    glVertex2f(0.25,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.65);
    glVertex2f(0.35,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.65);
    glVertex2f(0.45,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.65);
    glVertex2f(0.55,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.65);
    glVertex2f(0.65,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.65);
    glVertex2f(0.75,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.65);
    glVertex2f(0.85,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.65);
    glVertex2f(0.95,-1.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.65);
    glVertex2f(1.05,-1.6);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.75);
    glVertex2f(-0.95,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.75);
    glVertex2f(-0.85,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.75);
    glVertex2f(-0.75,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.75);
    glVertex2f(-0.65,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.75);
    glVertex2f(-0.55,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.75);
    glVertex2f(-0.45,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.75);
    glVertex2f(-0.35,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.75);
    glVertex2f(-0.25,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.75);
    glVertex2f(-0.15,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.75);
    glVertex2f(-0.05,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.75);
    glVertex2f(0.05,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.75);
    glVertex2f(0.15,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.75);
    glVertex2f(0.25,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.75);
    glVertex2f(0.35,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.75);
    glVertex2f(0.45,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.75);
    glVertex2f(0.55,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.75);
    glVertex2f(0.65,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.75);
    glVertex2f(0.75,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.75);
    glVertex2f(0.85,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.75);
    glVertex2f(0.95,-1.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.75);
    glVertex2f(1.05,-1.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.85);
    glVertex2f(-0.95,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.85);
    glVertex2f(-0.85,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.85);
    glVertex2f(-0.75,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.85);
    glVertex2f(-0.65,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.85);
    glVertex2f(-0.55,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.85);
    glVertex2f(-0.45,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.85);
    glVertex2f(-0.35,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.85);
    glVertex2f(-0.25,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.85);
    glVertex2f(-0.15,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.85);
    glVertex2f(-0.05,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.85);
    glVertex2f(0.05,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.85);
    glVertex2f(0.15,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.85);
    glVertex2f(0.25,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.85);
    glVertex2f(0.35,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.85);
    glVertex2f(0.45,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.85);
    glVertex2f(0.55,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.85);
    glVertex2f(0.65,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.85);
    glVertex2f(0.75,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.85);
    glVertex2f(0.85,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.85);
    glVertex2f(0.95,-1.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.85);
    glVertex2f(1.05,-1.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-1.95);
    glVertex2f(-0.95,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-1.95);
    glVertex2f(-0.85,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-1.95);
    glVertex2f(-0.75,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-1.95);
    glVertex2f(-0.65,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-1.95);
    glVertex2f(-0.55,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-1.95);
    glVertex2f(-0.45,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-1.95);
    glVertex2f(-0.35,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-1.95);
    glVertex2f(-0.25,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-1.95);
    glVertex2f(-0.15,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-1.95);
    glVertex2f(-0.05,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-1.95);
    glVertex2f(0.05,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-1.95);
    glVertex2f(0.15,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-1.95);
    glVertex2f(0.25,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-1.95);
    glVertex2f(0.35,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-1.95);
    glVertex2f(0.45,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-1.95);
    glVertex2f(0.55,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-1.95);
    glVertex2f(0.65,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-1.95);
    glVertex2f(0.75,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-1.95);
    glVertex2f(0.85,-1.9);
    glEnd();
       glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-1.95);
    glVertex2f(0.95,-1.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-1.95);
    glVertex2f(1.05,-1.9);
    glEnd();
//Next drawing space
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.95);
    glVertex2f(-0.95,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.95);
    glVertex2f(-0.85,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.95);
    glVertex2f(-0.75,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.95);
    glVertex2f(-0.65,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.95);
    glVertex2f(-0.55,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.95);
    glVertex2f(-0.45,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.95);
    glVertex2f(-0.35,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.95);
    glVertex2f(-0.25,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.95);
    glVertex2f(-0.15,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.95);
    glVertex2f(-0.05,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.95);
    glVertex2f(0.05,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.95);
    glVertex2f(0.15,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.95);
    glVertex2f(0.25,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.95);
    glVertex2f(0.35,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.95);
    glVertex2f(0.45,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.95);
    glVertex2f(0.55,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.95);
    glVertex2f(0.65,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.95);
    glVertex2f(0.75,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.95);
    glVertex2f(0.85,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.95);
    glVertex2f(0.95,1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.95);
    glVertex2f(1.05,1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.85);
    glVertex2f(-0.95,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.85);
    glVertex2f(-0.85,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.85);
    glVertex2f(-0.75,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.85);
    glVertex2f(-0.65,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.85);
    glVertex2f(-0.55,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.85);
    glVertex2f(-0.45,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.85);
    glVertex2f(-0.35,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.85);
    glVertex2f(-0.25,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.85);
    glVertex2f(-0.15,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.85);
    glVertex2f(-0.05,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.85);
    glVertex2f(0.05,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.85);
    glVertex2f(0.15,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.85);
    glVertex2f(0.25,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.85);
    glVertex2f(0.35,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.85);
    glVertex2f(0.45,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.85);
    glVertex2f(0.55,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.85);
    glVertex2f(0.65,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.85);
    glVertex2f(0.75,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.85);
    glVertex2f(0.85,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.85);
    glVertex2f(0.95,0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.85);
    glVertex2f(1.05,0.9);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.75);
    glVertex2f(-0.95,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.75);
    glVertex2f(-0.85,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.75);
    glVertex2f(-0.75,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.75);
    glVertex2f(-0.65,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.75);
    glVertex2f(-0.55,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.75);
    glVertex2f(-0.45,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.75);
    glVertex2f(-0.35,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.75);
    glVertex2f(-0.25,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.75);
    glVertex2f(-0.15,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.75);
    glVertex2f(-0.05,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.75);
    glVertex2f(0.05,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.75);
    glVertex2f(0.15,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.75);
    glVertex2f(0.25,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.75);
    glVertex2f(0.35,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.75);
    glVertex2f(0.45,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.75);
    glVertex2f(0.55,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.75);
    glVertex2f(0.65,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.75);
    glVertex2f(0.75,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.75);
    glVertex2f(0.85,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.75);
    glVertex2f(0.95,0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.75);
    glVertex2f(1.05,0.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.65);
    glVertex2f(-0.95,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.65);
    glVertex2f(-0.85,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.65);
    glVertex2f(-0.75,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.65);
    glVertex2f(-0.65,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.65);
    glVertex2f(-0.55,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.65);
    glVertex2f(-0.45,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.65);
    glVertex2f(-0.35,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.65);
    glVertex2f(-0.25,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.65);
    glVertex2f(-0.15,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.65);
    glVertex2f(-0.05,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.65);
    glVertex2f(0.05,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.65);
    glVertex2f(0.15,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.65);
    glVertex2f(0.25,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.65);
    glVertex2f(0.35,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.65);
    glVertex2f(0.45,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.65);
    glVertex2f(0.55,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.65);
    glVertex2f(0.65,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.65);
    glVertex2f(0.75,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.65);
    glVertex2f(0.85,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.65);
    glVertex2f(0.95,0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.65);
    glVertex2f(1.05,0.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.55);
    glVertex2f(-0.95,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.55);
    glVertex2f(-0.85,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.55);
    glVertex2f(-0.75,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.55);
    glVertex2f(-0.65,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.55);
    glVertex2f(-0.55,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.55);
    glVertex2f(-0.45,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.55);
    glVertex2f(-0.35,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.55);
    glVertex2f(-0.25,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.55);
    glVertex2f(-0.15,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.55);
    glVertex2f(-0.05,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.55);
    glVertex2f(0.05,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.55);
    glVertex2f(0.15,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.55);
    glVertex2f(0.25,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.55);
    glVertex2f(0.35,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.55);
    glVertex2f(0.45,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.55);
    glVertex2f(0.55,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.55);
    glVertex2f(0.65,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.55);
    glVertex2f(0.75,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.55);
    glVertex2f(0.85,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.55);
    glVertex2f(0.95,0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.55);
    glVertex2f(1.05,0.6);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.45);
    glVertex2f(-0.95,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.45);
    glVertex2f(-0.85,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.45);
    glVertex2f(-0.75,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.45);
    glVertex2f(-0.65,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.45);
    glVertex2f(-0.55,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.45);
    glVertex2f(-0.45,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.45);
    glVertex2f(-0.35,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.45);
    glVertex2f(-0.25,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.45);
    glVertex2f(-0.15,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.45);
    glVertex2f(-0.05,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.45);
    glVertex2f(0.05,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.45);
    glVertex2f(0.15,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.45);
    glVertex2f(0.25,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.45);
    glVertex2f(0.35,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.45);
    glVertex2f(0.45,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.45);
    glVertex2f(0.55,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.45);
    glVertex2f(0.65,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.45);
    glVertex2f(0.75,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.45);
    glVertex2f(0.85,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.45);
    glVertex2f(0.95,0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.45);
    glVertex2f(1.05,0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.35);
    glVertex2f(-0.95,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.35);
    glVertex2f(-0.85,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.35);
    glVertex2f(-0.75,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.35);
    glVertex2f(-0.65,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.35);
    glVertex2f(-0.55,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.35);
    glVertex2f(-0.45,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.35);
    glVertex2f(-0.35,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.35);
    glVertex2f(-0.25,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.35);
    glVertex2f(-0.15,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.35);
    glVertex2f(-0.05,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.35);
    glVertex2f(0.05,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.35);
    glVertex2f(0.15,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.35);
    glVertex2f(0.25,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.35);
    glVertex2f(0.35,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.35);
    glVertex2f(0.45,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.35);
    glVertex2f(0.55,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.35);
    glVertex2f(0.65,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.35);
    glVertex2f(0.75,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.35);
    glVertex2f(0.85,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.35);
    glVertex2f(0.95,0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.35);
    glVertex2f(1.05,0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.25);
    glVertex2f(-0.95,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.25);
    glVertex2f(-0.85,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.25);
    glVertex2f(-0.75,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.25);
    glVertex2f(-0.65,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.25);
    glVertex2f(-0.55,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.25);
    glVertex2f(-0.45,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.25);
    glVertex2f(-0.35,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.25);
    glVertex2f(-0.25,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.25);
    glVertex2f(-0.15,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.25);
    glVertex2f(-0.05,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.25);
    glVertex2f(0.05,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.25);
    glVertex2f(0.15,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.25);
    glVertex2f(0.25,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.25);
    glVertex2f(0.35,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.25);
    glVertex2f(0.45,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.25);
    glVertex2f(0.55,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.25);
    glVertex2f(0.65,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.25);
    glVertex2f(0.75,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.25);
    glVertex2f(0.85,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.25);
    glVertex2f(0.95,0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.25);
    glVertex2f(1.05,0.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.15);
    glVertex2f(-0.95,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.15);
    glVertex2f(-0.85,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.15);
    glVertex2f(-0.75,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.15);
    glVertex2f(-0.65,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.15);
    glVertex2f(-0.55,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.15);
    glVertex2f(-0.45,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.15);
    glVertex2f(-0.35,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.15);
    glVertex2f(-0.25,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.15);
    glVertex2f(-0.15,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.15);
    glVertex2f(-0.05,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.15);
    glVertex2f(0.05,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.15);
    glVertex2f(0.15,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.15);
    glVertex2f(0.25,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.15);
    glVertex2f(0.35,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.15);
    glVertex2f(0.45,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.15);
    glVertex2f(0.55,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.15);
    glVertex2f(0.65,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.15);
    glVertex2f(0.75,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.15);
    glVertex2f(0.85,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.15);
    glVertex2f(0.95,0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.15);
    glVertex2f(1.05,0.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,0.05);
    glVertex2f(-0.95,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,0.05);
    glVertex2f(-0.85,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,0.05);
    glVertex2f(-0.75,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,0.05);
    glVertex2f(-0.65,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,0.05);
    glVertex2f(-0.55,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,0.05);
    glVertex2f(-0.45,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,0.05);
    glVertex2f(-0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,0.05);
    glVertex2f(-0.25,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,0.05);
    glVertex2f(-0.15,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,0.05);
    glVertex2f(-0.05,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,0.05);
    glVertex2f(0.05,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,0.05);
    glVertex2f(0.15,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,0.05);
    glVertex2f(0.25,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,0.05);
    glVertex2f(0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,0.05);
    glVertex2f(0.45,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,0.05);
    glVertex2f(0.55,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,0.05);
    glVertex2f(0.65,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,0.05);
    glVertex2f(0.75,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,0.05);
    glVertex2f(0.85,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,0.05);
    glVertex2f(0.95,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,0.05);
    glVertex2f(1.05,0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.05);
    glVertex2f(-0.95,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.05);
    glVertex2f(-0.85,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.05);
    glVertex2f(-0.75,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.05);
    glVertex2f(-0.65,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.05);
    glVertex2f(-0.55,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.05);
    glVertex2f(-0.45,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.05);
    glVertex2f(-0.35,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.05);
    glVertex2f(-0.25,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.05);
    glVertex2f(-0.15,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.05);
    glVertex2f(-0.05,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.05);
    glVertex2f(0.05,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.05);
    glVertex2f(0.15,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.05);
    glVertex2f(0.25,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.05);
    glVertex2f(0.35,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.05);
    glVertex2f(0.45,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.05);
    glVertex2f(0.55,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.05);
    glVertex2f(0.65,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.05);
    glVertex2f(0.75,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.05);
    glVertex2f(0.85,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.05);
    glVertex2f(0.95,-0.0);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.05);
    glVertex2f(1.05,-0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.15);
    glVertex2f(-0.95,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.15);
    glVertex2f(-0.85,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.15);
    glVertex2f(-0.75,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.15);
    glVertex2f(-0.65,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.15);
    glVertex2f(-0.55,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.15);
    glVertex2f(-0.45,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.15);
    glVertex2f(-0.35,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.15);
    glVertex2f(-0.25,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.15);
    glVertex2f(-0.15,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.15);
    glVertex2f(-0.05,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.15);
    glVertex2f(0.05,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.15);
    glVertex2f(0.15,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.15);
    glVertex2f(0.25,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.15);
    glVertex2f(0.35,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.15);
    glVertex2f(0.45,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.15);
    glVertex2f(0.55,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.15);
    glVertex2f(0.65,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.15);
    glVertex2f(0.75,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.15);
    glVertex2f(0.85,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.15);
    glVertex2f(0.95,-0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.15);
    glVertex2f(1.05,-0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.25);
    glVertex2f(-0.95,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.25);
    glVertex2f(-0.85,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.25);
    glVertex2f(-0.75,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.25);
    glVertex2f(-0.65,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.25);
    glVertex2f(-0.55,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.25);
    glVertex2f(-0.45,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.25);
    glVertex2f(-0.35,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.25);
    glVertex2f(-0.25,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.25);
    glVertex2f(-0.15,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.25);
    glVertex2f(-0.05,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.25);
    glVertex2f(0.05,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.25);
    glVertex2f(0.15,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.25);
    glVertex2f(0.25,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.25);
    glVertex2f(0.35,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.25);
    glVertex2f(0.45,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.25);
    glVertex2f(0.55,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.25);
    glVertex2f(0.65,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.25);
    glVertex2f(0.75,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.25);
    glVertex2f(0.85,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.25);
    glVertex2f(0.95,-0.2);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.25);
    glVertex2f(1.05,-0.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.35);
    glVertex2f(-0.95,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.35);
    glVertex2f(-0.85,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.35);
    glVertex2f(-0.75,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.35);
    glVertex2f(-0.65,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.35);
    glVertex2f(-0.55,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.35);
    glVertex2f(-0.45,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.35);
    glVertex2f(-0.35,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.35);
    glVertex2f(-0.25,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.35);
    glVertex2f(-0.15,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.35);
    glVertex2f(-0.05,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.35);
    glVertex2f(0.05,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.35);
    glVertex2f(0.15,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.35);
    glVertex2f(0.25,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.35);
    glVertex2f(0.35,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.35);
    glVertex2f(0.45,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.35);
    glVertex2f(0.55,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.35);
    glVertex2f(0.65,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.35);
    glVertex2f(0.75,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.35);
    glVertex2f(0.85,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.35);
    glVertex2f(0.95,-0.3);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.35);
    glVertex2f(1.05,-0.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.45);
    glVertex2f(-0.95,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.45);
    glVertex2f(-0.85,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.45);
    glVertex2f(-0.75,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.45);
    glVertex2f(-0.65,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.45);
    glVertex2f(-0.55,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.45);
    glVertex2f(-0.45,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.45);
    glVertex2f(-0.35,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.45);
    glVertex2f(-0.25,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.45);
    glVertex2f(-0.15,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.45);
    glVertex2f(-0.05,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.45);
    glVertex2f(0.05,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.45);
    glVertex2f(0.15,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.45);
    glVertex2f(0.25,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.45);
    glVertex2f(0.35,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.45);
    glVertex2f(0.45,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.45);
    glVertex2f(0.55,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.45);
    glVertex2f(0.65,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.45);
    glVertex2f(0.75,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.45);
    glVertex2f(0.85,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.45);
    glVertex2f(0.95,-0.4);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.45);
    glVertex2f(1.05,-0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.55);
    glVertex2f(-0.95,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.55);
    glVertex2f(-0.85,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.55);
    glVertex2f(-0.75,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.55);
    glVertex2f(-0.65,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.55);
    glVertex2f(-0.55,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.55);
    glVertex2f(-0.45,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.55);
    glVertex2f(-0.35,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.55);
    glVertex2f(-0.25,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.55);
    glVertex2f(-0.15,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.55);
    glVertex2f(-0.05,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.55);
    glVertex2f(0.05,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.55);
    glVertex2f(0.15,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.55);
    glVertex2f(0.25,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.55);
    glVertex2f(0.35,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.55);
    glVertex2f(0.45,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.55);
    glVertex2f(0.55,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.55);
    glVertex2f(0.65,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.55);
    glVertex2f(0.75,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.55);
    glVertex2f(0.85,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.55);
    glVertex2f(0.95,-0.5);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.55);
    glVertex2f(1.05,-0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.65);
    glVertex2f(-0.95,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.65);
    glVertex2f(-0.85,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.65);
    glVertex2f(-0.75,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.65);
    glVertex2f(-0.65,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.65);
    glVertex2f(-0.55,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.65);
    glVertex2f(-0.45,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.65);
    glVertex2f(-0.35,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.65);
    glVertex2f(-0.25,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.65);
    glVertex2f(-0.15,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.65);
    glVertex2f(-0.05,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.65);
    glVertex2f(0.05,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.65);
    glVertex2f(0.15,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.65);
    glVertex2f(0.25,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.65);
    glVertex2f(0.35,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.65);
    glVertex2f(0.45,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.65);
    glVertex2f(0.55,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.65);
    glVertex2f(0.65,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.65);
    glVertex2f(0.75,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.65);
    glVertex2f(0.85,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.65);
    glVertex2f(0.95,-0.6);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.65);
    glVertex2f(1.05,-0.6);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.75);
    glVertex2f(-0.95,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.75);
    glVertex2f(-0.85,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.75);
    glVertex2f(-0.75,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.75);
    glVertex2f(-0.65,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.75);
    glVertex2f(-0.55,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.75);
    glVertex2f(-0.45,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.75);
    glVertex2f(-0.35,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.75);
    glVertex2f(-0.25,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.75);
    glVertex2f(-0.15,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.75);
    glVertex2f(-0.05,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.75);
    glVertex2f(0.05,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.75);
    glVertex2f(0.15,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.75);
    glVertex2f(0.25,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.75);
    glVertex2f(0.35,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.75);
    glVertex2f(0.45,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.75);
    glVertex2f(0.55,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.75);
    glVertex2f(0.65,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.75);
    glVertex2f(0.75,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.75);
    glVertex2f(0.85,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.75);
    glVertex2f(0.95,-0.7);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.75);
    glVertex2f(1.05,-0.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.85);
    glVertex2f(-0.95,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.85);
    glVertex2f(-0.85,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.85);
    glVertex2f(-0.75,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.85);
    glVertex2f(-0.65,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.85);
    glVertex2f(-0.55,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.85);
    glVertex2f(-0.45,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.85);
    glVertex2f(-0.35,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.85);
    glVertex2f(-0.25,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.85);
    glVertex2f(-0.15,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.85);
    glVertex2f(-0.05,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.85);
    glVertex2f(0.05,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.85);
    glVertex2f(0.15,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.85);
    glVertex2f(0.25,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.85);
    glVertex2f(0.35,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.85);
    glVertex2f(0.45,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.85);
    glVertex2f(0.55,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.85);
    glVertex2f(0.65,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.85);
    glVertex2f(0.75,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.85);
    glVertex2f(0.85,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.85);
    glVertex2f(0.95,-0.8);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.85);
    glVertex2f(1.05,-0.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-1,-0.95);
    glVertex2f(-0.95,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.9,-0.95);
    glVertex2f(-0.85,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.8,-0.95);
    glVertex2f(-0.75,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.7,-0.95);
    glVertex2f(-0.65,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.6,-0.95);
    glVertex2f(-0.55,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.5,-0.95);
    glVertex2f(-0.45,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.4,-0.95);
    glVertex2f(-0.35,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.3,-0.95);
    glVertex2f(-0.25,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.2,-0.95);
    glVertex2f(-0.15,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.1,-0.95);
    glVertex2f(-0.05,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.0,-0.95);
    glVertex2f(0.05,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.1,-0.95);
    glVertex2f(0.15,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.2,-0.95);
    glVertex2f(0.25,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.3,-0.95);
    glVertex2f(0.35,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.4,-0.95);
    glVertex2f(0.45,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.5,-0.95);
    glVertex2f(0.55,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.6,-0.95);
    glVertex2f(0.65,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.7,-0.95);
    glVertex2f(0.75,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.8,-0.95);
    glVertex2f(0.85,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0.9,-0.95);
    glVertex2f(0.95,-0.9);
    glEnd();
        glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(1,-0.95);
    glVertex2f(1.05,-0.9);
    glEnd();
glPopMatrix();
glLoadIdentity();

    glutTimerFunc(5000,display2,0);
	glFlush();  // Render now
}

void display1(int vlaue1){
    glutDisplayFunc(day);

}

void morning() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


	glBegin(GL_POLYGON);
	glColor3ub(0, 204, 255);
	glVertex2f(-1,0.4);
	glVertex2f(1,0.4);
	glVertex2f(1,1);
	glVertex2f(-1,1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(42, 162, 42);
	glVertex2f(1,0.4);
	glVertex2f(0.75,0.7);
	glVertex2f(0.5,0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5,0.4);
	glVertex2f(0.375,0.55);
	glVertex2f(0.25,0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.25,0.4);
    glVertex2f(0.0,0.7);
    glVertex2f(-0.25,0.4);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.25,0.4);
	glVertex2f(-0.375,0.55);
	glVertex2f(-0.5,0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5,0.4);
    glVertex2f(-0.75,0.7);
	glVertex2f(-1,0.4);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(42, 162, 42);
	glVertex2f(-1,0.4);
	glVertex2f(1,0.4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0, 153, 255);
	glVertex2f(-1,-1);
	glVertex2f(1,-1);
    glVertex2f(1,0.4);
    glVertex2f(-1,0.4);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(.12,-0.95);
	glVertex2f(.20,-0.88);
	glVertex2f(.20,-0.91);
	glVertex2f(.145,-0.96);
        glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(.079,-0.81);
	glVertex2f(0.3,-0.74);
	glVertex2f(0.3,-0.77);
	glVertex2f(.11,-0.83);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(0.095,-0.67);
	glVertex2f(0.2,-.62);
    glVertex2f(0.2,-.65);
    glVertex2f(0.128,-0.684);
    glEnd();
       glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
    glVertex2f(0.135,-.57);
	glVertex2f(0.35,-.49);
    glVertex2f(0.34,-.52);
    glVertex2f(0.163,-.59);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
	glVertex2f(.132,-.205);
	glVertex2f(0.3,-0.09);
    glVertex2f(0.3,-0.12);
	glVertex2f(.145,-.225);
    glEnd();

		glBegin(GL_POLYGON);
	glColor3ub(102, 255, 51);
	glVertex2f(-1,-1);
	glVertex2f(0.25,-1);
	glVertex2f(.125,-0.95);
	glVertex2f(.20,-0.88);
	glVertex2f(.08,-0.81);
	glVertex2f(0.3,-0.74);
	glVertex2f(0.1,-0.67);
	glVertex2f(0.2,-.62);
	glVertex2f(0.125,-.55);
	glVertex2f(0.35,-.49);
	glVertex2f(0.42,-0.29);
	glVertex2f(0.15,-0.23);
	glVertex2f(.1,-.16);
	glVertex2f(0.3,-0.09);
	glVertex2f(0.05,-0.0);
	glVertex2f(-1,-0.0);
	glEnd();

        glBegin(GL_QUADS);
	glColor3ub(230, 115, 0);
	glVertex2f(0.31,-.22);
	glVertex2f(0.298,-.22);
	glVertex2f(0.348,-.42);
	glVertex2f(0.36,-.42);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(230, 115, 0);
	glVertex2f(0.33,-.32);
	glVertex2f(0.33,-.312);
	glVertex2f(0.44,-.442);
	glVertex2f(0.44,-.45);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();

    glTranslatef(0,-.05,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.5,0.11);
    glVertex2f(-0.5,0.125);
    glVertex2f(-1,0.125);
    glVertex2f(-1,0.11);
    glEnd();
    glLoadIdentity();

//Boat
glPushMatrix();
glTranslatef(position4,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.6,0.3);
    glVertex2f(0.1,0.3);
    glVertex2f(0.2,0.2);
    glVertex2f(0.5,0.2);
    glEnd();
	    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 51);
    glVertex2f(0.47,0.45);
    glVertex2f(0.25,0.45);
    glVertex2f(0.215,0.39);
    glVertex2f(0.2,0.3);
    glVertex2f(0.5,0.3);
    glVertex2f(0.49,0.39);
	glEnd();
	    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(0.4,0.67);
    glVertex2f(0.29,0.7);
    glVertex2f(0.29,0.52);
    glVertex2f(0.4,0.495);
    glEnd();
        glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
    glVertex2f(0.35,0.75);
    glVertex2f(0.34,0.75);
    glVertex2f(0.34,0.45);
    glVertex2f(0.35,0.45);
    glEnd();
glPopMatrix();
glLoadIdentity();

//Sun
    int i;

	GLfloat x=-.2f; GLfloat y=.9f; GLfloat radius =.07f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 0);
		glVertex2f(x,y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
//Tree
    x=-.7f;y=.45f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    x=-.77f;y=.35f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    x=-.62f;y=.35f;radius =.1f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 204, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();

    glTranslatef(0.07,0,0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-0.97,0.14);
    glVertex2f(-0.97,-0.13);
    glVertex2f(-0.96,-0.13);
    glVertex2f(-0.96,0.14);
    glEnd();
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.105,0.25);
    glVertex2f(-0.105,0.19);
    glVertex2f(-0.095,0.19);
    glVertex2f(-0.095,0.25);
    glEnd();
        glBegin(GL_POLYGON);
	glColor3ub(230, 230, 0);
	glVertex2f(0.07,-0.11);
	glVertex2f(0.07,0.04);
	glVertex2f(0.0,0.14);
	glVertex2f(-0.1,0.2);
	glVertex2f(-0.17,0.14);
    glVertex2f(-0.25,0.04);
	glVertex2f(-0.25,-0.11);
	glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.17,-0.17);
    glVertex2f(-0.17,0.17);
    glVertex2f(-0.47,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.17,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.17,-0.17);
    glVertex2f(-0.17,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.17,0.17);
    glVertex2f(-0.47,0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.47,0.17);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.52,0.42);
    glVertex2f(-0.57,0.171);
	glVertex2f(-0.57,-0.14);
    glVertex2f(-0.47,-0.17);
    glVertex2f(-0.47,0.17);
    glVertex2f(-0.52,0.42);
	glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.57,0.171);
	glVertex2f(-0.57,-0.14);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
 	glVertex2f(-0.57,-0.14);
    glVertex2f(-0.47,-0.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.59,0.171);
    glVertex2f(-0.57,0.171);
    glVertex2f(-0.52,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.59,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.59,0.171);
    glVertex2f(-0.57,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.57,0.171);
    glVertex2f(-0.52,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.54,0.42);
    glVertex2f(-0.52,0.42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 184, 0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.15,0.171);
    glVertex2f(-0.21,0.42);
    glVertex2f(-0.54,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.15,0.171);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.15,0.171);
    glVertex2f(-0.21,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.21,0.42);
    glVertex2f(-0.54,0.42);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.48,0.171);
    glVertex2f(-0.54,0.42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.55,0.115);
	glVertex2f(-0.55,-0.148);
    glVertex2f(-0.49,-0.162);
    glVertex2f(-0.49,0.108);
	glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,0.115);
	glVertex2f(-0.55,-0.148);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,-0.148);
    glVertex2f(-0.49,-0.162);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.49,-0.162);
    glVertex2f(-0.49,0.108);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.55,0.115);
    glVertex2f(-0.49,0.108);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.52,0.112);
	glVertex2f(-0.52,-0.153);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.36,-0.05);
    glVertex2f(-0.36,0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.36,-0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.36,-0.05);
    glVertex2f(-0.36,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.36,0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.43,-0.05);
    glVertex2f(-0.43,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.395,-0.05);
    glVertex2f(-0.395,0.05);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.26,0.1);
    glVertex2f(-0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.26,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.26,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.26,0.1);
    glVertex2f(-0.35,0.1);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.35,0.1);
    glVertex2f(-0.35,-0.17);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.305,-0.17);
    glVertex2f(-0.305,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 51);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.18,-0.05);
    glVertex2f(-0.18,0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.18,-0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.18,-0.05);
    glVertex2f(-0.18,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.18,0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.25,-0.05);
    glVertex2f(-0.25,0.05);
    glEnd();
        glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.215,-0.05);
    glVertex2f(-0.215,0.05);
    glEnd();

//Phaki
glLoadIdentity();
glPushMatrix();
glTranslatef(position1,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-.7,.85);
    glVertex2f(-.718,.89);
    glVertex2f(-.745,.84);
    glVertex2f(-.76,.91);
    glVertex2f(-.76,.865);
    glVertex2f(-.78,.89);
    glVertex2f(-.765,.85);
    glVertex2f(-.79,.85);
    glVertex2f(-.775,.834);
    glVertex2f(-.74,.82);
    glEnd();

    glTranslatef(-.15,0,0);
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-.7,.85);
    glVertex2f(-.718,.89);
    glVertex2f(-.745,.84);
    glVertex2f(-.76,.91);
    glVertex2f(-.76,.865);
    glVertex2f(-.78,.89);
    glVertex2f(-.765,.85);
    glVertex2f(-.79,.85);
    glVertex2f(-.775,.834);
    glVertex2f(-.74,.82);
    glEnd();
glPopMatrix();
glLoadIdentity();

glPushMatrix();
glTranslatef(position,0.0f, 0.0f);

//Cloud
    x=-.05f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=.05f;y=.82f;radius =.095f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,1);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=.15f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glTranslatef(0.8,0,0);
    x=-.05f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=.05f;y=.82f;radius =.095f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=.15f;y=.82f;radius =.074f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
glLoadIdentity();
glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 0);
    glVertex2f(-0.74,-0.2);
	glVertex2f(-0.79,-0.27);
    glVertex2f(-0.72,-0.25);
    glVertex2f(-0.7,-0.35);
    glVertex2f(-0.67,-0.25);
    glVertex2f(-0.6,-0.27);
    glVertex2f(-0.65,-0.2);
    glVertex2f(-0.65,0.21);
    glVertex2f(-0.74,0.21);
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(153,51,0);
    glVertex2f(-0.68,0.23);
    glVertex2f(-0.68,0.28);
    glVertex2f(-0.71,0.28);
    glVertex2f(-0.71,0.16);
    glVertex2f(-0.75,0.25);
    glVertex2f(-0.78,0.25);
    glVertex2f(-0.74,0.21);
    glVertex2f(-0.65,0.21);
	glVertex2f(-0.61,0.25);
    glVertex2f(-0.64,0.25);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 102);
    glVertex2f(-0.26,-0.17);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.35,-0.17);
    glVertex2f(-0.4,-0.47);
    glVertex2f(-0.62,-1);
    glVertex2f(-0.5,-1);
    glVertex2f(-0.3,-0.47);
	glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 57, 0);
    glVertex2f(-0.6,-0.41);
    glVertex2f(-0.65,-0.39);
    glVertex2f(-0.8,-0.39);
    glVertex2f(-0.85,-0.41);
    glVertex2f(-0.85,-0.55);
    glVertex2f(-0.8,-0.57);
    glVertex2f(-0.65,-0.57);
    glVertex2f(-0.6,-0.55);
	glEnd();
	    glBegin(GL_POLYGON);
    glColor3ub(255, 102, 102);
    glVertex2f(-0.61,-0.415);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.84,-0.415);
    glVertex2f(-0.8,-0.43);
    glVertex2f(-0.65,-0.43);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
//flower
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();


glTranslatef(0.75,0.15,0);
	glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();
glLoadIdentity();
glTranslatef(0.85,0.55,0);
	glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.89,-0.83);
	glVertex2f(-0.9,-0.85);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.88);
	glEnd();
	x=-.91f; y=-.832f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,0,0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	    glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.84,-0.79);
	glVertex2f(-0.85,-0.79);
	glVertex2f(-0.85,-0.9);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.845f; y=-.772f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 51);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
		glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.79,-0.85);
	glVertex2f(-0.8,-0.83);
	glVertex2f(-0.85,-0.88);
	glVertex2f(-0.84,-0.9);
	glEnd();
	x=-.784f; y=-.83f; radius =.02f;
	triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 0, 0);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.885,-0.77);
	glVertex2f(-0.88,-0.77);
	glVertex2f(-0.843,-0.88);
	glVertex2f(-0.848,-0.9);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(51, 102, 0);
	glVertex2f(-0.802,-0.77);
	glVertex2f(-0.807,-0.77);
	glVertex2f(-0.848,-0.88);
	glVertex2f(-0.843,-0.9);
	glEnd();
glLoadIdentity();

    glTranslatef(-.07,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(0.9,-0.45);
    glVertex2f(0.8,-0.42);
    glVertex2f(0.6,-0.42);
    glVertex2f(0.5,-0.45);
    glVertex2f(0.6,-0.55);
    glVertex2f(0.8,-0.55);
	glEnd();
        glBegin(GL_TRIANGLES);
    glColor3ub(163, 163, 194);
    glVertex2f(0.6,-0.43);
    glVertex2f(0.51,-0.454);
    glVertex2f(0.6,-0.474);
    glEnd();
        glBegin(GL_QUADS);
	glColor3ub(163, 163, 194);
	glVertex2f(0.695,-0.43);
	glVertex2f(0.61,-0.43);
	glVertex2f(0.61,-0.474);
	glVertex2f(0.695,-0.474);
	glEnd();
        glBegin(GL_QUADS);
	glColor3ub(163, 163, 194);
	glVertex2f(0.79,-0.43);
	glVertex2f(0.705,-0.43);
	glVertex2f(0.705,-0.474);
	glVertex2f(0.79,-0.474);
	glEnd();
        glBegin(GL_TRIANGLES);
    glColor3ub(163, 163, 194);
    glVertex2f(0.8,-0.43);
    glVertex2f(0.89,-0.454);
    glVertex2f(0.8,-0.474);
    glEnd();
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3ub(107, 107, 71);
    glVertex2f(-0.48,-0.45);
    glVertex2f(-0.495,-0.435);
    glVertex2f(-0.545,-0.435);
    glVertex2f(-0.56,-0.45);
    glVertex2f(-0.54,-0.52);
    glVertex2f(-0.5,-0.52);
    glEnd();
        glBegin(GL_POLYGON);
    glColor3ub(45, 89, 134);
    glVertex2f(-0.485,-0.452);
    glVertex2f(-0.497,-0.442);
    glVertex2f(-0.542,-0.442);
    glVertex2f(-0.555,-0.452);
    glVertex2f(-0.542,-0.467);
    glVertex2f(-0.497,-0.467);
    glEnd();

	glFlush();  // Render now
	glutTimerFunc(5000,display1,0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("Basic Animation"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50);
	glutDisplayFunc(morning); // Register display callback handler for window re-paint
	glutTimerFunc(100, cloud, 0);
    glutTimerFunc(50, bird, 0);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, boat, 0);
    glutTimerFunc(30, rain , 0);
    sound1();
    glutMainLoop();           // Enter the event-processing loop

	return 0;
}
