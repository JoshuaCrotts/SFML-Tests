#include "../include/stds.hpp"

#define MAX_LINE_LENGTH 64
#define PI              3.14159265358979323846

static char text_buffer[MAX_LINE_LENGTH];
static bool seed = false;

int32_t 
random_int(int32_t min, int32_t max) {
  if (!seed) {
    srand((uint32_t) time(NULL));
    seed = true;
  }
  return (rand() % (max - min + 1)) + min;
}


float 
random_float(float min, float max) {
  if (!seed) {
    srand((uint32_t) time(NULL));
    seed = true;
  }

  float scale = rand() / (float) RAND_MAX;
  return min + scale * (max - min);
}


int32_t 
clamp(int32_t value, int32_t min, int32_t max) {
  int newValue = value;
  if (value < min) {
    newValue = min;
  } else if (value > max) {
    newValue = max;
  }

  return newValue;
}


void 
calc_slope(int x1, int y1, int x2, int y2, float* dx, float* dy) {
  int steps = MAX(abs(x1 - x2), abs(y1 - y2));

  if (steps == 0) {
    *dx = *dy = 0;
    return;
  }

  *dx = (x1 - x2);
  *dx /= steps;

  *dy = (y1 - y2);
  *dy /= steps;
}


float 
get_angle(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  float angle = (float) (-90 + atan2(y1 - y2, x1 - x2) * (180 / PI));
  return angle >= 0 ? angle : 360 + angle;
}


int32_t 
get_distance(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  int x = x2 - x1;
  int y = y2 - y1;

  return (int32_t) sqrt(x * x + y * y);
}


float 
to_radians(float degrees) {
  return (float) (degrees * (PI / 180.0));
}