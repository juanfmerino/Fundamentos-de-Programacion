#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXCAMP 7
#define MAXPLAZA 10
#define MAXDEPORTE 2


typedef struct{
    char Nombre_persona[40];
    char Dni[9];
    int edad;
    char sexo;
    }tRegListaPlazas;

typedef struct{
    char nombre_deporte[20];
    int semana;
    }tRegDeporte;

typedef struct{
    int edad_minima;
    int edad_maxima;
    }tRegEdad;

typedef struct{

    char clave[7];
    char lugar[40];
    int mes;
    int turno;
    tRegDeporte Deporte[MAXDEPORTE];
    tRegEdad Edad;
    tRegListaPlazas ListaPlazas[MAXPLAZA];
    int precio;
    int semana;
    int plazas;

    }tRegCampamento;








void MensajeBienvenida();
void MensajeDespedida();
int MenuPrincipal();
void MenuInformes(tRegCampamento tablaCampamento[],int ContCampamentos,int ContPartcipantes);
void AltaCampamento(tRegCampamento tablaCampameto[],int *ContCampamentos);
void BajaCampamento(tRegCampamento tablaCampamento[], int *ContCampamentos);
void ModCampamento(tRegCampamento tablaCampamento[], int ContCampamentos);
void RegParticipantes(tRegCampamento tablaCampamento[], int ContCampamentos,int *ContPartcipantes);
void ListadoCampamentos(tRegCampamento tablaCampamento[],int ContCampamentos);
void ConsultaParticipante(tRegCampamento tablaCampamento[],int ContPartcipantes);
void ConsultaCampamento(tRegCampamento tablaCampamento[],int ContCampamentos,int ContPartcipantes);
void ListadoDeporte(tRegCampamento tablaCampamento[],int ContCampamentos);
void ImporteTotal(tRegCampamento tablaCampamento[],int ContCampamentos);
void PromedioPlazas(tRegCampamento tablaCampamento[],int ContCampamentos);





int main()
{
    int opcion;
    int ContCampamentos=0;
    int ContPartcipantes=0;
    tRegCampamento tablaCampamento[MAXCAMP];


    setlocale(LC_CTYPE, "Spanish");

    MensajeBienvenida();

    do{
        opcion=MenuPrincipal();

        switch(opcion){
             case 1:AltaCampamento(tablaCampamento,&ContCampamentos);
                break;
             case 2:BajaCampamento(tablaCampamento,&ContCampamentos);
                break;
             case 3:ModCampamento(tablaCampamento,ContCampamentos);
                break;
             case 4:RegParticipantes(tablaCampamento,ContCampamentos,&ContPartcipantes);
                break;
             case 5:MenuInformes(tablaCampamento,ContCampamentos,ContPartcipantes);
                break;
             case 0:MensajeDespedida();
                break;


        }
    }while(opcion!=0);

}

void MensajeBienvenida(){
    printf("\n\nBienvenido a la aplicacion \n\n");

    system("pause");
    system("cls");
}

void MensajeDespedida(){
    system("cls");
    printf("Gracias por utilizar la aplicacion\n\n");
}


int MenuPrincipal(){

    int opcion;

    system("cls");
    printf("\tMENU PRINCIPAL\n\n");

    printf("1-Alta de Campamentos\n");
    printf("2-Baja de Campamentos\n");
    printf("3-Modificacion de Campamentos\n");
    printf("4-Registro de Participantes\n");
    printf("5-Informes\n");
    printf("0-Salir\n\n");


    fflush(stdin);
    printf("Elija opcion:");
    scanf("%i",&opcion);

    printf("\n");
    system("pause");
    system("cls");

    return opcion;
}

