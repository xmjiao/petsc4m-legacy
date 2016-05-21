% The classical greeting: "Hello world! I'm rank m/n"
%
%  Examples:
%  Note: Make sure your start-up script adds the MMPI directory
%        into the path of MATLAB/Octave.
%  To run within MATLAB or Octave:
%  >> run examples/hello.m                     % only 1 processor is used.
%
%  To run from command line with multiple octave instances.
%  $ mpirun -np 2 octave --no-gui -q --eval "startup; run examples/hello.m"
%
%  To run from command line with multiple Matlab instances.
%  $ mpirun -np 2 matlab -nosplash -nojvm -r "run examples/hello.m; exit"
%

fprintf(1, 'Hello, MPI_COMM_world! I''m rank %d/%d\n', ...
    mpi_Comm_rank(MPI_COMM_WORLD), mpi_Comm_size(MPI_COMM_WORLD));
