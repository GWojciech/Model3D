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
#define ANIM_FPS	40	/* Docelowa liczba ramek animacji na sekundê */

ChemicalElement *chem;
/* Zmienne pomocnicze */
static GLfloat lookA;	/* K¹t patrzenia w kierunku pionowym */
static GLfloat angle;	/* K¹t obrotu obiektów wokó³ œrodka sceny (animacja) */
static GLfloat moveCamera;

static GLuint electrons;
static GLuint protonsAndNeutrons;

/* Parametry œwiat³a i materia³ów */
static GLfloat lightAmb[] = {0.1, 0.1, 0.1, 1.0};
static GLfloat lightDif[] = {0.7, 0.7, 0.7, 1.0};
static GLfloat lightPos[] = {100, 200, 0.0, 1.0};
static GLfloat lightSpec[] = {1, 1, 1, 1};

/* Funkcja ustawia parametry renderowania i oœwietlenie... */
/* wywo³ywana na pocz¹tku programu */
void setupScene(void)
{
    /* Bufor g³êbokoœci */
    glEnable(GL_DEPTH_TEST);
    /* W³¹czenie oœwietlenia */
    glEnable(GL_LIGHTING);

    /* Natê¿enie œwiat³a otoczenia (AMBIENT) */
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    /* Natê¿enie œwiat³a rozpraszaj¹cego (DIFFUSE) */
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
    /* Œwiat³o nr 0 umieszczone nad scen¹ z prawej strony */
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    /* Natê¿enie odb³ysków */
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
    /* W³¹czenie œwiat³a nr 0 */
    glEnable(GL_LIGHT0);

    /* Ustawienie odb³ysku materia³ów */
    glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpec);
    /* Skupienie i jasnoœæ plamy œwiat³a */
    glMateriali(GL_FRONT, GL_SHININESS, 64);

    /* Œledzenie kolorów */
    /* Wspó³czynniki odbicia œwiat³a s¹ takie same jak kolor */
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

/* Zmiana rozmiarów okna */
void ChangeSize(int w, int h)
{
    /* Zabezpieczenie przed dzieleniem przez zero */
    if(h==0)	h=1;
    /* Ustawienie widoku */
    glViewport(0, 0, w, h);

    /* Ustawienie obszaru obcinania z uwzglêdnieniem proporcji okna */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /* Rzutowanie perspektywiczne */
    gluPerspective(50, (float)w/h, 130, 470);

    /* Wyzerowanie macierzy widoku modelu dla funkcji rysuj¹cej */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


/* Funkcja rysuj¹ca */
void RenderScene(void)
{
    /* Wyczyszczenie t³a czarnym kolorem */
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Wstêpne ustawienie sceny */
    glLoadIdentity();
    /* Odsuniêcie œrodka sceny od obserwatora */
    glTranslatef(0, 0, -200);
    /* Ustawienie k¹ta obserwacji */
    glRotatef(lookA, 1, 0, 0);

    /* Pozycjonowanie œwiat³a */
    /* Œwiat³o jest nieruchome wzglêdem obiektów - one przesuwaj¹ siê pod œwiat³em */
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    /* Ustawienie pozycji kamery (poziomo) */
    glRotatef(moveCamera, 0, 1, 0);
        if(chem){
            chem ->drawElectrons(electrons, angle);
    }
    glCallList(electrons);
    glCallList(protonsAndNeutrons);

/* Zmiana bufora i opró¿nienie kolejki renderowania */
glutSwapBuffers();
}

/* Funkcja zegarowa: */
void ZegarFun(int val)
{
    /* Rotacja obiektów wokó³ œrodka sceny MOŻE TO BYĆ JESZCZE UŻYTE DO OBRACANIA SIĘ ELEKTRONOW */
    angle +=1.5;
    if(angle >= 360)	angle -= 360;
    /* Odrysowanie sceny: */
    glutPostRedisplay();
    /* Ponowne wystartowanie zegara: */
    glutTimerFunc(1000/ANIM_FPS, ZegarFun, 0);
}

/* Funkcja obs³uguj¹ca klawiaturê */
void KeyFunc(unsigned char key, int x, int y)
{
    if(key=='z' || key=='Z')    lookA += 1;
    if(key=='x' || key=='X')    lookA -= 1;
    if(key=='a' || key=='A') moveCamera -=2.5;
    if(key=='d' || key=='D') moveCamera += 2.5;
    if(key == 0x1B){
        glDeleteLists(electrons, 1);
        glDeleteLists(protonsAndNeutrons, 1);
        delete chem;
        exit(0);
    }
}

void createMenu(void){
    ifstream file ("namesOfElements.csv");

    string z;

    int i=1;
    while(file.good())
    {
    getline(file, z);
    glutAddMenuEntry(z.c_str(), i);
    i++;
    }
    file.close();
}

void menu(int value){
    if(value){
        delete chem;
        chem = new ChemicalElement(value);
        chem->showPeriods();
        glFlush();
        chem->drawElectrons(electrons, angle);
        chem->drawProtonsAndNeutrons(protonsAndNeutrons);
    }
    else
    {
        glDeleteLists(electrons, 1);
        glDeleteLists(protonsAndNeutrons, 1);
        delete chem;
        exit(0);
    }

}

/* Funkcja g³ówna */
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    /* Przygotowanie okna */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(960, 600);
    glutCreateWindow("Pierwiastki 3D");

    int sub1 = glutCreateMenu(menu);
    createMenu();
    glutCreateMenu(menu);
    glutAddSubMenu("Pierwiastki", sub1);
    glutAddMenuEntry("Wyjdz", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    /* Ustawienie funkcji rysuj¹cej zawartoœæ okna */
    glutDisplayFunc(RenderScene);
    /* Funkcja ustawiaj¹ca parametry po zmianie rozmiaru okna */
    glutReshapeFunc(ChangeSize);
    /* Funkcja obs³uguj¹ca klawiaturê */
    glutKeyboardFunc(KeyFunc);

    /* Ustawienia OpenGL */
    setupScene();

    /* Start zegara po raz pierwszy */
    glutTimerFunc(1000/ANIM_FPS, ZegarFun, 0);
    /* Wejœcie do g³ównej pêtli programu */
    glutMainLoop();
    delete chem;
    return(0);
}