void MenuInformes(tRegCampamento tablaCampamento[],int ContCampamentos,int ContPartcipantes){

    int opcion;

    printf("\tMENU DE INFORMES\n\n");

    printf("1-Listado General de Campamentos\n");
    printf("2-Consulta de los datos de un Campamento\n");
    printf("3-Consulta de los datos de un Participamte\n");
    printf("4-Listado por Deporte\n");
    printf("5-Importes Totales\n");
    printf("6-Promedio de Plazas\n");
    printf("0-Volver al Menu Principal\n");

    fflush(stdin);
    printf("Elija opcion:");
    scanf("\n%i",&opcion);

    do{
        switch(opcion){
                 case 1:ListadoCampamentos(tablaCampamento,ContCampamentos);
                    break;
                 case 2:ConsultaCampamento(tablaCampamento,ContCampamentos,ContPartcipantes);
                    break;
                 case 3:ConsultaParticipante(tablaCampamento,ContPartcipantes);
                    break;
                 case 4:ListadoDeporte(tablaCampamento,ContCampamentos);
                    break;
                 case 5:ImporteTotal(tablaCampamento,ContCampamentos);
                    break;
                 case 6:PromedioPlazas(tablaCampamento,ContCampamentos);
                    break;
                 case 0:
                        system("pause");
                        system("cls");
                    break;
            }
        }while(opcion!=0);

    printf("\n");
    system("pause");
    system("cls");
}

void AltaCampamento(tRegCampamento tablaCampamento[],int *ContCampamentos){

    char claveabuscar[7];
    int contador;
    int i;
    char respuesta;

    i=0;

if(*ContCampamentos<MAXCAMP){

    do{
        printf("\tBienvenido a el Alta de Campamentos\n\n");
        printf("\nEl numero actual de campamentos es %i\n\n",*ContCampamentos);
        do{
                do{
                    printf("Introduzca la clave:\n\n");
                    fflush(stdin);
                    gets(claveabuscar);

                    if(strlen(claveabuscar)!=7){
                            printf("\n\nError.Formato de la clave incorrecto, Escriba otro\n\n");

                        }
                }while((strlen(claveabuscar)!=7));
                contador=-1;
                strupr(claveabuscar);

                do{
                    contador++;
                    if(strcmp(tablaCampamento[contador].clave,claveabuscar)==0){
                        printf("Codigo repetido. Introduzca otro");
                    }
                }while((strcmp(tablaCampamento[contador].clave,claveabuscar)!=0)&&(contador< *ContCampamentos));
        }while(strcmp(tablaCampamento[contador].clave,claveabuscar)==0);


        strcpy(tablaCampamento[i].clave,claveabuscar);
        printf("Introduce el lugar:");
        fflush(stdin);
        gets(tablaCampamento[i].lugar);

        do{
        printf("\nIntroduce el mes:");
        fflush(stdin);
        scanf("%i",&tablaCampamento[i].mes);
        }while((tablaCampamento[i].mes<5)||(tablaCampamento[i].mes>10));

        do{
        printf("\nIntroduce el turno:");
        fflush(stdin);
        scanf("%i",&tablaCampamento[i].turno);
        }while((tablaCampamento[i].turno!=1)&&(tablaCampamento[i].turno!=2));

        do{
        printf("\nIntroduce las plazas:");
        fflush(stdin);
        scanf("%i",&tablaCampamento[i].plazas);
        }while((tablaCampamento[i].plazas<5)||(tablaCampamento[i].plazas>10));

        do{
        do{
        printf("\nIntroduce la edad minima:");
        fflush(stdin);
        scanf("%i",&tablaCampamento[i].Edad.edad_minima);
        }while((tablaCampamento[i].Edad.edad_minima<14)||(tablaCampamento[i].Edad.edad_minima>18));

        do{
        printf("\nIntroduce la edad maxima:");
        fflush(stdin);
        scanf("%i",&tablaCampamento[i].Edad.edad_maxima);
        }while((tablaCampamento[i].Edad.edad_maxima>18)||(tablaCampamento[i].Edad.edad_maxima<14));

        if(tablaCampamento[i].Edad.edad_maxima>tablaCampamento[i].Edad.edad_minima);
        else{
            printf("La edad minima no puede ser mayor que la edad maxima.Introduza otra\n\n");
        }
        }while(tablaCampamento[i].Edad.edad_maxima<=tablaCampamento[i].Edad.edad_minima);

        printf("\nIntroduce el precio:");
        fflush(stdin);
        scanf("%i",&tablaCampamento[i].precio);

        printf("\nIntroduce el nombre del deporte:");
        fflush(stdin);
        gets(tablaCampamento[i].Deporte[i].nombre_deporte);

        printf("\n\nLa clave del campamento es: %s\n",tablaCampamento[i].clave);
        printf("El lugar donde se raliza el campamento es: %s\n",tablaCampamento[i].lugar);
        printf("El mes del campamento es: %i\n",tablaCampamento[i].mes);
        printf("El turno de este campamento es: %i\n",tablaCampamento[i].turno);
        printf("Las plazas existentes del campamento es: %i\n",tablaCampamento[i].plazas);
        printf("La edad minima del campamento es: %i\n",tablaCampamento[i].Edad.edad_minima);
        printf("La edad maxima del campamento es: %i\n",tablaCampamento[i].Edad.edad_maxima);
        printf("El precio del campamento es: %i\n",tablaCampamento[i].precio);

        if(tablaCampamento[i].turno==1){
            printf("El deporte que se ralizara en el campamento es: %s y la semana es 1 y 2\n",tablaCampamento[i].Deporte[i].nombre_deporte);
        }else{
            printf("El deporte que se ralizara en el campamento es: %s y la semana es 3 y 4\n",tablaCampamento[i].Deporte[i].nombre_deporte);
        }

        i++;

        printf("\n\n\t¿Datos correctos?(S/N)");
        fflush(stdin);
        scanf("%c",&respuesta);
        respuesta = toupper(respuesta);

        if(respuesta=='S'){
        *ContCampamentos=*ContCampamentos+1;
        }else{
            printf("Proceso de alta abortado");
            system("pause");
            system("cls");
        }

    }while((respuesta!='S')&&(*ContCampamentos<MAXCAMP));
}else{
    printf("No se pueden introducir mas campamentos\n");
    system("pause");
    system("cls");
}

    printf("la posicion del campamento es %i\n",i);
    printf("\nEl numero actual de campamentos es %i\n\n",*ContCampamentos);

    printf("\n");
    system("pause");
    system("cls");

}

