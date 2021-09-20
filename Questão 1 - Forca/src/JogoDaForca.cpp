#include "../include/JogoDaForca.h"
#include <iostream>
using namespace std;


JogoDaForca::JogoDaForca() {
    // Inicializa o jogo com 6 tentativas, com o estado inicial de "EM_ANDAMENTO", pontuacao 0 e palavra como a primeira.
    tentativas = 6;
    indice_palavra_atual = -1;
    pontuacao = 0;
    estado = EM_ANDAMENTO;
}

void JogoDaForca::carregarPalavras(string nome_arquivo) {
    // Lê o arquivo recebido e adiciona cada linha (palavra) ao vetor de palavras
    ifstream arquivo(nome_arquivo);
    string palavra;
    
    while (getline(arquivo, palavra))
        palavras.push_back(palavra);
    
}

void JogoDaForca::chutar(char letra) {
    // Percore a palavra do vetor de palavras no indice atual e verifica se alguma letra é igual a recebida
    // Se for, adiciona a letra ao vetor de letras chutadas
    // Se não, diminui uma tentativa

    // Verifica se a letra já foi chutada
    bool letra_encontrada = false;
    for (int i = 0; i < palavraAtual().size(); i++) {
        if (tolower(palavraAtual()[i] )== tolower(letra)) {
            letra_encontrada = true;
            letras_chutadas.push_back(letra);
            letras_acertadas.push_back(i);
            pontuacao+=1;
        }
    }
    if (letra_encontrada == false){
        tentativas--;
        pontuacao--;;
    }
        

    // Verifica se a palavra foi completamente chutada
    if (letras_acertadas.size() == palavraAtual().size()){
        // Se sim adiciona a pontuação bônus
        // 3 caso não tenha nenhum erro
        // 2 caso contrário
        pontuacao += tentativas == 6 ? 3 : 2;
    }

    return;
}

int JogoDaForca::getEstado(){
    // Retorna o estado do jogo
    // 0 - Jogo finalizado
    // 1 - Jogo em andamento
    // 2 - Jogo finalizado com vitória
    // 3 - Jogo finalizado com derrota

    return estado;
}

void JogoDaForca::perguntaChute(char* letra){
    // Recebe a letra a ser chutada pelo usuário
    // Verifica se a letra já não foi chutada
    // Se não, armazena a letra na variável letra
    do
    {
        cout << "Digite uma letra: ";
        cin >> letra;
        if(find(letras_chutadas.begin(), letras_chutadas.end(), *letra) != letras_chutadas.end())
            cout << "Letra já chutada!" << endl;
    } while (find(letras_chutadas.begin(), letras_chutadas.end(), *letra) != letras_chutadas.end());
        
}

string JogoDaForca::palavraAtual() {
    // Retorna a palavra atual
    return palavras[indice_palavra_atual];
}

void JogoDaForca::mostrarJogo(){
    // Mostra o estado atual do jogo
    cout << "+=================== NOVA RODADA ===================+" << endl;
    cout << "Letras chutadas: " << formataVetorChar(letras_chutadas) << endl;
    cout << "Pontuação: " << pontuacao << endl;
    mostrarForca();
    cout << endl;
    mostrarPalavra();
    cout << endl;
}

void JogoDaForca::mostrarForca(){
    // Mostra a forca atual

    if(tentativas == 0)
        cout <<  "==============" << endl <<
                    "   |      _|_" << endl <<
                    "   |       O" << endl <<
                    "   |      /|\\" << endl <<
                    "   |      / \\" << endl <<
                    "   |"            << endl <<
                    "---------" << endl;
    else if(tentativas == 1)
        cout <<  "=============="<< endl <<
                    "   |      _|_"  << endl <<
                    "   |       O" << endl <<
                    "   |      /|\\" << endl <<
                    "   |      /" << endl <<
                    "   |" << endl <<
                    "---------" << endl;
    else if(tentativas == 2)
        cout <<  "==============" << endl <<
                    "   |      _|_"  << endl <<
                    "   |       O " << endl <<
                    "   |      /|\\" << endl <<
                    "   |           " << endl <<
                    "   |          " << endl <<
                    "---------" << endl;
    else if(tentativas == 3)
        cout <<  "==============" << endl <<
                    "   |      _|_"  << endl <<
                    "   |       O" << endl <<
                    "   |       |\\" << endl <<
                    "   |        " << endl <<
                    "   |" << endl <<
                    "---------" << endl;
    else if(tentativas == 4)
        cout <<  "=============="<< endl <<
                    "   |      _|_" << endl <<
                    "   |       O"<< endl <<
                    "   |       |"<< endl <<
                    "   |        "<< endl <<
                    "   |"<< endl <<
                    "---------" << endl;
    else if(tentativas == 5)
        cout <<  "==============" << endl <<
                    "   |      _|_ " << endl <<
                    "   |       O "<< endl <<
                    "   |          "<< endl <<
                    "   |          "<< endl <<
                    "   |            "<< endl <<
                    "---------" << endl;
    else if(tentativas == 6)
        cout <<  "=============="<< endl <<
                    "   |      _|_ "  << endl <<
                    "   |           "<< endl <<
                    "   |           "<< endl <<
                    "   |           "<< endl <<
                    "   |           "<< endl <<
                    "---------" << endl;



}

