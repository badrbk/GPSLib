/*
 * ExtractGpsCordinate.h
 *
 *  Created on: 28 janv. 2013
 *      Author: KAMOUNI BELRHITI Badr
 */
#include "CoordonneGPS.h"
#ifndef EXTRACTGPSCORDINATE_H_
#define EXTRACTGPSCORDINATE_H_
#define MAX_NMEA_SENTENCE_LENGTH 85 // NMEA 0183 maximum is 82

class ExtractGpsCordinate {
	// ****Debut declaration Attributs *******
public :
	static CoordonneGPS* coordonnee;
// ****Fin declaration Attributs *******
// ***********Debut declaration de methodes **********
public:

	ExtractGpsCordinate();
	static CoordonneGPS getNMEAGGAcoord(char* trameGGA );
	static double DecimalCoordinates(char* coordonneExtraiteChar);
	static char* getFld (char *srchStr, char delim, int numFld);

	virtual ~ExtractGpsCordinate();
private:
// ***********Fin declaration de methodes **********
};

#endif /* EXTRACTGPSCORDINATE_H_ */
