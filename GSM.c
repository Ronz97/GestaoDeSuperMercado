#include "HEADER.h"
#include <stdio.h>
#include <stdlib.h>


//  criar listas de cada estrutura
//produtos

produtos *novono(int c, char nome[], char marca[], int codTipo, float prv, float prc, int codF, int stMin, int stMax, int stAt)
{
	produtos *Aux;
	Aux=(produtos*)malloc(sizeof(produtos));
	if(Aux!=NULL)
    {
      Aux->codigo=c;
      strcpy(Aux->nome, nome);
      strcpy(Aux->marca, marca);
      Aux->codigoTipo=codTipo;
      Aux->precoVenda=prv;
      Aux->precoCompra=prc;
      Aux->codFornecedor=codF;
      Aux->StockMin=stMin;
      Aux->stockMax=stMax;
      Aux->stockAt=stAt;
      Aux->prox=NULL;

    }

  return Aux;
}

// tipoProduto

tipoproduto *novoTipo(int c, char nome[], float iva)
{
	tipoproduto *tpAux;
	tpAux=(tipoproduto*)malloc(sizeof(tipoproduto)); /*Alocar espaco na memoria*/
	if(tpAux!=NULL)
    {
      tpAux->codigo=c;
      strcpy(tpAux->nome, nome);
      tpAux->iva=iva;
      tpAux->prox=NULL;
    }

  return tpAux;
}

//encomenda
encomenda *novaEncomenda(int codP, char data[], int quantidade, float custo)
{
	encomenda *encAux;
	encAux=(encomenda*)malloc(sizeof(encomenda)); /*Alocar espaco na memoria*/
	if(encAux!=NULL)
    {
      encAux->codigoProduto=codP;
      strcpy(encAux->data, data);
      encAux->quantidade=quantidade;
      encAux->custo=custo;
      encAux->prox=NULL;
    }

  return encAux;
}

//fornecedor

fornecedor *novoFornecedor(int cod, char morada[], char nome[], int telefone /*encomenda* e*/)
{
	fornecedor *fnAux;
	fnAux=(fornecedor*)malloc(sizeof(fornecedor)); /*Alocar espaco na memoria*/
	if(fnAux!=NULL)
    {
      fnAux->codigo=cod;
      strcpy(fnAux->morada, morada);
      strcpy(fnAux->nome, nome);
      fnAux->telefone=telefone;
     // fnAux->ec=e;
      fnAux->prox=NULL;
    }

  return fnAux;
}

venda *novaVenda(int c, int codprodutos, int quantidades, char data[], float total)
{
	venda *vAux;
	vAux=(venda*)malloc(sizeof(venda)); /*Alocar espaco na memoria*/
	if(vAux!=NULL)
    {
      vAux->codigoVenda=c;
      vAux->codprodutos= codprodutos;
      vAux->quantidades  = quantidades;
       strcpy(vAux->data, data);
      vAux->total = total;
      vAux->prox=NULL;
    }

  return vAux;
}

compra *novaCompra(int c, int codprodutos, int quantidades, 	int codFornecedor, char data[], float total)
{
	compra *cAux;
	cAux=(compra*)malloc(sizeof(compra));/*Alocar espaco na memoria*/
	if(cAux!=NULL)
    {
      cAux->codigoCompra=c;
      cAux->codprodutos= codprodutos;
      cAux->quantidades  = quantidades;
      cAux->codFornecedor = codFornecedor;
      strcpy(cAux->data, data);
      cAux->total = total;
      cAux->prox=NULL;
    }

  return cAux;
}

int MenuPrincipal()
{
    int op;


      printf("\t       %c----------%c\t\t\t\t       ",201,187);
      printf("\t\t\t                  ");printf("\t\t\t\t      \n");
      printf("		   MENU\n");
      printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <1>  Venda		               |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <2>  Compra                       |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <3>  Inventario		       |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <4>  Estatistica Fornecedor       |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <5> Faturacao		       |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <6>  Edita lista de produtos      |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <7>  Ordena lista de produtos     |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <8>  Sair                         |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n");

	  printf("Opcao => ");
      scanf(" %d",&op);

    return op;
}

