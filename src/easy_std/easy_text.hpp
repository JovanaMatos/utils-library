/**
 * Módulo com ultilitários gerais que integram a blibioteca EASY_STD.
 * 
 * Desenvolvido por Naiarana Silva e Suzana Dias
*/

/**ARQUIVO CABEÇALHO => HEADER FILE
* CPP => C PreProcessor: Ferramenta que processa inslustrações começadas 
* com #, como, por exemplo. #include, #define, #ifdef, #ifndef, etc.
*/

#ifndef __EASY_TEXT_HPP__ // Verifica se o cabeçalho já foi incluído
#define __EASY_TEXT_HPP__ // Define o cabeçalho para evitar múltiplas inclusões

#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>


namespace easy_std{
    
    //Devolve true se o caractere ch for um caractere de espaçamento.
    inline bool is_white_space(char ch){
         return ch == ' ' || ch == '\n' || ch == '\r' || ch ==  '\t';
    }
    
    
    //Devolve true se todos os caractere da string str forem de espaçamento
    inline bool is_white_space(const std::string& str){
        for (const char& ch: str){
         if (is_white_space(ch) == true){
            return true;
         }
        }
        return false;
    }

    
    //Devolve true se o caractere ch for um dígito decimal.
    
    inline bool is_digit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    //Devolve true se todos os caractere da string str forem dígitos
    inline bool is_digit(const std::string& str) {
    for (char ch : str) {
        if(is_digit(ch)) {
            return true;
        }
    }
    return false;
        } 
        
   
    //Converte uma letra maiúscula para minúscula
    inline char to_lower(char ch) {
        std::string newstr;
        const int x = 32; 
        if (ch >= 'A' && ch <= 'Z') {
            return ch = ch + x;
        }
         return ch;
        }

    
    //Converte uma letra maiúscula para minúscula
    std::string to_lower(const std::string& str) {
    std::string newstr;
    const int x = 32; // Valor para converter letras maiúsculas em minúsculas

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + x;
        }
        newstr += ch; 
    }
    return newstr; 
    }

    // Converte uma letra minuscula para maiusculas
    inline char to_upper(char ch) {
        std::string newstr;
        const int x = 32; 
        if (ch >= 'a' && ch <= 'z') {
            return ch = ch - x;
        }
            return ch;
    }

    //Converte uma letra minuscula para maiusculas
    std::string to_upper(const std::string& str) {
    std::string newstr;
    const int x = 32; 

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - x;
        }
        newstr += ch; 
    }
    return newstr; 
    }

    /**
    * Apara a string str à esquerda e devolve-a; implemente a versão complementar trim_right.
    * "Aparar" uma string à esquerda consiste em remover os caracteres de espaçamento à esquerda, que
    * estão entre o início da string e o primeiro caractere que não é de espaçamento. Esta função
    * modifca a string recebida, mas também devolve-a para que possa ser utilizada em expressões do
    * tipo string. Se a string não possuir caracteres de espaçamento à esquerda, então é simplesmente
    * devolvida.
    */
    inline std::string trim_left(const std::string &str) {
    std::string result(str);

    //Encontrando a posição do primeiro caractere não de espaço em branco
    auto first_not_space = std::find_if(result.begin(), result.end(), [](char ch) { return !std::isspace(ch); });

    //Removendo os espaços em branco à esquerda
    result.erase(result.begin(), first_not_space);

        return result;
    }
    
    //Apara a string str à direita devolvendo essa string.
    inline std::string trim_right(const std::string &str) {
    std::string result(str);

    //Encontrando a posição do último caractere não de espaço em branco
    auto last_not_space = std::find_if(result.rbegin(), result.rend(),[](char ch) { return !std::isspace(ch); }).base();

    //Removendo os espaços em branco à direita
    result.erase(last_not_space, result.end());

    return result;
    }

    //Apara a string str à esquerda e à direita devolvendo essa string.
    inline std::string& trim(std::string& str) {

    // Remove os espaços em branco à esquerda
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](char ch) { return !std::isspace(ch); }));

    // Remove os espaços em branco à direita
    str.erase(std::find_if(str.rbegin(), str.rend(), [](char ch) { return !std::isspace(ch); }).base(), str.end());

    return str;

    }

    
    //Inverte  a  string str  e  devolve-a. 
    inline std::string& reverse(std::string& str){
        for(int i= 0 , j = str.length() - 1; i< j; i+=1, j-= 1){
             std::swap(str[i] , str[j]); // swap troca um pelo outro
        }
        return str;

    }

    //Devolve uma cópia invertida da string 'str'. É de se notar que esta string não é modificada por esta função.
    inline std:: string reversed(const std::string& str){
        std::string new_str(str);
        easy_std::reverse(new_str);
        return new_str;
    
    }

    /**
    * Substitui todas as ocorrências do caractere ch1 pelo caractere ch2; devolve a string str.
    * Começa na posição dada por start e substitui até à posição dada por end. O valor -1 indica
    * que end deve ser a posição do último caractere.
    */
    inline std::string& replace(std::string& str, char ch1, char ch2, int start = 0, int end = -1){
        end = end == -1 ? str.length() - 1 : end;
        for (int i = start; i <= end; i += 1){
            if (str[i] == ch1){
                str[i] = ch2;
            }
        }
        return str;
    }

    /**
    * Versão Replace para Substrings.
    * Substitui em str todas as ocorrências da substring substr1 por substr2; 		
    * devolve a string str.
    */
    inline std::string& replace(
        std::string& str,
        const std::string& substr1,
        const std::string& substr2, 
        int start = 0,
        int end = -1)
        { end = end < 0 ? str.length()-1 : end;
        int advance_one = substr1.empty(); 
        int i = start;
        while ((i = str.find(substr1, i)) != std::string::npos) {
            str.replace(i, substr1.length(), substr2); 			 	
            i += substr2.length() + advance_one;
            end += substr2.length() - substr1.length() + advance_one;
            if (i >= end) {
                break;
            }
        }
        return str;
        }
 
    
    /** 
    * Função SPLIT() "Parte" uma string em pedaços delimitados por delim. Dada a string str com "ABC DEF GHI", e
    * delim igual a " " , a função split devolve um vector com {"ABC", "DEF", "GHI"}.
    */
    inline std::vector<std::string> split(const std::string& str, const std::string& delim){
        std::vector<std::string> vec;
        int k = 0;
        int i = 0;
        while ((i = str.find(delim, k)) != std::string::npos) {
            std::string s1 = str.substr(k, i - k);
            vec.emplace_back(s1);
            k = i + delim.length(); // Avançar para o próximo possível início de substring
            // Se houver delimitadores consecutivos, adiciona uma string vazia
            if (i == k) {
                vec.emplace_back("");
                k += delim.length(); // Avançar para além do próximo delimitador
            }
        }
        // Adiciona a substring final após o último delimitador
        std::string s1 = str.substr(k, str.length() - k);
        vec.emplace_back(s1);
        return vec;

    }

    /**
    * O oposto de split. "Une" as várias strings no vector parts com o delimitador delim e 
    * junta-as todas em uma só string.
    */
    inline std::string join(const std::vector<std::string>& parts, const std::string& delim) {
    if (parts.empty()) {
        return "";
    }

    std::string str = parts[0]; // Começa com o primeiro elemento

    for (int i = 1; i < parts.size(); ++i) {
        str += delim + parts[i]; // Adiciona o delimitador e o próximo elemento
    }

    return str;

  }

}
 


#endif