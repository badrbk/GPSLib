
#include <GEO.h>
#include <coordinates.h>
#include <arduino.h>
#include <GPS.h>


GEO* geo; // geo = GEO(44.136135,4.800502,3);


GPS gpsa(&Serial, 20000, 100);
double azi;
GPS_status_enum result;
char sentence[88];

void setup(){
  Serial.begin(9600);
	geo=  new GEO(44.136135,4.800502,3);

}
void loop(){
 result = gpsa.readGGA(sentence);
	Serial.println(result);
	Serial.println(sentence);
	sentence[0] = '\0';
	//geo->getX();   // eqv (*geo).getX();

  }

