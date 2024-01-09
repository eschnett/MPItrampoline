#!/usr/bin/env python3

import sys

constants    = ["" for x in range(0,1025)]
handle_types = ["" for x in range(0,1025)]

def parse_datatype(h):
    handle_types[h] = "MPI_Datatype"
    if not(h & 0b1_0000_0000):
        category = (h & 0b_1111_1000) >> 3
        kind     = (h & 0b_0000_0111)
        # category buckets:
        # 00... not strictly fixed-size
        # 01... C/C++ fixed-size
        # 10... reserved
        # 11... Fortran fixed-size
        #  ^ fixed-size bit
        #   ^^^ encoded size bits (log2 of size in bytes)
        match category:
            # language-independent types
            case 0b00_000:
                match kind:
                    case 0b000:
                        constants[h] = "MPI_DATATYPE_NULL"
                    case 0b001:
                        constants[h] = "MPI_AINT"
                    case 0b010:
                        constants[h] = "MPI_COUNT"
                    case 0b011:
                        constants[h] = "MPI_OFFSET"
                    case 0b111:
                        constants[h] = "MPI_PACKED"
                    case _:
                        constants[h] = "reserved datatype"

            # C integers
            case 0b00_001:
                signed = not(h & 0b100)
                kind = (h & 0b11)
                if signed:
                    match kind:
                        case 0b00:
                            constants[h] = "MPI_SHORT"
                        case 0b01:
                            constants[h] = "MPI_INT"
                        case 0b10:
                            constants[h] = "MPI_LONG"
                        case 0b11:
                            constants[h] = "MPI_LONG_LONG"
                else:
                    match kind:
                        case 0b00:
                            constants[h] = "MPI_UNSIGNED_SHORT"
                        case 0b01:
                            constants[h] = "MPI_UNSIGNED"
                        case 0b10:
                            constants[h] = "MPI_UNSIGNED_LONG"
                        case 0b11:
                            constants[h] = "MPI_UNSIGNED_LONG_LONG"

            # C/C++ floating-point types
            case 0b00_010:
                is_float = not(h & 0b100)
                kind = (h & 0b11)
                if is_float:
                    match kind:
                        case 0b00:
                            constants[h] = "MPI_FLOAT"
                        case 0b10:
                            constants[h] = "MPI_C_FLOAT_COMPLEX"
                        case 0b11:
                            constants[h] = "MPI_CXX_FLOAT_COMPLEX"
                        case _:
                            constants[h] = "reserved datatype"
                else:
                    match kind:
                        case 0b00:
                            constants[h] = "MPI_DOUBLE"
                        case 0b10:
                            constants[h] = "MPI_C_DOUBLE_COMPLEX"
                        case 0b11:
                            constants[h] = "MPI_CXX_DOUBLE_COMPLEX"
                        case _:
                            constants[h] = "reserved datatype"

            # Fortran types
            case 0b00_011:
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INTEGER"
                    case 0b001:
                        constants[h] = "MPI_LOGICAL"
                    case 0b010:
                        constants[h] = "MPI_REAL"
                    case 0b011:
                        constants[h] = "MPI_COMPLEX"
                    case 0b100:
                        constants[h] = "MPI_DOUBLE_PRECISION"
                    case 0b101:
                        constants[h] = "MPI_DOUBLE_COMPLEX"
                    case _:
                        constants[h] = "reserved datatype"

            # long double
            case 0b00_100:
                real = not(h & 0b100)
                kind = (h & 0b11)
                if real:
                    match kind:
                        case 0b00:
                            constants[h] = "MPI_LONG_DOUBLE"
                        case 0b10:
                            constants[h] = "<Fortran long double>"
                        case _:
                            constants[h] = "reserved datatype"
                else:
                    match kind:
                        case 0b00:
                            constants[h] = "MPI_C_LONG_DOUBLE_COMPLEX"
                        case 0b01:
                            constants[h] = "MPI_CXX_LONG_DOUBLE_COMPLEX"
                        case 0b10:
                            constants[h] = "<Fortran long double complex>"
                        case _:
                            constants[h] = "reserved datatype"

            # C pair types
            case 0b00_101:
                match kind:
                    case 0b000:
                        constants[h] = "MPI_FLOAT_INT"
                    case 0b001:
                        constants[h] = "MPI_DOUBLE_INT"
                    case 0b010:
                        constants[h] = "MPI_LONG_INT"
                    case 0b011:
                        constants[h] = "MPI_2INT"
                    case 0b100:
                        constants[h] = "MPI_SHORT_INT"
                    case 0b101:
                        constants[h] = "MPI_LONG_DOUBLE_INT"
                    case _:
                        constants[h] = "reserved datatype"

            # Fortran pair types
            case 0b00_110:
                match kind:
                    case 0b000:
                        constants[h] = "MPI_2REAL"
                    case 0b001:
                        constants[h] = "MPI_2DOUBLE_PRECISION"
                    case 0b010:
                        constants[h] = "MPI_2INTEGER"
                    # these are trash (https://github.com/open-mpi/ompi/issues/11556)
                    #case 0b011:
                    #    constants[h] = "MPI_2COMPLEX (non-standard)"
                    #case 0b100:
                    #    constants[h] = "MPI_2DOUBLE_COMPLEX (non-standard)"
                    case _:
                        constants[h] = "reserved datatype"

            # other C/C++ types
            case 0b00_111:
                match kind:
                    case 0b000:
                        constants[h] = "MPI_C_BOOL"
                    case 0b001:
                        constants[h] = "MPI_CXX_BOOL"
                    case 0b100:
                        constants[h] = "MPI_WCHAR"
                    case _:
                        constants[h] = "reserved datatype"

            # scheme
            # C/C++
            # 0b000: "MPI_INT(n)_T"
            # 0b001: "MPI_UINT(n)_T"
            # 0b010: "<float (n)b>"
            # 0b011: (size=1) ? "MPI_CHAR" : ""<C complex 2x(n/2)b>""
            # 0b100: (size=1) ? "MPI_SIGNED_CHAR" : "reserved datatype"
            # 0b101: (size=1) ? "MPI_UNSIGNED_CHAR" : "reserved datatype"
            # 0b110: (size=2) ? "<C++ bfloat16_t>" : "reserved datatype"
            # 0b111: (size=1) ? "MPI_BYTE" : ""<C++ complex 2x(n/2)b>""
            # Fortran
            # 0b000: "MPI_INTEGER(n)"
            # 0b001: "MPI_LOGICAL(n) (not standard)"
            # 0b010: "MPI_REAL(n)"
            # 0b011: (size=1) ? "MPI_CHARACTER" : "MPI_COMPLEX(n)"

            case 0b01_000: # 1 byte C/C++
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INT8_T"
                    case 0b001:
                        constants[h] = "MPI_UINT8_T"
                    case 0b010:
                        constants[h] = "<float 8b>"
                    case 0b011:
                        constants[h] = "MPI_CHAR"
                    case 0b100:
                        constants[h] = "MPI_SIGNED_CHAR"
                    case 0b101:
                        constants[h] = "MPI_UNSIGNED_CHAR"
                    case 0b111:
                        constants[h] = "MPI_BYTE"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b01_001: # 2 byte C/C++
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INT16_T"
                    case 0b001:
                        constants[h] = "MPI_UINT16_T"
                    case 0b010:
                        constants[h] = "<float 16b>"
                    case 0b011:
                        constants[h] = "<C complex 2x8b>"
                    case 0b111:
                        constants[h] = "<C++ complex 2x8b>"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b01_010: # 4 byte C/C++
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INT32_T"
                    case 0b001:
                        constants[h] = "MPI_UINT32_T"
                    case 0b010:
                        constants[h] = "<C float 32b>"
                    case 0b011:
                        constants[h] = "<C complex 2x16b>"
                    case 0b111:
                        constants[h] = "<C++ complex 2x16b>"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b01_011: # 8 byte C/C++
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INT64_T"
                    case 0b001:
                        constants[h] = "MPI_UINT64_T"
                    case 0b010:
                        constants[h] = "<C float64>"
                    case 0b011:
                        constants[h] = "<C complex 2x32b>"
                    case 0b111:
                        constants[h] = "<C complex 2x32b>"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b01_100: # 16 byte C/C++
                match kind:
                    case 0b0000:
                        constants[h] = "<C int128_t>"
                    case 0b0001:
                        constants[h] = "<C uint128_t>"
                    case 0b0010:
                        constants[h] = "<C float128_t>"
                    case 0b0011:
                        constants[h] = "<C complex 2x64b>"
                    case 0b0111:
                        constants[h] = "<C++ complex 2x64b>"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b01_101: # 32 byte C/C++
                match kind:
                    case 0b0011:
                        constants[h] = "<C complex 2x128b>"
                    case 0b0111:
                        constants[h] = "<C++ complex 2x128b>"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b11_000: # 1 byte Fortran
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INTEGER1"
                    case 0b001:
                        constants[h] = "MPIX_LOGICAL1"
                    case 0b010:
                        constants[h] = "MPIX_REAL1"
                    case 0b011:
                        constants[h] = "MPI_CHARACTER"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b11_001: # 2 byte Fortran
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INTEGER2"
                    case 0b001:
                        constants[h] = "MPIX_LOGICAL2"
                    case 0b010:
                        constants[h] = "MPI_REAL2"
                    case 0b011:
                        constants[h] = "<Fortran complex 2x8b>"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b11_010: # 4 byte Fortran
                match kind:
                    case 0b000:
                        constants[h] = "MPI_INTEGER4"
                    case 0b001:
                        constants[h] = "MPIX_LOGICAL4"
                    case 0b010:
                        constants[h] = "MPI_REAL4"
                    case 0b011:
                        constants[h] = "MPI_COMPLEX4"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b11_011: # 8 byte Fortran
                match kind:
                    case 0b0000:
                        constants[h] = "MPI_INTEGER8"
                    case 0b0001:
                        constants[h] = "MPIX_LOGICAL8"
                    case 0b0010:
                        constants[h] = "MPI_REAL8"
                    case 0b0011:
                        constants[h] = "MPI_COMPLEX8"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b11_100: # 16 byte Fortran
                match kind:
                    case 0b0000:
                        constants[h] = "MPI_INTEGER16"
                    case 0b0010:
                        constants[h] = "MPI_REAL16"
                    case 0b0011:
                        constants[h] = "MPI_COMPLEX16"
                    case _:
                        constants[h] = "reserved datatype"

            case 0b11_101: # 32 byte Fortran
                match kind:
                    case 0b0011:
                        constants[h] = "MPI_COMPLEX32"
                    case _:
                        constants[h] = "reserved datatype"

            case _:
                constants[h] = "reserved datatype"

    else:
        constants[h] = "reserved datatype"