void JogoDaForca::mostrarPalavra() {
    // Percorre a palavra atual
    // Se o indice da letra não estiver no vetor de letras acertadas exibe um "_"
    // Se o indice da letra estiver no vetor de letras acertadas exibe a letra
    for (int i = 0; i < palavraAtual().size(); i++) {
        if (find(letras_acertadas.begin(), letras_acertadas.end(), i) != letras_acertadas.end())
            cout << palavraAtual()[i];
        else
            cout << "_";
        cout << " ";

    }
}

void JogoDaForca::proximaPalavra() {
    indice_palavra_atual++;
    tentativas = 6;
    letras_chutadas.clear();
    letras_acertadas.clear();
}

bool JogoDaForca::verificaEstado() {
    // Verifica se a quantidade de letras acertadas é igual a quantidade de letras da palavra
    // Se sim, pergunta se o usuário deseja jogar novamente
    // Se o usuário desejar, reinicia o jogo
    // Se não, finaliza o jogo e define o estado como finalizado com vitória
    // Se a quantidade de letras não for igual, verifica se o usuário perdeu com tentativas acabadas
    bool nova_palavra = false;
    if (letras_acertadas.size() == palavraAtual().size()) {
        mostrarJogo();
        cout << "Parabéns! Você acertou a palavra!" << endl;
        palavras_acertadas.push_back(palavraAtual());
        // Verifica se ainda existem palavras na lista
        if (palavras.size() == indice_palavra_atual+1)
        {
                cout << "Parabéns! Você acertou todas as palavras!" << endl;
            estado = VITORIA;
        }
        else {
            cout << "Deseja jogar novamente? (S/N)" << endl;
            char resposta;
            cin >> resposta;
            if (resposta == 'N' || resposta == 'n'){
                estado = VITORIA;
                nova_palavra = false;
            }
            else if (resposta == 'S' || resposta == 's'){
                nova_palavra = true;
            }
        }
    }
    else if (tentativas == 0) {
        mostrarJogo();
        cout << "Você perdeu! A palavra era: " << palavraAtual() << endl;
        estado = DERROTA;
        nova_palavra = false;
    }
    return nova_palavra;
}

void JogoDaForca::salvarPontuacao(string nome) {
    // Salva a pontuação do usuário no arquivo pontuacoes.txt
    ofstream arquivo;
    // Abre o arquivo no modo de append
    arquivo.open("./data/pontuacoes.txt", ios::app);
    // Salva o nome do usuário e a pontuação no arquivo
    arquivo << nome << ";" << formataVetorString(palavras_acertadas) << ";" << pontuacao << endl;
}

string JogoDaForca::formataVetorString(vector<string> palavras) {
    string palavras_formatadas = "";
    for (int i = 0; i < palavras.size(); i++) {
        palavras_formatadas += palavras[i];
        if (i != palavras.size() - 1)
            palavras_formatadas += " ";
    }
    return palavras_formatadas;
}
string JogoDaForca::formataVetorChar(vector<char> letras) {
    string letras_formatadas = "";
    for (int i = 0; i < letras.size(); i++) {
        letras_formatadas += letras[i];
        if (i != letras.size() - 1)
            letras_formatadas += " ";
    }
    return letras_formatadas;
}