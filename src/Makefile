CC=g++
CFLAGS=-std=c++17 -Wall -Wextra
EXEC=./tp1
TMPOUT=tp1.testresult

$(EXEC): TipoNave.cpp PilhaDePreparacao.cpp ListaDeCombate.cpp FilaDeAvaria.cpp main.cc
	$(CC) $(CFLAGS) TipoNave.cpp PilhaDePreparacao.cpp ListaDeCombate.cpp FilaDeAvaria.cpp main.cc -o $(EXEC)

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm tp1