int SubMenuEditaLista()
{
    int ops;

     printf("\n\n:::::: SubMenu Edita Lista ::::::::::\n");
	 printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <1>  Inserir Produto	       |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <2>  Listar Produtos              |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <3>  Eliminar Produto	       |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <4>  Voltar ao Menu Principal     |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n");
      printf("Opcao => ");
      scanf(" %d",&ops);

    return ops;
}

int procurarTipo(int codigo){
	tipoproduto *Aux;

	 for(Aux=tp; Aux!= NULL; Aux = Aux->prox){
	 	if(Aux->codigo == codigo)
	 	return 1;
	 }
	 return 0;
}

int codUltimaVenda(){
	venda *Aux;

	 for(Aux=v; Aux!= NULL; Aux = Aux->prox){
	 	if(Aux->prox == NULL)
	 	return Aux->codigoVenda;
	 }
}

int codUltimaCompra(){
	compra *Aux;

	 for(Aux=c; Aux!= NULL; Aux = Aux->prox){
	 	if(Aux->prox == NULL)
	 	return Aux->codigoCompra;
	 }
}

int procurarProduto(int codigo){
	produtos *Aux;

	 for(Aux=p; Aux!= NULL; Aux = Aux->prox){
	 	if(Aux->codigo == codigo)
	 	return 1;
	 }
	 return 0;
}
// procurar fornecedor
int procurarFornecedor(char nome[]){
	fornecedor *Aux;

	 for(Aux=f; Aux!= NULL; Aux = Aux->prox){
	 	if(strcmp(Aux->nome, nome) == 0)
	 	return Aux->codigo;
	 }
	 return 0;
}

// guardar tipo produto na lista
void guardarTipoProduto(tipoproduto *novotipo){
	tipoproduto *Aux = tp;

	 if(tp!=NULL)
	{
	 while(Aux->prox!=NULL)
	    Aux = Aux->prox;
	 Aux->prox = novotipo;

	}
	else
	tp = novotipo;

}

// guardar produto na lista
void guardarProduto(produtos *novoProd){
	produtos *Aux = p;
	 if(p!=NULL)
	{
	  while(Aux->prox!=NULL)
	    Aux=Aux->prox;
		   Aux->prox=novoProd;
	}
	else
	p = novoProd;

}

//Guarda Vendas
void guardarVenda(venda *novaVenda){
	venda *Aux = v;
	 if(v!=NULL)
	{
	  while(Aux->prox!=NULL)
	    Aux=Aux->prox;
		   Aux->prox=novaVenda;
	}
	else
	v = novaVenda;

}

//Guarda Compra
void guardarCompra(compra *novaCompra){
	compra *Aux = c;
	 if(c!=NULL)
	{
	  while(Aux->prox!=NULL)
	    Aux=Aux->prox;
		   Aux->prox=novaCompra;
	}
	else
	c = novaCompra;

}

void guardarEncomenda(encomenda *Encomend){
	encomenda *Aux = e;
	 if(e!=NULL)
	{
	  while(Aux->prox!=NULL)
	    Aux=Aux->prox;
		   Aux->prox=Encomend;
	}
	else
	e = Encomend;

}

//guardar fornecedor
void guardarFornecedor(fornecedor *novoFornecdor){
	fornecedor *Aux = f;
	 if(f!=NULL)
	{
	  while(Aux->prox!=NULL)
	    Aux=Aux->prox;
		   Aux->prox=novoFornecdor;
	}
	else
	f = novoFornecdor;

}

