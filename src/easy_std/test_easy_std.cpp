//agora uma definição é tbm uma declaração
    #include <vector>
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <map>
    #include <unordered_map>
    #include <fstream>
    #include <list>
    #include <algorithm>
    #include <cctype>
    #include <random>
    #include <cstdlib>
    #include <ctime>
    #include <locale.h>  // Biblioteca para lidar com acentuações e caracteres especiais.

    #include "easy_utils.hpp"
    #include "easy_text.hpp"
    #include "easy_random.hpp"


    using namespace std;
    using namespace easy_std;

    //Declaração dos protótipos das funções de teste
    void test_easy_utils();
    void test_easy_text();
    void test_easy_random();


    int main(){
        // Ajusta a configuração de localidade para suportar acentuação em palavras.
        setlocale(LC_ALL, "portuguese");
        setlocale(LC_ALL, "pt_BR.UTF-8"); //Para ser usado na Máquina Virtual

        // Chama as funções de teste
        test_easy_utils();
        test_easy_text();
        test_easy_random();


     return 0;

    }

    //Função de teste para o módulo de números aleatórios.
    void test_easy_random(){
        
        cout <<"\n************** RAND_INT ********************\n\n"; 
            // Exemplo de uso das funções INTEIRO
        cout << "Número inteiro aleatório entre 1 e 10: " << random_int(1, 10) << endl;

        cout <<"\n************** RAND_REAL ********************\n\n"; 
        // Exemplo de uso das funções DOUBLE
        cout << "Número real aleatório entre 0 e 1: " << random_real(0.0, 1.0) << endl;

        cout <<"\n************** SEED ********************\n\n"; 
        // Definindo a semente do gerador de números aleatórios
        seed(3);
        cout << "Após a semente ser definida como 3: " << rand_gen() << '\n';

        cout <<"\n************** CHOICE ********************\n\n"; 
        // Escolhendo aleatoriamente em vetor de inteiros
        vector<int> numeros_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
        cout << "Escolha aleatória entre: " << choice(numeros_array) << '\n';

        // Escolhendo aleatoriamente em vetor de doubles
        vector<double> double_array = {1.4, 2.2, 3.5, 4.8, 9.5};
        cout << "Escolha aleatória entre: " << choice(double_array) << '\n';

        // Escolhendo aleatoriamente em vetor de strings
        vector<string> textos = {"Fernanda", "Maria", "Jovana", "Naiarana", "Suzana", "Pedro"};
        cout << "Escolha aleatória entre: " << choice(textos) << '\n';

        cout <<"\n************** SHUFFLE ********************\n\n"; 
        
       vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
        cout << "Antes de embaralhar: ";
        for (const auto& num : nums) {
            cout << num << " ";
        }
        cout << endl;
        
        shuffle_(nums);
        
        cout << "Depois de embaralhar: ";
        for (const auto& num : nums) {
            cout << num << " ";
        }
        cout << endl;


        cout <<"\n************** SAMPLE ********************\n\n"; 
        vector<int> seq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int n = 5;
        vector<int> sampled = sample<int>(seq, n);
        cout << "Amostra de " << n << " valores: ";
        for (int val : sampled) {
            cout << val << " ";
        }
        cout << endl;
    }

    //Função de teste para o módulo de manipulação de texto.
    void test_easy_text(){

    cout<<"\n*******************************************\n";
    cout<<"    INICIO DOS TESTES DO MODULO EASY_TEXT\n";
    cout<<"*******************************************\n";

    cout <<"\n************** IS_WHITE_SPACE ********************\n\n";
    cout << std::boolalpha; 

    cout << "is_white_space(' ') => " << is_white_space(' ') << endl;
    cout << "is_white_space('X') => " << is_white_space('X') << endl;
    cout << "is_white_space('Antonio\\n') => " << is_white_space("Antonio\n") << endl;
    cout << "is_white_space('Carlos') => " << is_white_space("Carlos") << endl;

    cout <<"\n************** IS_DIGIT ********************\n\n"; 

    cout << "is_digit('2') => " << is_digit('2') << endl;
    cout << "is_digit('X') => " <<is_digit('X') << endl;
    cout << "is_digit('Ano2.024') => " << is_digit("Ano2.024") << endl;
    cout << "is_digit('2.3') => " << is_digit("2.3") << endl;
    cout << "is_digit('Casa') => " << is_digit("Casa") << endl;

    cout <<"\n************** TO_LOWER ********************\n\n"; 

    cout << " to_lower('H') => " << to_lower('H') << endl;
    cout << " to_lower('X') => " << to_lower('X') << endl;
    cout << " to_lower('ARMANDO') => " << to_lower("ARMANDO") << endl;
    cout << " to_lower('AntoNio') => " << to_lower("AntoNio") << endl;

    cout <<"\n************** TO_UPPER ********************\n\n"; 

    cout << " to_upper('j') => " << to_upper('H') << endl;
    cout << " to_upper('a') => " << to_upper('X') << endl;
    cout << " to_upper('ana santos') => " << to_upper("ana santos") << endl;
    cout << " to_upper('sonia') => " << to_upper("sonia") << endl;

    cout <<"\n************** TRIM_LEFT ********************\n\n"; 

    string nome = "     Carla Dias    ";
    string nome1 = "  Antonio  ";

    cout << " trim_left('   Carla Dias   ') => " << trim_left(nome) << endl;
    cout << " trim_left('  Antonio  ') => " << trim_left(nome1) << endl;

    cout <<"\n************** TRIM_RIGTH ********************\n\n";

    int num = 40;
    string nome3 = "Armando Souza    ";
    string nome4 = "  Ana  ";

    cout << " trim_left('Armando Souza  ' << 40) => " << trim_right(nome3) << num << endl;
    cout << " trim_left('  Ana  ' << 40) => " << trim_right(nome4) << num << endl;

    cout <<"\n*********************** TRIM *************************\n\n";

    string nome5 = "  Joao Souza    ";
    string nome6 = "  Sandra  ";

    cout << " trim_left('  Joao Souza   ' << 40) => " << trim(nome5) << num << endl;
    cout << " trim_left('  Sandra ' << 40) => " << trim(nome6) << num << endl;

    cout <<"\n************** REVERSE ********************\n\n";                        

    string txt ("ABCDEF");

    cout << "txt: " << txt << endl;
    cout << "reverse(txt) => ";
    reverse(txt);
    cout << txt << endl;

    cout << "txt: " << txt << endl;
    cout << "reverse(txt) => " << reverse(txt) << endl;
    cout << "txt: " << txt << endl;
    cout << endl;

    cout << "\n*************** REVERSED *********************\n\n";
    string txt2("ABCDEF");

    cout << "txt2: " << txt << endl;
    cout << "reversed(txt2) => " << reversed(txt2) << endl;
    cout << "txt2:" << txt <<endl;
    cout << endl;

    cout << "\n*************** REPLACE *********************\n\n";
    string name1 = "ana avelar";
    cout << "name1: " << name1 << "          ";
    cout << "replace(name1, 'a', 'A')       => " << replace(name1, 'a', 'A') << endl;

    name1 = "ana avelar";
    cout << "name1: " << name1 << "          ";
    cout << "replace(name1, 'a', 'A', 4)   => " << replace(name1, 'a', 'A', 4) << endl;

    name1 = "ana avelar alves";
    cout << "name1: " << name1 << "    ";
    cout << "replace(name1, 'a', 'A', 4, 9) => " << replace(name1, 'a', 'A', 4, 9) << endl;

    name1 = "ana avelar";
    cout << "name1: " << name1 << "          ";
    cout << "replace(name1, 'b', 'A')       => " << replace(name1, 'b', 'A') << endl;


    cout << "\n*************** REPLACE substrings ***************\n\n"; 
    string nome2 = "ana mariana";
    cout << "nome2: " << nome2 << "      " ;
    cout << R"(replace (nome2, "ana", "ANA") => )" << replace(nome2, "ana", "ANA") << endl;

    nome2 = "ana mariana";
    cout << "nome2: " << nome2 << "      " ;
    cout << R"(replace (nome2, "ana", "anabela") => )" << replace(nome2, "ana", "anabela") << endl;

    nome2 = "ana mariana";
    cout << "nome2: " << nome2 << "      " ;
    cout << R"(replace(nome2, "ana", "anabela", 2) =>)" << replace(nome2, "ana", "anabela", 2) << endl;

    nome2 = "ana mariana";
    cout << "nome2: "<< nome2 << "      " ;
    cout << R"(replace (nome2, "ana", "anabela", 0, 3) -=> )" << replace(nome2, "ana", "anabela", 0, 3) << endl;

    nome2 = "diana mariana";
    cout <<"nome2: " << nome2 << "      " ;
    cout << R"(replace(nome2, "ana", "") => )"<<replace(nome2, "ana", "") << endl;

    nome2 = "ALBERTO";
    cout << "nome2: " << nome2 << "      " ;
    cout << R"(replace(nome2, "","--")  => )" ;
    cout<<replace(nome2, "","--") ;

    nome2 = "ALBERTO" ;
    cout << "nome2: " << nome2 << "      " ;
    cout << R"(replace(nome2,"", "")  => )";cout << replace(nome2,"","") << endl;

    cout << "\n*************** SPLIT substrings ***************\n\n"; 
    string str = "ABC.DEF.GHI";
    cout<<"str: " << str << endl;
    cout <<R"(split(str, ".") =>)" << tostring(split(str, ".")) << endl; cout << R"(split(str, "+") =>)" << tostring(split(str, "+")) <<endl; 
    cout << endl;
    str = "ABC.DEF...GHI";
    cout << "str: "<< str << endl;
    cout <<R"(split(str, ".") =>)" <<tostring(split(str, ".")) << endl; cout << endl;
    str = ".ABC.DEF.GHI.";
    cout << "str: "<< str << endl;
    cout << R"( split(str, ".") =>)" << tostring(split(str, "."))<<endl; cout << endl;
    str = "ABC--DEF--GHI";
    cout << "str: " << str << endl;
    cout << R"( split(str, "--") =>)" << tostring(split(str, "--")) <<endl; 
    cout << endl;
    str = "-ABC---DEF--GHI-";
    cout << "str: "<< str << endl;
    cout << R"(split(str,"--") =>)" << tostring(split(str, "--")) << endl; cout << endl;
    str = "ABCDEF";
    cout << "str: "<< str << endl;
    cout << R"(split(str," ") =>)" << tostring(split(str, " ")) << endl; 
    cout << endl;  

    cout << "\n*************** JOIN ***************\n\n";

    vector<string> parts = {"ABC", "DEF", "GHI"};
    cout << R"(join({"ABC", "DEF", "GHI"}, "+") => )" << join(parts, "+") << endl;
    vector<string> parts1 = {"ABC"};
    cout << R"(join({"ABC", ".") => )" << join(parts1, ".") << endl;
    vector<string> parts2 = {"ABC", "DEF"};
    cout << R"(join({"ABC", "DEF", ".") => )" << join(parts2, ".") << endl;
    string parts3 = "ABC.DEF.GHI";
    cout << R"(join(split({"ABC", "DEF", "+")) => )" << join(split(parts3, "."), "+") << endl;                    

    cout<<"\n*******************************************\n";
    cout<<"       FIM DOS TESTES DO MODULO EASY_TEXT    \n";
    cout<<"*********************************************\n";

    }

    //Função de teste para o módulo de utilidades fáceis.
    void test_easy_utils(){

    cout<<"\n*******************************************\n";
    cout<<"    INICIO DOS TESTES DO MODULO EASY_UTILS   \n";
    cout<<"*********************************************\n";

    cout<<"\n************ INPUT ************\n\n";
    string name1 = input ("Como se chama? ");
    cout << "name1 => "<< name1 << endl;

    cout<<"\n************ TO_STRING ************\n\n";
    int  valor1 = 1597;
    cout<< "valor1: " << valor1 << " => "<< "tostring(valor1) => " << tostring(valor1) << endl;    

    double  valor2 = 72.89;
    cout<< "valor2: " << valor2 << " => "<< "tostring(valor2) => " << tostring(valor2) << endl;  

    string  valor3 = "TESTE";
    cout<< "valor3: " << valor3 << " => "<< "tostring(valor3) => " << tostring(valor3) << endl;  


    cout << "\nVECTORES\n";

    vector <int> vec1A {10,20,30};
    cout<< "vec1A: vector <int> {10,20,30} | tostring (vec1A) => " << tostring(vec1A) << endl;  

    vector <int> vec1B {10};
    cout<< "vec1B: vector <int> { 10 } | tostring (vec1B) => " << tostring(vec1B) << endl;  

    vector <int> vec1C;
    cout<< "vec1C: vector <int> {} | tostring (vec1C) => " << tostring(vec1C) << endl;  

    vector <double> vec1D = {7.14};
    cout<< "vec1D: vector <double> {7.14} | tostring (vec1D) => " << tostring(vec1D) << endl;  

    vector <string> vec1E = {"abc", "def", "ghi"};
    cout<< R"(vec1E: vector <string> {"abc", "def", "ghi"} | )" << "tostring (vec1E) =>) " << tostring(vec1E) << endl; 

    cout <<"\n LISTAS\n";

    list <int> lista1 {10,20,30};
    cout<< "lista1: list <int> {10,20,30} | tostring (lista1) => " << tostring(lista1) << endl;  


    cout<<"\nMAPAS\n";

    map<string, int> idades1{
        {"Alberto", 31},
        {"Armando", 19},
        {"Arnaldo", 44}

    };

    cout << "idades1: map<string, int>{{Alberto, 31}, ...} =>\n" << tostring(idades1) << endl;


    map<string, int> idades2{
        {"Alberto", 31},
        {"Armando", 19},
        {"Arnaldo", 44}

    };

    cout << "idades2: unordered_map<string, int>{{Alberto, 31}, ...} =>\n" << tostring(idades2) << endl;

    cout<<"\n************ CONVERT ************\n\n";

    auto x = convert<int>("289");
    cout<< R"(convert<int>("289") => )" << x << endl;

    auto y = convert<double>("2.89");
    cout<< R"(convert<double>("2.89") => )" << y << endl;

    try{
        convert<int>("Armando");
    }
    catch( invalid_argument& ex){
        cout << "Excepção em convert taL como esperado => " << ex.what() << endl;
    }

    auto age = convert<int>(input("How old are you? "));
    cout<< "You are " << age << " years old." << endl;

    cout<<"\n************ PRINT ************\n\n";

    vector<double> vec5{10, 2.5, 12, -300, -2.78, 0, 450};
    cout<< "prints(vec5))\n    ";
    print(vec5);

    cout << "prints(vec5, {.sep = \"/\"})\n    ";
    print(vec5, {.sep = "/"});

    cout << "prints(vec5, {.end = \"$\"})\n    ";
    print(vec5, {.end = "$\n"});

    ofstream file("dados.txt");
    print(vec5, file, {.sep = ", "});


    print({"alberto", "armando", "arnaldo"}, {.sep = ".", .end = " <=\n"});

    cout <<"\n****************** FIND ********************\n\n";

    vector<int> vals{-5, 10, 31, 55, 10, 44};
    cout << "vals: ";print(vals);
    cout << "     find_index(vals, 10)     => " << find_index(vals, 10) << endl;
    cout << "     find_index(vals, 10, 2)  => " << find_index(vals, 10, 2) << endl;
    cout << "     find_index(vals, -10)    => " << find_index(vals, -10) << endl;
    cout << endl;

    cout << R"(find_index("Alberto"s, 'b') =>  )" << find_index("Alberto"s, 'b') << endl;

    cout << "\n*************** IN ********************\n\n" << std::boolalpha;

    cout << "vals: ";print(vals);
    cout << "     in(vals, 10)   => " << in(vals, 10) << endl;
    cout << "     in(vals, 55)   => " << in(vals, 55) << endl;
    cout << "     in(vals, -10)  => " << in(vals, -10) << endl;
    cout << endl;

    cout << R"(in("Alberto"s, 'b' ) => )" << in("Alberto"s, 'b') << endl;
    cout << R"(in({"ana", "bruno", "ze"}, "bruno" ) => )" << in({"ana", "bruno", "ze"}, "bruno" ) << endl;

    map<string, int> portos = {{"http"s, 80}, {"ftp"s, 21}, {"telnet"s, 25}};
    cout << "portos: "; print(portos);
    cout << R"(in(portos, "ftp"s) => )" << in(portos, "ftp"s) << endl;
    cout << R"(in(portos, "smtp"s) => )" << in(portos, "smtp"s) << endl;


    cout<<"\n*******************************************\n";
    cout<<"     FIM DOS TESTES DO MODULO EASY_UTILS     \n";
    cout<<"*********************************************\n";


}






