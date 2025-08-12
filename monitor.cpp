#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void vitalsCheckAttention() {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

int isInRange(float value, float min, float max) {
  return (value > min && value < max);
}

int temperatureOk(float temperature) {
  if (!isInRange(temperature, 95, 102)) {
    cout << "Temperature is critical!\n";
    vitalsCheckAttention();
    return 0;
  }
  return 1;
}

int pulseRateOk(float pulseRate) {
  if (!isInRange(pulseRate, 60, 100)) {
    cout << "Pulse Rate is out of range!\n";
    vitalsCheckAttention();
    return 0;
  }
  return 1;
}

int spo2Ok(float spo2) {
  if (!isInRange(spo2, 90, 100)) {
    cout << "Oxygen Saturation out of range.\n";
    vitalsCheckAttention();
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return temperatureOk(temperature) && pulseRateOk(pulseRate) && spo2Ok(spo2);
}
