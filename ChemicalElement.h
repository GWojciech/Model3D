#ifndef CHEMICALELEMENT_H
#define CHEMICALELEMENT_H

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ChemicalElement
{
public:
    ChemicalElement();
    ChemicalElement(int number);
    virtual ~ChemicalElement();
    void drawElectrons(GLuint &electrons, GLfloat electronMovementAngle);
    void drawProtonsAndNeutrons(GLuint &protonsAndNeutrons);
    void helpForDrawProtonsAndNeutrons();
    void drawByRings(void);
    void drawCircle(int elements, GLfloat x, GLfloat y);
    void drawProtonsAndNeutronsRandom();
    void showPeriods();
    int getProtons() const;
    void setProtons(int protons);
    int getNeutrons() const;
    void setNeutrons(int neutrons);
    int getK() const;
    void setK(int k);
    int getL() const;
    void setL(int l);
    int getM() const;
    void setM(int m);
    int getN() const;
    void setN(int n);
    int getO() const;
    void setO(int o);
    int getP() const;
    void setP(int p);
    int getQ() const;
    void setQ(int q);
    int getMass() const;
    void setMass(int mass);
    int getGroup() const;
    void setGroup(int group);
    int getPeriod() const;
    void setPeriod(int period);
    const string &getSymbol() const;
    void setSymbol(const string &symbol);
    const string &getName() const;
    void setName(const string &name);

protected:

private:
    int protons;
    int neutrons;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int mass;
    int group;
    int period;
    string symbol;
    string name;
};

#endif // CHEMICALELEMENT_H
