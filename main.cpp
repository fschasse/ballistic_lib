#include <iostream>
#include "bullets.cpp"
#include "scope.cpp"

int main(int argc, char **argv) {
    Bullets hornady;
    hornady.SetValues("Hornady", G7, 7.1, 7.2);
    std::cout << hornady.Get_Namebullet() << std::endl;
    std::cout << hornady.Get_Coefficient() << std::endl;
    std::cout << hornady.Get_BulletWeight() << std::endl;
    std::cout << hornady.Get_BulletSpeed() << std::endl;
    Angle angle;
    std::cout << angle.DegToRad(30.0) << std::endl;
    std::cout << angle.MILAtDistance(0.1, 100.0) << std::endl;
    Scope newScope;
    newScope.SetValues("Huskemaw", 5.5, 100.0);
    newScope.DefineClicValue(1/4, MOA);
    return 0;
}
