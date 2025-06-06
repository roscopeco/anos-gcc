/* { dg-do assemble { target aarch64_asm_sve-b16b16_ok } } */
/* { dg-do compile { target { ! aarch64_asm_sve-b16b16_ok } } } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

#pragma GCC target "+sve-b16b16"
#ifdef STREAMING_COMPATIBLE
#pragma GCC target "+sme2"
#endif

/*
** maxnm_bf16_m_tied1:
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_m_tied1, svbfloat16_t,
		z0 = svmaxnm_bf16_m (p0, z0, z1),
		z0 = svmaxnm_m (p0, z0, z1))

/*
** maxnm_bf16_m_tied2:
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0, z1
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_m_tied2, svbfloat16_t,
		z0 = svmaxnm_bf16_m (p0, z1, z0),
		z0 = svmaxnm_m (p0, z1, z0))

/*
** maxnm_bf16_m_untied:
**	movprfx	z0, z1
**	bfmaxnm	z0\.h, p0/m, z0\.h, z2\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_m_untied, svbfloat16_t,
		z0 = svmaxnm_bf16_m (p0, z1, z2),
		z0 = svmaxnm_m (p0, z1, z2))

/*
** maxnm_h4_bf16_m_tied1:
**	mov	(z[0-9]+\.h), h4
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZD (maxnm_h4_bf16_m_tied1, svbfloat16_t, __bf16,
		 z0 = svmaxnm_n_bf16_m (p0, z0, d4),
		 z0 = svmaxnm_m (p0, z0, d4))

/*
** maxnm_h4_bf16_m_untied:
**	mov	(z[0-9]+\.h), h4
**	movprfx	z0, z1
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZD (maxnm_h4_bf16_m_untied, svbfloat16_t, __bf16,
		 z0 = svmaxnm_n_bf16_m (p0, z1, d4),
		 z0 = svmaxnm_m (p0, z1, d4))

/*
** maxnm_1_bf16_m:
**	fmov	(z[0-9]+\.h), #1\.875(?:e\+0)?
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_1_bf16_m, svbfloat16_t,
		z0 = svmaxnm_n_bf16_m (p0, z0, 1),
		z0 = svmaxnm_m (p0, z0, 1))

/*
** maxnm_0p5_bf16_m:
**	fmov	(z[0-9]+\.h), #1\.75(?:e\+0)?
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_0p5_bf16_m, svbfloat16_t,
		z0 = svmaxnm_n_bf16_m (p0, z0, (bfloat16_t) (0.5)),
		z0 = svmaxnm_m (p0, z0, (bfloat16_t) (0.5)))

/*
** maxnm_m1_bf16_m:
**	fmov	(z[0-9]+\.h), #-1\.875(?:e\+0)?
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_m1_bf16_m, svbfloat16_t,
		z0 = svmaxnm_n_bf16_m (p0, z0, -1),
		z0 = svmaxnm_m (p0, z0, -1))

/*
** maxnm_m0p5_bf16_m:
**	fmov	(z[0-9]+\.h), #-1\.75(?:e\+0)?
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_m0p5_bf16_m, svbfloat16_t,
		z0 = svmaxnm_n_bf16_m (p0, z0, (bfloat16_t) (-0.5)),
		z0 = svmaxnm_m (p0, z0, (bfloat16_t) (-0.5)))

/*
** maxnm_m2_bf16_m_tied1:
**	fmov	(z[0-9]+\.h), #-2\.0(?:e\+0)?
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_m2_bf16_m_tied1, svbfloat16_t,
		z0 = svmaxnm_n_bf16_m (p0, z0, -2),
		z0 = svmaxnm_m (p0, z0, -2))

/*
** maxnm_m2_bf16_m_untied:
**	fmov	(z[0-9]+\.h), #-2\.0(?:e\+0)?
**	movprfx	z0, z1
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_m2_bf16_m_untied, svbfloat16_t,
		z0 = svmaxnm_n_bf16_m (p0, z1, -2),
		z0 = svmaxnm_m (p0, z1, -2))

/*
** maxnm_bf16_z_tied1:
**	movprfx	z0\.h, p0/z, z0\.h
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_z_tied1, svbfloat16_t,
		z0 = svmaxnm_bf16_z (p0, z0, z1),
		z0 = svmaxnm_z (p0, z0, z1))

/*
** maxnm_bf16_z_tied2:
**	movprfx	z0\.h, p0/z, z0\.h
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_z_tied2, svbfloat16_t,
		z0 = svmaxnm_bf16_z (p0, z1, z0),
		z0 = svmaxnm_z (p0, z1, z0))

/*
** maxnm_bf16_z_untied:
** (
**	movprfx	z0\.h, p0/z, z1\.h
**	bfmaxnm	z0\.h, p0/m, z0\.h, z2\.h
** |
**	movprfx	z0\.h, p0/z, z2\.h
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
** )
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_z_untied, svbfloat16_t,
		z0 = svmaxnm_bf16_z (p0, z1, z2),
		z0 = svmaxnm_z (p0, z1, z2))

/*
** maxnm_h4_bf16_z_tied1:
**	mov	(z[0-9]+\.h), h4
**	movprfx	z0\.h, p0/z, z0\.h
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZD (maxnm_h4_bf16_z_tied1, svbfloat16_t, __bf16,
		 z0 = svmaxnm_n_bf16_z (p0, z0, d4),
		 z0 = svmaxnm_z (p0, z0, d4))

/*
** maxnm_h4_bf16_z_untied:
**	mov	(z[0-9]+\.h), h4
** (
**	movprfx	z0\.h, p0/z, z1\.h
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
** |
**	movprfx	z0\.h, p0/z, \1
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
** )
**	ret
*/
TEST_UNIFORM_ZD (maxnm_h4_bf16_z_untied, svbfloat16_t, __bf16,
		 z0 = svmaxnm_n_bf16_z (p0, z1, d4),
		 z0 = svmaxnm_z (p0, z1, d4))

