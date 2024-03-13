/* KlasseA.h  */
#ifndef KLASSEA_H
#define KLASSEA_H

/* KlasseA */
class KlasseA {
public:
	KlasseA();

private:
	int z;
};

/* KlasseB */
class KlasseB : public KlasseA {
public:
	KlasseB();

private:
	double x;
};
#endif // KLASSEA_H
