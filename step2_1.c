#include <stdio.h>
#include <string.h>
# define N 200
void insertkeimeno(char text[N][100+1]);
void insertlexilogio();
void litourgiadiorthosis();
void savekimeno();
void countstatistics();

int main()
{
    char text[N][100+1];
    int epiloges;
    printf("Please tell me what to do 1.insert text 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
    scanf("%d", &epiloges);
    while(epiloges!=6)
    {
        if(epiloges==1)
        {
            insertkeimeno(text);
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==2)
        {
            insertlexilogio();
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==3)
        {
            litourgiadiorthosis();
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==4)
        {
            savekimeno();
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
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

void insertkeimeno(char text[N][100+1]) //eisagogh apo plhktrologio oxi arxeia
{
    printf("Please insert a text:");  
    char save[100+1];//save to keimeno pou vazw se allo pinaka strings
    char endword[10]= "T*E*L*O*S";
    int i=0;
    while(scanf("%s", text[i]),  strcmp(text[i], endword))
    {
        strcpy(text[i++], save);
        printf("%s ", save);
        if(text[i]==endword) break;
    }
}

void insertlexilogio()
{
    printf("insertlexilogio");
}

void litourgiadiorthosis()
{
    printf("litourgiadiorthosis");
}

void savekimeno()
{
    printf("savekimeno");
}

void countstatistics()
{
    printf("countstatistics");
}
