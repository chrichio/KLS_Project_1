
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#define MaxLimit 30
#define MinLimit 12

int main(int argc, char* argv[])
{
/*
    argv[1]=Maximum sugkrouseis, an einai -1 den uparxei orio
    argv[2]=Maximum xronos ektelesis, an einai -1 den uparxei orio
    argv[3]=To onoma toy arxeiou me tis suntetagmenes
    argv[4]=Mege8os nimaton openMP, me -1 xrisimopoiountai ola, me perissotera apo ta available pali ola
    argv[5]=Mege8os diergasiwn openMPI, me -1 oles, me perissotera pali oles oi dia8esimes
*/
    FILE *fp;
    fp = fopen(argv[3], "r");
    if (!fp)
        return 1;
    //Epistrofi 1 se periptwsi pou yparxei problima me to file
    int countcol=0; //Metrisi sygkrousewn
    int countlegit=0; //Sygkrouseis mesa sta oria
    float tmpX,tmpY,tmpZ;//temp metavlites
    int num=atoi(argv[1]);//atoi g n metatrepsw to string se int
    int i;
    int ar[num][3];
    for(i=0;i<num;i++)//vazw se pinaka tis suntetagmenes
    {
        fscanf(fp,"%f %f %f\n",ar[i][0],ar[i][1],ar[i][2]);
    }
    struct timespec start, end;
    MPI_INIT(&argc,&argv);//3ekinaei to MPI
    clock_gettime(CLOCK_MONOTONIC, &start);//ksekinaei o timer
    /* SERIAL
    for(i=0;i<num;i++)
    {
        if (ar[i][0]>=MinLimit && ar[i][0]<=MaxLimit && ar[i][1]>=MinLimit && ar[i][1]<=MaxLimit && ar[i][2]>=MinLimit && ar[i][2]Y<=MaxLimit)
            countlegit++;
    }
    */
    
    clock_gettime(CLOCK_MONOTONIC, &end);//stamataei o timer
    fclose(fp);
    //Block kwdika gia upologismo xronou
    const int DAS_NANO_SECONDS_IN_SEC=1000000000;
    long timeElapsed_s=end.tv_sec-start.v_sec;
    long timeElapsed_n=end.tv_nsec-start.tv_nsec;
    //An to timeElapsed_n<0 daneizomaste ena sec
    if (timeElapsed_n<0)
    {
        timeElapsed_n=DAS_NANO_SECONDS_IN_SEC+timeElapsed_n;
        timeElapsed_s--;
    }
    return 0;
}