// funcoes e procedimentos da lista de produtos
// AUI
 void pedirDados(){
	int codigo, codigoTipo, codFornecedor, stockMin, stockMax, stockAt;
	char nome[40], marca[40];
	float precoVenda, precoCompra;

	//if(tp!=NULL){
	printf("Introduza o codigo do produto:\n");
  	scanf("%d", &codigo);
  	if(procurarProduto(codigo) == 0){
	  		printf("Nome do produto:::\n");
	  	scanf("%s",nome);
	  	printf("Marca do produto:::\n");
	  	scanf("%s",marca);
	  	printf("codigo do tipo produto:\n");
	  	scanf("%d", &codigoTipo);
	  	if(procurarTipo(codigoTipo) == 1){
	  		printf("Preco de Venda $:::\n");
			scanf("%f",&precoVenda);
			printf("Preco de Compra $:::\n");
			scanf("%f",&precoCompra);

			printf("codigo do Fornecedor:\n");
	  		scanf("%d", &codFornecedor);
	  		printf("Stock Minimo:\n");
	  		scanf("%d", &stockMin);
	  		printf("Stock Maximo:\n");
	  		scanf("%d", &stockMax);
	  		printf("Stock Atual:\n");
	  		scanf("%d", &stockAt);
	  		produtos *novoProd = novono(codigo, nome, marca, codigoTipo, precoVenda, precoCompra, codFornecedor, stockMin, stockMax, stockAt);
	  		guardarProduto(novoProd);
	  		printf(":::Produto Registado com sucesso:::\n");
		  }
		  else
		 printf("Nao eh possivel guardar produto,o codigo do tipo Produto nao esta Lista\n");
  	}
  	 else
		 printf("Ja existe um produto registado com este codigo\n");

	//} else printf("Nao eh possivel guardar produto, nao ha nenhum tipo Produto na Lista\n");
}


/*Guardar dados da estrutura produtos no ficheiro produtos*/
void guardaficheiroprodutos()
 {
 	 produtos *Aux=p;
     FILE * al;
    if ((al = fopen("produtos.txt", "w")) == NULL)
   printf("Nao e' possivel abrir o ficheiro\n");
   else {
   for(Aux=p; Aux!= NULL; Aux = Aux->prox)
 {
  fprintf(al, "%d \t %s \t %s \t %d \t %.2f\t %.2f\t %d\t %d\t %d\t %d \n", Aux->codigo, Aux->nome, Aux->marca, Aux->codigoTipo, Aux->precoVenda, Aux->precoCompra, Aux->codFornecedor, Aux->StockMin, Aux->stockMax, Aux->stockAt);
 } fclose(al);
 }
}

// guardar ficheiro vendas
void guardaficheiroVendas()
 {
 	 venda *vAux=v;
     FILE * al;
    if ((al = fopen("vendas.txt", "w")) == NULL)
   printf("Nao e' possivel abrir o ficheiro\n");
   else {
   for(vAux=v; vAux!= NULL; vAux = vAux->prox)
 {
  fprintf(al, "%d \t %d \t %d \t %s \t %.2f \n", vAux->codigoVenda, vAux->codprodutos, vAux->quantidades, vAux->data, vAux->total);
 } fclose(al);
 }
}

// guardar ficheiro compras
void guardaficheiroCompras()
 {
 	 compra *cAux=c;
     FILE * al;
    if ((al = fopen("compras.txt", "w")) == NULL)
   printf("Nao e' possivel abrir o ficheiro\n");
   else {
   for(cAux=c; cAux!= NULL; cAux = cAux->prox)
 {
  fprintf(al, "%d \t %d \t %d \t %d \t %s \t %.2f \n", cAux->codigoCompra, cAux->codprodutos, cAux->quantidades, cAux->codFornecedor, cAux->data, cAux->total);
 } fclose(al);
 }
}

