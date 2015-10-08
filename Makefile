pro2: Goal.cpp TermVar.cpp Trail.cpp _Main.cpp Atom.h Clause.h Goal.h Program.h Term.h TermCons.h TermVar.h TermVarMapping.h Trail.h
	g++ Goal.cpp TermVar.cpp Trail.cpp _Main.cpp -o pro2

pro: prolog.cpp
	g++ prolog.cpp -o pro

grind: pro2
	valgrind --leak-check=full --show-reachable=yes -v ./pro2

put:
	git add *
	git commit 
	git push

pull:
	clear
	git pull
	Make grind
