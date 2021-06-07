/*
 * nomPrograma: Cursos v2
 * descripcion:
 *
 *
 * autor: Chávez Farro, Luis André
 *        Espinola Ravello, Annie Katerine
 *        Reyes De la Cruz, Andrés Eduardo
 *        Silva Barra, Ernesto Franco
 *        Tocto Mallqui, Alexis
 * fecha:
 */

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_C 20

using namespace std;
using namespace std;

 struct CURSOS{
   char codC[10];
   char nomC[40];
   int creditC;
   char sist_calif[2];
};

int  MenuPRINCIPAL();
void encabezado1();
void MenuEditar();
void raya1();
void raya2();

void MostrarRegistro(FILE *I, CURSOS RegistroC);
void BuscarRegistro(FILE *I, CURSOS RegistroC);
void EliminarRegistro(FILE *I, FILE *J,struct CURSOS RegistroC);
void EditarRegistro(FILE *I ,FILE *J,struct CURSOS RegistroC);


int main()
{
   int op;
   FILE *I;
   FILE *J;
   CURSOS RegistroC;
   MenuPRINCIPAL();
   do{
      do{
         cout<<"Ingrese opcion [ ]"<<"\b\b";
         cin>>op;
      }while(op<0 || op>8);

      switch(op){
         case 1 : MostrarRegistro(I,RegistroC);
                  break;
         case 2 : BuscarRegistro(I,RegistroC);
                  break;
         case 3 : EliminarRegistro(I,J,RegistroC);
                  break;
         case 4 : EditarRegistro(I,J,RegistroC);
                  break;
      }
      system("cls");
      MenuPRINCIPAL();
   }while(op != 0);
   system("pause");
   return(0);
}

int  MenuPRINCIPAL()
{
   system("cls");
   cout << "\n\r A R C H I V O    D E    C U R S O S";
   cout << "\n\r  Proyecto Final Algoritmica I ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] LECTURA DEL ARCHIVO CURSOS";
   cout << "\n\r [2] BUSQUEDA POR CODIGO";
   cout << "\n\r [3] ELIMINAR UN CURSO";
   cout << "\n\r [4] EDITAR UN CURSO";
   printf("\n");
}

void encabezado1(){
   system("cls");
   char title[]="\tREPORTE DE CURSOS";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="CURSO";
   char credito[]="CREDITO";
   char sist_calif[]="SIST. CALIF.";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-6s\t%-12s%-32s%-5s %15s\n",num,cod,nom,credito,sist_calif);
   raya1();
}

void MenuEditar(){
   cout << "\n\r A R C H I V O    D E    C U R S O S";
   cout << "\n\r  OPCIONES DE EDICION ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] EDITAR CODIGO DEL CURSO";
   cout << "\n\r [2] EDITAR NOMBRE DEL CURSO";
   cout << "\n\r [3] EDITAR CREDITO DEL CURSO";
   cout << "\n\r [4] EDITAR SISTEMA DE CALIFICACION";
   printf("\n");
}

void raya1(){
   printf("--------------------------------------------------------------------------\n");
}

void raya2(){
   printf("==========================================================================\n");
}


