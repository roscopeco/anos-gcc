#include "avx10-helper.h"
#define SIZE (AVX512F_LEN / 16)
#include "avx512f-mask-type.h"

void
TEST (void)
{
  int i;
  UNION_TYPE (AVX512F_LEN, bf16_uw) res1, res2, res3, src1;
  MASK_TYPE mask = MASK_VALUE;
  unsigned short res_ref[SIZE], res_ref2[SIZE];
  
  for (i = 0; i < SIZE; i++)
    {
      res1.a[i] = 0;
      res2.a[i] = DEFAULT_VALUE;
      res3.a[i] = DEFAULT_VALUE;
      float s1 = 2.0;
      src1.a[i] = convert_fp32_to_bf16 (s1);
      res_ref[i] = res_ref2[i] =  convert_fp32_to_bf16 (1.0 / s1);
    }

  res1.x = INTRINSIC (_rcp_pbh) (src1.x);
  res2.x = INTRINSIC (_mask_rcp_pbh) (res2.x, mask, src1.x);
  res3.x = INTRINSIC (_maskz_rcp_pbh) (mask, src1.x);

  if (UNION_CHECK (AVX512F_LEN, bf16_uw) (res1, res_ref))
    abort ();
  
  MASK_MERGE (bf16_uw) (res_ref2, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, bf16_uw) (res2, res_ref2))
    abort ();

  MASK_ZERO (bf16_uw) (res_ref2, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, bf16_uw) (res3, res_ref2))
    abort ();
}
