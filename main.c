#include <stdio.h>
#include <stdlib.h>
#include "HEADER.h"
int main()
{
    int op, ops, codFornecedor, codProduto;
	char nome[45], data[10];
	printf("*************************************************************** \n\n");
    printf("\t\t Gestao - Supermercados              \n\n");
    printf("***************************************************************\n");
    carregarTipoProdutos();
    carregarProdutos();
    carregarVendas();
    carregarFornecedores();
    carregarEncomendas();
    carregarCompras();
    do{
    	op = MenuPrincipal();
    	switch(op){
    		case 1:
    			{
    				printf("Opcao para Venda\n");
					registaVenda();
				}
				break;
			case 2:
				{
					registaCompra();
				}
				break;
			case 3:
				{
					printf(":::Nome do Produto::>\n");
					scanf("%s", nome);
					inventario(nome);
				}
				break;
			case 4:
				{
					printf(":::Codigo do Fornecedor::>\n");
					scanf("%d", &codFornecedor);
					estatisticaFornecedor(codFornecedor);
				}
				break;
			case 5:
				{
					// incompleto
					printf(":::Data da  Facturacao DD/MM/AAAA ::>\n");
					scanf(" %s", data);
					printf("\t:::Produtos vendidos no dia %s ::>\n", data);
					listarVenda(data);
				}
				break;
			case 6:
				{
					do{
						ops = SubMenuEditaLista();
						switch(ops){
							case 1:{
								pedirDados();
							} break;
							case 2:{
								listarProdutos();
							}break;
							case 3:{
								printf(":::Codigo do Produto a Eliminar::>\n");
								scanf("%d", &codProduto);
								if(procurarProduto(codProduto) == 1){
									eliminarProduto(codProduto);
									printf(":::Produto eliminado com sucesso::>\n");
								}
								else
								{
									printf(":::Erro: Este produto nao esta na lista :>\n");
								}

							}break;
							case 4:{
								printf("Voltando ao menu Principal\n");
							}break;
							default:
								printf("Opcao invalida\n");
							break;
						}
					}while(ops!=4);
				}
				break;
			case 7:
				{
					printf("Opcao para Ordena Lista Produtos\n");
				}
				break;
			case 8:
				{
					printf("Fechando Programa\n");
				}
				break;
			default:
				 printf("Opcao invalida\n");
				break;
		}
	} while(op!=8);
	listarProdutos();
	guardaficheiroprodutos();
	guardaficheirotipoprodutos();
	guardaficheiroEncomendas();
	guardaficheiroVendas();
	guardaficheiroFornecedores();
	guardaficheiroCompras();
}
