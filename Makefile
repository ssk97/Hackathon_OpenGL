CXX = g++
CXXFLAGS = -Wall  -Wno-unknown-pragmas -std=c++11  -O3  -I /usr/include/GL -I /usr/include/libdrm -D_GNU_SOURCE=1 -D_REENTRANT -g
LFLAGS = -lGL -lGLEW -lglfw
OBJ = Carrier.o CarrierHolder.o Enemy.o Follower.o FollowerHolder.o GenericHolder.o GenericObject.o LineTripper.o LineTripperHolder.o main.o Missile.o MissileHolder.o Mothership.o MothershipHolder.o Player.o PlayerHolder.o Spawner.o TextDisplay.o Zombie.o ZombieHolder.o

game : $(OBJ)
	$(CXX) -o $@ $^ $(FLAGS) $(LFLAGS)

%.hpp.gch: %.hpp
	$(CXX) $(FLAGS) -c  $<

clean:
	rm -f *.o *.gch *.gcda *.gcno dataGame tests

tests: $(OBJ) $(TEST_OBJ)
	$(CXX) -o $@ $^ $(FLAGS) $(LFLAGS)

all: dataGame tests

