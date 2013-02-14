/*
 * coordinates.h
 *
 *  Created on: 27 janv. 2013
 *      Author: HP
 */

#ifndef COORDINATES_H_
#define COORDINATES_H_
/*classe contenant les 3 variables utilisables pour le tracking
 * ces 3 variables c'est les angles < 360°
 *
 */
class coordinates {
public:
	double elevation;
	double azimuth;
	double distance;

	coordinates();
	virtual ~coordinates();
	double getElevation();
	double getAzimuth();
	double getDistance();
	void setElevation(double elevation);
	void setAzimuth(double azimuth);
	void setDistance(double distance);
};

#endif /* COORDINATES_H_ */
