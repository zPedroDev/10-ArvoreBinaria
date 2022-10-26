#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* esq;
	NO* dir;
};

NO* raiz = NULL;

// headers
// estrutura principal
void menu();
void inicializar();
void inserir();
void exibir();
void exibirQuantidade();



// funcoes auxiliares Arvore
NO* insereArvore(NO* no, int valor);
NO* criaNO(int valor);
int elementosArvore(NO* no);
void exibirElementosArvore(NO* no);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Arvore";
		cout << endl << endl;
		cout << "1 - Inicializar Arvore \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Inserir elemento \n";
		cout << "4 - Exibir elementos \n";

		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:exibirQuantidade();
			break;
		case 3: inserir();
			break;
		case 4: exibir();
			break;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// provisório porque não libera a memoria usada pela arvore
	NO* raiz = NULL;
	
	cout << "Arvore inicializada \n";

}


void inserir()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	if (raiz == NULL) {
		raiz = criaNO(valor);
	}
	else {
		 insereArvore(raiz, valor);
	}


}

void exibirQuantidade() {
	cout << "Quantidade de elementos: " << elementosArvore(raiz) << endl;
	
}

void exibir() {
	exibirElementosArvore(raiz);
}


NO* criaNO(int valor)
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

NO* insereArvore(NO* no, int valor)
{
	if (no == NULL) {
		no = criaNO(valor);
		return no;
	}
	else if (valor <= no->valor) {
		no->esq = insereArvore(no->esq, valor);
		cout << "Inserido do lado esquerdo!" << endl;
	}
	else {
		no->dir = insereArvore(no->dir, valor);
		cout << "Inserido do lado direito!" << endl;
	}
	return no;
}

int elementosArvore(NO* no)
{
	if (no == NULL) {
		return 0;
	}

	return 1 + elementosArvore(no->esq) + elementosArvore(no->dir);
}

void exibirElementosArvore(NO* no)
{
	if (raiz == NULL) {
		cout << "Arvore vazia!";
		return;
	}
	if (no->esq != NULL) {
		cout << no->valor << endl;
		exibirElementosArvore(no->esq);
	} 
	if (no->dir != NULL) {
		cout << no->valor << endl;
		exibirElementosArvore(no->dir);
	}
}
