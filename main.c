// main.c
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LEN 10

int windowWidth = 600, windowHeight = 250;
char inputBuffer[MAX_INPUT_LEN + 1] = "";
int inputPos = 0;
int m = 0, n = 0;
int inputState = 0; // 0 = input m, 1 = input n, 2 = done/displaying
int rand_i = 0, rand_j = 0;

// Button geometry
const int btn1X = 20,       btnY = 20;
const int btnW  = 120,      btnH = 40;
const int btnGap = 20;
const int btn2X = btn1X + btnW + btnGap;

void renderBitmapString(float x, float y, void *font, const char *string) {
    glRasterPos2f(x, y);
    for (; *string; ++string)
        glutBitmapCharacter(font, *string);
}

void drawButton(int x, int y, int w, int h, const char *label) {
    // fill
    glColor3f(0.2f, 0.5f, 0.8f);
    glBegin(GL_QUADS);
      glVertex2i(x,     y);
      glVertex2i(x + w, y);
      glVertex2i(x + w, y + h);
      glVertex2i(x,     y + h);
    glEnd();
    // border
    glColor3f(1,1,1);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
      glVertex2i(x,     y);
      glVertex2i(x + w, y);
      glVertex2i(x + w, y + h);
      glVertex2i(x,     y + h);
    glEnd();
    // label
    glColor3f(1,1,1);
    // approximate centering
    renderBitmapString(x + 10, y + 12, GLUT_BITMAP_HELVETICA_18, label);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    if (inputState == 0) {
        char prompt[64];
        snprintf(prompt, sizeof(prompt), "Enter rows (m): %s", inputBuffer);
        renderBitmapString(20, 180, GLUT_BITMAP_HELVETICA_18, prompt);
    }
    else if (inputState == 1) {
        char prompt[64];
        snprintf(prompt, sizeof(prompt), "Enter cols (n): %s", inputBuffer);
        renderBitmapString(20, 180, GLUT_BITMAP_HELVETICA_18, prompt);
    }
    else {
        char result[64];
        snprintf(result, sizeof(result), "A = [a_{%d,%d}]", rand_i, rand_j);
        renderBitmapString(20, 180, GLUT_BITMAP_HELVETICA_18, result);

        // Draw both buttons
        drawButton(btn1X,  btnY, btnW, btnH, "Randomize");
        drawButton(btn2X,  btnY, btnW, btnH, "Quit");
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (inputState < 2) {
        if (key >= '0' && key <= '9' && inputPos < MAX_INPUT_LEN) {
            inputBuffer[inputPos++] = key;
            inputBuffer[inputPos] = '\0';
        }
        else if ((key == 8 || key == 127) && inputPos > 0) {
            inputBuffer[--inputPos] = '\0';
        }
        else if (key == 13) { // Enter
            if (inputState == 0) {
                m = atoi(inputBuffer);
            } else {
                n = atoi(inputBuffer);
            }
            inputState++;
            inputPos = 0;
            inputBuffer[0] = '\0';
            if (inputState == 2) {
                srand((unsigned)time(NULL));
                rand_i = (rand() % m) + 1;
                rand_j = (rand() % n) + 1;
            }
        }
        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y) {
    if (inputState == 2 && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int winY = windowHeight - y;
        // Randomize button?
        if (x >= btn1X && x <= btn1X + btnW &&
            winY >= btnY && winY <= btnY + btnH)
        {
            rand_i = (rand() % m) + 1;
            rand_j = (rand() % n) + 1;
            glutPostRedisplay();
        }
        // Quit button?
        else if (x >= btn2X && x <= btn2X + btnW &&
                 winY >= btnY && winY <= btnY + btnH)
        {
            exit(0);
        }
    }
}

void reshape(int w, int h) {
    windowWidth = w;  windowHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Matrix Random Element");

    glClearColor(0,0,0,1);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
