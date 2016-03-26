#include <stdio.h>
#include <stdlib.h>
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
    int maxnum=atoi(argv[1]);
    //start timer
    while((countcol<maxnum))
    {
        if (feof (fp)) break;
        countcol++;
        fscanf(fp,"%f %f %f\n",tmpX,tmpY,tmpZ);
        if (tmpX>=MinLimit && tmpX<=MaxLimit && tmpZ>=MinLimit && tmpZ<=MaxLimit && tmpY>=MinLimit && tmpY<=MaxLimit)
            countlegit++;
    }
    //end timer
    fclose(fp);
    // printf xronos epe3ergasias kai ru8mos sugkrouseis/ana lepto
    return 0;
}
