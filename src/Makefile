COMP = g++
LIB = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -Wall -Wextra
EXEC = MineSweeper

$(EXEC): MineSweeper.o State.o Button.o Game.o Menu.o Sprite.o Animation.o TextureManager.o source.o Dbg_Log.o
	$(COMP) $^ -o $(EXEC) $(LIB) $(FLAGS)

source.o: source.cpp MineSweeper.o
	$(COMP) $< -c $(FLAGS)

MineSweeper.o: MineSweeper.cpp MineSweeper.h
	$(COMP) $< -c $(FLAGS)

State.o: State.cpp State.h
	$(COMP) $< -c $(FLAGS)

Button.o: Button.cpp Button.h
	$(COMP) $< -c $(FLAGS)

Game.o: Game.cpp Game.h
	$(COMP) $< -c $(FLAGS)

Sprite.o: Sprite/Sprite.cpp Sprite/Sprite.h Sprite/Animation.cpp Sprite/Animation.h TextureManager.o Dbg_Log.o
	$(COMP) -c Sprite/Animation.cpp $(FLAGS)
	$(COMP) -c Sprite/Sprite.cpp $(FLAGS)

TextureManager.o: TextureManager/TextureManager.cpp TextureManager/TextureManager.h Dbg_Log.o
	$(COMP) -c $< $(FLAGS)

Menu.o: Menu.cpp Menu.h
	$(COMP) $< -c $(FLAGS)

Dbg_Log.o: Dbg_Log/Dbg_Log.cpp Dbg_Log/Dbg_Log.h
	$(COMP) -c $< $(FLAGS)

clean:
	rm *.o
