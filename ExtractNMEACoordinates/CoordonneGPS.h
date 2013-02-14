/*
 * CoordonneGPS.h
 *
 *  Created on: 28 janv. 2013
 *      Author: Administrateur
 */

#ifndef COORDONNEGPS_H_
#define COORDONNEGPS_H_

class CoordonneGPS {
public :
	//Attributs

	double longitude;
	double latitude;
	double elevation;
	double vitesse;
	int nbrSat;
	//char hemisphereLatitude[2];
	//char greenwichLongitude[2];


public:
	CoordonneGPS();
	double getElevation();
	double getLatitude();
	double getLongitude();
	double getVitesse();
	void setElevation(double elevation);
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void setVitesse(double vitesse);


	virtual ~CoordonneGPS();
};

#endif /* COORDONNEGPS_H_ */
