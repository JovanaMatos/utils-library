/**
 * Módulo com ultilitários gerais que integram a blibioteca EASY_STD.
 * 
 * Desenvolvido por Jovana e Phillipe

/**ARQUIVO CABEÇALHO => HEADER FILE
* CPP => C PreProcessor: Ferramenta que processa inslustrações começadas 
* com #, como, por exemplo. #include, #define, #ifdef, #ifndef, etc.
*/

#ifndef __EASY_UTILS_HPP__  // Verifica se o cabeçalho já foi incluído
#define __EASY_UTILS_HPP__  // Define o cabeçalho para evitar múltiplas inclusões

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>


namespace easy_std{
    /**
    * Exibe uma mensagem a solicitar a introdução de uma linha de texto
    * através da entrada padrão. Envia uma string introduzida para saida padrão.
    * */

    //O inline é para usar em arquivo de cabeçarios com definições de funções não gerando multiplas versões da funções
    inline std::string input(const std::string &msg)
    {
        std::cout << msg;
        std::string str;
        std::getline(std::cin, str);
        return str;
    }

    /**Converte um objecto do tipo parametrizado T numa string
    * Ultiliza as facilidades definidas em streem (#include <sstream>).
    * */
    template <typename T>
    std::string tostring(const T &t)
    {
        std::ostringstream ss; // é um cout porem não mostra no output
        ss << t;
        return ss.str(); // passa com string
    
    }

    /**
    * Especialização de tostring para std::vector
    *A string a devolver possui um formato "{elem1, elem2...}", onde
    *cada elem é um elemento do vector.
    */
    template <typename T> // Representa um tipo de dados
    std::string tostring(const std::vector<T> &vec)
    {
        std::ostringstream ss;
        ss << "{ ";
        if (vec.size() > 0)
        {
            ss << vec[0];
            for (auto i = 1; i < vec.size(); i++)
            {
                ss << ", " << vec[i];
            };
        }
        ss << " }";
        return ss.str();
    }

    /**
    * Especialização do tostring para sdt::list. A string devolvida possui
    * o mesmo formato que a desenvolvida pelo template para vectores.
    */
    template <typename T>
    std::string tostring(const std::list<T>& lis)
    {
        std::ostringstream ss;
        ss << "{ ";
        if (lis.size() > 0){
            auto iter = lis.begin();//interador = begin(list)
            ss << *iter ;
            for (++iter; iter != end(lis); ++iter)
            {
                ss << ", " << *iter;
            };
        }
        ss << " }";
        return ss.str();
    }


    /**Especialização de tostring para std:: map. A string devolvida possui
    * o formato "{chav1,chave2 => valor2,...}"
    */
    template <typename T, typename V>
    std::string tostring(const std::map<T, V>& mp){
        std::ostringstream ss;
        ss << "{ ";
        if (mp.size() > 0){
            auto iter = mp.begin();//interador = begin(list)
            ss << (*iter).first << " => " << (*iter).second ;
            for (++iter; iter != end(mp); ++iter)
            {
                ss << ", " << (*iter).first << " => " << (*iter).second ;

            };
        }
        ss << " }";
        return ss.str();
    }

    template <typename T, typename V>
    std::string tostring(const std::unordered_map<T, V>& mp){
        return tostring(std::map (mp.begin(),mp.end()));
    }

    /**
    * Converte um string para um objeto parametrizado T.
    * É lançada um excepção do tipo std::invalid_argument em caso de falha
    * na conversão. 
    * Utilizar as facilidades definidas em sstream (#include <sstream>)
    */ 
    template<typename T> 
    T convert(const std::string& str){
        std::istringstream iss(str);
        T item;
        if (!(iss >> item)){
            throw std::invalid_argument("Error: failed to convert "+ str);
        }
        
        return item;
    }

