#include "ChemicalElement.h"

using namespace std;
ChemicalElement::ChemicalElement()
{
    //ctor
}
ChemicalElement::ChemicalElement(int number)
{
    ifstream file;
    file.open("elements.csv", ios::in);
    if(file.is_open())
    {
        string value;
        string protons, neutrons, k, l, m, n, o, p, q;
        string symbol, name, group, period, mass;
        for(int i=0; i<number; i++)
        {
            getline(file, value);
        }
        getline(file, symbol, ',');
        this->symbol=symbol;

        getline(file, protons, ',');
        int tmp = atoi(protons.c_str());
        this->protons = tmp;

        getline(file, neutrons, ',');
        tmp = atoi(neutrons.c_str());
        this->neutrons=tmp;

        getline(file, name, ',');
        this->name=name;

        getline(file, group, ',');
        this->group = group;

        getline(file, period, ',');
        tmp = atoi(period.c_str());
        this->period=tmp;

        getline(file, k, ',');
        tmp = atoi(k.c_str());
        this->periods[0]=tmp;

        getline(file, l, ',');
        tmp = atoi(l.c_str());
        this->periods[1]=tmp;

        getline(file, m, ',');
        tmp = atoi(m.c_str());
        this->periods[2]=tmp;

        getline(file, n, ',');
        tmp = atoi(n.c_str());
        this->periods[3]=tmp;

        getline(file, o, ',');
        tmp = atoi(o.c_str());
        this->periods[4] = tmp;

        getline(file, p, ',');
        tmp = atoi(p.c_str());
        this->periods[5] = tmp;

        getline(file, q, ',');
        tmp = atoi(q.c_str());
        this->periods[6]=tmp;

        getline(file, mass, '\n');
        tmp = atoi(mass.c_str());
        this-> mass = tmp;
    }
    file.close();

}

ChemicalElement::~ChemicalElement()
{
    //dtor
}


int ChemicalElement::getProtons() const {
    return protons;
}

void ChemicalElement::setProtons(int protons) {
    ChemicalElement::protons = protons;
}

int ChemicalElement::getNeutrons() const {
    return neutrons;
}

void ChemicalElement::setNeutrons(int neutrons) {
    ChemicalElement::neutrons = neutrons;
}


int ChemicalElement::getMass() const {
    return mass;
}

void ChemicalElement::setMass(int mass) {
    ChemicalElement::mass = mass;
}


int ChemicalElement::getPeriod() const {
    return period;
}

void ChemicalElement::setPeriod(int period) {
    ChemicalElement::period = period;
}

const string &ChemicalElement::getGroup() const {
    return group;
}

void ChemicalElement::setGroup(const string &group) {
    ChemicalElement::group = group;
}

const string &ChemicalElement::getSymbol() const {
    return symbol;
}

void ChemicalElement::setSymbol(const string &symbol) {
    ChemicalElement::symbol = symbol;
}

const string &ChemicalElement::getName() const {
    return name;
}

void ChemicalElement::setName(const string &name) {
    ChemicalElement::name = name;
}

