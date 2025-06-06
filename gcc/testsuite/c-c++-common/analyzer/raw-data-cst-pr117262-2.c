#include "analyzer-decls.h"

extern void use (unsigned char);

void
test ()
{
  const unsigned char meow_bytes[] = {
  0x69, 0x6e, 0x74, 0x0a, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a,
  0x7b, 0x0a, 0x20, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x20, 0x75, 0x6e,
  0x73, 0x69, 0x67, 0x6e, 0x65, 0x64, 0x20, 0x63, 0x68, 0x61, 0x72, 0x20,
  0x6d, 0x65, 0x6f, 0x77, 0x5f, 0x62, 0x79, 0x74, 0x65, 0x73, 0x5b, 0x5d,
  0x20, 0x3d, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20,
  0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x73, 0x68, 0x6f, 0x72, 0x74, 0x20, 0x6d,
  };

  /* Verify that analyzer "knows" the values of individual bytes in
     the array.  */

  /* First row.  */
  __analyzer_eval (meow_bytes[0] == 0x69); /* { dg-warning "TRUE" } */
  __analyzer_eval (meow_bytes[1] == 0x6e); /* { dg-warning "TRUE" } */
  __analyzer_eval (meow_bytes[11] == 0x0a); /* { dg-warning "TRUE" } */

  /* Second row.  */
  __analyzer_eval (meow_bytes[12] == 0x7b); /* { dg-warning "TRUE" } */
  __analyzer_eval (meow_bytes[23] == 0x6e); /* { dg-warning "TRUE" } */

  /* Final row.  */
  __analyzer_eval (meow_bytes[60] == 0x7d); /* { dg-warning "TRUE" } */
  __analyzer_eval (meow_bytes[70] == 0x20); /* { dg-warning "TRUE" } */
  __analyzer_eval (meow_bytes[71] == 0x6d); /* { dg-warning "TRUE" } */

  use (meow_bytes[-1]); /* { dg-warning "stack-based buffer under-read" } */
  use (meow_bytes[72]); /* { dg-warning "stack-based buffer over-read" } */
}
