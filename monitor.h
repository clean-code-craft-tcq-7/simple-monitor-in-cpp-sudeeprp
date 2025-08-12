#pragma once

void setDelayFunction(void (*delayFunc)(int));

int vitalsOk(float temperature, float pulseRate, float spo2);
