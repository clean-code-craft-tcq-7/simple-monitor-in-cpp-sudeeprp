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

int temperatureOk(float temperature) {
  if (temperature > 102 || temperature < 95) {
    cout << "Temperature is critical!\n";
    vitalsCheckAttention();
    return 0;
  }
}

int pulseRateOk(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    cout << "Pulse Rate is out of range!\n";
    vitalsCheckAttention();
    return 0;
  }
}

int spo2Ok(float spo2) {
  if (spo2 < 90) {
    cout << "Oxygen Saturation out of range.\n";
    vitalsCheckAttention();
    return 0;
  }
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return temperatureOk(temperature) && pulseRateOk(pulseRate) && spo2Ok(spo2);
}
