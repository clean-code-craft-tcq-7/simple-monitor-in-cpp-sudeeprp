#include <gtest/gtest.h>
#include "./monitor.h"

class Monitor : public ::testing::Test {
protected:
    void SetUp() override {
        setDelayFunction([](int ms) {});
    }
};

TEST_F(Monitor, OkWhenAllVitalsAreNormal) {
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST_F(Monitor, TemperatureHigh) {
  ASSERT_FALSE(vitalsOk(104, 70, 98));
}

TEST_F(Monitor, TemperatureLow) {
  ASSERT_FALSE(vitalsOk(94, 70, 98));
}

TEST_F(Monitor, PulseRateHigh) {
  ASSERT_FALSE(vitalsOk(98.1, 150, 98));
}

TEST_F(Monitor, PulseRateLow) {
  ASSERT_FALSE(vitalsOk(98.1, 30, 98));
}

TEST_F(Monitor, Spo2Low) {
  ASSERT_FALSE(vitalsOk(98.1, 70, 85));
}
