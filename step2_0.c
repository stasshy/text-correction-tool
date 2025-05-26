#include <stdio.h>
#include <string.h>
void insertkeimeno();
void insertfile();
void insertlexilogio();
void litoutgiadiorthosis();
void savekimeno();
void countstatistics();


int main()
{
    int epiloges;
    printf("Please tell me what to do 1.insert text or insert file 2.insert vocabulary 3.correct text 4.save text 5.count statistics 6. exit: ");
    scanf("%d", &epiloges);
    while(epiloges!=6)
    {
        if(epiloges==1)
        {
            insertkeimeno();
            printf("\n");
            insertfile();
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert file 3.insert vocabulary 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==2)
        {
            insertlexilogio();
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert file 3.insert vocabulary 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==3)
        {
            litoutgiadiorthosis();
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert file 3.insert vocabulary 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==4)
        {
            savekimeno();
            printf("\n");
            printf("Please tell me what to do 1.insert text 2.insert file 3.insert vocabulary 4.save text 5.count statistics 6. exit: ");
            scanf("%d", &epiloges);
        }
        else if(epiloges==5)
        {
           countstatistics();
           printf("\n");
           printf("Please tell me what to do 1.insert text 2.insert file 3.insert vocabulary 4.save text 5.count statistics 6. exit: ");
           scanf("%d", &epiloges);
        }   
    }

  return 0;
}

void insertkeimeno()
{
    printf("insertkeimeno");
}

void insertfile()
{
    printf("insertfilename");
}

void insertlexilogio()
{
    printf("insertlexilogio");
}

void litoutgiadiorthosis()
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

