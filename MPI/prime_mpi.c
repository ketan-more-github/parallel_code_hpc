#include "stdio.h"
#include "mpi.h"
#include <math.h>
#include <sys/time.h>

#define N 10

int main(int argc, char **argv)
{

    int my_id, size;
    int start, end, i, j, count, recv_count, flag;
    double exe_time;
    struct timeval stop_time, start_time;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    start = my_id * (N / size);
    end = start + (N / size);

    if (my_id == (size - 1))
    {
        end = N;
    }

    if (my_id == 0)
    {
        gettimeofday(&start_time, NULL);
    }
    start=start+2;
    for ( i = start; i < end; i++)
    {

        flag = 0;
        for (j = 2; j < i; j++)
        {
            if ((i % j) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            count++;
        }
    }
    start=start-2;

    if (my_id == 0)
    {

        for (int i = 1; i < size; i++)
        {
            MPI_Recv(&recv_count, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            count = count + recv_count;
        }

        gettimeofday(&stop_time, NULL);
        exe_time = (stop_time.tv_sec + (stop_time.tv_usec / 1000000.0)) - (start_time.tv_sec + (start_time.tv_usec / 1000000.0));
        printf("\n Number of prime numbers = %d \n Execution time is = %lf seconds\n", count, exe_time);
    }
    else
    {
        MPI_Send(&count, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}