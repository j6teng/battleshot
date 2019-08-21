CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla
EXEC = battleship
OBJECTS = main.o player.o game.o bslog.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
