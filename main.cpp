#define GLUT_DISABLE_ATEXIT_HACK

#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <string>
#include <fstream>
#include <iostream>
#include "ChemicalElement.h"

using namespace std;
///Docelowa liczba ramek animacji na sekundę
#define ANIM_FPS	40
///Pierwiastek
ChemicalElement *chem;

///Kąt patrzenia w kierunku pionowym
static GLfloat lookA;
///Kąt obrotu elektronów
static GLfloat angle;
///Kąt patrzenia w kierunku poziomym
static GLfloat moveCamera;
///Wartość przybliżenia
static GLfloat zoom=1;
///Do listy elektronów
static GLuint electrons;
///Do listy protonów i neutronów
static GLuint protonsAndNeutrons;
///Do listy odpowiedzialnej za wyświetlenie informacji o pierwiastku
static GLuint informationsAboutElements;
///Parametr oświetlenia otoczenia
static GLfloat lightAmb[] = {0.1, 0.1, 0.1, 1.0};
///Parametr oświetlenia rozproszenia
static GLfloat lightDif[] = {0.7, 0.7, 0.7, 1.0};
///Parametr pozycjonowania światła
static GLfloat lightPos[] = {100, 200, 0.0, 1.0};
///Parametr oświetlenia Phonga
static GLfloat lightSpec[] = {1, 1, 1, 1};


/** \brief
 * Funkcja ustawia parametry renderowania i oświetlenie
 * wywoływana na początku programu
 */

void setupScene(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpec);
    glMateriali(GL_FRONT, GL_SHININESS, 64);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

/** \brief
 * Funkcja odpowiedzialna za odpowiednie ustawienie okna w przypadku zmiany
 * rozmiaru
 * \param w szerokość ekranu
 * \param h wysokość ekranu
 *
 */
void changeSize(int w, int h)
{
    if(h==0)	h=1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, (float)w/h, 130, 470);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/** \brief
 * Funkcja rysująca
 *
 */
void renderScene(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0, 0, -200);
    glRotatef(lookA, 1, 0, 0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glRotatef(moveCamera, 0, 1, 0);
    glPushMatrix();
    glScalef(zoom, zoom, zoom);
        if(chem){
            chem ->drawElectrons(electrons, angle);
    }
    glCallList(electrons);
    glCallList(protonsAndNeutrons);
    glCallList(informationsAboutElements);
    glPopMatrix();
glutSwapBuffers();
}

/** \brief
 * Funkcja zegarowa
 *  \param val wartość
 */
void zegarFun(int val)
{
    angle +=1.5;
    if(angle >= 360)	angle -= 360;
    glutPostRedisplay();
    glutTimerFunc(1000/ANIM_FPS, zegarFun, 0);
}

/** \brief
 * Funkcja obsługująca klawiaturę
 * \param key informacja o klawiszu (kod ASCII)
 * \param x położenie myszy na osi x (okno) po wciśnięciu klawisza
 * \param y położenie myszy na osi y (okno) po wciśnięciu klawisza
 *
 */
void keyFunc(unsigned char key, int x, int y)
{
    if(key=='w' || key=='W')    lookA += 1;
    if(key=='s' || key=='S')    lookA -= 1;
    if(key=='a' || key=='A') moveCamera -=2.5;
    if(key=='d' || key=='D') moveCamera += 2.5;
    if(key=='+'){ zoom+=0.25;}
    if(key=='-'&&zoom>1){zoom-=0.25;};
    if(key == 0x1B){
        glDeleteLists(informationsAboutElements, 1);
        glDeleteLists(electrons, 1);
        glDeleteLists(protonsAndNeutrons, 1);
        delete chem;
        exit(0);
    }
}
/** \brief
 * Funkcja wykorzystywana przy tworzeniu menu, odczytuje
 * z pliku nazwy pierwiastków i umieszcza na odpowiedniej
 * pozycji w menu
 */

void createMenu(void)
{
    ifstream file;
    file.open("namesOfElements.csv", ios::in);
    if(file.is_open())
    {
        string z;
        int i=1;
        while(file.good())
        {
            getline(file, z);
            glutAddMenuEntry(z.c_str(), i);
            i++;
        }
    }
    file.close();
}

/** \brief
 * Funkcja obsługująca menu
 * \param value Przekazana wartość po kliknięciu w daną opcję,
 * która jest tu obsługiwana
 *
 */

void menu(int value){
    if(value){
        delete chem;
        chem = new ChemicalElement(value);
        glFlush();
        chem->drawElectrons(electrons, angle);
        chem->drawProtonsAndNeutrons(protonsAndNeutrons);
        chem->showInformationsAboutElement(informationsAboutElements);
    }
    else
    {
        glDeleteLists(electrons, 1);
        glDeleteLists(protonsAndNeutrons, 1);
        glDeleteLists(informationsAboutElements, 1);
        delete chem;
        exit(0);
    }

}

/** \brief
 * Funkcja główna
 */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(960, 600);
    glutCreateWindow("Pierwiastki 3D");

    int sub1 = glutCreateMenu(menu);
    createMenu();
    glutCreateMenu(menu);
    glutAddSubMenu("Pierwiastki", sub1);
    glutAddMenuEntry("Wyjdz", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(keyFunc);

    setupScene();

    glutTimerFunc(1000/ANIM_FPS, zegarFun, 0);

    glutMainLoop();
    delete chem;
    return(0);
}