void BajaCampamento(tRegCampamento tablaCampamento[], int *ContCampamentos){

    char claveaborrar[7];
    char respuesta;
    int contador;
    int i;

    i=0;

    do{
        printf("\tBienvenido a la Baja de Campamentos\n\n");
        printf("\nEl numero actual de campamentos es %i\n\n",*ContCampamentos);

        do{
            do{
                printf("Introduce la clave del campamento:");
                fflush(stdin);
                gets(claveaborrar);
                strupr(claveaborrar);

                if(strlen(claveaborrar)!=7){
                        printf("\n\nError.Formato de la clave incorrecto, Escriba otro\n\n");
                    }
            }while((strlen(claveaborrar)!=7));

            contador=-1;
        do{
            contador++;

            if(strcmp(tablaCampamento[contador].clave,claveaborrar)==0){

                printf("La clave del campamento es %s",tablaCampamento[i].clave);
                printf("El lugar donde se realiza es %s\n",tablaCampamento[i].lugar);
                printf("Mes cuando se realiza %i\n",tablaCampamento[i].mes);
                printf("Turno que tiene el campamento %i\n",tablaCampamento[i].turno);
                printf("Las edades estan comprendidas entre%i-%i\n",tablaCampamento[i].Edad.edad_minima,tablaCampamento[i].Edad.edad_maxima);
                printf("Las plazas que hay %i\n",tablaCampamento[i].plazas);
                printf("El precio del campamento es %i\n",tablaCampamento[i].precio);
                printf("La lista de reservas es %s\n",tablaCampamento[i].ListaPlazas[i].Nombre_persona);
                printf("Los deportes que se realizan %s y la semana %i\n",tablaCampamento[i].Deporte[i].nombre_deporte,tablaCampamento[i].Deporte[i].semana);

            }else(printf("La calve del campamento no existe. Intetalo de nuevo\n\n"));

        }while((strcmp(tablaCampamento[contador].clave,claveaborrar)!=0)&&(contador<*ContCampamentos));
        }while((strcmp(tablaCampamento[contador].clave,claveaborrar)!=0));

        if(strcmp(tablaCampamento[i].clave,claveaborrar)==0){
            printf("\nEliminando Campamento... \n\n");
        }else{
            printf("Imposible eliminar el campamento. Ya hay plazas asignadas");
        }

        *ContCampamentos=*ContCampamentos-1;

        printf("\n\t¿Desea continuar?(S/N)");
        scanf("%c", &respuesta);
        respuesta=toupper(respuesta);


    }while(respuesta!='S');



    printf("\n");
    system("pause");
    system("cls");
}

