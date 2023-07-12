# Estrutura de Diretórios

Este projeto tem a seguinte estrutura de diretórios:

*   doc: Contém documentação sobre o projeto, se houver.
*   lib: Contém bibliotecas externas utilizadas pelo projeto.
*   src: Contém os arquivos fonte (.cpp) do projeto.
*   bin: Contém os arquivos executáveis gerados pelo projeto.
*   include: Contém os arquivos de cabeçalho do projeto (.h).
*   test: Contém os arquivos de teste da aplicação. 

# Arquivo Makefile
Este projeto também inclui um arquivo Makefile, um tipo de arquivo que é consumido pelo comando "make" e que define regras de como os arquivos fontes devem ser compilados e linkados para produzir um executável final. 

Ao executar o comando "make", o programa make verifica as dependências e, se houver alterações em arquivos fontes ou outras dependências, as regras serão executadas para atualizar o executável final. Desta forma, é possível automatizar os processo de compilação e construção (build). 

Além disso, o makefile permite a criação de comandos personalizados, como "make clean" para excluir arquivos temporários ou "make run" para executar o programa compilado.

Neste projeto, as diretivas que o usuário pode passar ao comando "make" são:

*   all: Compila o programa principal e os arquivos de teste, criando os executáveis "bin/main" e "bin/test".
*   test: Compila apenas os arquivos de teste, criando o executável "bin/test".
*   run-test: Executa o arquivo "bin/test".
*   run: Executa o arquivo "bin/main".
*   clean: Remove todos os arquivos objeto e executáveis gerados pelo makefile.

As variáveis definidas no início do makefile deste projeto incluem:

*   CC: Especifica o compilador a ser usado (g++).
*   CFLAGS: Especifica as opções de compilação a serem usadas.
*   SOURCES: Lista todos os arquivos fonte da aplicação, isto é, todos arquivos .cpp na pasta "src".
*   OBJECTS: Lista todos os arquivos objeto da aplicação, isto é, todos arquivos objeto correspondentes aos arquivos .cpp em "SOURCES".
*   EXECUTABLE: Especifica o nome do executável principal.
*   TEST_SOURCES: Lista todos os arquivos fonte do teste executável, isto é, todos os arquivos .cpp na pasta "src" e "test", exceto o arquivo "src/main.cpp".
*   TEST_OBJECTS: Lista todos os arquivos objeto do teste executável, isto é, todos arquivos objetos correspondentes aos arquivos .cpp em "TEST_SOURCES".
*   TEST_EXECUTABLE: Especifica o nome do teste executável.

As regras definidas pelo makefile incluem:

*   $(EXECUTABLE): Compila os arquivos objeto em "OBJECTS" para criar o executável "bin/main".
*   $(TEST_EXECUTABLE): Compila os arquivos objeto em "TEST_OBJECTS" para criar o executável "bin/test".
*   %.o: Compila os arquivos .cpp em arquivos objeto.
