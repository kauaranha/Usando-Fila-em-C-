#include <iostream>
#include <cstdlib> // para malloc e free

using namespace std;

struct Fila {
    int valor;
    Fila* prox;
};

Fila* inicio = nullptr; // primeiro elemento da fila
Fila* fim = nullptr;    // último elemento da fila
Fila* aux = nullptr;    // auxiliar

void mostra() {
    aux = inicio;
    cout << "-->Fila: \n\n";
    while (aux != nullptr) {
        cout << "Valor: " << aux->valor
            << " endereco: " << aux
            << " proximo: " << aux->prox << endl;
        aux = aux->prox;
    }
    cout << "\n";
}

void insere(int valor) {
    aux = (Fila*)malloc(sizeof(Fila));
    aux->valor = valor;
    aux->prox = nullptr;

    if (inicio == nullptr) {
        inicio = aux;
        fim = aux;
    }
    else {
        fim->prox = aux;
        fim = aux;
    }
    mostra();
}

void retira() {
    if (inicio == nullptr) {
        cout << "----Fila vazia-----\n";
        return;
    }
    aux = inicio;
    inicio = inicio->prox;
    free(aux);
    mostra();
}

Fila* busca(int valor) {
    Fila* pos = inicio;

    while (pos != nullptr) {
        if (pos->valor == valor)
            return pos;
        pos = pos->prox;
    }
    return nullptr;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int v;
    inicio = nullptr;
    fim = nullptr;
    aux = nullptr;
    v = 0;

    while (v != 5) {
        cout << "1 - insere\n";
        cout << "2 - remove\n";
        cout << "3 - busca\n";
        cout << "4 - mostra\n";
        cout << "5 - termina\n";
        cin >> v;

        if (v == 1) {
            cout << "Digite o valor: ";
            cin >> v;
            insere(v);
            v = 0;
        }

        if (v == 2) {
            retira();
            v = 0;
        }

        if (v == 3) {
            cout << "Digite o valor: ";
            cin >> v;
            aux = busca(v);
            if (aux != nullptr)
                cout << "---- Encontrado " << aux->valor << ".\n";
            else
                cout << "---- Não encontrado\n";
            v = 0;
        }

        if (v == 4) {
            mostra();
        }
    }
    return 0;
}