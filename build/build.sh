echo "Removing old stuff"
rm -rf *.o

echo "Building new objects"
g++ -Wall -g -c ../src/*.cc
g++ -Wall -g -c ../src/*/*.cc
g++ -Wall -g -c *.cc

echo "Link object together into test binary"
echo "DONE BUILDING"
echo "--------------------------------------"
echo ""
g++ -Wall -g -o test *.o -framework OpenGL -framework Cocoa