#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct TpFreezer{
  char Marca[15];
  float Capacidade;
  float Meses;
  float Economia;
  float TemperaturaMin;
  } RgFreezer;

FILE *Arquivo;

long int tamanho = sizeof(struct TpFreezer); 

long int TArquivo(){
	Arquivo=fopen("PesquisaFreezer.dat","a+b");
  fseek(Arquivo,0,2);
	long int ty=ftell(Arquivo)/tamanho;
  fclose(Arquivo);
	return ty;}

void Incluir(){
  char d;
  system("cls");
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  do{
    printf("\n*** REGISTRAR FREEZER ***\n\n");
    printf("Marca: ");
    scanf(" %s",RgFreezer.Marca);
    printf("Capacidade (L): ");
    scanf("%f",&RgFreezer.Capacidade);
    printf("Garantia (Meses): ");
    scanf("%f",&RgFreezer.Meses);
    printf("Economia (Kwh/mes): ");
    scanf("%f",&RgFreezer.Economia);
    printf("Temperatura Minima (C): ");
    scanf("%f",&RgFreezer.TemperaturaMin);
    fseek(Arquivo,0,2);
    fwrite(&RgFreezer, tamanho, 1, Arquivo);
    printf("\nFREEZER REGISTRADO COM SUCESSO!\n\n");
    printf("\n Deseja incluir outro freezer ? S/N ");
    scanf(" %c",&d);
    d=toupper(d);}
    while(d!='N');
    system("pause");
  fclose(Arquivo);

}

void Exibir(){
  system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  printf("\n*** EXIBIR DADOS ***\n\n");  
  fseek(Arquivo,0,0);
  do {
	fread(&RgFreezer,tamanho,1,Arquivo);
	if (!feof(Arquivo)){
	  printf("\nMarca: %s\n",RgFreezer.Marca);
    printf("Capacidade: %2.fL\n",RgFreezer.Capacidade);
    printf("Garantia: %2.f Meses\n",RgFreezer.Meses);
    printf("Economia: %.1fKwh/mes\n",RgFreezer.Economia);
    printf("Temperatura Minima: %.1fC\n",RgFreezer.TemperaturaMin);
      }}
    while (!feof(Arquivo));
  fclose(Arquivo);}
  else
     printf("\nNENHUM FREEZER REGISTRADO!\n");
  system("pause");}

void Dados(){
	system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  printf("\n*** DADOS DO FREEZER ***\n\n");  
  fseek(Arquivo,0,0);
  printf("Qual a marca do freezer ? \n\n");
  char freezer[15];
  printf("Freezers disponiveis para consulta de dados : ");
  do{
   fread(&RgFreezer,tamanho,1,Arquivo);
   if (!feof(Arquivo)){
     printf("%s // ",RgFreezer.Marca); 
   }}
    while(!feof(Arquivo));
  printf("\n\n");
  fseek(Arquivo,0,0);
  scanf("%s",freezer);
  int Existente=0;
  do{
	fread(&RgFreezer,tamanho,1,Arquivo);
	if (strcmp(RgFreezer.Marca,freezer)==0){
	  Existente=1;	
	  printf("\nMarca: %s\n",RgFreezer.Marca);
      printf("Capacidade: %2.fL\n",RgFreezer.Capacidade);
      printf("Garantia: %2.f meses\n",RgFreezer.Meses);
      printf("Economia: %.1fKwh/mes\n",RgFreezer.Economia);
      printf("Temperatura Minima: %.1fC\n",RgFreezer.TemperaturaMin);}}
    while (!feof(Arquivo)&&(Existente==0));
  if (Existente==0)
    printf("\nFREEZER NAO REGISTRADO!\n"); 
  fclose(Arquivo);}
  else
    printf("\nNENHUM FREEZER REGISTRADO!\n");
    
  
 system("pause");
 return;}

