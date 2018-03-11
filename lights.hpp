#include <iostream>
#include <string>

using namespace std;

class Light {
public:
  Light(string lightName){
    colour = lightName;
  };

  ~Light(){};

  string getColour() const { return colour; }

private:
  string colour;
};