// guardar ficheiro fornecedores
void guardaficheiroFornecedores()
 {
 	 fornecedor *fAux=f;
     FILE * al;
    if ((al = fopen("fornecedores.txt", "w")) == NULL)
   printf("Nao e' possivel abrir o ficheiro\n");
   else {
   for(fAux=f; fAux!= NULL; fAux = fAux->prox)
 {
  fprintf(al, "%d \t %s \t %s \t %d \n", fAux->codigo, fAux->morada, fAux->nome, fAux->telefone);
 } fclose(al);
 }
}
//listar produtos
void listarProdutos(){
	produtos *produts= p;
	printf(" %c----------------------------------------------------------------------------%c\n",201,187);
    printf(" | ");printf("\t\t\t    PRODUTOS DO SUPERMERCADO");printf("\t\t\t      |\n");
    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
    printf(" |Cod\tNome\tMarca\tTipo\tPV\tPC\tCF\tStMin\tStMax\tStAt  |\n");
     printf(" %c----------------------------------------------------------------------------%c\n",200,188);
	for(produts=p; produts!= NULL; produts = produts->prox)
	 {
	  printf( " |%d \t %s\t %s\t %d \t %2.f$ \t %2.f$ \t %d \t %d \t %d \t %d  |\n", produts->codigo, produts->nome, produts->marca, produts->codigoTipo, produts->precoVenda, produts->precoCompra, produts->codFornecedor, produts->StockMin, produts->stockMax, produts->stockAt);
	 printf(" %c----------------------------------------------------------------------------%c\n",200,188);
	 }
}
/*Guardar dados da estrutura tipoprodutos no ficheiro tipoprodutos*/
void guardaficheirotipoprodutos()
 {
 	 tipoproduto *tProd= tp;
     FILE * al;
    if ((al = fopen("tipoProdutos.txt", "w")) == NULL)
   printf("Nao e' possivel abrir o ficheiro\n");
   else {
   for(tProd=tp; tProd!= NULL; tProd = tProd->prox)
 {
  fprintf(al, "%d \t %s \t %.2f\n", tProd->codigo, tProd->nome, tProd->iva);
 } fclose(al);
 }
}


/*Guardar dados da estrutura encomendas no ficheiro encomendas*/
void guardaficheiroEncomendas()
 {
 	 encomenda *encomend= e;
     FILE * al;
    if ((al = fopen("encomendas.txt", "w")) == NULL)
   printf("Nao e' possivel abrir o ficheiro\n");
   else {
   for(encomend=e; encomend!= NULL; encomend = encomend->prox)
 {
  fprintf(al, "%d \t %s\t %d \t %.2f\n",encomend->codigoProduto, encomend->data, encomend->quantidade, encomend->custo);
 } fclose(al);
 }
}

/* Carregar dados para estrutura tipoProdutos*/
 void carregarTipoProdutos()
 {
     int c;
	 char nome[20];
	 float i;
     FILE * al;
    if ((al = fopen("tipoProdutos.txt", "r")) == NULL)
    printf("Nao e' possivel abrir o ficheiro\n");
    else {
           while(fscanf(al, "%d%s%f", &c, nome, &i)!=EOF)
          {
        	tipoproduto *novotp = novoTipo(c, nome, i);
        	guardarTipoProduto(novotp);
           	//printf( "%d\t%s\t%f\n", c, nome, i);
         } fclose(al);
       }
}

/* Carregar dados para estrutura Produtos*/
void carregarProdutos()
 {
    int codigo, codigoTipo, codFornecedor, stockMin, stockMax, stockAt;
	char nome[40], marca[40];
	float precoVenda, precoCompra;
     FILE * al;
    if ((al = fopen("produtos.txt", "r")) == NULL)
    printf("Nao e' possivel abrir o ficheiro\n");
    else {
           while(fscanf(al, "%d%s%s%d%f%f%d%d%d%d", &codigo, nome, marca, &codigoTipo, &precoVenda, &precoCompra, &codFornecedor, &stockMin, &stockMax, &stockAt)!=EOF)
          {
        	produtos *novoProd = novono(codigo, nome, marca, codigoTipo, precoVenda, precoCompra, codFornecedor, stockMin, stockMax, stockAt);
        	guardarProduto(novoProd);
           	//printf( "%d\t%s\t%f\n", c, nome, i);
         } fclose(al);
       }
}

