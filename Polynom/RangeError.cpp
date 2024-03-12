/*
 *  RangeError.cpp
 *  Programmieren IIb - Uebung 3, Aufgabe 4
 */
 
#include "RangeError.h" 

RangeError::RangeError() 
: out_of_range("FEHLER: Der Index uebersteigt das Grad des Polynoms!") {}
/* Der Konstruktor der Klasse out_of_range erwartet als Parameter einen string */
