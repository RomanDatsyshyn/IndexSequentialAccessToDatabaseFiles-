#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int year, price, id;
    char name[30], model[20], town[10], resolution[20], os[20], mileage[10], engine[20];
};

struct header {
    int id, filled, size;
};

struct index {
    int v, b;
};

void printDatabase();
void printIndex();
void restoreDatabase();
void addCars();
void addOwerflow();
void removeCars();
void removeOverflow();
void modifyCars();
void searchCars();
void addFilled();
void removeFilled();
void searchInt();
void searchString();


int main(){
remove("temp.txt");
system("cls");

int n;
printf("1 - Print Blocks\n2 - Print Index\n3 - Add Car\n4 - Remove Car\n5 - Modify Car\n6 - Search\n7 - Exit\nChoose 1..7: ");
scanf("%d", &n);
switch (n)
{
    case 1:
        system("cls");
        printDatabase();
        break;
    case 2:
        system("cls");
        printIndex();
    case 3:
        system("cls");
        addCars();
        break;
    case 4:
        system("cls");
        int id;
        printf("Enter ID: ");
        scanf("%d", &id);
        removeCars(id, 0);
        break;
    case 5:
        modifyCars();
        break;
    case 6:
        searchCars();
        system("cls");
        break;
    case 666:
        restoreDatabase();
    default:
        system("cls");
        exit(0);
}

   return(0);
}

