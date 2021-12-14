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
    DC() {}
    ~DC() {}
    VectorXd _x;
    VectorXd _q;
    inline void initialize();
private:
};

void DC::initialize()
{
    _x.setZero(6);
    cout << _x.transpose() << '\n';
    _q.setZero(9);
}