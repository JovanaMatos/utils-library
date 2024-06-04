

#ifndef __EASY_RANDOM_HPP__
#define __EASY_RANDOM_HPP__

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

namespace easy_std {

    // Definição da variável global
    static std::mt19937 rand_gen(std::random_device{}());
    
    // Função para gerar números inteiros aleatórios no intervalo [min, max]
    int random_int(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rand_gen);
    }
    
    // Função para gerar números reais aleatórios no intervalo [min, max]
    double random_real(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rand_gen);
    }
    
    // Função para definir a semente do gerador de números aleatórios
    void seed(int value) {
        rand_gen.seed(value);
    }
    
    // Função para escolher aleatoriamente um elemento de uma sequência
    template<typename Seq>
    Seq choice(const std::vector<Seq>& seq) { 
        static std::random_device randomizador;    
        static std::mt19937 rand_gen(randomizador());     
        std::uniform_int_distribution<> distro(0, seq.size() - 1);     
        return seq[distro(rand_gen)]; 
    }
    

    // Função para embaralhar elementos de uma sequência
    template<typename Seq>
    void shuffle_(Seq& seq) {
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Semeia o gerador de números aleatórios
        for (int i = seq.size() - 1; i > 0; --i) {
            int j = std::rand() % (i + 1); // Gere um índice aleatório
            if (i != j) {
                std::swap(seq[i], seq[j]); // Trocar elementos nos índices i e j
            }
        }
    }


   // Função para realizar amostragem aleatória de um contêiner
    template<typename T, typename Seq>
    std::vector<T> sample(const Seq& seq, int n) {
        std::vector<T> result(n);
        // Inicializando o gerador de números aleatórios
        std::random_device rd;
        std::default_random_engine rng(rd());
        // Realizando a amostragem
        std::sample(seq.begin(), seq.end(), result.begin(), n, rng);
        return result;
    }
}

#endif