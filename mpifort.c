void init_mpitrampoline();

void mpitrampoline_initialize_fortran90_();
void mpitrampoline_initialize_fortran08_();

#ifdef __APPLE__
#define CONSTRUCTOR_PRIORITY
#else
#define CONSTRUCTOR_PRIORITY (1000)
#endif
static void __attribute__((__constructor__ CONSTRUCTOR_PRIORITY))
init_mpitrampoline_fortran() {
  // Initialize MPItrampoline
  init_mpitrampoline();

  // Set up high-level Fortran constants
  mpitrampoline_initialize_fortran90_();
  mpitrampoline_initialize_fortran08_();
}