void ChemicalElement::drawPeriod(int numberOfElectrons, int index, GLfloat electronMovementAngle){
    GLfloat rotation = (float)360/numberOfElectrons;
    GLfloat x =(float) 40 + index*5;

        glPushMatrix();
            for(int i=0; i<numberOfElectrons; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(x, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
}

void ChemicalElement::drawElectrons(GLuint &electrons, GLfloat electronMovementAngle){
    glDeleteLists(electrons, 1);
    electrons = glGenLists(1);
    glNewList(electrons, GL_COMPILE);
    GLfloat rotationAngle = (float) 360/period;
    glPushMatrix();
        for(int i=0; i<period; i++){
            if(periods[i]){
                glRotatef(rotationAngle, 1, 1, 1);
                drawPeriod(periods[i], i, electronMovementAngle);
            }
        }
    glPopMatrix();
    glEndList();
}


int ChemicalElement::drawRing(int number, int index, int nucleons, int colorTab[])
{
    GLfloat posY= (float)(4-index)*2.00;
    GLfloat rotation;
    if(number==0)
    {
        glPushMatrix();
            glTranslatef(0, posY, 0);
            if(colorTab[nucleons]==1){
            glColor3f(1, 0, 0);
            }
            else{
                glColor3f(0,1,0);
            }
            glutSolidSphere(2, 10, 10);
        glPopMatrix();
        return 1;
    }
    else
    {
        int elements=4;
        GLfloat posX= number*2.75;
        for(int i=0; i<number; i++)
        {
            elements*=2;
        }

        if(nucleons/elements>0){
            rotation = (float)360/elements;
            for(int i=0; i<elements; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glTranslatef(posX, posY, 0);
                    if(colorTab[nucleons-i]==1){
                    glColor3f(1, 0, 0);
                    }
                    else{
                        glColor3f(0,1,0);
                    }
                    glutSolidSphere(2, 10, 10);
                glPopMatrix();
            }

        }
        else{
            rotation = (float)360/nucleons;
            elements=nucleons;
            for(int i=0; i<elements; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glTranslatef(posX, posY, 0);
                     if(colorTab[nucleons-i]==1){
                    glColor3f(1, 0, 0);
                    }
                    else{
                        glColor3f(0,1,0);
                    }
                    glutSolidSphere(2, 10, 10);
                glPopMatrix();
            }

        }
        return elements;

    }
}

void ChemicalElement::drawColors(int tab[]){
    srand(time(0));
    int neutronsTmp=neutrons, protonsTmp=protons, drawNumber;
    for(int i=0; i<mass; i++){
        drawNumber=rand()%2;
        if(drawNumber==1&&protonsTmp){
            tab[i]=1;
            protonsTmp--;
        }
        else if(drawNumber==0&&neutronsTmp){
            tab[i]=2;
            neutronsTmp--;
        }
        else if(drawNumber==1&&neutronsTmp){
            tab[i]=2;
            neutronsTmp--;
        }
        else if(drawNumber==0&&protonsTmp){
            tab[i]=1;
            protonsTmp--;
        }
}
}


void ChemicalElement::drawByRings(void)
{
    int last=0,tab[9], nucleons=mass, colorTab[mass];
    fillZeroTab(tab, 7);
    fillZeroTab(colorTab, mass);
    drawColors(colorTab);

    while(nucleons>0)
    {
        if(last==0)
        {
            nucleons-=drawRing(tab[3],3, nucleons, colorTab);
            tab[3]++;
            if(tab[3]-tab[4]==2&&tab[3]-tab[2]==2){
                last=1;
            }
            else{
                last=0;
            }

        }
        else if (last==1)
        {
            nucleons-=drawRing(tab[2],2, nucleons, colorTab);
            tab[2]++;
            last = 2;

        }
        else if(last==2)
        {

            nucleons-=drawRing(tab[4],4, nucleons, colorTab);
            tab[4]++;
            if(((tab[4]-tab[5])==2)&&((tab[2]-tab[1])==2))
            {
                last = 3;
            }
            else
            {
            last = 0;
            }

        }
        else if(last==3)
        {

            nucleons-=drawRing(tab[1],1, nucleons, colorTab);
            tab[1]++;
            last = 4;


        }
        else if(last==4)
        {
            nucleons-=drawRing(tab[5],5, nucleons, colorTab);
            tab[5]++;
            if(tab[1]-tab[0]==2&&tab[5]-tab[6]==2){
                last=5;
            }
            else{
                last=0;
            }
        }
        else if(last==5){
            nucleons-=drawRing(tab[0],0, nucleons, colorTab);
            tab[0]++;
            last = 6;
        }
        else if(last==6){
            nucleons-=drawRing(tab[6],6, nucleons, colorTab);
            tab[6]++;
            last = 0;
        }
    }
}


void ChemicalElement::drawProtonsAndNeutrons(GLuint &protonsAndNeutrons){
    glDeleteLists(protonsAndNeutrons, 1);
    protonsAndNeutrons = glGenLists(1);
	glNewList(protonsAndNeutrons, GL_COMPILE);
    drawByRings();
    glEndList();
}



void ChemicalElement::showInformationsAboutElement(GLuint &informationsAboutElement)
{
    glDeleteLists(informationsAboutElement, 1);
    string informations;
    informations = "<Nazwa:" + name + "> <Symbol:"+ symbol + "> <Protony:" + intToStr(protons) +
                   + "> <Neutrony:" + intToStr(neutrons) + "> <Grupa:" + group + ">";
    informationsAboutElement= glGenLists(1);
	glNewList(informationsAboutElement, GL_COMPILE);
    glColor3f(1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 1024, 0, 768, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(10, 730);
    for (unsigned int i=0; i<informations.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, informations[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEndList();
}