/*
** maxnm_1_bf16_z:
**	fmov	(z[0-9]+\.h), #1\.875(?:e\+0)?
**	movprfx	z0\.h, p0/z, z0\.h
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_1_bf16_z, svbfloat16_t,
		z0 = svmaxnm_n_bf16_z (p0, z0, 1),
		z0 = svmaxnm_z (p0, z0, 1))

/*
** maxnm_bf16_x_tied1:
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_x_tied1, svbfloat16_t,
		z0 = svmaxnm_bf16_x (p0, z0, z1),
		z0 = svmaxnm_x (p0, z0, z1))

/*
** maxnm_bf16_x_tied2:
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_x_tied2, svbfloat16_t,
		z0 = svmaxnm_bf16_x (p0, z1, z0),
		z0 = svmaxnm_x (p0, z1, z0))

/*
** maxnm_bf16_x_untied:
** (
**	movprfx	z0, z1
**	bfmaxnm	z0\.h, p0/m, z0\.h, z2\.h
** |
**	movprfx	z0, z2
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
** )
**	ret
*/
TEST_UNIFORM_Z (maxnm_bf16_x_untied, svbfloat16_t,
		z0 = svmaxnm_bf16_x (p0, z1, z2),
		z0 = svmaxnm_x (p0, z1, z2))

/*
** maxnm_h4_bf16_x_tied1:
**	mov	(z[0-9]+\.h), h4
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZD (maxnm_h4_bf16_x_tied1, svbfloat16_t, __bf16,
		 z0 = svmaxnm_n_bf16_x (p0, z0, d4),
		 z0 = svmaxnm_x (p0, z0, d4))

/*
** maxnm_h4_bf16_x_untied:
**	mov	z0\.h, h4
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZD (maxnm_h4_bf16_x_untied, svbfloat16_t, __bf16,
		 z0 = svmaxnm_n_bf16_x (p0, z1, d4),
		 z0 = svmaxnm_x (p0, z1, d4))

/*
** maxnm_1_bf16_x_tied1:
**	fmov	(z[0-9]+\.h), #1\.875(?:e\+0)?
**	bfmaxnm	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (maxnm_1_bf16_x_tied1, svbfloat16_t,
		z0 = svmaxnm_n_bf16_x (p0, z0, 1),
		z0 = svmaxnm_x (p0, z0, 1))

/*
** maxnm_1_bf16_x_untied:
**	fmov	z0\.h, #1\.875(?:e\+0)?
**	bfmaxnm	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (maxnm_1_bf16_x_untied, svbfloat16_t,
		z0 = svmaxnm_n_bf16_x (p0, z1, 1),
		z0 = svmaxnm_x (p0, z1, 1))

/*
** ptrue_maxnm_bf16_x_tied1:
**	...
**	ptrue	[^\n]+
**	...
**	ret
*/
TEST_UNIFORM_Z (ptrue_maxnm_bf16_x_tied1, svbfloat16_t,
		z0 = svmaxnm_bf16_x (svptrue_b16 (), z0, z1),
		z0 = svmaxnm_x (svptrue_b16 (), z0, z1))

/*
** ptrue_maxnm_bf16_x_tied2:
**	...
**	ptrue	[^\n]+
**	...
**	ret
*/
TEST_UNIFORM_Z (ptrue_maxnm_bf16_x_tied2, svbfloat16_t,
		z0 = svmaxnm_bf16_x (svptrue_b16 (), z1, z0),
		z0 = svmaxnm_x (svptrue_b16 (), z1, z0))

/*
** ptrue_maxnm_bf16_x_untied:
**	...
**	ptrue	[^\n]+
**	...
**	ret
*/
TEST_UNIFORM_Z (ptrue_maxnm_bf16_x_untied, svbfloat16_t,
		z0 = svmaxnm_bf16_x (svptrue_b16 (), z1, z2),
		z0 = svmaxnm_x (svptrue_b16 (), z1, z2))
