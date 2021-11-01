void mpitrampoline_init();

void mpitrampoline_initialize_fortran90_();
void mpitrampoline_initialize_fortran08_();

#ifdef __APPLE__
#define CONSTRUCTOR_PRIORITY
#else
#define CONSTRUCTOR_PRIORITY (1000)
#endif
static void __attribute__((__constructor__ CONSTRUCTOR_PRIORITY))
mpitrampoline_init_fortran() {
  // Initialize MPItrampoline
  mpitrampoline_init();

  // Set up high-level Fortran constants
  mpitrampoline_initialize_fortran90_();
  mpitrampoline_initialize_fortran08_();
}

// A dummy function that can be called to ensure that this file is
// linked into the executable, so that the initializer above is
// actually run
void mpitrampoline_fortran_dummy_function_() {}
