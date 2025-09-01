/**
 * Open Space Program
 * Copyright © 2019-2025 Open Space Program Project
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include <osp/universe/universe.h>
#include <osp/core/math_types.h>

namespace adera
{

struct CirclePathSim
{
    struct SatData
    {
        osp::universe::Vector3g     position;
        osp::Vector3                velocity;
        osp::Vector3                accel;
        double                      radius;
        std::uint64_t               period{};
        std::uint64_t               cycleTime{};
        osp::universe::SatelliteId  id;
    };

    void update(std::uint64_t deltaTime) noexcept;

    std::vector<SatData>            m_data;
};


struct ConstantSpinSim
{
    struct SatData
    {
        osp::Quaternion             rot;
        osp::Vector3                axis;
        std::uint64_t               period{};
        std::uint64_t               cycleTime{};
        osp::universe::SatelliteId  id;
    };

    void update(std::uint64_t deltaTime) noexcept;

    std::vector<SatData>            m_data;
};


struct SimpleGravitySim
{
    struct SatData
    {
        osp::universe::Vector3g     position;
        osp::Vector3d               velocity;
        osp::Vector3d               accel;
        float                       mass;
        osp::universe::SatelliteId  id;
    };

    void update(std::uint64_t deltaTime) noexcept;

    std::vector<SatData>            m_data;
    double                          m_metersPerPosUnit;
    double                          m_secPerTimeUnit;
};



} // namespace adera::sims
