# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Nome do arquivo executável
TARGET = grafo

# Lista de arquivos fonte
SRC = Grafo.c

# Regra padrão para compilar o programa
all: $(TARGET)

# Regra para compilar o arquivo fonte e gerar o executável
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Regra para limpar os arquivos gerados durante a compilação
clean:
	rm -f $(TARGET) *.o

# Regra para compilar o programa e executar um caso de teste
run: all
	./$(TARGET)


