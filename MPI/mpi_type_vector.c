// int MPI_Type_vector(int block_count,
//                     int block_length,
//                     int stride, ->> diffrence
//                     MPI_Datatype old_datatype,--> MPI_int
//                     MPI_Datatype* new_datatype); --> Derrived data type

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{

    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Datatype column_type;
    MPI_Type_vector(3, 1, 3, MPI_INT, &column_type);
    MPI_Type_commit(&column_type);

    if (size != 2)
    {
        printf("This application is meant to be run with 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    enum rank_roles
    {
        SENDER,
        RECEIVER
    };

    switch (my_rank)

    {

    case SENDER:

    {

        // Create the datatype

        int buffer[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

        MPI_Request request;

        printf("MPI process %d sends values %d, %d and %d.\n", my_rank, buffer[0][1], buffer[1][1], buffer[2][1]);

        MPI_Send(&buffer[0][1], 1, column_type, RECEIVER, 0, MPI_COMM_WORLD);

        break;
    }

    case RECEIVER:

    {
        int revcived[3];
        MPI_Recv(&revcived, 3, MPI_INT, SENDER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("MPI process %d received values: %d, %d and %d.\n", my_rank, revcived[0], revcived[1], revcived[2]);
        break;
    }
    }

    MPI_Type_free(&column_type);
    MPI_Finalize();

    return 0;
}
