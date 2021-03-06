all: MapEditor

MapEditor: MapEditor.o MapEditor_OnInit.o MapEditor_OnEvent.o MapEditor_OnLoop.o MapEditor_OnRender.o MapEditor_OnCleanup.o MapEditor_OnSave.o Surface.o Event.o Camera.o Map.o Tile.o
	g++ MapEditor.o MapEditor_OnInit.o MapEditor_OnEvent.o MapEditor_OnLoop.o MapEditor_OnRender.o MapEditor_OnCleanup.o MapEditor_OnSave.o Surface.o Event.o Camera.o Map.o Tile.o -o MapEditor -lSDL -lSDL_image -lSDL_mixer

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
MapEditor_OnSave.o: MapEditor_OnSave.cpp
	g++ -c MapEditor_OnSave.cpp
Surface.o: Surface.cpp
	g++ -c Surface.cpp
Event.o: Event.cpp
	g++ -c Event.cpp
Camera.o: Camera.cpp
	g++ -c Camera.cpp
Map.o: Map.cpp
	g++ -c Map.cpp
Tile.o: Tile.cpp
	g++ -c Tile.cpp

clean:
	rm -f *.o CApp
