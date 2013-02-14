/*
 * GEO.h
 *
 *  Created on: 27 janv. 2013
 *      Author: HP
 */
#include "coordinates.h"
#ifndef GEO_H_
#define GEO_H_
#define RAYON  (double)6371000.0;;
class GEO {
public:
	double x_home, y_home, z_home, lat_h,alt_h,long_h;/*Decalarations attributs */
	

	coordinates* coord;



public:
	GEO(double lat_h,double long_g,double alt_h);
	virtual ~GEO();
	/* retourne les coordonnés polaires du drone par rapport à la station fixe */
	coordinates trackInfo(double at_dr,double long_dr, double alt_dr);
	/* retourne les coordonnés polaires du drone par rapport à la station mobile */
	coordinates trackInfoMobile(double lat_h,double long_h,double alt_h,double at_dr,double long_dr, double alt_dr);

	private :
	double degreesToRad(double angle);
	double radToDegrees(double angle);
	

};

#endif /* GEO_H_ */