// carregar do ficheiro para estrutura vendas
void carregarVendas()
 {
    int codigo, codigoProduto, quantidade;
	char data[40];
	float total;
     FILE * al;
    if ((al = fopen("vendas.txt", "r")) == NULL)
    printf("Nao e' possivel abrir o ficheiro\n");
    else {
           while(fscanf(al, "%d%d%d%s%f", &codigo, &codigoProduto, &quantidade, data, &total)!=EOF)
          {
        	venda *novaVend = novaVenda(codigo, codigoProduto, quantidade, data, total);
        	guardarVenda(novaVend);
         } fclose(al);
       }
}
// carregar encomendas para a estrutura
void carregarEncomendas()
 {
    int codigo, codigoProduto, quantidade;
	char data[40];
	float custo;
     FILE * al;
    if ((al = fopen("encomendas.txt", "r")) == NULL)
    printf("Nao e' possivel abrir o ficheiro\n");
    else {
           while(fscanf(al, "%d%s%d%f", &codigo, data, &quantidade, &custo)!=EOF)
          {
        	encomenda *novaEnc = novaEncomenda(codigo, data, quantidade, custo);
        	guardarEncomenda(novaEnc);
         } fclose(al);
       }
}
// carregar ficheiro compras

void carregarCompras()
 {
    int codigoCompra, codigoProduto, quantidade, codigoFornecedor;
	char data[40];
	float total;
     FILE * al;
    if ((al = fopen("compras.txt", "r")) == NULL)
    printf("Nao e' possivel abrir o ficheiro\n");
    else {
           while(fscanf(al, "%d%d%d%d%s%f", &codigoCompra, &codigoProduto, &quantidade, &codigoFornecedor, data, &total)!=EOF)
          {
        	compra *novaCompr = novaCompra(codigoCompra, codigoProduto, quantidade, codigoFornecedor, data, total);
        	guardarCompra(novaCompr);
         } fclose(al);
       }
}
//carrega fornecedores para a estrutura
void carregarFornecedores()
 {
    int codigo, telefone;
	char nome[40], morada[40];
     FILE * al;
    if ((al = fopen("fornecedores.txt", "r")) == NULL)
    printf("Nao e' possivel abrir o ficheiro\n");
    else {
           while(fscanf(al, "%d%s%s%d", &codigo, morada, nome, &telefone)!=EOF)
          {
        	fornecedor *novFornecedor = novoFornecedor(codigo, morada, nome, telefone);
        	guardarFornecedor(novFornecedor);
         } fclose(al);
       }
}

// inventario
void inventario(char nome[]){
	produtos *produts= p;
	int quantidade, control;
	float custoAquisicao, valorVendas, previsaoLucro;
	control = 0;

		for(produts=p; produts!= NULL; produts = produts->prox)
	 {
	 	if(strcmp(produts->nome, nome) == 0){
		  quantidade = produts->stockAt;
		  custoAquisicao = quantidade * produts->precoCompra;
		  valorVendas = quantidade * produts->precoVenda;
		  previsaoLucro = valorVendas - custoAquisicao;
		  printf("   %c-----------------------------------%c \n",201,187);
	      printf("   |Inventario do produto %s       |\n", nome);
	      printf("   |-----------------------------------|\n");
	      printf("   | Quantidade            ---->  %d  |\n", quantidade);
	      printf("   | Custo de Aquisicao      --> %2.f$ |\n", custoAquisicao);
	      printf("   | Valor de Vendas Previsto--> %2.f$|\n", valorVendas);
		  printf("   | Margem de lucro         --> %2.f$|\n", previsaoLucro);
	      printf("   %c-----------------------------------%c\n\n",200,188);
		  control = 1;
		 }
	 }
	 if(control == 0)
	 printf("::: Este produto nao se encontra na Lista\n\n");

}