void ModCampamento(tRegCampamento tablaCampamento[], int ContCampamentos){

    char claveabuscar[7];
    int contador;
    int opcion;




    do{
        printf("\tBienvenido a la Modificacion de Datos\n\n");
        printf("\nEl numero actual de campamentos es %i\n\n",ContCampamentos);

        do{
            printf("Introduzca la clave:\n\n");
            fflush(stdin);
            gets(claveabuscar);

            if(strlen(claveabuscar)!=7){
                printf("Error.Formato de la clave incorrecto, Escriba otro\n\n");
                }

        }while(strlen(claveabuscar)!=7);


        strupr(claveabuscar);

        do{
           contador=-1;
           contador++;

            if(strcmp(tablaCampamento[contador].clave,claveabuscar)!=0){
                printf("Codigo introduzido no existe. Introduzca otro");
                system("pause");
                system("cls");
           }


       }while((strcmp(tablaCampamento[contador].clave,claveabuscar)!=0)&&(contador< ContCampamentos));
    }while(strcmp(tablaCampamento[contador].clave,claveabuscar)!=0);

    system("pause");
    system("cls");

    printf("Bienvenido a la Modificacion de Datos\n\n");
    do{
        printf("1-Modificar lugar:\n");
        printf("2-Modificar mes:\n");
        printf("3-Modificar turno:\n");
        printf("4-Modificar plazas:\n");
        printf("5-Modificar edad minima:\n");
        printf("6-Modificar edad maxima:\n");
        printf("7-Modificar precio:\n");
        printf("8-Modificar deporte:\n");
        printf("0-Salir\n\n");

        printf("Elija la opcion:");
        scanf("%i",&opcion);
        system("cls");

        switch(opcion){
        case 1: printf("Introduce el nuevo nombre del lugar:");
                fflush(stdin);
                gets(tablaCampamento[contador].lugar);
                system("pause");
                system("cls");

            break;
        case 2: do{
                printf("\nIntroduce el nuevo mes:");
                fflush(stdin);
                scanf("%i",&tablaCampamento[contador].mes);
                }while((tablaCampamento[contador].mes<5)||(tablaCampamento[contador].mes>10));
                system("pause");
                system("cls");

            break;
        case 3: do{
                printf("\nIntroduce el nuevo turno");
                fflush(stdin);
                scanf("%i",&tablaCampamento[contador].turno);
                }while((tablaCampamento[contador].turno!=1)&&(tablaCampamento[contador].turno!=2));
                system("pause");
                system("cls");

            break;
        case 4: do{
                printf("\nIntroduce las nuevas plazas");
                fflush(stdin);
                scanf("%i",&tablaCampamento[contador].plazas);
                }while((tablaCampamento[contador].plazas<5)||(tablaCampamento[contador].plazas>10));
                system("pause");
                system("cls");

            break;
        case 5: do{
                printf("\nIntroduce la nueva edad minima");
                fflush(stdin);
                scanf("%i",&tablaCampamento[contador].Edad.edad_minima);
                }while((tablaCampamento[contador].Edad.edad_minima<14)||(tablaCampamento[contador].Edad.edad_minima>18));
                system("pause");
                system("cls");

            break;
        case 6: do{
                printf("\nIntroduce la nueva edad maxima");
                fflush(stdin);
                scanf("%i",&tablaCampamento[contador].Edad.edad_maxima);
                }while((tablaCampamento[contador].Edad.edad_maxima>18)||(tablaCampamento[contador].Edad.edad_maxima<14));
                system("pause");
                system("cls");

            break;
        case 7: printf("\nIntroduce el nuevo precio");
                fflush(stdin);
                scanf("%i",&tablaCampamento[contador].precio);
                system("pause");
                system("cls");

            break;
        case 8: printf("\nIntroduce el deporte:");
                fflush(stdin);
                gets(tablaCampamento[contador].Deporte[contador].nombre_deporte);
                system("pause");
                system("cls");

            break;
        case 0: printf("Estas saliendo de la Modificacion de Datos\n\n");
                system("pause");
                system("cls");
            break;
        }

    }while(opcion!=0);

        printf("La clave del campamento es: %s\n",tablaCampamento[contador].clave);
        printf("El nuevo lugar donde se raliza el campamento es: %s\n",tablaCampamento[contador].lugar);
        printf("El nuevo mes del campamento es: %i\n",tablaCampamento[contador].mes);
        printf("El nuevo turno de este campamento es: %i\n",tablaCampamento[contador].turno);
        printf("Las nuevas plazas existentes del campamento es: %i\n",tablaCampamento[contador].plazas);
        printf("La nueva edad minima del campamento es: %i\n",tablaCampamento[contador].Edad.edad_minima);
        printf("La nueva edad maxima del campamento es: %i\n",tablaCampamento[contador].Edad.edad_maxima);
        printf("El nuevo precio del campamento es: %i\n",tablaCampamento[contador].precio);
        if(tablaCampamento[contador].turno==1){
            printf("El deporte que se ralizara en el campamento es: %s y la semana es 1 y 2\n",tablaCampamento[contador].Deporte[contador].nombre_deporte);
        }else{
            printf("El deporte que se ralizara en el campamento es: %s y la semana es 3 y 4\n",tablaCampamento[contador].Deporte[contador].nombre_deporte);
        }

    printf("\n");
    system("pause");
    system("cls");
}

