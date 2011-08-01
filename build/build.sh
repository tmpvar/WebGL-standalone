echo "Removing old stuff"
rm -rf *.o

echo "Building new objects"
g++ -g -c ../src/*.cc
g++ -g -c *.cc

echo "Link object together into test binary"
echo "DONE BUILDING"
echo "--------------------------------------"
echo ""
g++ -g -o test *.o -framework OpenGL -framework Cocoa