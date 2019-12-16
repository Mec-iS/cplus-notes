/*
Define class ParticleModel, including its state and Move() function.
Extend class BicycleModel from class ParticleModel.
Override the Move() function within class BicycleModel.
Specify BicycleModel::Move() as override.
Pass the tests in main() by verifying that the two Move() functions override each other in different scenarios.
*/

#include <assert.h>
#include <math.h>
using std::cos;
using std::tan;

// TODO: Declare abstract class VehicleModel
  // TODO: Declare virtual function Move()
class VehicleModel {
public:
    VehicleModel(float a=0.0, float b=0.0): x(a), y(b) {};
    virtual void Move(double v, double t) = 0;

    float x;
    float y;
    double theta = 0.0;
};

// TODO: Derive class ParticleModel from VehicleModel
  // TODO: Override the Move() function
  // TODO: Define x, y, and theta
class ParticleModel: public VehicleModel {
public:
    ParticleModel(float a=0.0, float b=0.0): VehicleModel(a, b) {};
    void Move(double v, double t) override {
        this->theta += t;
        this->x += v * cos(this->theta);
        this->y += v * cos(this->theta);
    };

    double theta;
};

// TODO: Derive class BicycleModel from ParticleModel
  // TODO: Override the Move() function
  // TODO: Define L
class BicycleModel: public ParticleModel {
public:
    BicycleModel(float a=0.0, float b=0.0, float l=0.0): ParticleModel(a, b), length(l) {};
    void Move(double v, double t) override {
        this->theta += (v / this->length) * tan(t);
        this->x += v * cos(this->theta);
        this->y += v * cos(this->theta);
    };

    float length;

};

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, M_PI / 9);
  bicycle.Move(10, M_PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}