void RegParticipantes(tRegCampamento tablaCampamento[], int ContCampamentos,int *ContPartcipantes){

    char claveabuscar[7];
    int contador;
    int i;

    i=0;
        printf("\tBienvenido a el Registrro de Participantes\n\n");
        printf("\nEl numero actual de campamentos es %i\n\n",ContCampamentos);
        printf("\nEl numero actual de participantes es %i\n\n",*ContPartcipantes);
        do{
                do{
                    printf("Introduzca la clave:\n\n");
                    fflush(stdin);
                    gets(claveabuscar);

                    if(strlen(claveabuscar)!=7){
                            printf("\n\nError.Formato de la clave incorrecto, Escriba otro\n\n");
                        }

                }while(strlen(claveabuscar)!=7);

                contador=-1;
                strupr(claveabuscar);

                do{
                    contador++;
                    if(strcmp(tablaCampamento[contador].clave,claveabuscar)!=0){
                        printf("Codigo no encontrado. Introduzca otro");
                    }

                }while((strcmp(tablaCampamento[contador].clave,claveabuscar)!=0)&&(contador< ContCampamentos));
        }while(strcmp(tablaCampamento[contador].clave,claveabuscar)!=0);

        system("cls");

        printf("\tHas entrado al Registro de Participantes\n\n");
        printf("Introduce el nombre del Paricipante:  ");
        fflush(stdin);
        gets(tablaCampamento[i].ListaPlazas[i].Nombre_persona);

        do{

        printf("\n\nIntroduce el DNI del Participante:  ");
        fflush(stdin);
        gets(tablaCampamento[i].ListaPlazas[i].Dni);

        if(strlen(tablaCampamento[i].ListaPlazas[i].Dni)!=9){
                            printf("\n\nError.Formato del DNI incorrecto, Escriba otro\n\n");
        }
        }while(strlen(tablaCampamento[i].ListaPlazas[i].Dni)!=9);

        do{
        printf("\n\nIntroduce la edad del Participante:  ");
        fflush(stdin);
        scanf("%i",&tablaCampamento[i].ListaPlazas[i].edad);
        }while((tablaCampamento[i].Edad.edad_maxima<=tablaCampamento[i].ListaPlazas[i].edad)&&(tablaCampamento[i].Edad.edad_minima>=tablaCampamento[i].ListaPlazas[i].edad));

        do{
        printf("\n\nIntroduce el sexo del Participante:  ");
        fflush(stdin);
        scanf("%c",&tablaCampamento[i].ListaPlazas[i].sexo);

        }while((tablaCampamento[i].ListaPlazas[i].sexo!='v')&&(tablaCampamento[i].ListaPlazas[i].sexo!='h'));

        *ContPartcipantes=*ContPartcipantes+1;




    printf("\n");
    system("pause");
    system("cls");
}

