
#include <iostream>
#include "../include/JogoDaForca.h"

using namespace std;


int main(int argc, char const *argv[])
{
    // Se não houver argumentos sair e solicitar arquivo de entrada
    if (argc < 2)
    {
        cout << "Não há arquivo de entrada" << endl;
        return 0;
    }

    // Exibir 2 opções (exibir pontuações anteriores e jogar novo jogo)
    cout << "1 - Jogar novo jogo" << endl;
    cout << "2 - Exibir pontuações anteriores" << endl;

    // Ler opção
    int opcao;
    cin >> opcao;

    // Se opção for 1, jogar novo jogo
    if (opcao == 1)
    {
        JogoDaForca jogo;
        jogo.carregarPalavras(argv[1]);
        
        char letra_chute;
        jogo.proximaPalavra();
        while (jogo.getEstado() == jogo.EM_ANDAMENTO)
        {
            jogo.mostrarJogo();
            jogo.perguntaChute(&letra_chute);
            jogo.chutar(letra_chute);
            if(jogo.verificaEstado())
                jogo.proximaPalavra();
        }
        // Pergunta ao usuario o seu nome e salva a pontuação atual no arquivo pontuacoes.txt
        string nome;
        cout << "Digite seu nome: ";
        cin >> nome;
        jogo.salvarPontuacao(nome);
        cout << "Fim de jogo" << endl;
    }
    // Se opção for 2, exibir pontuações anteriores
    else if (opcao == 2)
    {
        // Lê o arquivo pontuacoes.txt e imprime linha por linha
        ifstream arquivo("pontuacoes.txt");
        string linha;
        while (getline(arquivo, linha))
        {
            cout << linha << endl;
        }  
    }
    return 0;
}


