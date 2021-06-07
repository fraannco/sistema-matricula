/*
 * nomPrograma: FINAL v2
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

   struct EXFINAL{
   char codAlu[10];
   char codCur[10];
   float exfin;
   };

int  MenuPRINCIPAL();
void encabezado1();
void MenuEditar();
void raya1();
void raya2();

void MostrarRegistro(FILE *I, EXFINAL RegistroC);
void BuscarRegistro(FILE *I, EXFINAL RegistroC);
void EliminarRegistro(FILE *I, FILE *J,struct EXFINAL RegistroC);
void EditarRegistro(FILE *I ,FILE *J,struct EXFINAL RegistroC);


int main()
{
   int op;
   FILE *I;
   FILE *J;
   EXFINAL RegistroC;
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
   cout << "\n\r [1] LECTURA DEL ARCHIVO FINAL";
   cout << "\n\r [2] BUSQUEDA POR CODIGO";
   cout << "\n\r [3] ELIMINAR UN EXAMEN";
   cout << "\n\r [4] EDITAR UN EXAMEN";
   printf("\n");
}

void encabezado1(){
   //system("cls");
   char title[]="\tREPORTE DE NOTAS DEL FINAL";
   char cod[]="COD.ALUM";
   char nom[]="COD.CURSO";
   char nota[]="NOTA";
   printf("\n");
   raya2();
   printf("\t\t%s\n",title);
   raya2();
   printf("%-13s%-31s%-5s\n",cod,nom,nota);
   raya1();
}

void MenuEditar(){
   system("cls");
   cout << "\n\r A R C H I V O    D E    F I N A L";
   cout << "\n\r  OPCIONES DE EDICION ";
   cout << "\n\n\n\r 0.- TERMINAR";
   cout << "\n\r [1] EDITAR CODIGO DEL ALUMNO";
   cout << "\n\r [2] EDITAR CODIGO DEL CURSO";
   cout << "\n\r [3] EDITAR NOTA DEL EXAMEN FINAL";
   printf("\n");
}

void raya2(){
   printf("============================================================================\n");
}

void raya1(){
   printf("----------------------------------------------------------------------------\n");
}


void MostrarRegistro(FILE *I, EXFINAL RegistroC){
   int i=0;
   I=fopen("Final.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }

   fread(&RegistroC,sizeof(RegistroC),1,I);

   encabezado1();

   while(!feof(I)){

      printf("\n\r %6s\t\t%-30s\t%-4.1f\t",RegistroC.codAlu, RegistroC.codCur, RegistroC.exfin);
      fread(&RegistroC,sizeof(RegistroC),1,I);

      i++;
   }

   fclose(I);
   printf("\n");
   raya1();
   cout << "\n\rFin del listado !!!\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;
}

void BuscarRegistro(FILE *I,EXFINAL RegistroC){

   system("cls");
   char Codigo[10];
   int i=0;
   printf("\n\rIngrese el codigo del alumno a buscar ---> ");
   fflush(stdin);
   gets(Codigo);

   encabezado1();

   I=fopen("Final.dat","a+");
   if(I==NULL){
      cout<<"ERROR: NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
      system("pause");
      exit(1);
   }
   while(!feof(I)){
      if(stricmp(RegistroC.codAlu,Codigo)==0){
         printf("\n\r %6s\t\t%-30s\t %-4.1f\t",RegistroC.codAlu, RegistroC.codCur, RegistroC.exfin);
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

void EliminarRegistro(FILE *I ,FILE *J,struct EXFINAL RegistroC){

   system("cls");
   int i=0,Hallado=0,remo,rena;
   char Codigo[10];

   printf("\n\rIngrese el codigo del alumno con el examen a eliminar ---> ");
   fflush(stdin);
   gets(Codigo);


   I=fopen("Final.dat","r+");
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
      if(stricmp(RegistroC.codAlu,Codigo)==0){
            Hallado=1;
            printf("\n\r %6s\t\t%-30s\t%-4.1f\t",RegistroC.codAlu, RegistroC.codCur, RegistroC.exfin);
      }
      else{
         fwrite(&RegistroC,sizeof(RegistroC),1,J);
      }
      i++;
      fread(&RegistroC,sizeof(RegistroC),1,I);
   }

   fclose(I);
   fclose(J);

   remo=remove("Final.dat");

   rena=rename("Temporal.dat","Final.dat");

   if(Hallado==0){
      cout<<"\n\rERROR: EL  CODIGO NO EXISTE..."<<endl;
   }
   else{
      cout<<"\n\r\nSE ELIMINO EL REGISTRO CON EXITO"<<endl;
   }
   cout << "\n\r----------------------------------------------------------------";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;

}

void EditarRegistro(FILE *I ,FILE *J,struct EXFINAL RegistroC){

   system("cls");
   int i=0,Hallado=0,remo,rena,op;
   char Codigo[10];

   printf("\n\rIngrese el codigo del alumno con el examen a editar ---> ");
   fflush(stdin);
   gets(Codigo);


   I=fopen("Final.dat","r+");
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
      if(stricmp(RegistroC.codAlu,Codigo)==0){
         Hallado=1;
         printf("\n\r %6s\t\t%-30s\t%-4.1f\t",RegistroC.codAlu, RegistroC.codCur, RegistroC.exfin);
         MenuEditar();
         do{
            do{
               cout<<"\nIngrese opcion [ ]"<<"\b\b";
               cin>>op;
            }while(op<0 || op>8);

            switch(op){
               case 1 : fflush(stdin);
                        printf("Nuevo codigo de alumno --> ");
                        gets(RegistroC.codAlu);
                        encabezado1();
                        printf("\n\r %6s\t\t%-30s\t%-4.1f\t",RegistroC.codAlu, RegistroC.codCur, RegistroC.exfin);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar\n >>>";
                        getch();
                        break;
               case 2 : fflush(stdin);
                        printf("Nuevo codigo de curso --> ");
                        gets(RegistroC.codCur);
                        encabezado1();
                        printf("\n\r %6s\t\t%-30s\t%-4.1f\t",RegistroC.codAlu, RegistroC.codCur, RegistroC.exfin);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
                        getch();
                        break;
               case 3 : printf("Nueva nota --> ");
                        scanf("%f",&RegistroC.exfin);
                        encabezado1();
                        printf("\n\r %6s\t\t%-30s\t%-4.1f\t",RegistroC.codAlu, RegistroC.codCur, RegistroC.exfin);
                        cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>\n";
                        getch();
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

   remo=remove("Final.dat");

   rena=rename("Temporal2.dat","Final.dat");

   if(Hallado==0){
      cout<<"\n\rERROR: EL  CODIGO NO EXISTE..."<<endl;
   }
   else{
      cout<<"\n\rSE EDITO EL REGISTRO CON EXITO"<<endl;
   }
   cout << "\n\r----------------------------------------------------------------\n";
   cout << "\n\r<<< ... PRESIONE ENTER para continuar >>>";
   getch();
   return;

}




