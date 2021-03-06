#pragma once
#include <assert.h>
#include "Service.h"

void addStarService_ValidInput_AllGood();

void addStarService_InvalidInputForName_ThrowEx();

void addStarService_InvalidInputForDiam_ThrowEx();