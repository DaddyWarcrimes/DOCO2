OBJS	= DataParser.o location.o main.o map.o pellet.o DOCO.o tenant.o tenantlist.o world.o DOCOFactory.o behavior.o verticalBehavior.o obstacle.o staticBehavior.o horizontalBehavior.o diagonalBehavior.o
SOURCE	= DataParser.cpp location.cpp main.cpp map.cpp pellet.cpp DOCO.cpp tenant.cpp tenantlist.cpp world.cpp DOCOFactory.cpp behavior.cpp verticalBehavior.cpp obstacle.cpp staticBehavior.cpp horizontalBehavior.cpp diagonalBehavior.cpp
HEADER	= tenant.h tenantlist.h world.h config.h DataParser.h DOCO.h location.h map.h pellet.h DOCOFactory.h behavior.h verticalBehavior.h obstacle.h staticBehavior.h horizontalBehavior.h diagonalBehavior.h
OUT	= doco
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
		$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

DataParser.o: DataParser.cpp
		$(CC) $(FLAGS) DataParser.cpp 

location.o: location.cpp
		$(CC) $(FLAGS) location.cpp 

main.o: main.cpp
		$(CC) $(FLAGS) main.cpp 

map.o: map.cpp
		$(CC) $(FLAGS) map.cpp 

pellet.o: pellet.cpp
		$(CC) $(FLAGS) pellet.cpp 

DOCO.o: DOCO.cpp
		$(CC) $(FLAGS) DOCO.cpp 

obstacle.o: obstacle.cpp
		$(CC) $(FLAGS) obstacle.cpp 

tenant.o: tenant.cpp
		$(CC) $(FLAGS) tenant.cpp 

tenantlist.o: tenantlist.cpp
		$(CC) $(FLAGS) tenantlist.cpp 

world.o: world.cpp
		$(CC) $(FLAGS) world.cpp 

DOCOFactory.o: DOCOFactory.cpp
		$(CC) $(FLAGS) DOCOFactory.cpp 

behavior.o: behavior.cpp
		$(CC) $(FLAGS) behavior.cpp 

staticBehavior.o: staticBehavior.cpp
		$(CC) $(FLAGS) staticBehavior.cpp 

verticalBehavior.o: verticalBehavior.cpp
		$(CC) $(FLAGS) verticalBehavior.cpp 
		
horizontalBehavior.o: horizontalBehavior.cpp
		$(CC) $(FLAGS) horizontalBehavior.cpp 

diagonalBehavior.o: diagonalBehavior.cpp
		$(CC) $(FLAGS) diagonalBehavior.cpp 

clean:
		rm -f $(OBJS) $(OUT)
