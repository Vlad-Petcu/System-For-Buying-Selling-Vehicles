// Sistem pentru cumpărare / vânzare autovehicule
// Aplicația permite postarea de anunțuri de vânzare a autovehiculelor. Utilizatorului îi sunt
// cerute date despre mașină, de exemplu seria de șasiu, numărul de kilometri rulați, anul fabricației,
// tip caroserie, marcă etc. și prețul de vânzare. Unui utilizator ce dorește să cumpere o mașină,
// îi sunt oferite următoarele opțiuni: vizualizare listă întreagă, filtrare listă în funcție de oricare
// atribut, vizualizare listă mașini sub un preț dorit. Când utilizatorul selectează o mașină, acestuia
// îi sunt afișate toate informațiile despre mașină și o poate cumpăra (moment în care anunțul va fi șters).

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1000

void meniu_principal();
void meniu_vanzare(char path[]);
void inapoi_vanzare();
void meniu_cumparare();
void inapoi_cumparare();
void afisare(char path[]);
void filtrare();
void marca();
void model();
void series();
void anulfb();
void caroserie();
void pret();
void sterge();
void stergeLinie();
void cumpar();


int main(){
    meniu_principal();
    return 0;
}


void meniu_principal() {
    char path[] = "masini.txt";

    int optiune;

    printf("/----------------------/");
    printf("         MENIU          ");
    printf("/----------------------/\n");
    printf("1. Vreau sa vand o masina\n");
    printf("2. Vreau sa cumpar o masina\n");
    printf("3. Iesire\n");
    printf("\n");
    printf("Introduceti optiunea dorita: ");
    scanf("%d", &optiune);
    printf("\n");

    switch(optiune){
        case 1:
            system("clear");
            meniu_vanzare(path);
            system("clear");
            inapoi_vanzare();
            break;
        case 2:
            system("clear");
            meniu_cumparare();
            printf("\n");
            break;
        case 3:
            system("clear");
            printf("Ati ales iesirea din meniu!\n");
            exit(1);
            break;
        default:
            system("clear");
            printf("Optiune invalida!\n");
            printf("Alege o optiune valida!\n");
            printf("\n");
            meniu_principal();
    }
}

void meniu_vanzare(char path[]){

    FILE * filePointer;
    filePointer = fopen(path, "a");

    char marca[50], modelul[50], seria[50], nrkm[50], anulf[50], caroseria[50];
    int pret;

    getchar();
    printf("Marca: ");
    scanf("%[^\n]", marca);

    getchar();
    printf("Modelul: ");
    scanf("%[^\n]", modelul);

    getchar();
    printf("Seria de sasiu: ");
    scanf("%[^\n]", seria);

    getchar();
    printf("Numarul de kilometri: ");
    scanf("%[^\n]", nrkm);

    getchar();
    printf("Anul fabricatiei: ");
    scanf("%[^\n]", anulf);

    getchar();
    printf("Carosieria: ");
    scanf("%[^\n]", caroseria);

    printf("Pret: ");
    scanf("%d", &pret);

    printf("\n");

    if ( filePointer == NULL )
    {
        printf( "Fisierul nu poate fi accesat." ) ;
    }
    else
    {
        fprintf(filePointer, "%s %s %s %s %s %s %d\n", marca, modelul, seria, nrkm, anulf, caroseria,pret);
        fclose(filePointer) ;
    }
    printf("\n");
}

void inapoi_vanzare() {
    printf("Ai adaugat masina.\n");
    printf("\n");
    printf("1. Inapoi la meniul princicpal\n");
    printf("2. Meniul de cumparare\n");
    int optiune;
    scanf("%d", &optiune);
    system("clear");
    if(optiune == 1) {
        meniu_principal();
    }
    if(optiune == 2) {
        meniu_cumparare();
    }
}

void meniu_cumparare() {
    char path[] = "masini.txt";

    int optiune;
    
    printf("/----------------------/");
    printf("         MENIU          ");
    printf("/----------------------/\n");
    printf("1. Vizualizare lista intreaga\n");
    printf("2. Filtrare lista\n");
    printf("3. Vizualizare lista sub un pret\n");
    printf("4. Inapoi la meniul principal\n");
    printf("\n");
    printf("Introduceti optiunea dorita: ");
    scanf("%d", &optiune);
    printf("\n");

    switch(optiune){
        case 1:
            system("clear");
            afisare(path);
            printf("\n");
            inapoi_cumparare();
            break;
        case 2:
            system("clear");
            filtrare();
            break;
        case 3:
            system("clear");
            pret();
            printf("\n");
            inapoi_cumparare();
            break;
        case 4:
            system("clear");
            meniu_principal();
            break;
        default:
            system("clear");
            printf("Optiune invalida!\n");
            meniu_cumparare();
    }
}