// Estatistica por fornecedor
void estatisticaFornecedor(int codFornecedor){
	produtos *produts= p;
	int quantidade, control, totalGeral;
	float custoAquisicao, valorVendas, previsaoLucro, custoAquisicaoTotal, valorVendasTotal, lucroTotal;
	custoAquisicaoTotal = 0;
	valorVendasTotal = 0;
	lucroTotal = 0;
	totalGeral = 0;
	control = 0;
		  printf("   %c-----------------------------------%c \n",201,187);
	      printf("   |Estatisitica do fornecedor %d       |\n", codFornecedor);
	      printf("   |-----------------------------------|\n");
		for(produts=p; produts!= NULL; produts = produts->prox)
	 {
	 	if(produts->codFornecedor == codFornecedor){
		  quantidade = produts->stockAt;
		  custoAquisicao = quantidade * produts->precoCompra;
		  valorVendas = quantidade * produts->precoVenda;
		  previsaoLucro = valorVendas - custoAquisicao;
		  printf("   %c-----------------------------------%c \n",201,187);
	      printf("   |Produto %s       		|\n", produts->nome);
	      printf("   |-----------------------------------|\n");
	      printf("   | Quantidade            ---->  %d  |\n", quantidade);
	      printf("   | Custo de Aquisicao      --> %2.f$ |\n", custoAquisicao);
	      printf("   | Valor de Vendas Previsto--> %2.f$|\n", valorVendas);
		  printf("   | Margem de lucro         --> %2.f$|\n", previsaoLucro);
	      printf("   %c-----------------------------------%c\n",200,188);
		  control = 1;
		  totalGeral = totalGeral + quantidade;
		  custoAquisicaoTotal = custoAquisicaoTotal + custoAquisicao;
		  valorVendasTotal = valorVendasTotal + valorVendas;
		  lucroTotal = lucroTotal + previsaoLucro;
		 }
	 }
	 if(control == 0)
	 printf("::: Este Fornecedor nao se encontra na Lista\n\n");
	 else{
	 	  printf("   | Quantidade  Total       ---->  %d|\n", totalGeral);
	      printf("   | Custo de Aquisicao Total--> %2.f$|\n", custoAquisicaoTotal);
	      printf("   | Valor de Vendas Total   --> %2.f$|\n", valorVendasTotal);
		  printf("   | Margem de lucro Total   --> %2.f$ |\n", lucroTotal);
	      printf("   %c-----------------------------------%c\n\n",200,188);
	 }

}
// void listar venda por codigo
void vendaByCodigo(int codigo){
	venda *vAux= v;
    printf(" %c--------------------------------------------------------------------------%c\n",201,187);
    printf(" |CodVenda\tCodProduto\tQuantidade\t  Data Venda\t Valor pago |\n");
    printf(" %c--------------------------------------------------------------------------%c\n",200,188);
	for(v=vAux; vAux!= NULL; vAux = vAux->prox)
	 {
	 	if(vAux->codigoVenda == codigo)
	 	{
	 		 printf( " |%d \t\t    %d\t\t   %d\t\t  %s \t     %2.f    |\n", vAux->codigoVenda, vAux->codprodutos, vAux->quantidades, vAux->data, vAux->total);
	  		 printf(" %c--------------------------------------------------------------------------%c\n",200,188);
		 }
	 }
}
float getPreco(int codProduto){
	produtos *produts = p;
	for(produts=p; produts!= NULL; produts = produts->prox)
	 {
	   if(produts->codigo == codProduto){
	   	return produts->precoVenda;
	   }
	 }
	 return 0;
}

void subtrairQuantidade(int codProduto, int quantidades){
	produtos *produts = p;
	for(produts=p; produts!= NULL; produts = produts->prox)
	 {
	   if(produts->codigo == codProduto){
	    produts->stockAt = produts->stockAt - quantidades;
	   }
	 }
}

