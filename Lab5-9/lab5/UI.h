#pragma once
#include "Service.h"

class UI
{
private:
	Service service;
public:
	UI(const Service& newService) : service(newService) {}

	void start();

};

