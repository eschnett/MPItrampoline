module mpiabi_f08_types
  implicit none
  public
  save

  type MPIABI_Datatype
     integer datatype
  end type MPIABI_Datatype

  type MPIABI_Comm
     integer comm
  end type MPIABI_Comm

end module mpiabi_f08_types