void atualizarStock(int codProduto, int quantidades){
	produtos *produts = p;
	for(produts=p; produts!= NULL; produts = produts->prox)
	 {
	   if(produts->codigo == codProduto){
	    produts->stockAt = produts->stockAt + quantidades;
	   }
	 }
}
// Venda
void registaVenda(){
	int i, codigoVenda, codigoProdutos, quantidades, control;
	float total, totalProduto, preco;
	control = 0;
	char opv, data[10];
	int ultimoRegisto;
	total = 0;

	if(v == NULL)
	{
		ultimoRegisto = 0;
	}
	else
	{
		ultimoRegisto = codUltimaVenda();
	}
	printf("%d\n", ultimoRegisto);
	codigoVenda = ultimoRegisto +1;
	printf("%d\n", codigoVenda);
	opv = 'S';
	printf("%c\n", opv);
	do{
			printf("::: codigo do Produto--> ");
			scanf("%d", &codigoProdutos);

			if(procurarProduto(codigoProdutos) == 1){
				printf("::: quantidade--> ");
				scanf("%d", &quantidades);
				if(quantidades >= 1){

				}
				else
				printf("\t ERRO! -> Quantidade invalida\n");

				printf("::: Data DD/MM/AAAA --> ");
				scanf("%s", data);
				preco = getPreco(codigoProdutos);
				totalProduto = quantidades * preco;
				total = total + totalProduto;
				venda *novaVend = novaVenda(codigoVenda, codigoProdutos, quantidades, data, totalProduto);
				guardarVenda(novaVend);
					printf(":::Venda efetuada com sucesso:::\n");
				subtrairQuantidade(codigoProdutos, quantidades);
			}
			else{
				printf("\t ERRO! -> Este produto nao se encontra no Supermercado\n");
			}
				printf("\n\t---> Mais Produtos ? S / N:\n");
				scanf(" %c", &opv);

	} while(opv!='N' && opv!='n');
	printf("\t-----> Fatura <-----\n");
	vendaByCodigo(codigoVenda);
	printf("\t-----> Valor total pago : %2.f  <-----\n\n", total);

}

// pegar preco de compra
float getPrecoCompra(int codProduto){
	produtos *produts = p;
	for(produts=p; produts!= NULL; produts = produts->prox)
	 {
	   if(produts->codigo == codProduto){
	   	return produts->precoCompra;
	   }
	 }
	 return 0;
}
// void listar por data
void listarVenda(char data[]){
	venda *vAux= v;
	float precoCompra, valorCompra, lucro;
    printf(" %c---------------------------------------------------------------------------------------------------%c\n",201,187);
    printf(" |CodVenda\tCodProduto\tQuantidade\t  Data Venda\t Valor Venda\tPreco Compra\tLucro|\n");
    printf(" %c---------------------------------------------------------------------------------------------------%c\n",200,188);
	for(v=vAux; vAux!= NULL; vAux = vAux->prox)
	 {
	 	if(strcmp(vAux->data, data) == 0)
	 	{
	 		 precoCompra = getPrecoCompra(vAux->codprodutos);
	 		 valorCompra = vAux->quantidades * precoCompra;
	 		 lucro = vAux->total - valorCompra;
	 		 printf( " |%d \t\t    %d\t\t   %d\t\t  %s \t     %2.f$    \t%2.f$\t\t%2.f$ |\n", vAux->codigoVenda, vAux->codprodutos, vAux->quantidades, vAux->data, vAux->total, valorCompra, lucro);
	  		 printf(" %c---------------------------------------------------------------------------------------------------%c\n",200,188);
		 }
	 }
}

// eliminar produto

void eliminarProduto(int codProduto){
	produtos *produts = p;
	produtos *pr;
	while(produts->prox!= NULL && produts->prox->codigo != codProduto)
		produts = produts->prox;

	   	pr = produts->prox;
	   	produts->prox = pr->prox;
	   	free(pr);
}

// encomendas

