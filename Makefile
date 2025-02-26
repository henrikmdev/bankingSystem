CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = bankingSystem.o logic.o ui.o

banking_app: $(OBJ)
	$(CC) $(CFLAGS) -o banking_app $(OBJ)

bankingSystem.o: bankingSystem.c bank.h
	$(CC) $(CFLAGS) -c bankingSystem.c

logic.o: logic.c bank.h
	$(CC) $(CFLAGS) -c logic.c

ui.o: ui.c bank.h
	$(CC) $(CFLAGS) -c ui.c

clean:
	rm -f *.o banking_app
