#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200
void insertfile(char text[N][100+1]);
void insertlexilogio(char correcttext[N][100+1]);
void savekimeno(char text[N][100+1]);
void litourgiadiorthosis();
void countstatistics();

int main()
{
    char text[N][100+1];
    char correcttext[N][100+1];
    int epiloges;
    printf("Please tell me what to do 1.insert file 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
    scanf("%d", &epiloges);
    while(epiloges!=6)
    {
        if(epiloges==1)
        {
            insertfile(text);
            printf("\n");
            printf("Please tell me what to do 1.insert file 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==2)
        {
            insertlexilogio(correcttext);
            printf("\n");
            printf("Please tell me what to do 1.insert file 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==3)
        {
            litourgiadiorthosis();
            printf("\n");
            printf("Please tell me what to do 1.insert file 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==4)
        {
            savekimeno(text);
            printf("\n");
            printf("Please tell me what to do 1.insert file 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==5)
        {
           countstatistics();
           printf("\n");
           printf("Please tell me what to do 1.insert text 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
           scanf("%d", &epiloges);
        }   
    }

    return 0;
}

void insertfile(char text[N][100+1])
{
    char *filename;
    printf("Enter the filename:");
    scanf("%s", filename);
    FILE *file=fopen(filename, "r");
    int i=0;
    while(!feof(file))
    {
        fscanf(file, "%s", text[i]);
        i++;
    }
    if(file==NULL)
    {
        printf("ERROR COULD NOT OPEN FILE\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void insertlexilogio(char correcttext[N][100+1])
{
    FILE* fp= fopen("Top1000EnglishWords", "r");
    int i=0;
    while(!feof(fp))
    {
        fscanf(fp, "%s", correcttext[i]);
        i++;
    }
    if(fp==NULL)
    {
        printf("ERROR COULD NOT OPEN VOCABULARY FILE\n");
        exit(EXIT_FAILURE);
    }
    fclose(fp);
}

void litourgiadiorthosis()
{
    printf("litourgiadiorthosis");
}

void savekimeno(char text[N][100+1])
{
    FILE *cfPtr=fopen("myfile.txt", "w");
    for(int i=0; i<200; i++)
    {
        fprintf(cfPtr, "%s", text[i]);
    }
}

void countstatistics()
{
    printf("countstatistics");
}

