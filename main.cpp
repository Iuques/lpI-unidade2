#include <iostream>
#include <string>
#include "vetor.h"
#include "funcs.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Checa se os parâmetros foram passados corretamente
    if (argc != 2)
    {
        // Demonstra como executar o programa corretamente
        cerr << "Informe: " << argv[0] << " <datatype>" << endl;
        return 1;
    }

	// Checa o tipo de dados passado e inicializa o vetor de acordo
    string dataType = argv[1];
    if (dataType == "int")
    {
        Vetor<int> vetor;
        menu(vetor);
    }
    else if (dataType == "float")
    {
        Vetor<float> vetor;
        menu(vetor);
    }
    else if (dataType == "char")
    {
        Vetor<char> vetor;
        menu(vetor);
    }
    else if (dataType == "string")
    {
        Vetor<string> vetor;
        menu(vetor);
    }
    else
    {
        cerr << "Tipo de dado inválido: " << dataType << endl;
        return 1;
    }

    return 0;
}

