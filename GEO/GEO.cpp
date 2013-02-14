/*
 * GEO.cpp
 *
 *  Created on: 27 janv. 2013
 *      Author: KAMOUNI BELRHITI Badr
		This Lib is used to calculate the bearing , elevation and distance of your GPS coordinates in format D MM.MM , 
		the home poisition is initialized in creation of the object GEO.
		
		This Lib needs the "coordinates" librarie for the 4 returned calculated parameters
 */

#include "GEO.h"
#include <math.h>
#include "coordinates.h" // needed to save the azimuth , elevation , distance instead of using a struct format

GEO::GEO(double lat_h,double long_h,double alt_h) { // Initialization of Home Position and converting to cartesian coordinates
	
	
	    
		this->x_home = cos(degreesToRad(lat_h))*cos(degreesToRad(long_h))*6371;
		this->y_home = cos(degreesToRad(lat_h))*sin(degreesToRad(long_h))*6371;
		this->z_home =sin(degreesToRad(lat_h))*6371;
		this->long_h =long_h;
		this->lat_h= lat_h;
		this->alt_h = alt_h;
		//this->long_h = long_h;
		this->coord = new coordinates();

}
coordinates GEO::trackInfo(double lat_dr,double long_dr, double alt_dr){  // To calculate the bearing , distance and elevation beetween Home and GPS object
	
	double distance_lat;
	double distance_long;
	double x_drone = cos(this->degreesToRad(lat_dr))*cos(this->degreesToRad(long_dr))*6371;  
    double y_drone = cos(this->degreesToRad(lat_dr))*sin(this->degreesToRad(long_dr))*6371;
    double z_drone = sin(this->degreesToRad(lat_dr))*6371;
	
	this->coord->setDistance(sqrt(pow(this->x_home-x_drone,2)+pow(this->y_home-y_drone,2)+pow(this->z_home-z_drone,2))); // Calcul de la distance
    distance_lat = tan(this->degreesToRad(lat_dr)-this->degreesToRad(lat_h))*6371;
	
	
	
    this->coord->setAzimuth(this->radToDegrees(acos(distance_lat/this->coord->getDistance())));
	this->coord->setElevation(this->radToDegrees(atan((alt_dr-this->alt_h)/this->coord->getDistance())));
	
	
    

    return *(this->coord);
}
double GEO::degreesToRad(double angle){
  return (angle*3.14159265)/180;
}
double GEO::radToDegrees(double angle){
  return (angle*180)/3.14159265;
}
GEO::~GEO() {
	
}

