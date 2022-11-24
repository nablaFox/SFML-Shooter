all: compile

compile:
	g++ Application\main.cpp Application\src\Collision.cpp Application\src\Shooter.cpp \
	-I include -I Application\include -o Application\bin\Shooter \
	-L include\SFML\lib -l sfml-window -l sfml-system -l sfml-graphics
	