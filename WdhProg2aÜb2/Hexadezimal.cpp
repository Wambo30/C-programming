#include "Hexadezimal.h"

/*
bsp hexazahl

1278 in 10er system
1278: 16 = 79 Rest: 14 (= E) (Nr:1278-(79*16)=14)
79: 16 =  4 Rest: 15 (= F) (Nr:79-(4*16)=15)
4: 16 =  0 Rest:  4       (Nr:4-(0*16)=4)

4FE = 4*16^2 + 15*16^1+ 14*16^0 = 1278 in 10 er system


*/



Hexadezimal::Hexadezimal(int i)
{
	switch (i) {
	
	case 0:
		i % 16 == 0;
		
	case 1:
		i % 16 == 1;

	case 2: 
		i % 16 == 2;

	case 3:
		i % 16 == 3;

	case 4:
		i % 16 == 4;



	}
}


Hexadezimal::~Hexadezimal()
{
}
