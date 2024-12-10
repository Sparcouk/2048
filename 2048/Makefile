modele: modele.cpp
	clang++ $(CPPFLAGS) -c modele.cpp

modele_test: modele_test.cpp
	clang++ $(CPPFLAGS) -c modele_test.cpp

2048: 2048.cpp
	clang++ $(CPPFLAGS) -c 2048.cpp

test: modele.o modele_test.o
	clang++ $(CPPFLAGS) $(LDFLAGS) modele.o modele_test.o -lncurses -o test

jeu: modele.o 2048.o
	clang++ $(CPPFLAGS) $(LDFLAGS) modele.o 2048.o -lncurses -o jeu

clear:
	rm *.o
	rm jeu
	rm test