void addCars(){
    FILE*data;
    FILE*temp;
    FILE*index;
    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "a");
    index = fopen("index.txt", "r");

    struct product Car;
    struct product Car1;
    struct header header;
    struct index i;

    char buff[100];
    int check = 0;

    printf("ID: ");
    scanf("%d", &Car1.id);
    printf("Name: ");
    scanf("%s", Car1.name);
    printf("model: ");
    scanf("%s", Car1.model);
    printf("Year: ");
    scanf("%d", &Car1.year);
    printf("town: ");
    scanf("%s", Car1.town);
    printf("mileage: "); 
    scanf("%s", Car1.mileage);
    printf("engine: ");
    scanf("%s", Car1.engine);
    printf("Resolution: ");
    scanf("%s", Car1.resolution);
    printf("OS: ");
    scanf("%s", Car1.os);
    printf("Price: ");
    scanf("%d", &Car1.price);

    int bid = 0;
    int z5 = 0;

    while (fgets(buff, sizeof(buff), index) != NULL){
        sscanf(buff, "%d%*c %d%*c", &i.v, &i.b);
        if(Car1.id < i.v){
            bid = i.b - 1;
            printf("\n%d\n", bid);
            z5++;
            break;
        }
    }

    if(z5 == 0){
        bid = 6;
        printf("\n%d\n", bid);
    }

    while (fgets(buff, sizeof(buff), data) != NULL){
        int z1 = 0;
        
        if(strlen(buff) < 12){
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
            if(header.id == bid){
                if(header.filled < header.size){
                    fprintf(temp, "%d:%d/%d\n", header.id, header.filled + 1, header.size);
                    z1++;
                    int s = 0;
                    int z = 0;
                    while(feof(data) == 0 && s < header.filled){
                        fgets(buff, 100, data);
                        sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                        if(Car1.id == Car.id){
                            system("cls");
                            printf("Car with ID %d already exists", Car1.id);
                            int z2 = 0;
                            printf("\n1 - Replace\n2 - Back to menu\n");
                            scanf("%d", &z2);
                            system("cls");
                            if(z2 == 1){
                            
                            fclose(data);
                            fclose(temp);
                            removeCars(Car1.id, 1);
                            
                            FILE*data;
                            FILE*temp;
                            data = fopen("data.txt", "r");
                            temp = fopen("temp.txt", "a");

                            while (fgets(buff, sizeof(buff), data) != NULL){
                                int z1 = 0;
                                if(strlen(buff) < 12){

                                    sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
                                    printf("ID:%d, Filled:%d, Size:%d\n", header.id, header.filled, header.size);

                                    if(header.filled < header.size){
                                        if(header.id == bid){
                                            fprintf(temp, "%d:%d/%d\n", header.id, header.filled + 1, header.size);
                                            z1++;
                                            int s = 0;
                                            int z = 0;
                                            while(feof(data) == 0 && s < header.filled){
                                                fgets(buff, 100, data);
                                                sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                                                if(Car1.id < Car.id && z == 0){
                                                    fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                                                    fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                                                    z++;
                                                }else{
                                                    fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                                                }

                                                printf("|% 3d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                                                s++;
                                            }
                                            if(z == 0){
                                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                                            }
                                        }

                                    }
                                }
                                if(z1 == 0){
                                    fprintf(temp, buff);
                                }
                            }
                        }else{
                            fclose(data);
                            fclose(temp);
                            main();
                        }

                        fclose(data);
                        fclose(temp);
                        remove("data.txt");
                        rename("temp.txt", "data.txt");
                        main();

                        }
                        if(Car1.id < Car.id && z == 0){
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                            z++;
                        }else{
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                        }

                        printf("|% 3d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                        s++;
                    }
                        if(z == 0){
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                        }
                }else{
                    check++;
                }
            }
            
        }
        if(z1 == 0){
        fprintf(temp, buff);
        }
    }

    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    if(check != 0){
        addOwerflow(Car1);
    }
    main();
}


void removeCars(int id, int ret){
    remove("temp.txt");
    FILE*data;
    FILE*temp;
    FILE*index;
    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "a");
    index = fopen("index.txt", "r");


    struct product Car;
    struct header header;
    struct index i;

    char buff[100];
    int r1 = 0;
    int r1filled = -1;
    int r1id = 0;
    int r2 = 0;
    int r2filled = 666;
    int r2id = 0;

    int bid = 0;
    int z5 = 0;

    while (fgets(buff, sizeof(buff), index) != NULL){
        sscanf(buff, "%d%*c %d%*c", &i.v, &i.b);
        if(id < i.v){
            bid = i.b - 1;
            printf("\n%d\n", bid);
            z5++;
            break;
        }
    }

    if(z5 == 0){
        bid = 6;
        printf("\n%d\n", bid);
    }
    fclose(index);
    
    while(feof(data) == 0){
        int z1 = 0;
        fgets(buff, 100, data);

        if(strlen(buff) < 12){
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
            if(header.id == bid){
                z1++;
                int s = 0;
                if((header.filled - 1) >= 0){
                    fprintf(temp, "%d:%d/%d\n", header.id, header.filled - 1, header.size);
                }else fprintf(temp, "%d:%d/%d\n", header.id, header.filled, header.size);
                while(feof(data) == 0 && s < header.filled){
                    fgets(buff, 100, data);
                    sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                    if(Car.id != id){
                        fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                        r1id = header.id;
                        r1filled = header.filled;
                        r1++;
                    }
                    s++;
                }
            }
        }

        if(z1 == 0){
        fprintf(temp, buff);
        }
    }

    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");

    if(r1 >= r1filled){
        addFilled(r1id);
        removeOverflow(id);
    }

    if(ret == 0){
        main();
    }
}

