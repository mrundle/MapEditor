all: MapEditor

MapEditor: MapEditor.o MapEditor_OnInit.o MapEditor_OnEvent.o MapEditor_OnLoop.o MapEditor_OnRender.o MapEditor_OnCleanup.o Surface.o Event.o Animation.o Entity.o Camera.o Area.o Map.o Tile.o
	g++ MapEditor.o MapEditor_OnInit.o MapEditor_OnEvent.o MapEditor_OnLoop.o MapEditor_OnRender.o MapEditor_OnCleanup.o Surface.o Event.o Animation.o Entity.o Camera.o Area.o Map.o Tile.o -o MapEditor -lSDL -lSDL_image -lSDL_mixer

MapEditor.o: MapEditor.cpp
	g++ -c MapEditor.cpp
MapEditor_OnInit.o: MapEditor_OnInit.cpp
	g++ -c MapEditor_OnInit.cpp
MapEditor_OnEvent.o: MapEditor_OnEvent.cpp
	g++ -c MapEditor_OnEvent.cpp
MapEditor_OnLoop.o: MapEditor_OnLoop.cpp
	g++ -c MapEditor_OnLoop.cpp
MapEditor_OnRender.o: MapEditor_OnRender.cpp
	g++ -c MapEditor_OnRender.cpp
MapEditor_OnCleanup.o: MapEditor_OnCleanup.cpp
	g++ -c MapEditor_OnCleanup.cpp
Surface.o: Surface.cpp
	g++ -c Surface.cpp
Event.o: Event.cpp
	g++ -c Event.cpp
Animation.o: Animation.cpp
	g++ -c Animation.cpp
Entity.o: Entity.cpp
	g++ -c Entity.cpp
Camera.o: Camera.cpp
	g++ -c Camera.cpp
Area.o: Area.cpp
	g++ -c Area.cpp
Map.o: Map.cpp
	g++ -c Map.cpp
Tile.o: Tile.cpp
	g++ -c Tile.cpp

clean:
	rm -f *.o CApp
