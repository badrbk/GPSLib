/*
 * ExtractGpsCordinate.cpp
 *
 *  Created on: 28 janv. 2013
 *      Author: Administrateur
 */

#include "ExtractGpsCordinate.h"
#include "CoordonneGPS.h"
#include <cstdlib.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arduino.h>
#include <malloc.h>

CoordonneGPS* ExtractGpsCordinate::coordonnee = new CoordonneGPS(); //!!!! Declaration d'attributs static en dehors de la classe /!\ OUFFFF!!!
ExtractGpsCordinate::ExtractGpsCordinate() { //Construceteur analogie avec java  ExtractGpsCordinate(){       }
	// ! Pas d'attributs static à declarer contrairement à Java : This.coordonnee = new cordoneeGPS();
	 

}
CoordonneGPS ExtractGpsCordinate::getNMEAGGAcoord(char* trameGGA ){
	
    char *fld;
	// /!\ Extraction la latitude qui est le champs 2 de la trame NMEA GPGGA 
    
    if ((fld = ExtractGpsCordinate::getFld (trameGGA, ',', 2)) != NULL) {
		
		//ExtractGpsCordinate::coordonnee->latitude =  atof((const char* )fld );
		ExtractGpsCordinate::coordonnee->latitude =  DecimalCoordinates(fld); // Conversion en decimal
        free (fld);
    }
	// /!\ Extraction la longitude qui est le champs 4 de la trame NMEA GPGGA 
    if ((fld = ExtractGpsCordinate::getFld (trameGGA, ',', 4)) != NULL) {
        ExtractGpsCordinate::coordonnee->longitude =  DecimalCoordinates(fld);  // Conversion en decimal
        free (fld);
    }
		// /!\ Extraction l'altitude qui est le champs 10 de la trame NMEA GPGGA
	  if ((fld = ExtractGpsCordinate::getFld (trameGGA, ',', 10)) != NULL) {
        ExtractGpsCordinate::coordonnee->elevation =  atof((const char* )fld );
        free (fld);
    }
	// /!\ Extraction du nombre de satelites recus qui est le champs 7 de la trame NMEA GPGGA
	if ((fld = ExtractGpsCordinate::getFld (trameGGA, ',', 7)) != NULL) {
        ExtractGpsCordinate::coordonnee->nbrSat =  atoi(fld) ;
        free (fld);
    }
	
	return *(ExtractGpsCordinate::coordonnee);

}

char* ExtractGpsCordinate::getFld (char *srchStr, char delim, int numFld){ // FCT pour extraire les champs qu'on veut sur une chaine de caractere
char *copyStr, *retStr, *tmpStrPtr, delims[2];

    // Make a copy so as to not damage original.

    if ((copyStr = strdup (srchStr)) == NULL) return NULL;

    // Create delimiter string from character.

    delims[0] = delim; delims[1] = '\0';
    retStr = NULL;

    // Start loop, extracting fields.

    tmpStrPtr = strtok (copyStr, delims);
    while (tmpStrPtr != NULL) {
        // If this is the field we want, make a copy.

        if (numFld == 0) retStr = strdup (tmpStrPtr);

        // Get next field.

        tmpStrPtr = strtok (NULL, delims);
        numFld--;
    }

    // Clean up, return field copy (must be freed eventually) or NULL.

    free (copyStr);
    return retStr;
}

double ExtractGpsCordinate::DecimalCoordinates(char* coordonneExtraiteChar){
		double coordonneExtraite = atof((const char* )coordonneExtraiteChar);																	// Analogie au java this.cooodonne.latitude = atof((const char* )fld );
		// la trame NMEA est de Type 4500,7600 ==> 45 deg et 00,7600 min il faudra la mettre sous format decimal DD,DDDDD
		int partie_deg = (int)coordonneExtraite /100 ;    // Partons de l'exemple 4500,7600 = fld, on fait 4500,7600 / 100 = 45,007600 et on retient juste la partie sans virgule donc 45
		
		double partie_minutes = (coordonneExtraite - (partie_deg * 100))  / 60 ;
		if ( partie_minutes < 0){partie_minutes = - partie_minutes; }
		
		double coordonnee_decimal = partie_minutes + partie_deg;
		return coordonnee_decimal;
		}
		

ExtractGpsCordinate::~ExtractGpsCordinate() {
	// TODO Auto-generated destructor stub
}
