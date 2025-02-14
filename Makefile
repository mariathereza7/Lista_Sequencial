#Definindo o compilador
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#Nome do arquivo executável
TARGET = lista_sequencial


$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)
	
test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
