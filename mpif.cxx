#include "mpi.h"

#include <cstring>
#include <map>

// Fortran related functions

// TODO: Watch delete calls, remove elements from mapping.

// TODO: If we map in MPIwrapper, then we can check sizeof(F) and
// sizeof(C), and possibly avoid using the std::map. If so, we need to
// wrap the Fortran API.

// TODO: Test whether using std::unordered_map is faster.

template <typename C, typename F> class mapping {
  std::map<C, F> c2f;
  std::map<F, C> f2c;
  F nextF;

public:
  mapping() : nextF(0) {}

  F getF(C c) {
    if (!c2f.count(c)) {
      F f = nextF++;
      c2f[c] = f;
      f2c[f] = c;
      return f;
    }
    return c2f.at(c);
  }
  C getC(F f) const {
    return f2c.at(f);
  }
};

mapping<MPI_Comm, MPI_Fint> comm_mapping;
extern "C" MPI_Fint MPI_Comm_c2f(MPI_Comm comm) {
  return comm_mapping.getF(comm);
}
extern "C" MPI_Comm MPI_Comm_f2c(MPI_Fint comm) {
  return comm_mapping.getC(comm);
}

mapping<MPI_File, MPI_Fint> file_mapping;
extern "C" MPI_Fint MPI_File_c2f(MPI_File file) {
  return file_mapping.getF(file);
}
extern "C" MPI_File MPI_File_f2c(MPI_Fint file) {
  return file_mapping.getC(file);
}

mapping<MPI_Group, MPI_Fint> group_mapping;
extern "C" MPI_Fint MPI_Group_c2f(MPI_Group group) {
  return group_mapping.getF(group);
}
extern "C" MPI_Group MPI_Group_f2c(MPI_Fint group) {
  return group_mapping.getC(group);
}

mapping<MPI_Info, MPI_Fint> info_mapping;
extern "C" MPI_Fint MPI_Info_c2f(MPI_Info info) {
  return info_mapping.getF(info);
}
extern "C" MPI_Info MPI_Info_f2c(MPI_Fint info) {
  return info_mapping.getC(info);
}

mapping<MPI_Message, MPI_Fint> message_mapping;
extern "C" MPI_Fint MPI_Message_c2f(MPI_Message message) {
  return message_mapping.getF(message);
}
extern "C" MPI_Message MPI_Message_f2c(MPI_Fint message) {
  return message_mapping.getC(message);
}

mapping<MPI_Op, MPI_Fint> op_mapping;
extern "C" MPI_Fint MPI_Op_c2f(MPI_Op op) { return op_mapping.getF(op); }
extern "C" MPI_Op MPI_Op_f2c(MPI_Fint op) { return op_mapping.getC(op); }

mapping<MPI_Request, MPI_Fint> request_mapping;
extern "C" MPI_Fint MPI_Request_c2f(MPI_Request request) {
  return request_mapping.getF(request);
}
extern "C" MPI_Request MPI_Request_f2c(MPI_Fint request) {
  return request_mapping.getC(request);
}

mapping<MPI_Datatype, MPI_Fint> datatype_mapping;
extern "C" MPI_Fint MPI_Type_c2f(MPI_Datatype datatype) {
  return datatype_mapping.getF(datatype);
}
extern "C" MPI_Datatype MPI_Type_f2c(MPI_Fint datatype) {
  return datatype_mapping.getC(datatype);
}

mapping<MPI_Win, MPI_Fint> win_mapping;
extern "C" MPI_Fint MPI_Win_c2f(MPI_Win win) { return win_mapping.getF(win); }
extern "C" MPI_Win MPI_Win_f2c(MPI_Fint win) { return win_mapping.getC(win); }

static_assert(MPI_STATUS_SIZE * sizeof(MPI_Fint) == sizeof(MPI_Status));
extern "C" int MPI_Status_c2f(const MPI_Status *c_status, MPI_Fint *f_status) {
  std::memcpy(f_status, c_status, sizeof c_status);
  return MPI_SUCCESS;
}
extern "C" int MPI_Status_f2c(const MPI_Fint *f_status, MPI_Status *c_status) {
  std::memcpy(c_status, f_status, sizeof c_status);
  return MPI_SUCCESS;
}