void MostrarRegistro(FILE *I, CURSOS RegistroC){
   int i=0;
   I=fopen("Cursos.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   fread(&RegistroC,sizeof(RegistroC),1,I);

   encabezado1();

   while(!feof(I)){

      printf("%3d\t%s\t%-30s\t\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
      fread(&RegistroC,sizeof(RegistroC),1,I);

      i++;
   }

   fclose(I);
   raya1();
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void BuscarRegistro(FILE *I,CURSOS RegistroC){

   system("cls");
   char Codigo[10];
   int i=0;
   printf("\n\rIngrese el codigo del curso a buscar ---> ");
   fflush(stdin);
   gets(Codigo);

   encabezado1();

   I=fopen("Cursos.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }
   while(!feof(I)){
      if(stricmp(RegistroC.codC,Codigo)==0){
         printf("%3d\t%s\t%-30s\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
      }
      i++;
      fread(&RegistroC,sizeof(RegistroC),1,I);
   }

   fclose(I);
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void EliminarRegistro(FILE *I ,FILE *J,struct CURSOS RegistroC){

   system("cls");
   int i=0,Hallado=0,remo,rena;
   char Codigo[10];

   printf("\n\rIngrese el codigo del curso a eliminar ---> ");
   fflush(stdin);
   gets(Codigo);


   I=fopen("Cursos.dat","r+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   J=fopen("Temporal.dat","a+");
   if(J==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   encabezado1();

   fread(&RegistroC,sizeof(RegistroC),1,I);

   while(!feof(I)){
      if(stricmp(RegistroC.codC,Codigo)==0){
            Hallado=1;
            printf("%3d\t%s\t%-30s\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
      }
      else{
         fwrite(&RegistroC,sizeof(RegistroC),1,J);
      }
      i++;
      fread(&RegistroC,sizeof(RegistroC),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Cursos.dat");

   rena=rename("Temporal.dat","Cursos.dat");

   if(Hallado==0){
      cout<<"\n\rERROR: EL  CODIGO NO EXISTE..."<<endl;
   }
   else{
      cout<<"\n\rSE ELIMINO EL REGISTRO CON EXITO"<<endl;
   }
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;

}

void EditarRegistro(FILE *I ,FILE *J,struct CURSOS RegistroC){

   system("cls");
   int i=0,Hallado=0,remo,rena,op;
   char Codigo[10];

   printf("\n\rIngrese el codigo del curso a eliminar ---> ");
   fflush(stdin);
   gets(Codigo);
   fflush(stdin);

   I=fopen("Cursos.dat","r+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   J=fopen("Temporal2.dat","a+");
   if(J==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   encabezado1();

   fread(&RegistroC,sizeof(RegistroC),1,I);

   while(!feof(I)){
      if(stricmp(RegistroC.codC,Codigo)==0){
         Hallado=1;
         printf("%3d\t%s\t%-30s\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
         MenuEditar();
         do{
            do{
               cout<<"\NIngrese opcion [ ]"<<"\b\b";
               cin>>op;
               fflush(stdin);
               system("pause");
            }while(op<0 || op>8);

            switch(op){
               case 1 : fflush(stdin);
                        printf("Nuevo codigo --> ");
                        gets(RegistroC.codC);
                        encabezado1();
                        printf("%3d\t%s\t%-30s\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 2 : fflush(stdin);
                        printf("Nuevo nombre --> ");
                        gets(RegistroC.nomC);
                        encabezado1();
                        printf("%3d\t%s\t%-30s\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 3 : printf("Nuevo credito --> ");
                        scanf("%d",&RegistroC.creditC);
                        encabezado1();
                        printf("%3d\t%s\t%-30s\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
               case 4 : fflush(stdin);
                        printf("Nuevo Sist. de calificacion --> ");
                        gets(RegistroC.sist_calif);
                        encabezado1();
                        printf("%3d\t%s\t%-30s\t%d\t%5s\n",i+1,RegistroC.codC,RegistroC.nomC,RegistroC.creditC,RegistroC.sist_calif);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
                        system("pause");
                        break;
            }
            system("cls");
            MenuEditar();
         }while(op != 0);
         fwrite(&RegistroC,sizeof(RegistroC),1,J);
      }
      else{
         fwrite(&RegistroC,sizeof(RegistroC),1,J);
      }
      i++;
      fread(&RegistroC,sizeof(RegistroC),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Cursos.dat");

   rena=rename("Temporal2.dat","Cursos.dat");

   if(Hallado==0){
      cout<<"\n\rERROR: EL  CODIGO NO EXISTE..."<<endl;
   }
   else{
      cout<<"\n\rSE EDITO EL REGISTRO CON EXITO"<<endl;
   }
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;

}




