#pragma once
#include "Starbucks.h"

class anglesswStarbucks : public Starbucks {
public:
	anglesswStarbucks(void);
	void build(Entry* c, int n);
	Entry* getNearest(double x, double y);
	virtual ~anglesswStarbucks(void);
private:
	Entry* entry_arr;
	int length;
};

