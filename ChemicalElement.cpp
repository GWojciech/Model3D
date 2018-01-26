#include "ChemicalElement.h"

using namespace std;
int drawedElements;
ChemicalElement::ChemicalElement()
{
    //ctor
}
int red, green;
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

int ChemicalElement::drawRing(int number, int index, int nucleons, int colorTab[])
{
    GLfloat posY= (float)(4-index)*4.0;
    GLfloat rotation;
    if(number==0)
    {
        glPushMatrix();
            glTranslatef(0, posY, 0);
            if(colorTab[nucleons]==1){
            glColor3f(1, 0, 0);
            green++;
            }
            else{
                glColor3f(0,1,0);
                red++;
            }
            glutSolidSphere(2, 10, 10);
        glPopMatrix();
        drawedElements++;
        return 1;
    }
    else
    {
        int elements=4;
        GLfloat posX= number*3.75;
        for(int i=0; i<number; i++)
        {
            elements*=2;
        }

        if(nucleons/elements>0){
            rotation = (float)360/elements;
            drawedElements+=elements;
            for(int i=0; i<elements; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glTranslatef(posX, posY, 0);
                    if(colorTab[nucleons-i]==1){
                    glColor3f(1, 0, 0);
                    green++;
                    }
                    else{
                        glColor3f(0,1,0);
                        red++;
                    }
                    glutSolidSphere(2, 10, 10);
                glPopMatrix();
            }

        }
        else{
            rotation = (float)360/nucleons;
            elements=nucleons;
            drawedElements+=nucleons;
            for(int i=0; i<elements; i++)
            {
                glRotatef(rotation, 0, 1, 0);
                glPushMatrix();
                    glTranslatef(posX, posY, 0);
                     if(colorTab[nucleons-i]==1){
                    glColor3f(1, 0, 0);
                    green++;
                    }
                    else{
                        glColor3f(0,1,0);
                        red++;
                    }
                    glutSolidSphere(2, 10, 10);
                glPopMatrix();
            }

        }
        return elements;

    }
}

void fillZeroTab(int tab[], int numberOfElements)
{
    for(int i=0; i<numberOfElements; i++){
        tab[i]=0;
    }
}

void printTab(int tab[], int numberOfElements){
    for(int i=0; i<numberOfElements; i++){
        cout << "tab["<< i << "]: "<< tab[i] <<endl;
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


int findFreeIndexUp(int tab[]){
    int pom[9]={1,2,3,4,5,4,3,2,1};
    int valueOf4thElement=tab[4];
    for(int i=5; i<9; i++){
        if(tab[i]<valueOf4thElement&&tab[i]<=pom[i]){
            return i;
        }
    }
    return -1;
}

int findFreeIndexDown(int tab[]){
    int pom[9]={1,2,3,4,5,4,3,2,1};
    int valueOf4thElement=tab[4];
    for(int i=3; i>=0; i--){
        if(tab[i]<valueOf4thElement&&tab[i]<=pom[i]){
            return i;
        }
    }
    return -1;
}


void ChemicalElement::drawByRings(void)
{
    red=green=0;
    int last=0,tab[9], nucleons=mass, tmp, colorTab[mass];
    fillZeroTab(tab, 9);
    fillZeroTab(colorTab, mass);
    drawColors(colorTab);
    printTab(colorTab, mass);
    //nucleons-=drawRing(tab[4], 4, nucleons, colorTab);
    //tab[4]++;
    while(nucleons>0)
    {
        if(last==0)
        {
                nucleons-=drawRing(tab[4],4, nucleons, colorTab);
                tab[4]++;
                last = 1;

        }
        else if (last==1)
        {
            tmp=findFreeIndexUp(tab);
            if(tmp==-1){
                last=0;
            }
            else{
                nucleons-=drawRing(tab[tmp],tmp, nucleons, colorTab);
                tab[tmp]++;
                last = 2;
            }


        }
        else
        {
            if(tmp==-1){
                    last=0;
            }
            else{
                tmp=findFreeIndexDown(tab);
                nucleons-=drawRing(tab[tmp],tmp, nucleons, colorTab);
                tab[tmp]++;
                last = 0;
            }

        }
    }
    puts("");
    printTab(tab, 9);
    cout << "Narysowane elementy: " << drawedElements << " wymagane: " << mass << endl;
    cout << "Zielonych:" << green << " Czerwonych:"<< red << endl;
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
    //drawProtonsAndNeutronsRandom();
    drawedElements=0;
    drawByRings();
    glEndList();
}

void ChemicalElement::showPeriods(){
    cout <<"Nazwa: "<< this->name << " K="<< this->k << " L=" << this->l << " M=" << this->m
     << " N=" << this->n <<" O=" << this->o <<" P=" << this->p <<" Q=" << this->q <<  endl;

}
