dev:
	make clean && make build && make run;
	
build:
	g++ -w -std=c++20 \
	./src/*.cpp \
	-o game \
	-I "./libs/SDL2/include" \
	-I "./libs/asio/include" \
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
