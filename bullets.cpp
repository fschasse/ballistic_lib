#include <string.h>
#include <math.h>

//Coefficient list. This list is use for determine the shape of bullet
enum Coefficient {
    G1,                                             //G1, Ingalls, plate base bullet, common type of bullet
    G2,                                             //G2, Aberdeen J
    G5,                                             //G5, Short boat tail bullet
    G6,                                             //G6, plate base bullet with secant bullet for 6mm caliber
    G7,                                             //G7, long boat tail bullet, common type for rifle
    G8,                                             //G8, same as G6 but for 10mm caliber
    GL,                                             //GL, bullet with plate lead nose
};


class Bullets {                                     // Class for define bullet parameter
    private:
        std::string name_bullet;                    //Name define by user
        float bullet_weight;                        //Weight of bullet (grains)
        float bullet_speed;                         //Bullet speed in m/s
        Coefficient coefficient_bullet;             //See enum for detail

    public:
        void SetValues (std::string nameBullet, Coefficient coef_bullet, float bul_weight, float bul_speed)
        {
            name_bullet = nameBullet;
            coefficient_bullet = coef_bullet;
            bullet_weight = bul_weight;
            bullet_speed = bul_speed;
        }

        std::string CoefficientToString(Coefficient bulcoefficient)
        {
            switch(bulcoefficient) {
                case G1:
                    return "G1";
                case G2:
                    return "G2";
                case G5:
                    return "G5";
                case G6:
                    return "G6";
                case G7:
                    return "G7";
                case G8:
                    return "G8";
                case GL:
                    return "GL";
                default:
                    return "G7";
            }
        }

        std::string Get_Namebullet() { return name_bullet; }
        std::string Get_Coefficient() { return CoefficientToString(coefficient_bullet); }
        float Get_BulletWeight() { return bullet_weight; }
        float Get_BulletSpeed() { return bullet_speed; }
};

