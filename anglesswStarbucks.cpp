#include "anglesswStarbucks.h"

static const double difference = 0.00001;

anglesswStarbucks::anglesswStarbucks(void)
{
}

void anglesswStarbucks::build(Entry* c, int n) 
{
	length = n;
	entry_arr = new Entry[7700];
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if((j+1==i) && (abs(c[j].x-c[i].x) > difference) &&
				(abs(c[j].y-c[i].y) > difference)) {
				entry_arr[i] = c[i];
			}
		}
	}
}

Entry* anglesswStarbucks::getNearest(double x, double y)
{
	Entry* nearest = new Entry();
	double shortest = ((x-nearest->x)*(x-nearest->x))
		+((y-nearest->y)*(y-nearest->y));
	double dist_temp;
	Entry temp;

	for(int i=1; i<length; i++) {
		temp = entry_arr[i];
		dist_temp = ((x-temp.x)*(x-temp.x))
			+((y-temp.y)*(y-temp.y));

		if(dist_temp < shortest) {
			shortest = dist_temp;
			*nearest = temp;
		}
	}
	return nearest;
}

anglesswStarbucks::~anglesswStarbucks(void)
{
	delete [] entry_arr;
}
