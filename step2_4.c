#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 200
#define maxlength 50

void insertfile(char text[N][100+1]);
void insertlexilogio(char correcttext[N][100+1]);
void savekimeno(char text[N][100+1]);
void litourgiadiorthosis(char text[N][100+1], char correcttext[N][100+1]);
void countstatistics(char text[N][100+1]);

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
            litourgiadiorthosis(text, correcttext);
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
           countstatistics(text);
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

void litourgiadiorthosis(char text[N][100+1], char correcttext[N][100+1])
{
    int choice;
    printf("Please tell me what to do 1.antikatastasi lexewn 2.insert word to vocabulary 3.continue correcting the rest 4.exit diorthosi:");
    scanf("%d", &choice);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            while(choice!=4)
            {
                if(choice==1)
                {   
                    char sosto[100];
                    if(scanf("%s", sosto), strcmp(text[i], correcttext[j]))
                    {
                        strcpy(text[i], sosto);
                    }
                    char *filename;
                    printf("Enter the filename:");
                    scanf("%s", filename);
                    FILE *file=fopen(filename, "a");
                    int i=0;
                    printf("POS=%ld", ftell(file));
                    while(!feof(file))
                    {
                      fprintf(file, "%s", sosto[i]);
                       printf("%c", fgetc(file));
                       i++;
                    }
                    if(file==NULL)
                    {
                       printf("ERROR COULD NOT OPEN FILE\n");
                       exit(EXIT_FAILURE);
                    }
                    fclose(file);

                }
                if(choice==2)
                {
                    strcpy(correcttext[j],text[i]);
                    FILE* fp= fopen("Top1000EnglishWords", "a");
                    int i=0;
                    printf("POS=%ld", ftell(fp));
                    while(!feof(fp))
                    {
                        fprintf(fp, "%s", correcttext[i]);
                        i++;
                        printf("%c", fgetc(fp));
                    }
                    if(fp==NULL)
                    {
                        printf("ERROR COULD NOT OPEN VOCABULARY FILE\n");
                        exit(EXIT_FAILURE);
                    }
                    fclose(fp);
                }
                if(choice==3)
                {
                    continue;
                }
                if(choice==4)
                {
                    break;
                }
            } 
        }
        
    }
}

void savekimeno(char text[N][100+1])
{
    FILE *cfPtr=fopen("myfile.txt", "w");
    for(int i=0; i<200; i++)
    {
        fprintf(cfPtr, "%s", text[i]);
    }
}

void countstatistics(char text[N][100+1])
{
    char *filename;//copy tin epilogh 1 gia na gemisw ton text 
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

    char ch;
    int charskena;
    int words=0;
    int chars=0;

    while((ch=fgetc(file))!=EOF) //3.1
    {
        chars++;
        if(ch==' ' || ch=='\n' || ch=='\t')
        {
            charskena++;
            words++;
        }
    }
    
    printf("Number of words in file: %d\n", words+1);
    printf("Number of characters in file: %d\n", chars);
    printf("Number of characters-kena in file: %d\n", charskena); //ksexwrista oi xaraktires kena
    
    //3.2
    int difwords=0;
    int found =0;
    rewind(file);
    while(!feof(file))
    {
        for(int i=0; i<difwords; i++)
        {
            for(int j=0; j<difwords; j++)
            {
                for(i=0; i<N; i++)
                {
                    for(j=0; j<101; j++)
                    {
                        if(strcmp(text[i], text[j])==0)
                        {
                            found=1;
                            break;
                        } 
                    }
                }  
            }
        }
        
    }
    printf("Number of dfferent words: %d\n", difwords);

    //3.3 
    int letter[maxlength]={0}; //pinakas me midenika sta grammata
    for(int i=0; i<N; i++)
    {
        while(fscanf(file, "%s", text[i])==1)
        {
            printf("%s", text[i]);
            int length=0;
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<101; j++)
                {
                   if(isalpha(text[i][j]))
                    {
                       length++;
                    }
                }
            }
            if(length<maxlength) //increase grammata analoga me mikos lexis
            {
              letter[length]++;
            }
        }
    }
   
    printf("HISTOGRAM THAT COUNTS THE CHARACTERS OF EACH WORD:\n");
    for(int i=1; i<maxlength; i++)
    {
        printf("%d", i);
        for(int j=0; j<letter[j]; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    fclose(file);

    //3.4
    printf("Enter a filename to save the previous statistics:");
    char *filename2;                           
    FILE* savestatistics;
    scanf("%s", filename2);       
    savestatistics= fopen("filename2", "w");
    fprintf(savestatistics, "histogram:\n"); //grafw to istogramma sto arxeio mou
    for(int i=1; i<maxlength; i++)
    {
        fprintf(savestatistics, "%2d:", i);
        for(int j=0; j<letter[i]; j++)
        {
            fprintf(savestatistics, "#");
        }
        fprintf(savestatistics, "\n");
    }
    if(savestatistics==NULL)
    {
        printf("ERROR COULD NOT OPEN FILE\n");
        exit(EXIT_FAILURE);
    }
    fclose(savestatistics);
    printf("histogram saved to %s. \n", filename);
    
}