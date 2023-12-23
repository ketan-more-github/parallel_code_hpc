
#include"stdio.h"
#include"mpi.h"

int main(int argc, char **argv){


        int my_id, size;
        
        MPI_Init(&argc, &argv);

        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

        int start, end;
        int N=10;
        start=my_id*(N/size);
        end= start+(N/size);

        if(my_id==(size-1)){
                end=N;
        }

        for(int i=start; i<end; i++){

                printf("\nProcess number %d : Processing %d\n",my_id,i);
        }


        MPI_Finalize();

}