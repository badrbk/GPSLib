/*
 * coordinates.cpp
 *
 *  Created on: 27 janv. 2013
 *      Author: HP
 */

#include "coordinates.h"

coordinates::coordinates() {
	
	this->elevation= 0;
	this->azimuth=0;
	this->distance=0;



}
double coordinates::getElevation(){return this->elevation;}
	double coordinates::getAzimuth(){return this->azimuth;}
	double coordinates::getDistance(){return this->distance;}
	void coordinates::setElevation(double elevation){
		this->elevation=elevation;
		 while (this->elevation > 360){ this->elevation -= 360;}
	}
	void coordinates::setAzimuth(double azimuth){
		this->azimuth=azimuth;
		while (this->azimuth > 360){ this->azimuth -= 360;}
	}
	void coordinates::setDistance(double distance){this->distance=distance;}


coordinates::~coordinates() {
	
}

