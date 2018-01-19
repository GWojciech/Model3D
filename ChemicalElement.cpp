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
    tmp = atoi(group.c_str());
    this->group = tmp;

    getline(file, period, ',');
    tmp = atoi(period.c_str());
    this->period=tmp;

    getline(file, k, ',');
    tmp = atoi(k.c_str());
    this->k=tmp;

    getline(file, l, ',');
    tmp = atoi(l.c_str());
    this->l=tmp;

    getline(file, m, ',');
    tmp = atoi(m.c_str());
    this->m=tmp;

    getline(file, n, ',');
    tmp = atoi(n.c_str());
    this->n=tmp;

    getline(file, o, ',');
    tmp = atoi(o.c_str());
    this->o = tmp;

    getline(file, p, ',');
    tmp = atoi(p.c_str());
    this->p = tmp;

    getline(file, q, ',');
    tmp = atoi(q.c_str());
    this->q=tmp;

    getline(file, mass, '\n');
    tmp = atoi(mass.c_str());
    this-> mass = tmp;

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

int ChemicalElement::getK() const {
    return k;
}

void ChemicalElement::setK(int k) {
    ChemicalElement::k = k;
}

int ChemicalElement::getL() const {
    return l;
}

void ChemicalElement::setL(int l) {
    ChemicalElement::l = l;
}

int ChemicalElement::getM() const {
    return m;
}

void ChemicalElement::setM(int m) {
    ChemicalElement::m = m;
}

int ChemicalElement::getN() const {
    return n;
}

void ChemicalElement::setN(int n) {
    ChemicalElement::n = n;
}

int ChemicalElement::getO() const {
    return o;
}

void ChemicalElement::setO(int o) {
    ChemicalElement::o = o;
}

int ChemicalElement::getP() const {
    return p;
}

void ChemicalElement::setP(int p) {
    ChemicalElement::p = p;
}

int ChemicalElement::getQ() const {
    return q;
}

void ChemicalElement::setQ(int q) {
    ChemicalElement::q = q;
}

int ChemicalElement::getMass() const {
    return mass;
}

void ChemicalElement::setMass(int mass) {
    ChemicalElement::mass = mass;
}

int ChemicalElement::getGroup() const {
    return group;
}

void ChemicalElement::setGroup(int group) {
    ChemicalElement::group = group;
}

int ChemicalElement::getPeriod() const {
    return period;
}

void ChemicalElement::setPeriod(int period) {
    ChemicalElement::period = period;
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

void ChemicalElement::drawElectrons(GLuint &electrons, GLfloat angle)
{
    GLfloat rotationAngle = (float)360/period;
    glDeleteLists(electrons, 1);
    electrons = glGenLists(1);
    glNewList(electrons, GL_COMPILE);
    glPushMatrix();
    GLfloat rotation = (float)360/k; // tu bêdzie liczba
    glRotatef(rotationAngle, 1,0, 0);
    for(int i=0; i<k; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glRotatef(angle, 0,1,0);
            glTranslatef(20, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidSphere(1, 10, 10);
        glPopMatrix();
    }
    rotation = (float)360/l;
    glRotatef(rotationAngle, 1,0, 0);
    for(int i=0; i<l; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glRotatef(angle, 0,1,0);
            glTranslatef(25, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidSphere(1, 10, 10);
        glPopMatrix();
    }
    rotation = (float)360/m; // tu bêdzie liczba
    glRotatef(rotationAngle, 1,0, 0);
    for(int i=0; i<m; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glRotatef(angle, 0,1,0);
            glTranslatef(30, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidSphere(1, 10, 10);
        glPopMatrix();
    }
    rotation = (float)360/n;
    glRotatef(rotationAngle, 1,0, 0);
    for(int i=0; i<n; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glRotatef(angle, 0,1,0);
            glTranslatef(35, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidSphere(1, 10, 10);
        glPopMatrix();
    }
    rotation = (float)360/o;
    glRotatef(rotationAngle, 1,0, 0);
    for(int i=0; i<o; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glRotatef(angle, 0,1,0);
            glTranslatef(40, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidSphere(1, 10, 10);
        glPopMatrix();
    }
    rotation = (float)360/p;
    glRotatef(rotationAngle, 1,0, 0);
    for(int i=0; i<p; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glRotatef(angle, 0,1,0);
            glTranslatef(45, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidSphere(1, 10, 10);
        glPopMatrix();
    }
    rotation = (float)360/q;
    glRotatef(rotationAngle, 1,0, 0);
    for(int i=0; i<q; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glRotatef(angle, 0,1,0);
            glTranslatef(50, 0, 0);
            glColor3f(0, 0, 1);
            glutSolidSphere(1, 10, 10);
        glPopMatrix();
    }
    glPopMatrix();
    glEndList();
}

void ChemicalElement::drawProtonsAndNeutrons(GLuint &protonsAndNeutrons){

    protonsAndNeutrons = glGenLists(1);
	glNewList(protonsAndNeutrons, GL_COMPILE);
        glPushMatrix();
            glTranslatef(0,8,0);
            glColor3f(0,1,0);
            glutSolidSphere(4,20,20);
        glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 0, 0);
        glColor3f(1, 0, 0);
        glutSolidSphere(4,20,20);
    glPopMatrix();

    glEndList();
}

void ChemicalElement::showPeriods(){
    cout << "K="<< this->k << " L=" << this->l << " M=" << this->m
     << " N=" << this->n <<" O=" << this->o <<" P=" << this->p <<" Q=" << endl;

}
