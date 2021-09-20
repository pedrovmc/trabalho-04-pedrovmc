#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class JogoDaForca {
      private:
        vector<string> palavras;
        int indice_palavra_atual;
        vector<int> letras_acertadas;
        vector<char> letras_chutadas;
        int tentativas;
        int pontuacao;
        int estado;
        vector<string> palavras_acertadas;
    public:
        JogoDaForca();
        void carregarPalavras(string nome_arquivo);
        void chutar(char letra);
        int getEstado();
        void perguntaChute(char* letra);
        string palavraAtual();
        void proximaPalavra();
        void mostrarJogo();
        void mostrarForca();
        void mostrarPalavra();
        bool verificaEstado();
        void salvarPontuacao(string nome);
        string formataVetorString(vector<string> vetor);
        string formataVetorChar(vector<char> vetor);
        enum {
            FINALIZADO,
            EM_ANDAMENTO,
            VITORIA,
            DERROTA,
        };
};

#endif