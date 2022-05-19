#include <string.h>
#include <math.h>
#include "angle.cpp"

#define STRING(num) #num

//Unit use by Angle
enum Unit {
    MOA,                                            //Scope unit is in minute of angle (1/60 degree)
    MIL,                                            //Scope unit is in miliradians
    DEG,                                            //Scope unit is in deg. Usefull for define user unit
    RAD,                                            //Scope unit is in RAD. Usefull for define user unit
};

class Scope {                                       //Class for define scope before ballistic calc
    private:
        std::string scopeName;                      //Name of the scope
        float scopeHeight;                          //Distance between scope and axe of barrel
        float scopeZeroing;                         //Distance scope zero in meter
        float scopeClicValueinDegree;               //Value of scope clic. Ex: 1/2 MOA, 1/4MOA, 0.1MIL
        float scopeClicValueUsr;                    //Value use by default
        Unit valueScopeUnitUsr;                     //Unit of scope clic
        Angle angleConvertion;                      //Usefull function for scope


    public:
        void SetValues(std::string scopeNameDef, float scopeHeightDef, float scopeZeroingDef) {
            scopeName = scopeNameDef;
            scopeHeight = scopeHeightDef;
            scopeZeroing = scopeZeroingDef;
        }

        void DefineClicValue(float value, Unit valueScopeUnit) {
            valueScopeUnitUsr = valueScopeUnit;
            scopeClicValueUsr = value;
            switch(valueScopeUnit) {
                case MOA:
                    scopeClicValueinDegree = angleConvertion.MOAToDeg(value);
                    break;
                case MIL:
                    scopeClicValueinDegree = angleConvertion.MILToDeg(value);
                    break;
                default:
                    scopeClicValueinDegree = angleConvertion.MOAToDeg(value);
                    break;
            }
        }

        std::string GetName() {
            if(scopeName.empty())
                return "undefined";
            else
                return scopeName;
        }

        float GetScopeHeight() {
            if(scopeHeight)
                return scopeHeight;
            else
                return 0.0;
        }

        float GetScopeZeroing() {
            if(scopeZeroing)
                return scopeZeroing;
            else
                return 0.0;
        }

        std::string GetScopeClicValue() {
            std::string clicUnit;
            switch(valueScopeUnitUsr) {
                case MOA:
                    clicUnit = "MOA";
                    return STRING(scopeClicValueUsr) + clicUnit;
                case MIL:
                    clicUnit = "MIL";
                    return STRING(scopeClicValueUsr) + clicUnit;
                default:
                    clicUnit = "MOA";
                    return STRING(scopeClicValueUsr) + clicUnit;
            }
        }
};
