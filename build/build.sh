echo "Removing old stuff"
rm -rf *.o

echo "Building new objects"
g++ -c ../src/*.cc

echo "Link object together into test binary"
g++ -o test *.o -framework GLUT -framework OpenGL