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

void ChemicalElement::drawElectrons(GLuint &electrons, GLfloat electronMovementAngle)
{

    glDeleteLists(electrons, 1);
    electrons = glGenLists(1);
    glNewList(electrons, GL_COMPILE);
    GLfloat rotation = (float)360/k; // tu bêdzie liczba
    GLfloat rotationAngle = (float)360/period;
    glPushMatrix();
        glRotatef(rotationAngle, 1, 1, 1);
        glPushMatrix();
            for(int i=0; i<k; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(40, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
        rotation = (float)360/l;
        glRotatef(rotationAngle, 1, 1, 1);
        glPushMatrix();
            for(int i=0; i<l; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(45, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
        rotation = (float)360/m; // tu bêdzie liczba
        glRotatef(rotationAngle, 1, 1, 1);
        glPushMatrix();
            for(int i=0; i<m; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(50, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
        rotation = (float)360/n;
        glRotatef(rotationAngle, 1, 1, 1);
        glPushMatrix();
            for(int i=0; i<n; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(55, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
        rotation = (float)360/o;
        glRotatef(rotationAngle, 1, 1, 1);
        glPushMatrix();
            for(int i=0; i<o; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(60, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
        rotation = (float)360/p;
        glRotatef(rotationAngle, 1, 1, 1);
        glPushMatrix();
            for(int i=0; i<p; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(65, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
        rotation = (float)360/q;
        glRotatef(rotationAngle, 1, 1, 1);
        glPushMatrix();
            for(int i=0; i<q; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glRotatef(electronMovementAngle, 0,1,0);
                    glTranslatef(70, 0, 0);
                    glColor3f(0, 0, 1);
                    glutSolidSphere(1, 10, 10);
                glPopMatrix();
            }
        glPopMatrix();
    glPopMatrix();
    glEndList();
}

void drawRing(GLfloat x, GLfloat y, int elements)
{
    GLfloat rotation = (float)360/elements;
    for(int i=0; i<elements; i++)
    {
        glRotatef(rotation, 0, 1, 0);
        glPushMatrix();
            glTranslatef(x, y, 0);
            glColor3f(0, 1, 0);
            glutSolidSphere(2, 10, 10);
        glPopMatrix();
    }
}

void ChemicalElement::drawByRings(void){
    int tmp = mass-1, elements=8;
    GLfloat x=4, y=0;
    glColor3f(0,1,0);
    glutSolidSphere(2,10,10);
    while(tmp){
        if(tmp!=(mass-1)){
        elements*=2;
        }
        if(tmp/elements){
            tmp-=elements;
            drawRing(x,y,elements);
            x=-x;
            y+=4;
            if(tmp){
                tmp--;
                glPushMatrix();
                    glTranslatef(0,y,0);
                    glutSolidSphere(2,10,10);
                glPopMatrix();
            }
            if(tmp){
                tmp--;
                glPushMatrix();
                    glTranslatef(0,-y,0);
                    glutSolidSphere(2,10,10);
                glPopMatrix();
                x+=4;
                y+=4;
            }
        }
        else
            drawRing(x,y,(int)tmp);
            tmp=0;
    }


}

void ChemicalElement::drawProtonsAndNeutronsRandom(void){
    srand(time(0));
    GLfloat x,y,z;
    glColor3f(0,1,0);
    if(mass<=10){
    for(int i=0; i<mass; i++){
        x=-mass+rand()%mass;
        y=-mass+rand()%mass;
        z=-mass+rand()%mass;
        glPushMatrix();
            glTranslatef(x,y,z);
            glutSolidSphere(2,10,10);
        glPopMatrix();
    }
    }
    else if(mass >10 && mass <=50){
        for(int i=0; i<mass; i++){
        x=-mass/2+rand()%mass;
        y=-mass/2+rand()%mass;
        z=-mass/2+rand()%mass;
        glPushMatrix();
            glTranslatef(x/6,y/6,z/6);
            glutSolidSphere(2,10,10);
        glPopMatrix();
    }
    }
        else if(mass >50 && mass <=100){
        for(int i=0; i<mass; i++){
        x=-mass/2+rand()%mass;
        y=-mass/2+rand()%mass;
        z=-mass/2+rand()%mass;
        glPushMatrix();
            glTranslatef(x/7,y/7,z/7);
            glutSolidSphere(2,10,10);
        glPopMatrix();
    }
    }
    else if(mass>100 && mass <200){
        for(int i=0; i<mass; i++){
        x=-mass/2+rand()%mass;
        y=-mass/2+rand()%mass;
        z=-mass/2+rand()%mass;
        glPushMatrix();
            glTranslatef(x/8,y/8,z/8);
            glutSolidSphere(2,10,10);
        glPopMatrix();
    }
    }
    else{
        for(int i=0; i<mass; i++){
        x=-mass/2+rand()%mass;
        y=-mass/2+rand()%mass;
        z=-mass/2+rand()%mass;
        glPushMatrix();
            glTranslatef(x/10,y/10,z/10);
            glutSolidSphere(2,10,10);
        glPopMatrix();
    }
    }
}

void ChemicalElement::drawProtonsAndNeutrons(GLuint &protonsAndNeutrons){
    glDeleteLists(protonsAndNeutrons, 1);
    protonsAndNeutrons = glGenLists(1);
	glNewList(protonsAndNeutrons, GL_COMPILE);
    drawProtonsAndNeutronsRandom();
    //drawByRings();
    glEndList();
}

void ChemicalElement::showPeriods(){
    cout <<"Nazwa: "<< this->name << " K="<< this->k << " L=" << this->l << " M=" << this->m
     << " N=" << this->n <<" O=" << this->o <<" P=" << this->p <<" Q=" << this->q <<  endl;

}