void inapoi_cumparare() {
    printf("1. Inapoi la meniul de cumparare\n");
    printf("2. Inapoi la meniul princicpal\n");
    int alegere;
    scanf("%d", &alegere);
    system("clear");
    if(alegere == 1) {
        meniu_cumparare();
    }
    if(alegere == 2) {
        meniu_principal();
    }
    if(alegere != 1 && alegere != 2) {
        printf("Alegere invalida");
    }
}

void afisare(char path[]) {

    FILE * filePointer;
    filePointer = fopen(path, "r");

    if ( filePointer == NULL )
    {
        printf("Fisierul nu poate fi accesat.");
    }
    else
    {
        char c = fgetc(filePointer);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(filePointer);
        }
        fclose(filePointer);
    }
    printf("\n");
    cumpar();
}

void filtrare() {
    int alegere;
    printf("In functie de ce atribut vrei sa faci filtrarea?\n");
    printf("1. Marca\n");
    printf("2. Model\n");
    printf("3. Seria de sasiu\n");
    printf("4. Anul fabricatiei\n");
    printf("5. Caroseira\n");
    printf("6. Inapoi\n");
    scanf("%d", &alegere);
    switch (alegere)
    {
    case 1:
        system("clear");
        marca();
        break;
    case 2:
        system("clear");
        model();
        break;
    case 3:
        system("clear");
        series();
        break;
    case 4:
        system("clear");
        anulfb();
        break;
    case 5:
        system("clear");
        caroserie();
        break;
    case 6:
        system("clear");
        meniu_cumparare();
        break;
    default:
        system("clear");
        printf("Alegere invalida!\n");
        printf("\n");
        filtrare();
        break;
    }
}

void marca() {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int ok = 0;
    char marca_cautata[50];
    fflush(stdin);
    printf("Introduceti marca:");
    scanf("%[^\n]",marca_cautata);
    getchar();
    printf("\n");
    char marca[50], modelul[50], seria[50], nrkm[50], anulf[50], caroseria[50];
    int pret;
    FILE *fp;
    fp = fopen("masini.txt", "r");
    fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
    if(strcmp(marca,marca_cautata) == 0) {
        printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
        ok = 1;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
        if(strcmp(marca,marca_cautata) == 0) {
            if((read = getline(&line, &len, fp)) != -1) {
                printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
            }
            ok = 1;
        }
    }
    if (ok == 0) {
        printf("Nu avem acesta marca.\n");
    }
    printf("\n");
    fclose(fp);
    printf("1.Inapoi la meniul de cumparare\n");
    printf("2.Inapoi la meniul de filtrare\n");
    int alegere;
    scanf("%d", &alegere);
    if (alegere == 1) {
        system("clear");
        meniu_cumparare();
    }
    if (alegere == 2) {
        system("clear");
        filtrare();
    }
}

void model () {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int ok = 0;
    char modelul_cautat[50];
    fflush(stdin);
    printf("Introduceti modelul:");
    scanf("%[^\n]",modelul_cautat);
    getchar();
    printf("\n");
    char marca[50], modelul[50], seria[50], nrkm[50], anulf[50], caroseria[50];
    int pret;
    FILE *fp;
    fp = fopen("masini.txt", "r");
    fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
    if(strcmp(modelul,modelul_cautat) == 0) {
        printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
        ok = 1;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
        if(strcmp(modelul,modelul_cautat) == 0) {
            if((read = getline(&line, &len, fp)) != -1) {
                printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
            }
            ok = 1;
        }
    }
    if (ok == 0) {
        printf("Nu avem acest model.\n");
    }
    printf("\n");
    fclose(fp);
    printf("1.Inapoi la meniul de cumparare\n");
    printf("2.Inapoi la meniul de filtrare\n");
    int alegere;
    scanf("%d", &alegere);
    if (alegere == 1) {
        system("clear");
        meniu_cumparare();
    }
    if (alegere == 2) {
        system("clear");
        filtrare();
    }
}

void series () {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int ok = 0;
    char seria_cautata[50];
    fflush(stdin);
    printf("Introduceti seria:");
    scanf("%[^\n]",seria_cautata);
    getchar();
    printf("\n");
    char marca[50], modelul[50], seria[50], nrkm[50], anulf[50], caroseria[50];
    int pret;
    FILE *fp;
    fp = fopen("masini.txt", "r");
    fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
    if(strcmp(seria,seria_cautata) == 0) {
        printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
        ok = 1;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
        if(strcmp(seria,seria_cautata) == 0) {
            if((read = getline(&line, &len, fp)) != -1) {
                printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
            }
            ok = 1;
        }
    }
    if (ok == 0) {
        printf("Nu avem acesta serie.\n");
    }
    printf("\n");
    fclose(fp);
    printf("1.Inapoi la meniul de cumparare\n");
    printf("2.Inapoi la meniul de filtrare\n");
    int alegere;
    scanf("%d", &alegere);
    if (alegere == 1) {
        system("clear");
        meniu_cumparare();
    }
    if (alegere == 2) {
        system("clear");
        filtrare();
    }
}

