#include <stdio.h>
#include <stdlib.h>
#include <utime.h>

//kaleite me tin morfi mygenerator datafile number

int main(int argc, char *argv[])
{
    int number=atoi(argv[2]);//o ari8mos twn sugkrousewn, atoi gia metatropi apo string se int
    FILE *fp;
    fp = fopen(argv[1], "w");
    if (!fp)
        return 1; //Epistrofi 1 se periptwsi pou yparxei problima me to file
    int utime;
    long int ltime;
    int i;
    float cords[number][3];
    ltime = time(NULL);
    utime = (unsigned int) ltime/2;
    srand(utime);
    for(i=0;i<number;i++)
    {
        cords[i][0]=(float)34*rand()/(RAND_MAX-1);
        cords[i][1]=(float)34*rand()/(RAND_MAX-1);
        cords[i][2]=(float)34*rand()/(RAND_MAX-1);
        fprintf(fp, "%f %f %f\n",cords[i][0],cords[i][1],cords[i][2] );
    }
    fclose(fp);//kleinw to file
    return 0;

}
