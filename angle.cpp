#include <string.h>
#include <math.h>

class Angle { //Class for Angle convertions
    public:
        float DegToRad(float degree) {                              //Convert angle in degree to rad
            return degree*M_PI/180;
        }

        float RadToDeg(float radians) {                             //Convert angle in rad to degree
            return radians*180/M_PI;
        }

        float DegToMOA(float degree) {                              //Convert angle in degree to MOA
            return degree*60;
        }

        float RadToMOA(float radians) {                             //Convert angle in radians to MOA
            return radians*60*180/M_PI;
        }

        float MOAToDeg(float moavalue) {                            //Convert MOA to degree
            return moavalue/60;
        }

        float MOAToRad(float moavalue) {                            //Convert MOA to radians
            return moavalue/60*M_PI/180;
        }

        float MILToRad(float miliradians) {                         //Convert miliradians to radians
            return miliradians/1000;
        }

        float MILToDeg(float miliradians) {                         //Convert miliradians to degree
            return (miliradians/1000)*180/M_PI;
        }

        float MILToMOA(float miliradians)   {                       //Convert miliradians to MOA
            return (miliradians/1000)*60*180/M_PI;
        }

        float MOAAtDistance(float moavalue, float distance) {       //Get value in meter of dispersion for distance (Distance in meter)
            return tan(MOAToRad(moavalue))*distance;
        }

        float MILAtDistance(float miliradians, float distance) {    //Get value in meter of dispersion for distance (Distance in meter)
            return tan(MILToRad(miliradians))*distance;
        }
};
