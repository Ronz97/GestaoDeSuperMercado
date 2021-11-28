#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct prod
{
	int codigo;
	char nome[40];
	char marca[40];
	int codigoTipo;
	float precoVenda;
	float precoCompra;
	int codFornecedor;
	int StockMin;
	int stockMax;
	int stockAt;
	struct prod * prox;
} produtos;
produtos *p;


typedef struct tipoprod
{
	int codigo;
	char nome[40];
	float iva;
	struct tipoprod * prox;
} tipoproduto;
tipoproduto *tp;

typedef struct enc
{
	int codigoProduto;
	char data[10];
	int quantidade;
	float custo;
	struct enc * prox;
} encomenda;
  encomenda *e;

typedef struct forn{
	int codigo;
	char nome[40];
	char morada[40];
	int telefone;
	//encomenda *ec;
	struct forn * prox;
} fornecedor;
fornecedor *f;

typedef struct ven
{
	int codigoVenda;
	int codprodutos;
	int quantidades;
	char data[10];
	float total;
	struct ven * prox;
} venda;
venda *v;

typedef struct comp
{
	int codigoCompra;
	int codprodutos;
	int quantidades;
	int codFornecedor;
	char data[10];
	float total;
	struct comp * prox;
} compra;
compra *c;
//Funções do Projecto
produtos *novono(int c, char nome[], char marca[], int codTipo, float prv, float prc, int codF, int stMin, int stMax, int stAt);
tipoproduto *novoTipo(int c, char nome[], float iva);
encomenda *novaEncomenda(int codP, char data[], int quantidade, float custo);
fornecedor *novoFornecedor(int cod, char morada[], char nome[], int telefone /*encomenda* e*/);
venda *novaVenda(int c, int codprodutos, int quantidades, char data[], float total) ;
compra *novaCompra(int c, int codprodutos, int quantidades, 	int codFornecedor, char data[], float total);
int MenuPrincipal();
int SubMenuEditaLista();
int procurarTipo(int codigo);
int codUltimaVenda();
int codUltimaCompra();
int procurarProduto(int codigo);
int procurarFornecedor(char nome[]);
void guardarTipoProduto(tipoproduto *novotipo);
void guardarProduto(produtos *novoProd);
void guardarVenda(venda *novaVenda);
void guardarCompra(compra *novaCompra);
void guardarEncomenda(encomenda *Encomend);
void guardarFornecedor(fornecedor *novoFornecdor);
void pedirDados();
void guardaficheiroprodutos();
void guardaficheiroVendas();
void guardaficheiroCompras();
void guardaficheiroFornecedores();
void listarProdutos();
void guardaficheirotipoprodutos();
void guardaficheiroEncomendas();
void carregarTipoProdutos();
void carregarProdutos();
void carregarVendas();
void carregarEncomendas();
void carregarCompras();
void carregarFornecedores();
void inventario(char nome[]);
void estatisticaFornecedor(int codFornecedor);
void vendaByCodigo(int codigo);
float getPreco(int codProduto);
void subtrairQuantidade(int codProduto, int quantidades);
void atualizarStock(int codProduto, int quantidades);
void registaVenda();
float getPrecoCompra(int codProduto);
void listarVenda(char data[]);
void eliminarProduto(int codProduto);
void registaCompra();

#endif // HEADER_H_INCLUDED
