/* c-isr library stuff of Andes NDS32 cpu for GNU compiler
   Copyright (C) 2012-2025 Free Software Foundation, Inc.
   Contributed by Andes Technology Corporation.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

	.section	.nds32_vector.28, "ax"
#if __NDS32_ISR_VECTOR_SIZE_4__
	/* The vector size is default 4-byte for v3 architecture.  */
	.vec_size	4
	.align	2
#else
	/* The vector size is default 16-byte for other architectures.  */
	.vec_size	16
	.align	4
#endif
	.weak	_nds32_vector_28
	.type	_nds32_vector_28, @function
_nds32_vector_28:
1:
	j	1b
	.size	_nds32_vector_28, .-_nds32_vector_28
