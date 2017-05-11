CLEANFILES       =  petsc_test petsc_test.o

all: petsc_test

include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules

petsc_test: petsc_test.o  chkopts
	-${CLINKER} -o petsc_test petsc_test.o ${PETSC_KSP_LIB}