void registaCompra(){
	int i, codigoCompra, codigoProdutos, quantidades, control, codFornecedor, codTipo, stMin, StMax, stMax;
	float precoUnitario, totalProduto, custo, total, precoVenda;
	char opv, data[10], nomeFornecedor[50], nomeProduto[50], marca[50];
	int ultimoRegisto;
	total = 0;

	if(p == NULL)
	{
		ultimoRegisto = 0;
	}
	else
	{
		ultimoRegisto = codUltimaCompra();
	}
	printf("%d\n", ultimoRegisto);
	codigoCompra = ultimoRegisto +1;
	printf("Compra numero:--> %d\n", codigoCompra);
	printf("::: Nome do Fornecedor--> ");
	scanf("%s", nomeFornecedor);
	codFornecedor = procurarFornecedor(nomeFornecedor);
	if(codFornecedor != 0){
		printf("\t O Fornecedor esta registado na lista\n");
	}
	else{
		char morada[40];
		int telefone;
		printf("\t Por favor preenche o cadastro do fornecedor:\n");
		printf("\t Codigo do Fornecedor (numero):\n");
		scanf("%d", &codFornecedor);
		printf("\t Morada:\n");
		scanf("%s", morada);
		printf("\t Telefone:\n");
		scanf("%d", &telefone);
		//encomenda *enco;
		fornecedor *Fn = novoFornecedor(codFornecedor, morada, nomeFornecedor, telefone);
		guardarFornecedor(Fn);
		printf("\t---> Fornecedor Registado com sucesso <---\n");
	}

	do{
			printf("::: codigo do Produto--> ");
			scanf("%d", &codigoProdutos);
			printf("::: quantidade--> ");
			scanf("%d", &quantidades);
			if(quantidades >= 1){

			}
			else
				printf("\t ERRO! -> Quantidade invalida\n");

			printf("::: Preco Unitario--> ");
			scanf("%f", &precoUnitario);
			custo = precoUnitario * quantidades;
			total = total + custo;
			printf("::: Data DD/MM/AAAA --> ");
			scanf("%s", data);

				/*preco = getPreco(codigoProdutos);
				totalProduto = quantidades * preco;
				total = total + totalProduto;
				*/
			encomenda *novaEnc = novaEncomenda(codigoProdutos, data, quantidades, custo);
			guardarEncomenda(novaEnc);
			printf(":::Encomenda Registada com sucesso:::\n");
			//subtrairQuantidade(codigoProdutos, quantidades);
			printf("\t:::Dados do produto:::\n");
			if(procurarProduto(codigoProdutos) == 1){
				printf("\t:>> O produto ja esta registado na Lista <<:\n");
				printf("\t... Foi atualizado o stock no inventario <<:\n");
				atualizarStock(codigoProdutos, quantidades);
			}
			else
			{
				printf("::: Nome do Produto --> ");
				scanf("%s", nomeProduto);
				printf("::: Marca do Produto --> ");
				scanf("%s", marca);
				printf("::: Codigo do Tipo --> ");
				scanf("%d", &codTipo);
				printf("::: Preco de venda --> ");
				scanf("%f", &precoVenda);
				printf(":::Stock Minimo --> ");
				scanf("%d", &stMin);
				printf("::: Stock Maximo --> ");
				scanf("%d", &stMax);

				produtos *novoProd = novono(codigoProdutos, nomeProduto, marca, codTipo, precoVenda, precoUnitario, codFornecedor, stMin, stMax, quantidades);
	  			guardarProduto(novoProd);
			}
				compra *comp = novaCompra(codigoCompra, codigoProdutos, quantidades, codFornecedor, data, custo);
				guardarCompra(comp);
				printf("\n\t---> Mais Produtos ? S / N:\n");
				scanf(" %c", &opv);

	} while(opv!='N' && opv!='n');
	printf("\t-----> Fatura da Compra <-----\n");
	printf("\t-----> Valor total pago : %2.f  <-----\n\n", total);

}

