#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class CUENTA{

   public:

    char NOM[20];
    int DNI;
    int COD;
    float DIN;

    CUENTA(char*,int,int,float);

    CUENTA * SIG;

    ~CUENTA();

};
CUENTA::CUENTA(char * S,int IDENTIFICACION,int CODIGO,float DINERO){

    strcpy(NOM,S);

    DNI = IDENTIFICACION;

    COD = CODIGO;

    DIN = DINERO;

}

CUENTA::~CUENTA(){

cout << "\n\n CUENTA DE "<<NOM<<" ELIMINADA\n";

getchar();

}

class LISTA{

    private :

   CUENTA * INICIO;

   void poner(CUENTA *);

    public :

   void ARMAR(char*,int,int,float);

   void BUSCAR(int,int);

    void BUSCAR_ELIM(int);

    void ELIMINAR(CUENTA *);

    void RETIRAR(int,int);

    LISTA();

    ~LISTA();

    void MIRAR();

};

LISTA::LISTA(){

    INICIO = NULL;

}
LISTA::~LISTA(){

getchar();

}
void LISTA::ARMAR(char * NOMBRE,int IDENTIFICACION,int CODIGO,float DINERO){

    CUENTA * C;

    C = new CUENTA(NOMBRE,IDENTIFICACION,CODIGO,DINERO);

    poner(C);
}
void LISTA::poner(CUENTA * CA){

    CUENTA * C;

    C = INICIO;

    CA->SIG = NULL;

    if(INICIO == NULL){

        INICIO = CA;
        return;

    }

    while(C->SIG){

      C = C->SIG;
    }
      C->SIG = CA;

}

void LISTA::BUSCAR(int CODIGO,int IDENTIFICADOR){

   int flag = 1;

    CUENTA * C;

    C = INICIO;

    while(C){

        if(C->COD == CODIGO && C->DNI == IDENTIFICADOR){

          flag = 0;

       cout<<"\nNOMBRE = "<<C->NOM<<"\tDINERO = "<<C->DIN;

        }

        C = C->SIG;

    }

    if(flag == 1){

        cout<<"\nNO EXISTE LA CUENTA";

    }

}
void LISTA::MIRAR(){

    CUENTA * C;

    C = INICIO;

    if(INICIO == NULL){

        cout<<"\nNO EXISTE NINGUNA CUENTA\n\n";

        return;

    }

        while(C){

            cout <<"\n\t"<<C->NOM<<"\t"<<C->DIN;

            C = C->SIG;

        }

    getchar();

}
void LISTA::BUSCAR_ELIM(int IDENTIFICADOR){

    int flag = 1 ;

    CUENTA * C;

    C = INICIO;

    if(INICIO == NULL){

        cout<<"\nNO EXISTE NINGUNA CUENTA";

        return;

    }

    while(C){

        if(IDENTIFICADOR == C->DNI){

            flag = 0;

            ELIMINAR(C);

            return;

        }

        C = C->SIG;
    }

    if(flag == 1){

        cout<<"\nNO EXISTE LA CUENTA";

    }

}
void LISTA :: ELIMINAR(CUENTA * CA){

    CUENTA * C;

    C = INICIO;

    if(INICIO == CA){

        INICIO = CA->SIG;

        delete CA;

        return;

    }
    while(C->SIG != CA && C){

    C = C->SIG;

    }
    if(C){

    C->SIG = CA->SIG;

    delete CA;

    }


}
void LISTA :: RETIRAR(int CODIGO,int IDENTIFICADOR){

    CUENTA * C;

    C = INICIO;

    float RETIRO;

    int FLAG = 1;

    while(C){

    if(CODIGO == C->COD && IDENTIFICADOR == C->DNI){

        printf("\nDINERO A RETIRAR : ");

        scanf("%f",&RETIRO);

        C->DIN = C->DIN - RETIRO;

        FLAG = 0;

    }

        C= C->SIG;

    }
    if(FLAG == 1){

        printf("\nCUENTA NO ENCONTRADA.....");
    }




}
int main(){

    int ELECCION;
    char NOM[20];
    int DNI;
    int COD;
    float DIN;
    int FLAG ;

        LISTA  I;

        printf("INGRESE 1 PARA INGRESAR\nINGRESE 2 PARA BUSCAR CUENTA\nINGRESE 3 PARA RETIRAR DINERO\nINGRESE 4 PARA ELIMINAR UNA CUENTA\nINGRESE 0 PARA SALIR\n");

        printf("\nINGRESE OPCION :");
        scanf("%d",&ELECCION);

     while(ELECCION!=0){

        if(ELECCION ==0 || ELECCION ==1 || ELECCION ==2 || ELECCION ==3 || ELECCION ==4){

               if(ELECCION == 1){

                fflush(stdin);

                 printf("\nINGRESE NOMBRE :");
                 gets(NOM);
                 printf("\nINGRESE DNI :");
                 scanf("%d",&DNI);
                 printf("\nINGRESE CODIGO :");
                 scanf("%d",&COD);
                 printf("\nINGRESE DINERO :");
                 scanf("%f",&DIN);

                fflush(stdin);

                I.ARMAR(NOM,DNI,COD,DIN);

               }

               if(ELECCION == 2){

                printf("\nINGRESE DNI :");
                scanf("%d",&DNI);
                printf("\nINGRESE CODIGO :");
                scanf("%d",&COD);

                    I.BUSCAR(COD,DNI);

                     printf("\n");

               }
                if(ELECCION == 3){

                    printf("INGRESE CODIGO : ");
                    scanf("%d",&COD);
                    printf("INGRESE DNI : ");
                    scanf("%d",&DNI);

                    I.RETIRAR(COD,DNI);



                }
               if(ELECCION == 4){

                printf("\nINGRESE DNI :");
                scanf("%d",&DNI);

                I.BUSCAR_ELIM(DNI);

                printf("\n");

            }
        }else{

            cout<<"\nINGRESE LOS NUMEROS MENCIONADOS EN LA PARTE SUPERIOR";

        }
                printf("\nINGRESE OPCION :");
                scanf("%d",&ELECCION);

        }

    I.MIRAR();

}
