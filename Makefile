build:
	g++ -w -std=c++20 \
	./src/*.cpp \
	-o game \
	-I "./lib/lua" \
	-L "./lib/lua" \
	-llua \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer \
	-lGL \
	-lglut \
	-lGLU \
	-lGLEW;

clean:
	rm ./game;

run:
	./game;
