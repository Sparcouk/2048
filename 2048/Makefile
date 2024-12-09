modele: modele
	clang++ $(CPPFLAGS) -c modele.cpp

modele_test: modele_test
	clang++ $(CPPFLAGS) -c modele_test.cpp

2048: 2048
	clang++ $(CPPFLAGS) -c 2048.cpp

test: modele_test
	clang++ $(CPPFLAGS) $(LDFLAGS) modele.o modele_test.o -lncurses -o test

jeu: 2048
	clang++ $(CPPFLAGS) $(LDFLAGS) modele.o 2048.o -lncurses -o 2048

clear:
	rm 2048.o
	rm test
	rm modele_test.o
	rm modele.o
