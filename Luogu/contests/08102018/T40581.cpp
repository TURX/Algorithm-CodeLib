#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
const double pi = 3.1415926575;

struct Bullet{
    double force, size, alpha, omega, practicalAngle;
} bullet;
string tank[2];
struct AngleConversion{
    double angelToRad(const double& angle) {
        return angle * (pi / (double)180);
    }
    double radToAngle(const double& rad) {
        return rad * ((double)180 / pi);
    }
} angleConversion;

map<string, double> omega;
map<string, double> unableAngle;
double targetThickness, practicalThickness;
string bulletType;

inline void init() {
    omega["AP"] = 5;
    omega["APCR"] = 5;
    omega["APFSDS"] = 2;
    unableAngle["AP"] = 70;
    unableAngle["APCR"] = 70;
    unableAngle["APFSDS"] = 70;
    unableAngle["HEAT"] = 85;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> tank[0] >> tank[1];
    cin >> bulletType >> bullet.force >> bullet.alpha >> bullet.size >> targetThickness;
    init();
    bullet.omega = omega[bulletType];
    if(bullet.size > targetThickness * 3) bullet.omega *= 3;
    else if(bullet.size > targetThickness * 2) bullet.omega += bullet.omega;
    bullet.practicalAngle = max((double)0, bullet.alpha - bullet.omega);
    if(unableAngle[bulletType]) if(bullet.practicalAngle >= unableAngle[bulletType]) {
        cout << "We didn't penetrate their armor!" << endl;
        return 0;
    }
    practicalThickness = (double)1 / (angleConversion.radToAngle(cos(angleConversion.angelToRad(90 - bullet.practicalAngle)))) * targetThickness;
    if(practicalThickness <= (bullet.force * 0.75)) {
        cout << "Penetration!" << endl;
        return 0;
    }
    else if(practicalThickness <= (bullet.force * 1.25)) {
        cout << "Server is important~" << endl;
        return 0;
    }
    else {
        cout << "We didn't penetrate their armor!" << endl;
        return 0;
    }
}