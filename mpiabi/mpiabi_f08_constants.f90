module mpiabi_f08_constants
  use mpiabi_f08_types
  implicit none
  public
  save

  integer, private :: dummy

  integer, parameter :: MPIABI_COUNT_KIND = kind(loc(dummy))
end module mpiabi_f08_constants