def parse_other(h):
    handle_type = (h & 0b11111_000) >> 3;
    if   (handle_type == 0b00000):
        handle_types[h] = "MPI_Comm"
        comm_type = (h & 0b111) 
        if   (comm_type == 0b000):
            constants[h] = "MPI_COMM_NULL"
        elif (comm_type == 0b001):
            constants[h] = "MPI_COMM_WORLD"
        elif (comm_type == 0b010):
            constants[h] = "MPI_COMM_SELF"
        else:
            constants[h] = "reserved comm"
    elif (handle_type == 0b00001):
        handle_types[h] = "MPI_Group"
        group_type = (h & 0b111) 
        if   (group_type == 0b000):
            constants[h] = "MPI_GROUP_NULL"
        elif (group_type == 0b001):
            constants[h] = "MPI_GROUP_EMPTY"
        else:
            constants[h] = "reserved group"
    elif (handle_type == 0b00010):
        handle_types[h] = "MPI_Win"
        win_type = (h & 0b111) 
        if   (win_type == 0b000):
            constants[h] = "MPI_WIN_NULL"
        else:
            constants[h] = "reserved win"
    elif (handle_type == 0b00011):
        handle_types[h] = "MPI_File"
        file_type = (h & 0b111) 
        if   (file_type == 0b000):
            constants[h] = "MPI_FILE_NULL"
        else:
            constants[h] = "reserved file"
    elif (handle_type == 0b00100):
        handle_types[h] = "MPI_Session"
        session_type = (h & 0b111) 
        if   (session_type == 0b000):
            constants[h] = "MPI_SESSION_NULL"
        else:
            constants[h] = "reserved session"
    elif (handle_type == 0b00101):
        handle_types[h] = "MPI_Message"
        message_type = (h & 0b111) 
        if   (message_type == 0b000):
            constants[h] = "MPI_MESSAGE_NULL"
        elif (message_type == 0b001):
            constants[h] = "MPI_MESSAGE_NO_PROC"
        else:
            constants[h] = "reserved message"
    elif (handle_type == 0b00110):
        handle_types[h] = "MPI_Info"
        info_type = (h & 0b111)
        if   (info_type == 0b000):
            constants[h] = "MPI_INFO_NULL"
        else:
            constants[h] = "reserved info"
    # 0b00111 (space for new handle that only needs 8 slots)
    elif (handle_type == 0b01000):
        handle_types[h] = "MPI_Errhandler"
        errhandler_type = (h & 0b111) 
        if   (errhandler_type == 0b000):
            constants[h] = "MPI_ERRHANDLER_NULL"
        elif (errhandler_type == 0b001):
            constants[h] = "MPI_ERRORS_ARE_FATAL"
        elif (errhandler_type == 0b010):
            constants[h] = "MPI_ERRORS_RETURN"
        elif (errhandler_type == 0b011):
            constants[h] = "MPI_ERRORS_ABORT"
        else:
            constants[h] = "reserved errhandler"
    # 0b01... (lots of space for errhandlers, if necessary)
    elif (handle_type == 0b10000):
        handle_types[h] = "MPI_Request"
        request_type = (h & 0b111) 
        if (request_type == 0b000):
            constants[h] = "MPI_REQUEST_NULL"
        else:
            constants[h] = "reserved request"
    else:
        constants[h] = "reserved handle"