void Caracteristica (){
	system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  printf("\n*** DADOS DE UMA CARACTERISTICA ***\n\n");
  fseek(Arquivo,0,0);
  printf("Qual caracteristica se deseja observar os dados ? \n\n");
  printf("Opcoes : Capacidade // Garantia // Economia // Temperatura Minima\n");
  char caracteristica[25];
  scanf(" %[^\n]s",caracteristica);
  int aux2=0;
  if(strcmp(caracteristica,"Capacidade")==0){
    aux2=1;
    do {
	  fread(&RgFreezer,tamanho,1,Arquivo);
	  if (!feof(Arquivo)){
	   printf("\nMarca: %s\n",RgFreezer.Marca);
     printf("Capacidade: %2.fL\n",RgFreezer.Capacidade);}}
    while (!feof(Arquivo));
  }
  if(strcmp(caracteristica,"Garantia")==0){
    aux2=1;  
    do {
	  fread(&RgFreezer,tamanho,1,Arquivo);
	  if (!feof(Arquivo)){
	   printf("\nMarca: %s\n",RgFreezer.Marca);
     printf("Garantia: %2.f meses\n",RgFreezer.Meses);}}
    while (!feof(Arquivo));
  }
  if(strcmp(caracteristica,"Economia")==0){
    aux2=1;  
    do {
	  fread(&RgFreezer,tamanho,1,Arquivo);
	  if (!feof(Arquivo)){
	   printf("\nMarca: %s\n",RgFreezer.Marca);
     printf("Economia: %.1fKwh/mes\n",RgFreezer.Economia);}}
    while (!feof(Arquivo));
  }
  if(strcmp(caracteristica,"Temperatura Minima")==0){
    aux2=1; 
    do {
	  fread(&RgFreezer,tamanho,1,Arquivo);
	  if (!feof(Arquivo)){
	   printf("\nMarca: %s\n",RgFreezer.Marca);
     printf("Temperatura Minima: %.1fC\n",RgFreezer.TemperaturaMin);}}
    while (!feof(Arquivo));
  }
  if (aux2==0){
    printf("\nCARACTERISTICA INEXISTENTE\n");
  }
  fclose(Arquivo);}
  else
     printf("\nNENHUM FREEZER REGISTRADO!\n");
system("pause");}

