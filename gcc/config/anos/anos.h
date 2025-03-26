#undef TARGET_ANOS
#define TARGET_ANOS 1

#undef __ANOS
#define __ANOS 1
 
/* Default arguments for the x86_64-elf-anos-gcc toolchain 
   - link newlib BSP, GDB support optionally, and use our link script... */
#undef LIB_SPEC
#define LIB_SPEC "%{!g:-lc -lanos -lc} %{g:-lg -lanos %{mgdb:-lanos_gdb} -lg} %{bin:--oformat=binary} %{!T*:-T anos.ld%s}" 
 
/* Files that are linked before user code.
   The %s tells GCC to look for these files in the library directory. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{g:%{!mgdb:crt0.o%s} %{mgdb:gcrt0.o%s}} %{!g:crt0.o%s} crti.o%s crtbegin.o%s"
 
/* Files that are linked after user code. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"
 
/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()             \
  do {                                       \
    builtin_define ("__anos__");             \
    builtin_define ("ANOS");                 \
  } while(0);

