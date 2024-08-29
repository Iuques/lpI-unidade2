# Projeto da Unidade 2 de LPI - Lista Encadeada

Este projeto implementa uma lista encadeada genérica usando tipos abstratos de dados (TAD), feito para a disciplina de Linguagens de Programação I (LPI). O usuário pode interagir com a lista encadeada por meio de um menu que oferece as seguintes operações: adicionar, remover, mostrar e ordenar elementos.

## Descrição do Projeto

O programa permite ao usuário escolher o tipo de dado da lista encadeada por meio de um parâmetro posicional. Os tipos de dados disponíveis são:
- `int`
- `float`
- `char`
- `string`

Depois de selecionar o tipo de dado, o programa exibe um menu com as seguintes operações:
1. **Adicionar**: Adiciona um elemento à lista encadeada.
2. **Remover**: Remove um elemento da lista encadeada.
3. **Mostrar**: Exibe todos os elementos da lista encadeada.
4. **Ordenar**: Ordena os elementos da lista encadeada.

## Como Executar

1. **Compile o programa**:
   Use o comando `make` para compilar o programa. Certifique-se de estar no diretório do projeto onde o `Makefile` está localizado.
   
   ```bash
   make
   ```
2. **Execute o programa**: Após a compilação, execute o programa passando o tipo de dado desejado como parâmetro posicional. Por exemplo:
   
   ```bash
   ./Main int
   ```
   Ou para outros tipos de dados:
   
   ```bash
   ./Main float
   ./Main char
   ./Main string
   ```
3. **Interaja com o Menu**: Após a execução, o programa exibirá um menu onde você pode escolher a operação desejada.

## Observações
- Certifique-se de fornecer o tipo de dado correto como parâmetro posicional.
- A ordenação é realizada usando um critério de comparação padrão. Para tipos personalizados, a função de comparação pode ser ajustada conforme necessário.