void ListadoCampamentos(tRegCampamento tablaCampamento[],int ContCampamentos){
    system("cls");

    int i;
    i=0;

    printf("\tBienvenido a el Listado de todos los Campamentos\n\n");
    printf("\nEl numero actual de campamentos es %i\n\n",ContCampamentos);

    printf("Clave\t");
    printf("Lugar\t\t");
    printf("Mes\t");
    printf("Semanas\t");
    printf("Plazas\t");
    printf("Rango Edad\t");
    printf("Precio\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for(i=0;i<=ContCampamentos;i++){
        printf("%s\t",tablaCampamento[i].clave);
        printf("%s\t\t",tablaCampamento[i].lugar);
        printf("%i\t",tablaCampamento[i].mes);

        if(tablaCampamento[i].turno==1){
            printf("1 y 2\t");
        }else{
            printf("3 y 4\t");
        }

        printf("%i\t",tablaCampamento[i].plazas);
        printf("%i-%i\t",tablaCampamento[i].Edad.edad_minima,tablaCampamento[i].Edad.edad_maxima);
        printf("\t%i\n",tablaCampamento[i].precio);
    }

    system("pause");
    system("cls");
}

void ConsultaCampamento(tRegCampamento tablaCampamento[],int ContCampamentos,int ContPartcipantes){

    char claveabuscar[8];
    int contador;
    char respuesta;
    int i;


    system("cls");

    do{
            printf("\tHas entrado a la Consulta de un Campamentos\n\n");
            printf("\nEl numero actual de campamentos es %i\n\n",ContCampamentos);
            printf("\nEl numero actual de participantes es %i\n\n",ContPartcipantes);
            do{
                    do{
                        printf("Introduzca la clave:\n\n");
                        fflush(stdin);
                        gets(claveabuscar);

                        if(strlen(claveabuscar)!=7){
                                printf("\n\nError.Formato de la clave incorrecto, Escriba otro\n\n");
                            }

                    }while(strlen(claveabuscar)!=7);

                    strupr(claveabuscar);


                    do{
                        contador=-1;
                        if(strcmp(tablaCampamento[contador].clave,claveabuscar)!=0){
                        }
                        contador++;
                    }while((strcmp(tablaCampamento[contador].clave,claveabuscar)!=0)&&(contador< ContCampamentos));
            }while(strcmp(tablaCampamento[contador].clave,claveabuscar)!=0);

            system("pause");
            system("cls");

            printf("\tCampamento encontrado\n\n");

            printf("\n\nLa clave del campamento es: %s\n",tablaCampamento[contador].clave);
            printf("El lugar donde se raliza el campamento es: %s\n",tablaCampamento[contador].lugar);
            printf("El mes del campamento es: %i\n",tablaCampamento[contador].mes);
            printf("El turno de este campamento es: %i\n",tablaCampamento[contador].turno);
            printf("Las plazas existentes del campamento es: %i\n",tablaCampamento[contador].plazas);
            printf("La edad minima del campamento es: %i\n",tablaCampamento[contador].Edad.edad_minima);
            printf("La edad maxima del campamento es: %i\n",tablaCampamento[contador].Edad.edad_maxima);
            printf("El precio del campamento es: %i\n",tablaCampamento[contador].precio);
            if(tablaCampamento[contador].turno==1){
                printf("El deporte que se ralizara en el campamento es: %s y la semana es 1 y 2\n",tablaCampamento[contador].Deporte[contador].nombre_deporte);
            }else{
                printf("El deporte que se ralizara en el campamento es: %s y la semana es 3 y 4\n",tablaCampamento[contador].Deporte[contador].nombre_deporte);
                }

            printf("Los DNI del los participantes son:\n");
            for(i=0;i<ContPartcipantes;i++){
                printf("%s\n",tablaCampamento[i].ListaPlazas[i].Dni);
            }


        printf("\n\n\t¿Quieres consultar otro campamento?(S/N)");
        fflush(stdin);
        scanf("%c",&respuesta);

        }while(respuesta=='s');


    printf("\n");
    system("pause");
    system("cls");
}

void ConsultaParticipante(tRegCampamento tablaCampamento[],int ContPartcipantes){
    system("cls");

    int contador;
    int i;
    char dniabuscar[9];

    contador=-1;
    i=-1;

    do{
        printf("\tBienvenido a la Consulta de Particpantes\n\n");
        printf("\nEl numero actual de participantes es %i\n\n",ContPartcipantes);
        do{
            printf("\n\nIntroduce el DNI del participante:");
            fflush(stdin);
            gets(dniabuscar);

           if(strlen(dniabuscar)!=9){
            printf("Error en el formato del DNI\n");
           }
          }while(strlen(dniabuscar)!=9);

         do{
            contador++;

            if(strcmp(tablaCampamento[contador].ListaPlazas[contador].Dni,dniabuscar)==0){
               i++;
               printf("\n\nEL participante con DNI %s esta incrito en el campamento %s en la posicon %i \n\n",tablaCampamento[i].ListaPlazas[i].Dni,tablaCampamento[i].clave,contador);
            }else{
                printf("\n\nERROR:este Dni no esta inscrito en ningun campamento\n\n");
                }

          }while(strcmp(tablaCampamento[contador].ListaPlazas[contador].Dni,dniabuscar)!=0);
    }while(strcmp(tablaCampamento[contador].ListaPlazas[contador].Dni,dniabuscar)!=0);

    printf("El bucle ha terminado");

    printf("\n");
    system("pause");
    system("cls");
}

