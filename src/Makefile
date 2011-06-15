GL_GLUT=-lGL -lGLU -lglut

all : Example_Viewer

Example_Viewer : tools.o vector3d.o define.o mesh.o main.o
	g++ tools.o vector3d.o define.o mesh.o main.o -o Example_Viewer $(GL_GLUT)

tools.o : tools.cpp
	g++ -c tools.cpp -o tools.o

vector3d.o : vector3d.cpp
	g++ -c vector3d.cpp -o vector3d.o

define.o : define.cpp
	g++ -c define.cpp -o define.o

mesh.o : mesh.cpp
	g++ -c mesh.cpp -o mesh.o $(GL_GLUT)

main.o : main.cpp
	g++ -c main.cpp -o main.o $(GL_GLUT)

clean :
	rm *.o