void Alterar(){
	system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","r+b");
  printf("\n*** ALTERAR DADO ***\n\n");  
  fseek(Arquivo,0,0);
  printf("Qual a marca do freezer que os dados seram alterados ? \n\n");
  printf("Frezzers disponiveis para alteracao de dados : ");
  do{
   fread(&RgFreezer,tamanho,1,Arquivo);
   if (!feof(Arquivo)){
     printf("%s // ",RgFreezer.Marca); 
   }}
    while(!feof(Arquivo));
  printf("\n\n");
  fseek(Arquivo,0,0);
  char merch[15];
  scanf("%s",merch);
  int aux3=0;
  int auxx;
  printf("\nDeseja alterar todas as caracteristicas ou apenas uma ?\n\n");
  printf("1 - Todas as caracteristicas\n");
  printf("2 - Capacidade\n");
  printf("3 - Garantia\n");
  printf("4 - Economia\n");
  printf("5 - Temperatura Minima\n");
  scanf("%d",&auxx);
  switch(auxx){
    case 1 : {do {
	fread(&RgFreezer,tamanho,1,Arquivo);
	if (strcmp(RgFreezer.Marca,merch)==0){
	  aux3=1;	
	  printf("Marca: %s\n",RgFreezer.Marca);
    printf("Capacidade: %2.fL\n",RgFreezer.Capacidade);
    printf("Garantia: %2.f meses\n",RgFreezer.Meses);
    printf("Economia: %.1f Kwh/mes\n",RgFreezer.Economia);
    printf("Temperatura Minima: %.1fC\n",RgFreezer.TemperaturaMin);}}
  while (!feof(Arquivo)&&(aux3==0));
  if (aux3==1){
    printf("\nApresente os novos valores para cada caracteristica: \n\n");
    printf("Capacidade (L): ");
    scanf("%f",&RgFreezer.Capacidade);
    printf("Garantia (Meses): ");
    scanf("%f",&RgFreezer.Meses);
    printf("Economia (Kwh/mes): ");
    scanf("%f",&RgFreezer.Economia);
    printf("Temperatura Minima (C): ");
    scanf("%f",&RgFreezer.TemperaturaMin);
    fseek(Arquivo,-tamanho,1);
    fwrite(&RgFreezer,tamanho,1,Arquivo);
    printf("\nDADOS ALTERADOS COM SUCESSO\n");
  fclose(Arquivo);}
       else{
    printf("\nFREEZER NAO REGISTRADO!\n");
  fclose(Arquivo);}break;}
    case 2 : {do {
	fread(&RgFreezer,tamanho,1,Arquivo);
	if (strcmp(RgFreezer.Marca,merch)==0){
	  aux3=1;	
	  printf("\nMarca: %s\n",RgFreezer.Marca);
    printf("Capacidade: %2.fL\n",RgFreezer.Capacidade);}}
  while (!feof(Arquivo)&&(aux3==0));
  if (aux3==1){
    printf("\nApresente o novo valor: \n\n");
    printf("Capacidade (L): ");
    scanf("%f",&RgFreezer.Capacidade);
    fseek(Arquivo,-tamanho,1);
    fwrite(&RgFreezer,tamanho,1,Arquivo);
    printf("\nDADOS ALTERADOS COM SUCESSO\n");
  fclose(Arquivo);}
       else{
    printf("\nFREEZER NAO REGISTRADO!\n");
  fclose(Arquivo);}break;}
    case 3 : {do {
	fread(&RgFreezer,tamanho,1,Arquivo);
	if (strcmp(RgFreezer.Marca,merch)==0){
	  aux3=1;	
	  printf("\nMarca: %s\n",RgFreezer.Marca);
    printf("Garantia: %2.f meses\n",RgFreezer.Meses);}}
  while (!feof(Arquivo)&&(aux3==0));
  if (aux3==1){
    printf("\nApresente o novo valor: \n\n");
    printf("Garantia (Meses): ");
    scanf("%f",&RgFreezer.Meses);
    fseek(Arquivo,-tamanho,1);
    fwrite(&RgFreezer,tamanho,1,Arquivo);
    printf("\nDADOS ALTERADOS COM SUCESSO\n");
  fclose(Arquivo);}
       else{
    printf("\nFREEZER NAO REGISTRADO!\n");
  fclose(Arquivo);}break;}
    case 4 : {do {
	fread(&RgFreezer,tamanho,1,Arquivo);
	if (strcmp(RgFreezer.Marca,merch)==0){
	  aux3=1;	
	  printf("\nMarca: %s\n",RgFreezer.Marca);
    printf("Economia: %.1fKwh/mes\n",RgFreezer.Economia);}}
  while (!feof(Arquivo)&&(aux3==0));
  if (aux3==1){
    printf("\nApresente o novo valor: \n\n");
    printf("Economia (Kwh/mes): ");
    scanf("%f",&RgFreezer.Economia);
    fseek(Arquivo,-tamanho,1);
    fwrite(&RgFreezer,tamanho,1,Arquivo);
    printf("\nDADOS ALTERADOS COM SUCESSO\n");
  fclose(Arquivo);}
       else{
    printf("\nFREEZER NAO REGISTRADO!\n");
  fclose(Arquivo);}break;}
    case 5 : {do {
	fread(&RgFreezer,tamanho,1,Arquivo);
	if (strcmp(RgFreezer.Marca,merch)==0){
	  aux3=1;	
	  printf("\nMarca: %s\n",RgFreezer.Marca);
    printf("Temperatura Minima: %.1fC\n",RgFreezer.TemperaturaMin);}}
  while (!feof(Arquivo)&&(aux3==0));
  if (aux3==1){
    printf("\nApresente o novo valor: \n\n");
    printf("Temperatura Minima (C): ");
    scanf("%f",&RgFreezer.TemperaturaMin);
    fseek(Arquivo,-tamanho,1);
    fwrite(&RgFreezer,tamanho,1,Arquivo);
    printf("\nDADOS ALTERADOS COM SUCESSO\n");
  fclose(Arquivo);}
       else{
    printf("\nFREEZER NAO REGISTRADO!\n");
  fclose(Arquivo);}break;}
  } }
   else
    printf("\nNENHUM FREEZER REGISTRADO!\n");
  system("pause");
  return;}

