/*
 *  DateError.h
 *  Programmieren IIb - Uebung 3, Aufgabe 2
 *
 */

#ifndef DATEERROR_H
#define DATEERROR_H

class DateError {
public:
    DateError(int t, int m, int j);
    virtual	void meldung() const;

protected:
    int tag, monat, jahr;
};

class InvalidDayError: public DateError {
public:
    InvalidDayError(int t, int m, int j);
    virtual	void meldung() const;
};

class InvalidMonthError: public DateError {
public:
    InvalidMonthError(int t, int m, int j);
    virtual	void meldung() const;
};

class InvalidYearError: public DateError {
public:
    InvalidYearError(int t, int m, int j);
    virtual	void meldung() const;
};


#endif //DATEERROR_H
