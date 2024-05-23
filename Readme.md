
`
mpicc -o mpi mpi.c
mpirun --machinefile hosts.txt mpi
mpirun --machinefile hosts.txt -np 12 mpi
mpirun --machinefile hosts.txt -np 12 --mca btl_tcp_if_include 10.20.221.0/24 mpi
`