void anulfb () {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int ok = 0;
    char anul_cautat[50];
    fflush(stdin);
    printf("Introduceti anul fabricatiei:");
    scanf("%[^\n]",anul_cautat);
    getchar();
    printf("\n");
    char marca[50], modelul[50], seria[50], nrkm[50], anulf[50], caroseria[50];
    int pret;
    FILE *fp;
    fp = fopen("masini.txt", "r");
    fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
    if(strcmp(anulf,anul_cautat) == 0) {
        printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
        ok = 1;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
        if(strcmp(anulf,anul_cautat) == 0) {
            if((read = getline(&line, &len, fp)) != -1) {
                printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
            }
            ok = 1;
        }
    }
    if (ok == 0) {
        printf("Nu avem nici o masina fabricata in acest an.\n");
    }
    printf("\n");
    fclose(fp);
    printf("1.Inapoi la meniul de cumparare\n");
    printf("2.Inapoi la meniul de filtrare\n");
    int alegere;
    scanf("%d", &alegere);
    if (alegere == 1) {
        system("clear");
        meniu_cumparare();
    }
    if (alegere == 2) {
        system("clear");
        filtrare();
    }
}

void caroserie () {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int ok = 0;
    char caroseria_cautata[50];
    fflush(stdin);
    printf("Introduceti caroseria:");
    scanf("%[^\n]",caroseria_cautata);
    getchar();
    printf("\n");
    char marca[50], modelul[50], seria[50], nrkm[50], anulf[50], caroseria[50];
    int pret;
    FILE *fp;
    fp = fopen("masini.txt", "r");
    fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
    if(strcmp(caroseria,caroseria_cautata) == 0) {
        printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
        ok = 1;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
        if(strcmp(caroseria,caroseria_cautata) == 0) {
            if((read = getline(&line, &len, fp)) != -1) {
                printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
            }
            ok = 1;
        }
    }
    if (ok == 0) {
        printf("Nu avem nici o masina cu acest tip de caroserie.\n");
    }
    printf("\n");
    fclose(fp);
    printf("1.Inapoi la meniul de cumparare\n");
    printf("2.Inapoi la meniul de filtrare\n");
    int alegere;
    scanf("%d", &alegere);
    if (alegere == 1) {
        system("clear");
        meniu_cumparare();
    }
    if (alegere == 2) {
        system("clear");
        filtrare();
    }
}

void pret() {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int ok = 0;
    int pretul_cautat;
    fflush(stdin);
    printf("Introduceti pretul maxim:");
    scanf("%d",&pretul_cautat);
    printf("\n");
    char marca[50], modelul[50], seria[50], nrkm[50], anulf[50], caroseria[50];
    int pret;
    FILE *fp;
    fp = fopen("masini.txt", "r");
    fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
    if(pret <= pretul_cautat) {
        printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
        ok = 1;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        fscanf(fp,"%s %s %s %s %s %s %d",marca,modelul,seria,nrkm,anulf,caroseria,&pret);
        if(pret <= pretul_cautat) {
            if((read = getline(&line, &len, fp)) != -1) {
                printf("%s %s %s %s %s %s %d\n",marca,modelul,seria,nrkm,anulf,caroseria,pret);
            }
            ok = 1;
        }
    }
    if (ok == 0) {
        printf("Nu avem masini sub acest pret.\n");
    }
    printf("\n");
    fclose(fp);
    printf("1.Inapoi la meniul de cumparare\n");
    int alegere;
    scanf("%d", &alegere);
    if (alegere == 1) {
        system("clear");
        meniu_cumparare();
    }
    if (alegere != 1) {
        printf("Alegere invalida.");
    }
}

void stergere(){
    FILE * fPtr;
    FILE * fTemp;
    char path[100] = "masini.txt";
    
    char buffer[BUFFER_SIZE];
    char newline[8] = "Vandut\n";
    int line, count;

    printf("Ce masina vreti sa cumparati? ");
    scanf("%d", &line);

    fflush(stdin);

    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    if (fPtr == NULL || fTemp == NULL)
    {
        printf("\nNu s-a reusit deschiderea fisierului\n");
        exit(EXIT_SUCCESS);
    }
    int ok = 0;
    count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        count++;

        if (count == line){
            fputs(newline, fTemp);
            ok = 1;
        }
        else
            fputs(buffer, fTemp);
    }

    if (ok == 1) {
        printf("Felicitari ati cumparat masina.\n");
    }
    if (ok == 0) {
        printf("Nu avem avem aceasta masina.\n");
    }

    fclose(fPtr);
    fclose(fTemp);

    remove(path);

    rename("replace.tmp", path);
}

void cumpar() {
    printf("1. Vreau sa cumpar o masina.\n");
    printf("2. Inapoi.\n");
    int alegere;
    scanf("%d", &alegere);
    if (alegere == 1) {
        stergere();
    }
    if (alegere == 2) {
        system("clear");
        meniu_cumparare();
    }
    if (alegere != 1 && alegere != 2) {
        printf("Alegere invalida.\n");
        printf("\n");
        cumpar();
    }
}