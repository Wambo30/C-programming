#include "DatumStaticConst.h"
#include <iostream>
using namespace std;

DatumStaticConst::DatumStaticConst() : tag(1),monat(1), jahr(STARTJAHR) {}

DatumStaticConst::DatumStaticConst(int t,int m,int j): tag(t),monat(m),jahr(j){}

DatumStaticConst::~DatumStaticConst(){}


void DatumStaticConst::setTag(int t) {tag = t;}

void DatumStaticConst::setMonat(int m) {monat = m;}

void DatumStaticConst::setJahr(int j) {	jahr = j;}

int DatumStaticConst::getTag() const {return tag;}

int DatumStaticConst::getMonat() const {return monat;}

int DatumStaticConst::getJahr() const {return jahr;}