#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::milliseconds;

void (*delay)(int) = [](int ms) {
  sleep_for(milliseconds(ms));
};

void setDelayFunction(void (*delayFunc)(int)) {
  delay = delayFunc;
}

void vitalsCheckAttention() {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    delay(100);
    cout << "\r *" << flush;
    delay(100);
  }
}

int isInRange(float value, float min, float max) {
  return (value > min && value < max);
}

int alertWhenOutOfRange(const char* vital, float value, float min, float max) {
  if (!isInRange(value, min, max)) {
    cout << vital << " is out of range!\n";
    vitalsCheckAttention();
    return 0;
  }
  return 1;
}

int temperatureOk(float temperature) {
  return alertWhenOutOfRange("Temperature", temperature, 95, 102);
}

int pulseRateOk(float pulseRate) {
  return alertWhenOutOfRange("Pulse Rate", pulseRate, 60, 100);
}

int spo2Ok(float spo2) {
  return alertWhenOutOfRange("Oxygen Saturation", spo2, 90, 100);
}

int bloodSugarOk(float bloodSugar) {
  return alertWhenOutOfRange("Blood Sugar", bloodSugar, 70, 140);
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return temperatureOk(temperature) && pulseRateOk(pulseRate) && spo2Ok(spo2);
}

// TODO: Write test for patientReportOk and implement it.
// int patientReportOk(Report report) {
//   return vitalsOk(report.temperature, report.pulseRate, report.spo2) &&
//          bloodSugarOk(report.bloodSugar);
// }