    /**
    * Estrutura de fotmatação da função 'easy_std::print','sep' é um delimitador ultilizado para separa os elementos da 
    * coleção a se exibida pela dunção 'easy_std::print'. 'end' é um terminador.
    */
    struct print_params {
        std::string sep{" "};
        std::string end{"\n"};
    };

    /**
    * Escreve em 'out' os elemnetos de uma coleção. Separa os elementos
    * com string 'prin_params::sep' e termina com 'print_params::end'.
    */
    template<typename Container>
    void print(const Container& cont, std::ostream& out, const print_params& p = print_params()) {
        if (cont.size() > 0){
            auto iter = begin(cont);
            out << *iter;

        for (++iter; iter != end(cont); ++iter) {
                out << p.sep << *iter;
            }
        }
        out << p.end;
    }
    
    /**
    * Escreve em 'std::cout' os elemnetos de uma coleção. Separa os elementos
    * com string 'prin_params::sep' e termina com 'print_params::end'.
    */
    template<typename Container>
    void print(const Container& cont, const print_params& p = print_params()) {
         print(cont, std::cout, p);
    }

    /**
     * Função para imprimir os elementos de um inicializador de lista.
     * Esta função utiliza a função de impressão para vetor, convertendo o inicializador de lista em um vetor.
     * @param il Lista inicializadora a ser impressa.
     * @param out Fluxo de saída onde os elementos serão impressos.
     * @param p Parâmetros de impressão opcionais.
     */
    template<typename T>
    void print(const std::initializer_list<T>& il, std::ostream& out, const print_params& p = print_params()) {
         print(std::vector<T>(il), out, p);
    }

    /**
     * Função para imprimir os elementos de uma lista inicializadora para a saída padrão.
     * Esta função utiliza a função de impressão para inicializador de lista, enviando a saída para std::cout.
     * @param ilist Lista inicializadora a ser impressa.
     * @param p Parâmetros de impressão opcionais.
     */
    template<typename T>
    void print(const std::initializer_list<T>& ilist, const print_params& p = print_params()) {
         print(ilist, std::cout, p);
         }


    /**
     * Escreve em 'out' os elemnetos de uma coleção. Separa os elementos
     * com string 'prin_params::sep' e termina com 'print_params::end'.
    */
    template<typename T, typename V>
    void print(const std::map<T, V>& map, std::ostream& out, const print_params& p = print_params()) {
         if (map.size()> 0){
            auto iter = begin(map);
            out << (*iter).first << " => " << (*iter).second;
            for (++iter; iter != end(map); ++iter) {
                out << p.sep << (*iter).first << " => " << (*iter).second;
            } 
         }
         out << p.end;
         }

    /**
     * Dado a sequência do tipo S (que devá ser um container),
     * contendo itens do tipo T, procura por item e desenvolve a sua posição,
     * caso este exita, -1 caso contrario. Procura a partir da posição start.
    */
    template<typename Sequence, typename T>
    int find_index(const Sequence& s, T item, int start = 0){
        auto start_it = begin(s) + start;
        auto it = std::find(start_it, end(s), item);
        return it != end(s) ? it - start_it : -1;
    }

    //Devolve true se o item está presente na coleção s.
    template<typename Container, typename T>
    bool in(const Container& s, T item){
        return std::find(begin(s), end(s), item) != end(s);
   }
    
    //Devolve true se o item está presente na lista de inicialização 'ilist' s.
    template<typename T>
    bool in(const std::initializer_list <T>& ilist, T item){
            return std::find(begin(ilist), end(ilist), item) != end(ilist);
    }

    //Devolve true se o item está presente no mapa 'map'.
    template<typename Key, typename Value>
        bool in(const std::map<Key, Value>& map, const Key& item) {
            return map.find(item) != map.end();
        }

    //Devolve true se o item está presente no mapa 'map'.
    template<typename Key, typename Value>
    bool in(const std::unordered_map<Key, Value>& map, const Key& item) {
        return map.find(item) != map.end();
    }

}

#endif