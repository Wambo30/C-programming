#ifndef Spaceship_h
#define Spaceship_h
//davor stand Spaceship_hh
#include <iostream>


//class Laser;
class Spaceship {
public:
	Spaceship(float startHealth, Laser& laser1):totalHealth(startHealth), health(startHealth),laser(laser1){}

	void applyDamage(float damage) { 
		health -= damage; 
		if (health <= 0) throw "BIG EXPLOSION";
	}

	float getRelativeHealth() const {
		return health / totalHealth;
	}

	const Laser& getLaser() const { return laser; }

private:
	float totalHealth;
	float health;
	Laser& laser;

};


class Laser {
public:
	Laser() : shotCount(0){}
	void shootLaser(Spaceship& enemyShip) {
		enemyShip.applyDamage(DAMAGE_PER_SHOT);
		++shotCount;
	}


private:
	int shotCount;
	static float DAMAGE_PER_SHOT;

};

 float Laser::DAMAGE_PER_SHOT = 90.01f;
 /*
 bzgl damage per shot ==> so ists korrekt da
 1) static const variable muss immer in public von klasse stehen
 damit es für jedes objekt zur verfügung steht und kann auch da initialisiert werden
 2)rein static var wird immer in der main initialisiert oder außerhalb der klasse
 3) schlüsselwort static bei rein static vars wird NUR einmal im header benutzt

 */


#endif