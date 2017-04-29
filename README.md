OVERVIEW
========

Petsc4m is an Octave Interface for PETSc. It supports solving large-scale
sparse linear systems using PETSc in Octave. The data exchanges between Octave
and PETSc are done through memory.

Petsc4m is flexible and easy to use. Its top-most functions are composed
of `petscSolve` and `petscSolveCRS`, plus nine other helper functions.
These functions support accessing iterative solvers in PETSc directly
from Octave without much codingx.  Petsc4m also offers about 150 low-level
PETSc API functions, so that you can also directly program in Octave using
the PETSc API for prototyping. Petsc4m depends on
[ParaCoder](http://github.com/fastsolve/paracoder) for some basic
MPI calls.

The high-level Petsc4m functions support two matrix formats: Sequential
AIJ and MPI AIJ. These formats tend to deliver good performance and
offer good interoperability with Octave. Other matrix formats, such as
dense and MPI Block AIJ, are accessible through the low-level functions.

EXAMPLE
=======

The following example illustrates how to use `petscSolveCRS`:
```
   % Set up a test matrix
   A = sprand(100,100,0.3);
   A = A + speye(100);
   [rowptr, colind, val] = crs_matrix(A);
   b = rand(100,1);

   % Solve using default KSP solver and preconditioner
   [x,flag,relres,reshis,iter] = petscSolveCRS(rowptr, colind, val, b);

   % Solve using GMRES with Jacobi preconditioner with default options
   [x,flag,relres,iter,reshis] = petscSolveCRS(rowptr, colind, val, b, ...
        PETSC_KSPGMRES, 0, int32(0), PETSC_PCJACOBI, 'right');

   % Solve using BiCGSTAB with Jacobi preconditioner as right preconditioner
   % with relative tolerance 1.e-10 and a maximum of 100 iterations
   [x,flag,relres,iter,reshis] = petscSolveCRS(rowptr, colind, val, b, ...
        PETSC_KSPBCGS, 1.e-10, int32(100), PETSC_PCJACOBI, 'right');

   % Solve using SuperLU as a direct solver (assuming SuperLU is installed)
   [x,flag,relres,iter,reshis] = petscSolveCRS(rowptr, colind, val, b, ...
        PETSC_KSPPREONLY, 0, int32(0), PETSC_PCLU, PETSC_MATSOLVERSUPERLU);
```

The top-level functions use the low-level PETSc function along with some
basic MATLAB/Octave features.

TRYING OUT PETSC4M
==================

Petsc4m is a very complicated piece of software with many dependencise. The
easiest way to try it out is to use the Jupyter Notebook through Docker.
It offers a very convenient way to try out different solvers in PETSc.

There are three simple steps to set it up:
 - Make sure you have Python and Docker installed on your computer
 - Download [petsc-notebook.ipynb](petsc-notebook](http://github.com/fastsolve/petsc4m/petsc-notebook.ipynb) and save it into a working directory
 - Download petsc-jupyter.py and save it into your working directory

Now, you can run the Notebook by issuing the command:
```
petsc-jupyter.py petsc-notebook.ipynb
```

NAMING AND NUMBERING CONVENTIONS
================================

Top-Level Functions
-----------------------

The top-level functions in Petsc4m have the prefix petsc, and are all in
the Petsc4m root directory. The array indices of top-level functions
are 1-based.  The character strings for the top-level functions do not
need to be null-terminated. These are consistent with the convention
of MATLAB/Octave.

For most users, `petscSolve` and `petscSolveCRS` are the only two
function you need to use. The former uses Octave's built-in sparse
matrix format, and the latter uses the CRS format stored in three
different arrays: `rowptr`, `colind`, and `val`.

Low-Level Functions
-----------------------

The low-level functions in Petsc4m allow accessing virtually all features
of PETSc in MATLAB. The indices for all low-level functions are 0-based,
and all the strings must be null-terminated.

There are three types of low-level functions in Petsc4m.
  * PETSc Functions: All functions have prefix petsc, such as petscMatCreate.
  * PETSc Constants: All constants have prefix PETSC_, such as PETSC_COMM_WORLD.
  * PETSc Data Types: All data types in Petsc4m have prefix Petsc, such as
         PetscMat, PetscVec, PetscKSP, etc.
The first two types are useful for all users. The third types are for
internal use.

When specifying KSPType, PCType, MatType, VecType, etc.,
it is the best to use the constants defined by Petsc4m instead of using
character strings directly. These constants have the prefix PETSC_KSP,
PETSC_PC, PETSC_MAT, and PETSC_VEC respectively. These names are all
null-terminated strings, so you do not need to worry about null-terminating
them manually.

The functions for Mat, Vec, KSP, and PC are all located in the sub-directory
Mat/, Vec/, KSP/, and PC/, respectively. Most of these functions do not need to be
used directly, except for the APIs for creating and destroying them. The other
functions are helpful for prototyping new algorithms or experimenting with
different matrix formats in PETSc.

The functions related to initialization, finalization, and options are in
the sys/ subdirectory.

Basic MPI Functions
-------------------

Petsc4m uses a few basic MPI functions provided by
[`ParaCoder`](http://github.com/fastsolve/paracoder), including
```
   mpi_Init
   mpi_Initialized
   mpi_Comm_size
   mpi_Comm_rank
   mpi_Barrier
   mpi_Finalize
   mpi_Finalized
```

Additional MPI features are available through `ParaCoder`.

NOTES ON PETSC4M IN MATLAB
==========================

Bsides Octave, Petsc4m is also compatible without MATLAB. However, there seem
to be some conflicts between MATLAB's and PETSc's memory managers.
Therefore, data exchange between MATLAB and Petsc4m is done through
files to avoid MATLAB from random crashings. For production runs, we
strongly recommend using Petsc4m with Octave.

LIMITATIONS
===========

Virtually all features in PETSc are available through Petsc4m. However,
Petsc4m does not yet support `KSPRegister` and `PCRegister`, so you
cannot easily use Petsc4m to implement new solvers for PETSc.
