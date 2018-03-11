#include <chrono>
#include <stdio.h>

using namespace chrono;
using namespace std;

/*
Expandable Helper class that keeps helpful functions and other logic handlers separate
from the main program.
*/

class Helper {
public:
	Helper() {}

	~Helper() {}

	void getTime();
};

void Helper::getTime() {
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);
  	printf("%2d:%02d:%02d", tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec);
}