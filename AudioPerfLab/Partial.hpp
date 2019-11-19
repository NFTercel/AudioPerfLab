/*
 * Copyright (c) 2019 Ableton AG, Berlin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include "AudioBuffer.hpp"

#include <array>
#include <chrono>
#include <vector>

struct Partial
{
  float ampWhenActive{};
  float targetAmp{};
  float amp{};
  float ampSmoothingCoeff{};

  float pan{};

  float phaseIncrement{};
  float phase{};
};

std::vector<Partial> generateSaw(float sampleRate,
                                 float amp,
                                 std::chrono::duration<float> ampSmoothingDuration,
                                 float pan,
                                 float frequency);

std::vector<Partial> generateChord(float sampleRate,
                                   std::chrono::duration<float> ampSmoothingDuration,
                                   const std::vector<float>& noteNumbers);

std::vector<Partial> randomizePhases(std::vector<Partial> partials, int partialsToSkip);

void processPartial(Partial& partial, int numFrames, StereoAudioBuffer& output);
