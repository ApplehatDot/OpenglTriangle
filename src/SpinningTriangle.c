/*  SpinningTriangle - rewritten for Freeglut library
 *           27th of December 2024
 *  Github: ApplehatDoesStuff (ApplehatDot)
 */

#include <GL/freeglut.h>
#include <GL/glut.h>

#define WindowHeight 256
#define WindowWidth 256

float theta = 0.0f;

void Timer(int value){
     theta += 1.0f;
     
     glutPostRedisplay();
     glutTimerFunc(10, Timer, 0);        // call function after 1 ms
}

void reshape(int w, int h){
     glViewport(0, 0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-1, 1, -1, 1);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glutReshapeWindow(WindowWidth, WindowHeight);
}

void display(){
     glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
     glClear (GL_COLOR_BUFFER_BIT);
     
     glPushMatrix ();
     glRotatef (theta, 0.0f, 0.0f, 1.0f);
     
     glBegin (GL_TRIANGLES);
             glColor3f (1.0f, 0.0f, 0.0f);   
             glVertex2f (0.0f, 1.0f);

             glColor3f (0.0f, 1.0f, 0.0f);   
             glVertex2f (0.87f, -0.5f);
     
             glColor3f (0.0f, 0.0f, 1.0f);   
             glVertex2f (-0.87f, -0.5f);
     glEnd ();
     glPopMatrix ();

     glutSwapBuffers();  // changed from SwapBuffers(); - since using glut
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Sample");
    
    // initializing OpenGL 
    glEnable(GL_COLOR_MATERIAL);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(10, Timer, 0);
    
    glutMainLoop();
    return 0;    
}