void Capacidade (){
	system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  printf("\n*** MELHOR FREEZER EM CAPACIDADE ***\n\n");
  fseek(Arquivo,0,0);
  char mlrmarca1 [15];
  float aux5=0;  
  do {
	fread(&RgFreezer,tamanho,1,Arquivo);
    if (!feof(Arquivo)){
      if(RgFreezer.Capacidade>aux5){
        aux5=RgFreezer.Capacidade;
        strcpy(mlrmarca1,RgFreezer.Marca);
      }    }}
    while (!feof(Arquivo));
  printf(" %s e o MELHOR FREEZER EM CAPACIDADE!\n",mlrmarca1);
  printf("Capacidade: %2.fL\n",aux5);
  fclose(Arquivo);}
  else
    printf("\nNENHUM FREEZER REGISTRADO!\n");
system("pause");}

void Garantia (){
	system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  printf("\n*** MELHOR FREEZER EM GARANTIA ***\n\n");
  fseek(Arquivo,0,0);
  char mlrmarca2 [15];
  float aux6=0;  
  do {
	fread(&RgFreezer,tamanho,1,Arquivo);
    if (!feof(Arquivo)){
      if(RgFreezer.Meses>aux6){
        aux6=RgFreezer.Meses;
        strcpy(mlrmarca2,RgFreezer.Marca);
      }    }}
    while (!feof(Arquivo));
  printf(" %s e o MELHOR FREEZER EM GARANTIA!\n",mlrmarca2);
  printf("Garantia: %2.f Meses\n",aux6);
  fclose(Arquivo);}
  else
    printf("\nNENHUM FREEZER REGISTRADO!\n");
system("pause");}

void Economia (){
	system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  printf("\n*** MELHOR FREEZER EM ECONOMIA ***\n\n");
  fseek(Arquivo,0,0);
  char mlrmarca3 [15];
  float aux7=0;  
  do {
	fread(&RgFreezer,tamanho,1,Arquivo);
    if (!feof(Arquivo)){
      if(RgFreezer.Economia>aux7){
        aux7=RgFreezer.Economia;
        strcpy(mlrmarca3,RgFreezer.Marca);
      }    }}
    while (!feof(Arquivo));
  printf(" %s e o MELHOR FREEZER EM ECONOMIA!\n",mlrmarca3);
  printf("Economia: %.1fKwh/mes\n",aux7);
  fclose(Arquivo);}
  else
    printf("\nNENHUM FREEZER REGISTRADO!\n");
system("pause");}

void TemperaturaMin(){
	system("cls");
  if (TArquivo()!=0){
  Arquivo=fopen("PesquisaFreezer.dat","a+b");
  printf("\n*** MELHOR FREEZER EM TEMPERATURA ***\n\n");
  fseek(Arquivo,0,0);
  char mlrmarca4 [15];
  float aux8=1000;  
  do {
	fread(&RgFreezer,tamanho,1,Arquivo);
    if (!feof(Arquivo)){
      if(RgFreezer.TemperaturaMin<aux8){
        aux8=RgFreezer.TemperaturaMin;
        strcpy(mlrmarca4,RgFreezer.Marca);
      }    }}
    while (!feof(Arquivo));
  printf(" %s e o MELHOR FREEZER EM TEMPERATURA!\n",mlrmarca4);
  printf("Temperatura minima: %.1fC\n",aux8);
  fclose(Arquivo);}
  else
    printf("\nNENHUM FREEZER REGISTRADO!\n");
system("pause");}

int main(void) {
   int Op;
   do{
    system("cls");
    printf("\n>>> CONSULTA FREEZER <<<\n\n");
    printf("Selecione a opcao desejada:\n");
    printf("1 - Registrar Freezer\n");
    printf("2 - Exibir dados dos Freezers\n");
    printf("3 - Dados de um Freezer\n");
    printf("4 - Dados de uma Caracteristica\n");
    printf("5 - Alterar Dado\n");
    printf("6 - Melhor Freezer em Capacidade\n");
    printf("7 - Melhor Freezer em Garantia\n");
    printf("8 - Melhor Freezer em Economia\n");
    printf("9 - Melhor Freezer em Temperatura\n");
    printf("10 - Sair\n");
    scanf("%d",&Op);
    switch (Op){
      case 1 : Incluir (); break;
      case 2 : Exibir(); break;
      case 3 : Dados (); break;
      case 4 : Caracteristica (); break;
      case 5 : Alterar (); break; 
      case 6 : Capacidade(); break;
      case 7 : Garantia(); break;
      case 8 : Economia(); break;
      case 9 : TemperaturaMin(); break;   
    }}
     while(Op!=10);
  return 0;
}