def parse_op(h):
    handle_types[h] = "MPI_Op"
    op_type = (h & 0b11000) >> 3
    op = h & 0b111
    if   (op_type == 0b00): # arithmetic
        if   (op == 0b000):
            constants[h] = "MPI_OP_NULL"
        elif (op == 0b001):
            constants[h] = "MPI_OP_SUM"
        elif (op == 0b010):
            constants[h] = "MPI_OP_MIN"
        elif (op == 0b011):
            constants[h] = "MPI_OP_MAX"
        elif (op == 0b100):
            constants[h] = "MPI_OP_PROD"
        else:
            constants[h] = "reserved arithmetic op"
    elif (op_type == 0b01): # bit ops
        if   (op == 0b000):
            constants[h] = "MPI_OP_BAND"
        elif (op == 0b001):
            constants[h] = "MPI_OP_BOR"
        elif (op == 0b010):
            constants[h] = "MPI_OP_BXOR"
        else:
            constants[h] = "reserved bit op"
    elif (op_type == 0b10): # logical ops
        op = h & 0b111
        if   (op == 0b000):
            constants[h] = "MPI_OP_LAND"
        elif (op == 0b001):
            constants[h] = "MPI_OP_LOR"
        elif (op == 0b010):
            constants[h] = "MPI_OP_LXOR"
        else:
            constants[h] = "reserved logical op"
    elif (op_type == 0b11): # other ops
        op = h & 0b111
        if   (op == 0b000):
            constants[h] = "MPI_OP_MINLOC"
        elif (op == 0b001):
            constants[h] = "MPI_OP_MAXLOC"
        elif (op == 0b100):
            constants[h] = "MPI_OP_REPLACE"
        elif (op == 0b101):
            constants[h] = "MPI_NO_OP"
        else:
            constants[h] = "reserved other op"

