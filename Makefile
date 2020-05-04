CXX = g++
CXXFLAGS = -std=c++14 -I/opt/X11/include -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = main.o window.o Player.o Score.o Board.o Cell.o Display.o Point.o LevelZero.o LevelOne.o LevelTwo.o LevelThree.o LevelFour.o Block.o SBlock.o IBlock.o ZBlock.o OBlock.o JBlock.o LBlock.o TBlock.o NextBlock.o Core.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} $^ -o $@ -L/opt/X11/lib -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} ${DEPENDS}