void printDatabase(){
    system("cls");
    FILE*data;
    data = fopen("data.txt", "r");
    struct product Car;
    struct header header;
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
    printf("|% 6s|% 21s|% 10s|% 6s|% 10s|% 8s|% 15s|% 12s|% 11s|% 4s|\n", "ID", "Name", "model", "Year", "town", "mileage", "engine", "Resolution", "OS", "Price");
    char buff[100];
    
    while(feof(data) == 0){
        int z1 = 0;
        fgets(buff, 100, data);

        if(strlen(buff) > 10){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
        }else{
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
            printf("+-----------------------------------------------------------------------------------------------------------------+\n");
            if(header.id != 99){
            if(header.id == 10){
                printf("|                                              |    Overflow - 1   |                                              |\n", header.id, header.filled, header.size);
            }else if(header.id == 20){
                printf("|                                              |    Overflow - 2   |                                              |\n", header.id, header.filled, header.size);
            }else if(header.id == 30){
                printf("|                                              |    Overflow - 3   |                                              |\n", header.id, header.filled, header.size);
            }else{
            printf("|                                              |  Block - %d (%d/%d)  |                                              |\n", header.id, header.filled, header.size);
            }
            printf("+-----------------------------------------------------------------------------------------------------------------+\n");
            
            }
        }
    }

    fclose(data);
    int z = 0;
    printf("\n1 - Reload\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) printDatabase();
    else main();
}

void restoreDatabase(){
    FILE*data;
    FILE*back;
    data = fopen("data.txt", "w");
    back = fopen("back.txt", "r");

    char ch;
    system("cls");
    printf("RESTORING [");
    while( ( ch = fgetc(back) ) != EOF ){
        fputc(ch, data);
        if(ch == '\n'){
            Sleep(40);
            printf("|");
        }
    }
    printf("]");
    
    fclose(data);
    fclose(back);
    main();
}



void searchCars(){
system("cls");

int k2 = 0;
printf("1 - By ID\n2 - By field\n");
scanf("%d", &k2);
if(k2 == 1){

FILE*data;
FILE*index;
data = fopen("data.txt", "r");
index = fopen("index.txt", "r");
int n,t = 0;
struct product Car;
struct header header;
struct index i;

char buff[100];

system("cls");
printf("Enter ID:");
scanf("%d", &n);
system("cls");

printf("+-----------------------------------------------------------------------------------------------------------------+\n");
printf("|% 6s|% 21s|% 10s|% 6s|% 10s|% 8s|% 15s|% 12s|% 11s|% 4s|\n", "ID", "Name", "model", "Year", "town", "mileage", "engine", "Resolution", "OS", "Price");
printf("+-----------------------------------------------------------------------------------------------------------------+\n");

    int bid = 0;
    int z5 = 0;

    while (fgets(buff, sizeof(buff), index) != NULL){
        sscanf(buff, "%d%*c %d%*c", &i.v, &i.b);
        if(n < i.v){
            bid = i.b - 1;
            z5++;
            break;
        }
    }

    if(z5 == 0){
        bid = 6;
    }
    fclose(index);

while(feof(data) == 0){
    int z1 = 0;
    fgets(buff, 100, data);

    if(strlen(buff) < 12){
        sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
        if(header.id == bid){
            printf("|                                              |  Block - %d (%d/%d)  |                                              |\n", header.id, header.filled, header.size);
            printf("+-----------------------------------------------------------------------------------------------------------------+\n");
        int s = 0;
            while(feof(data) == 0 && s < header.filled){
                fgets(buff, 100, data);
                sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                if(Car.id == n){
                    printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                    t++;
                }
            }
        }
    }
}
    fclose(data);
    if(t == 0){
        int z = 0;
        printf("|% 111s%d|\n", "There is no Cars with ID ", n);
        printf("+-----------------------------------------------------------------------------------------------------------------+\n");
        printf("\n1 - Try again\n2 - Back to menu\n");
        scanf("%d", &z);
        if(z == 1) searchCars();
        else main();
    }
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
    int z = 0;
    printf("\n1 - Continue searching\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) searchCars();
    else main();
}if(k2 == 2){
system("cls");
int z3;
printf("1 - model\n2 - Year\n3 - town\n4 - mileage\n5 - engine\n6 - Resolution\n7 - OS\n8 - Price\n\nChoose 1..8: ");
scanf("%d", &z3);
int sint;
char schar[30];
system("cls");


switch (z3)
{
    case 1:
        printf("Enter model: ");
        scanf("%s", schar);
        searchString(schar, 0);
        break;
    case 2:
        printf("Enter year: ");
        scanf("%d", &sint);
        searchInt(sint, 0);
        break;
    case 3:
        printf("Enter town: ");
        scanf("%s", schar);
        searchString(schar, 1);
        break;
    case 4:
        printf("Enter mileage: ");
        scanf("%s", schar);
        searchString(schar, 2);
        break;
    case 5:
        printf("Enter engine: ");
        scanf("%s", schar);
        searchString(schar, 3);
        break;
    case 6:
        printf("Enter resolution: ");
        scanf("%s", schar);
        searchString(schar, 4);
        break;
    case 7:
        printf("Enter OS: ");
        scanf("%s", schar);
        searchString(schar, 5);
        break;
    case 8:
        printf("Enter price: ");
        scanf("%d", &sint);
        searchInt(sint, 1);
        break;
    default:
        main();
}
int z4 = 0;
printf("\n1 - Try again\n2 - Back to menu\n");
scanf("%d", &z4);
if(z4 == 1) searchCars();
else main();

}


}


void searchInt(int f, int sw){
system("cls");

FILE*data;
data = fopen("data.txt", "r");
int n,t = 0;
struct product Car;
struct header header;
char buff[100];


printf("+-----------------------------------------------------------------------------------------------------------------+\n");
printf("|% 6s|% 21s|% 10s|% 6s|% 10s|% 8s|% 15s|% 12s|% 11s|% 4s|\n", "ID", "Name", "model", "Year", "town", "mileage", "engine", "Resolution", "OS", "Price");
printf("+-----------------------------------------------------------------------------------------------------------------+\n");


while(feof(data) == 0){
    int z1 = 0;
    fgets(buff, 100, data);

    if(strlen(buff) > 12){
        if(sw == 0){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            if(Car.year == f){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
        if(sw == 1){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            if(Car.price == f){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
    }
}
    fclose(data);
    if(t == 0){
        int z = 0;
        printf("|% 111s|\n", "There is no Cars");
        printf("+-----------------------------------------------------------------------------------------------------------------+\n");
        printf("\n1 - Try again\n2 - Back to menu\n");
        scanf("%d", &z);
        if(z == 1) searchCars();
        else main();
    }
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
    int z = 0;
    printf("\n1 - Continue searching\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) searchCars();
    else main();

}

void searchString(char f[30], int sw){
system("cls");

FILE*data;
data = fopen("data.txt", "r");
int n,t = 0;
struct product Car;
char *strcheck;
char buff[100];


printf("+-----------------------------------------------------------------------------------------------------------------+\n");
printf("|% 6s|% 21s|% 10s|% 6s|% 10s|% 8s|% 15s|% 12s|% 11s|% 4s|\n", "ID", "Name", "model", "Year", "town", "mileage", "engine", "Resolution", "OS", "Price");
printf("+-----------------------------------------------------------------------------------------------------------------+\n");


while(feof(data) == 0){
    int z1 = 0;
    fgets(buff, 100, data);

    if(strlen(buff) > 12){
        if(sw == 0){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            strcheck = strstr(Car.model, f);
            if(strcheck != 0){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
        if(sw == 1){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            strcheck = strstr(Car.town, f);
            if(strcheck != 0){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
        if(sw == 2){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            strcheck = strstr(Car.mileage, f);
            if(strcheck != 0){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
        if(sw == 3){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            strcheck = strstr(Car.engine, f);
            if(strcheck != 0){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
        if(sw == 4){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            strcheck = strstr(Car.resolution, f);
            if(strcheck != 0){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
        if(sw == 5){
            sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
            strcheck = strstr(Car.os, f);
            if(strcheck != 0){
                printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                t++;
            }
        }
    }
}
    fclose(data);
    if(t == 0){
        int z = 0;
        printf("|% 111s|\n", "There is no Cars");
        printf("+-----------------------------------------------------------------------------------------------------------------+\n");
        printf("\n1 - Try again\n2 - Back to menu\n");
        scanf("%d", &z);
        if(z == 1) searchCars();
        else main();
    }
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
    int z = 0;
    printf("\n1 - Continue searching\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) searchCars();
    else main();
}

void modifyCars(){
    system("cls");
    FILE*data;
    FILE*temp;
    FILE*index;
    data = fopen("data.txt", "r");
    index = fopen("index.txt", "r");
    struct product Car1;
    struct header header;
    struct index i;
    char buff[100];
    int n;
    int count = 0;

    printf("Enter Car ID: ");
    scanf("%d", &n);
    system ("cls");

    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
    printf("|% 6s|% 21s|% 10s|% 6s|% 10s|% 8s|% 15s|% 12s|% 11s|% 4s|\n", "ID", "Name", "model", "Year", "town", "mileage", "engine", "Resolution", "OS", "Price");
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");

    int bid = 0;
    int z5 = 0;

    while (fgets(buff, sizeof(buff), index) != NULL){
        sscanf(buff, "%d%*c %d%*c", &i.v, &i.b);
        if(n < i.v){
            bid = i.b - 1;
            z5++;
            break;
        }
    }

    if(z5 == 0){
        bid = 6;
    }
    fclose(index);


while(feof(data) == 0){
    int z1 = 0;
    fgets(buff, 100, data);

    if(strlen(buff) < 12){
        sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
        if(header.id == bid){
            if(header.id == 10){
                printf("|                                              |    Overflow - 1   |                                              |\n", header.id, header.filled, header.size);
            }else if(header.id == 20){
                printf("|                                              |    Overflow - 2   |                                              |\n", header.id, header.filled, header.size);
            }else if(header.id == 30){
                printf("|                                              |    Overflow - 3   |                                              |\n", header.id, header.filled, header.size);
            }else{
                printf("|                                              |  Block - %d (%d/%d)  |                                              |\n", header.id, header.filled, header.size);
            }
            printf("+-----------------------------------------------------------------------------------------------------------------+\n");
            int s = 0;
            while(feof(data) == 0 && s < header.filled){
                fgets(buff, 100, data);
                sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car1.id, Car1.name, Car1.model, &Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, &Car1.price);
                if(Car1.id == n){
                    printf("|% 6d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                    count++;
                    break;
                }
            }
        }
    }
}
    
    
    if(count == 0){
    printf("|% 1011s%d|\n", "There is no Cars with ID ", n);
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
    fclose(data);
    int z = 0;
    printf("\n1 - Try again\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) modifyCars();
    else main();
    }
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
    fclose(data);
    int z = 0;

    printf("\nModify:\n1 - ID         3 - model       5 - town        7 - engine        9 - OS     11 - Exit to menu\n2 - Name       4 - Year        6 - mileage        8 - Resolution    10 - Price\nChoose 1..11: ");
    scanf("%d", &z);
    system ("cls");
    switch(z){
        case 1:
        printf("Old ID: %d\n", Car1.id);
        printf("New ID: ");
        scanf("%d", &Car1.id);
        break;
        case 2:
        printf("Old Name: %s\n", Car1.name);
        printf("New Name: ");
        scanf("%s", Car1.name);
        break;
        case 3:
        printf("Old model: %s\n", Car1.model);
        printf("New model: ");
        scanf("%s", Car1.model);
        break;
        case 4:
        printf("Old Year: %d\n", Car1.year);
        printf("New Year: ");
        scanf("%d", &Car1.year);
        break;
        case 5:
        printf("Old town: %s\n", Car1.town);
        printf("New town: ");
        scanf("%s", Car1.town);
        break;
        case 6:
        printf("Old mileage: %s\n", Car1.mileage);
        printf("New mileage: ");
        scanf("%s", Car1.mileage);
        break;
        case 7:
        printf("Old engine: %s\n", Car1.engine);
        printf("New engine: ");
        scanf("%s", Car1.engine);
        break;
        case 8:
        printf("Old Resolution: %s\n", Car1.resolution);
        printf("New Resolution: ");
        scanf("%s", Car1.resolution);
        break;
        case 9:
        printf("Old OS: %s\n", Car1.os);
        printf("New OS: ");
        scanf("%s", Car1.os);
        break;
        case 10:
        printf("Old Price: %d\n", Car1.price);
        printf("New Price: ");
        scanf("%d", &Car1.price);
        break;
        case 11:
        main();
        default:
        main();
    }
    system("cls");

    struct product Car;
    int check = 0;

    removeCars(Car1.id, 1);

    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "a");

    while (fgets(buff, sizeof(buff), data) != NULL){
        int z1 = 0;
        if(strlen(buff) < 12){
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
            if(header.id == bid){
                
                    fprintf(temp, "%d:%d/%d\n", header.id, header.filled + 1, header.size);
                    z1++;
                    int s = 0;
                    int z = 0;
                    while(feof(data) == 0 && s < header.filled){
                        fgets(buff, 100, data);
                        sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                        if(Car1.id < Car.id && z == 0){
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                            z++;
                        }else{
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                        }
                    s++;
                    }
                if(z == 0){
                    fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                }
            }
        }
        if(z1 == 0){
            fprintf(temp, buff);
        }
    }
                
    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    main();
}



void addOwerflow(struct product Car1){
    FILE*data;
    FILE*temp;
    FILE*index;
    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "a");
    index = fopen("index.txt", "r");

    struct product Car;
    struct header header;
    struct index i;

    char buff[100];
    int zz = 0;

    int bid = 0;
    int z5 = 0;

    while (fgets(buff, sizeof(buff), index) != NULL){
        sscanf(buff, "%d%*c %d%*c", &i.v, &i.b);
        if(Car1.id < i.v){
            bid = i.b - 1;
            printf("\n%d\n", bid);
            z5++;
            break;
        }
    }

    if(z5 == 0){
        bid = 6;
        printf("\n%d\n", bid);
    }


    while (fgets(buff, sizeof(buff), data) != NULL){
        int z1 = 0;
        if(strlen(buff) < 12 && zz == 0){
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
            if(header.id == 10 || header.id == 20 || header.id == 30){
                if(header.filled < header.size){
                    fprintf(temp, "%d:%d/%d\n", header.id, header.filled + 1, header.size);
                    z1++;
                    int s = 0;
                    int z = 0;
                    while(feof(data) == 0 && s < header.filled){
                        fgets(buff, 100, data);
                        sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                        if(Car1.id == Car.id){
                            system("cls");
                            printf("Car with ID %d already exists", Car1.id);
                            int z2 = 0;
                            printf("\n1 - Replace\n2 - Back to menu\n");
                            scanf("%d", &z2);
                            system("cls");
                            if(z2 == 1){
                            
                            fclose(data);
                            fclose(temp);
                            removeCars(Car1.id, 1);
                            
                            FILE*data;
                            FILE*temp;
                            data = fopen("data.txt", "r");
                            temp = fopen("temp.txt", "a");

                            while (fgets(buff, sizeof(buff), data) != NULL){
                                int z1 = 0;
                                if(strlen(buff) < 12){

                                    sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
                                    printf("ID:%d, Filled:%d, Size:%d\n", header.id, header.filled, header.size);

                                    if(header.filled < header.size){
                                        if(header.id == bid){
                                            fprintf(temp, "%d:%d/%d\n", header.id, header.filled + 1, header.size);
                                            z1++;
                                            int s = 0;
                                            int z = 0;
                                            while(feof(data) == 0 && s < header.filled){
                                                fgets(buff, 100, data);
                                                sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                                                if(Car1.id < Car.id && z == 0){
                                                    fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                                                    fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                                                    z++;
                                                }else{
                                                    fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                                                }

                                                printf("|% 3d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                                                s++;
                                            }
                                            if(z == 0){
                                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                                            }
                                        }

                                    }
                                }
                                if(z1 == 0){
                                    fprintf(temp, buff);
                                }
                            }
                        }else{
                            fclose(data);
                            fclose(temp);
                            main();
                        }

                        fclose(data);
                        fclose(temp);
                        remove("data.txt");
                        rename("temp.txt", "data.txt");
                        main();

                        }
                        if(Car1.id < Car.id && z == 0){
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                            z++;
                            zz++;
                        }else{
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                        }

                        printf("|% 3d|% 21s|% 10s|% 6d|% 10s|% 8s|% 15s|% 12s|% 11s|% 5d|\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                        s++;
                    }
                        if(z == 0){
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car1.id, Car1.name, Car1.model, Car1.year, Car1.town, Car1.mileage, Car1.engine, Car1.resolution, Car1.os, Car1.price);
                            zz++;
                        }
                }else{
                    
                }

            }
        
        }
        if(z1 == 0){
        fprintf(temp, buff);
        }
    }

    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    main();
}

void addFilled(int id){
    FILE*data;
    FILE*temp;
    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "a");

    struct header header;
    char buff[100];

    while (fgets(buff, sizeof(buff), data) != NULL){
        int z1 = 0;
        if(strlen(buff) < 12){
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
            if(header.id == id){
                fprintf(temp, "%d:%d/%d\n", header.id, header.filled + 1, header.size);
                z1++;
            }
            
        }
        
    
        if(z1 == 0){
        fprintf(temp, buff);
        }
    }

    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");

}

void removeOverflow(int id){
    FILE*data;
    FILE*temp;
    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "a");

    struct product Car;
    struct header header;

    char buff[100];
    int r2 = 0;
    int r2filled = 999;
    int r2id = 0;
    
    while(feof(data) == 0){
        int z1 = 0;
        fgets(buff, 100, data);

        if(strlen(buff) < 12){
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
                if(header.id == 10 || header.id == 20 || header.id == 30){
                    fprintf(temp, "%d:%d/%d\n", header.id, header.filled, header.size);
                    z1++;
                    int s = 0;
                    
                    
                    if(header.filled != 0){
                    while(feof(data) == 0 && s < header.filled){
                        fgets(buff, 100, data);
                        sscanf(buff, "%d%*c %[^:]%*c %[^:]%*c %d%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %[^:]%*c %d%*c", &Car.id, Car.name, Car.model, &Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, &Car.price);
                        if(Car.id != id){
                            fprintf(temp, "%d:%s:%s:%d:%s:%s:%s:%s:%s:%d\n", Car.id, Car.name, Car.model, Car.year, Car.town, Car.mileage, Car.engine, Car.resolution, Car.os, Car.price);
                        }else{
                            r2++;
                            r2id = header.id;
                            printf("\n%d:%d\n", r2, r2filled);
                        } 
                        s++;
                    }
                    }

            }
        }

        if(z1 == 0){
        fprintf(temp, buff);
        }

    }

    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");

    if(r2 != 0){
    printf("r2id --- %d\n", r2id);
    removeFilled(r2id);
    }
}

void removeFilled(int id){
    remove("temp.txt");
    FILE*data;
    FILE*temp;
    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "a");

    struct product Car;
    struct header header;

    char buff[100];
    
    while(feof(data) == 0){
        int z1 = 0;
        fgets(buff, 100, data);

        if(strlen(buff) < 12){
            sscanf(buff, "%d%*c %d%*c %d%*c", &header.id, &header.filled, &header.size);
            if(header.id == id){
            z1++;
            fprintf(temp, "%d:%d/%d\n", header.id, header.filled - 1, header.size);
            }
        }

        if(z1 == 0){
        fprintf(temp, buff);
        }

    }

    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");

}

void printIndex(){

    system("cls");
    FILE*index;
    index = fopen("index.txt", "r");

    struct index i;
    char buff[100];

    printf("+----------------+\n");
    printf("|   INDEX FILE   |\n");
    printf("+-----+----------+\n");
    printf("|  ID |   BLOCK  |\n");
    printf("+-----+----------+\n");

    while (fgets(buff, sizeof(buff), index) != NULL){
        sscanf(buff, "%d%*c %d%*c", &i.v, &i.b);
        printf("|% 5d|% 10d|\n", i.v, i.b);
    }
    printf("+-----+----------+\n");

    fclose(index);
    int z = 0;
    printf("\n1 - Reload\n2 - Back to menu\n");
    scanf("%d", &z);
    if(z == 1) printIndex();
    else main();
}