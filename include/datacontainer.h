#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <ros/ros.h>

using namespace std;
using namespace Eigen;

// Data Container class //
class DC
{
public:
    DC() {initialize();}
    ~DC();
    Vector3d _x;
private:
    void initialize()
    {
        // _x.setZero(6);
    }
};