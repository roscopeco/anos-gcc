// Copyright (C) 2017-2025 Free Software Foundation, Inc.
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

#include <bit>

static_assert( std::is_enum_v<std::endian> );
static_assert( std::endian::little != std::endian::big );
static_assert( std::endian::native == std::endian::big
		|| std::endian::native == std::endian::little );

namespace gnu {
  int little, big, native;
}

using namespace std;
using namespace gnu;

// std::endian is a scoped-enum so these should refer to gnu::native etc.
int test = little + big + native;