def parse_handle(h):

    # uninitialized handle
    if (h == 0b0):
        constants[h] = "invalid (uninitialized)"
        return

    # if h > 1023 also works :-)
    if (h & 0b1111111111111111111111111111111111111111111111111111110000000000):
        constants[h] = "not a predefined handle constant"
        return

    # datatype: 0b10_..._.....
    if (h & 0b10_000_00000):
        parse_datatype(h)
    # other: 0b01_..._.....
    elif (h & 0b01_000_00000):
        parse_other(h)
    # op: 0b00_001_.....
    elif (h & 0b11_111_00000 == 0b00_001_00000):
        parse_op(h)
    # reserved: 0b11_..._..... or 0b00_(not op)
    else:
        constants[h] = "reserved handle"
        

def main():
    for h in range(0,1025):
        parse_handle(h)
        #print(h,constants[h])

    if ( len(sys.argv) == 1 ):
        for h in range(0,1025):
            #print(h,bin(h),constants[h],handle_types[h],hex(h))
            print(format(h,"4d"),format(h,"012b"),constants[h])
            #print(h,constants[h])

    # make mpi.h
    if ( len(sys.argv) > 1 ):
        for h in range(0,1025):
            if (constants[h][0:3] == "MPI"):
                #print(format('#define',"7s"),constants[h],'(',handle_types[h],') 0x',format(h,"4x"))
                line = '#define ' + format(constants[h],"30s") + " (" + handle_types[h] + ")" + "0x" + format(h,"08x")
                print(line)

if __name__ == '__main__':
    main()

