#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <math.h> 
int main(int argc, char **argv)
{
int rank, size;
double send_number=9;
double rec_number;
MPI_Init (&argc,&argv);

MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Status status;

/*   if(rank==0) {
      MPI_Send(&send_number, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
      MPI_Recv(&rec_number, 1, MPI_DOUBLE, size-1, 0, MPI_COMM_WORLD, &status);
    }
   else if( rank == size-1) {
      MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD, &status);
      MPI_Send(&send_number, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
   else {
      MPI_Recv(&rec_number, 1, MPI_DOUBLE, rank-1, 0, MPI_COMM_WORLD, &status);
      MPI_Send(&send_number, 1, MPI_DOUBLE, rank+1, 0, MPI_COMM_WORLD);
    }
   printf("Process %i send %1.3e and recieved %1.3e\n", rank,send_number,rec_number );
*/
double x_process_max;
double x_max=-100;
MPI_Reduce(&x_process_max,&x_max,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
printf("process ID %i, x=%f,max x = %f\n",rank,x_process_max,x_max );  
 MPI_Finalize();
return 0;
}

