// Copyright (C) 2019-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// { dg-do compile { target c++20 } }

#include <algorithm>
#include <array>
#include <functional>

constexpr bool
test()
{
  std::array<int, 12> ar1{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};
  std::array<int, 12> ar2{{0, 1, 2, 3, 4, 5, 6, 6, 8, 9, 9, 11}};

  const auto out33 = std::unique(ar1.begin(), ar1.end());

  const auto out44 = std::unique(ar2.begin(), ar2.end(), std::equal_to<int>());

  return out33 == ar1.begin() + 10 && out44 == ar2.begin() + 10;
}

static_assert(test());
