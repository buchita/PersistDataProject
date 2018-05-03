/*
DESCRIPTION :   Program that reads the details of an mp3 file and checks if it contains a valid mp3 tag

DATE :18/04/2017

COMPLIER : CodeBlocks

OS : Windows10

AUTHOR: Kevin Fitzpatrick and Buchita Gitchamnan
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declare structure with file details
struct mp3file
{
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[30];
    char genre;
};


int main()
{
    struct mp3file mp3tag;
    char filename[20];

    //declare file pointer
    FILE *fp;

    //ask user to enter name of the mp3 file
    printf("Enter the name of the file\n");
    scanf("%s",filename);

    //open the file for reading
    fp = fopen(filename,"rb");

    //check if the file exists
    if(fp == NULL)
    {
        printf("Error: File does not exist\n");
    }
    else
    {
        printf("\nFile opened\n");
        getchar();
    }


    //sets the pointer to 128 bytes from the end
    fseek(fp, -128, SEEK_END);


    //reads in details of the mp3 tag
    fread(&mp3tag,sizeof(mp3tag),1,fp);


    //checks if the mp3 file contains a valid tag
    if(strncmp(mp3tag.tag,"TAG",3)==0)
    {
        printf("\nTag found\n");

        //print the details of the mp3 file
        printf("\nSong Title: %s\n",mp3tag.title);
        printf("Artist: %s\n",mp3tag.artist);
        printf("Album: %s\n",mp3tag.album);
        printf("Year: %.4s\n",mp3tag.year);
        printf("Genre: %d\n",mp3tag.genre);

    }
    else
    {
        printf("\nThe file does not contain a valid audio tag\n");
        fclose(fp);
    }

    fclose(fp);
    getchar();
    return(0);
}
