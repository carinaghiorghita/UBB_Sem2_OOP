#pragma once
#include "controller.h"

typedef struct
{
	Service* service;
}UI;

UI* createUI(Service* service);
void destroyUI(UI* ui);
void startUI();