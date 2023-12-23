#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    int my_id, size;
    int a , b;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

     a = 10;
     b = a+5; 

    if (my_id == 0)
    {
         a = 20;
         b = 10;
    }

    MPI_Bcast(&a , 2 , MPI_INT, 0, MPI_COMM_WORLD);
    printf("myid:%d \t data = %d and %d\n",my_id, a , b);
    MPI_Finalize();

    return 0;
}
