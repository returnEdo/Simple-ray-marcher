#pragma once

#include "Vector.h"

bool comparef(float a, float b);

float clamp(float val, float lower, float upper);
Vector clamp(Vector val, const Vector& lower, const Vector& upper);

float randf(float a, float b);

float pow2(float a);