void ListadoDeporte(tRegCampamento tablaCampamento[],int ContCampamentos){
    system("cls");

    int i;
    int contador;
    char nombreDeporte[20];




    do{
         printf("\nEl numero actual de campamentos es %i\n\n",ContCampamentos);
         do{
             printf("\t\tListado de Deportes\n\n");
             printf("Introduce el nombre del deporte:");
             fflush(stdin);
             gets(nombreDeporte);
             do{
                contador=-1;
                contador++;
                 if(strcmp(nombreDeporte,tablaCampamento[contador].Deporte[contador].nombre_deporte)==0){

                     printf("Campamentos:");
                     printf("\t\tCalve");
                     printf("\t\tLugar");
                     printf("\t\tMes");
                     printf("\t\tSemanas\n");
                     printf("\t\t---------------------------------------------------------------------\n");



                     for(i=0;i<ContCampamentos;i++){

                        printf("\t\t%s",tablaCampamento[i].clave);
                        printf("\t\t%s",tablaCampamento[i].lugar);
                        printf("\t\t%i",tablaCampamento[i].mes);
                        if(tablaCampamento[i].turno==1){
                            printf("\t\t1 y 2\n");
                        }else{
                            printf("\t\t3 y 4\n");
                            }
                     }

                 }else{
                    printf("\n\nEl deporte que has elegido no se practica\n\n");
                    system("cls");
                 }
             }while((i<ContCampamentos)&&(strcmp(nombreDeporte,tablaCampamento[contador].Deporte[contador].nombre_deporte)!=0));
         }while((i<ContCampamentos)&&(strcmp(nombreDeporte,tablaCampamento[contador].Deporte[contador].nombre_deporte)!=0));
    }while(strcmp(nombreDeporte,tablaCampamento[contador].Deporte[contador].nombre_deporte)!=0);


    printf("\n");
    system("pause");
    system("cls");
}

void ImporteTotal(tRegCampamento tablaCampamento[],int ContCampamentos){
    system("cls");

    int i;
    int total,totalcampamento;

    total=0;
    i=0;

    printf("\nEl numero actual de campamentos es %i\n\n",ContCampamentos);

    printf("\tIMPORTES TOTALES\n\n");

    printf("Clave del Campamento\t");
    printf("Nº Plazas\t");
    printf("Importe/Plazas\t");
    printf("Importe total del Campamento\n");



    do{

        printf("%s\t\t",tablaCampamento[i].clave);
        printf("%i\t\t",tablaCampamento[i].plazas);
        printf("%i\t\t\t",tablaCampamento[i].precio);

        totalcampamento=tablaCampamento[i].precio*tablaCampamento[i].plazas;
        printf("%i\n\n\n",totalcampamento);
        i++;

    }while(i<ContCampamentos);


    for(i=0;i<ContCampamentos;i++){
    total=total+((tablaCampamento[i].precio)*(tablaCampamento[i].plazas));
    }

    printf("\tImporte Total por todos los Campamentos:%i euros\n\n",total);


    printf("\n");
    system("pause");
    system("cls");
}

void PromedioPlazas(tRegCampamento tablaCampamento[],int ContCampamentos){
    system("cls");

    int i;
    int media;
    int plazas;
    plazas=0;

    printf("\nEl numero actual de campamentos es %i\n\n",ContCampamentos);

    for(i=0;i<ContCampamentos;i++){
        plazas=plazas+tablaCampamento[i].plazas;
        media=plazas/ ContCampamentos;
    }

    printf("\n\nEl numero medio de participantes por Campamento es: %i",media);



    printf("\n");
    system("pause");
    system("cls");
}
