#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, OkWhenAllVitalsAreNormal) {
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, TemperatureHigh) {
  ASSERT_FALSE(vitalsOk(104, 70, 98));
}

TEST(Monitor, TemperatureLow) {
  ASSERT_FALSE(vitalsOk(94, 70, 98));
}

TEST(Monitor, PulseRateHigh) {
  ASSERT_FALSE(vitalsOk(98.1, 150, 98));
}

TEST(Monitor, PulseRateLow) {
  ASSERT_FALSE(vitalsOk(98.1, 30, 98));
}

TEST(Monitor, Spo2Low) {
  ASSERT_FALSE(vitalsOk(98.1, 70, 85));
}