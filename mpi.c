#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char * argv[]) {
    int id, size;
    int lista[100] = {0};
    int i, tag = 0;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Quantos processos temos?
    MPI_Comm_rank(MPI_COMM_WORLD, &id); // Quem sou seu na fila do pão?
    printf("Olá %d de %d\n", id, size);
    // for(;;) {

    // }

    if (id == 0) { //mestre
        for (i = 0; i<size; i++) {
            lista[i] = i;
        }
        for (i = 1; i<size; i++) {
            MPI_Send(lista, 100, MPI_INT, i, tag, MPI_COMM_WORLD);
        }
    } else { // trabalhador
        MPI_Recv(lista, 100, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
        printf("Processo %d: vetor[%d]: %d", id, i, lista[i]);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    printf("Depois da barreira %d\n", id);

    MPI_Finalize();

    return 0;
}