#include "Client.h"
#include <iostream>
#include <locale>

using namespace std;

Client::Client()
{
    dinheiro = 0;
    menu();
}

void Client::menu()
{
	setlocale(LC_ALL, "portuguese");
    int operacao = 0;
    
    cout << "\t********** ECP BANK **********\n\n";

    do{
        cout<<"0 - Sair do Sistema [x]" <<endl;
        cout<<"1 - Realizar consulta de saldo em conta! [%]" <<endl;
        cout<<"2 - Depositar dinheiro [$] " <<endl;
        cout<<"3 - Sacar dinheiro [*]" <<endl;
        cin >> operacao;

        acao(operacao);

    }while(operacao);
}

void Client::acao(int operacao)
{
    switch(operacao)
    {
        case 0:
                cout << "Sistema encerrado!"<<endl;
                break;
        case 1:
                verSaldo();
                break;

        case 2:
                depositarDinheiro();
                break;

        case 3:
                sacarDinheiro();
                break;

        default:
                cout << "Opção inválida! Por favor, digite uma opção válida!\n" <<endl;
    }

}

void Client::verSaldo()
{
    cout<<"\nSeu saldo atual é: R$" << dinheiro <<endl;
}

void Client::depositarDinheiro()
{
    double valor;

    cout<< "Valor que deseja depositar: ";
    cin >> valor;

    if(valor > 0){
        dinheiro = dinheiro + valor;
        verSaldo();
    }
    else
        cout<< "Valor inválido! Por favor, tente novamente!\n" <<endl;

}

void Client::sacarDinheiro()
{
    double valor;

    cout<< "Digite o valor que deseja sacar: ";
    cin >> valor;

    if(valor <= dinheiro){
        dinheiro = dinheiro - valor;
        verSaldo();
    }
    else
        cout<<"Saldo insuficiente! Por favor, adicione saldo à conta para realizar esta operação!\n" <<endl;
}
