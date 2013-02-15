  __  __             ______    _ _ _             
 |  \/  |           |  ____|  | (_) |            
 | \  / | __ _ _ __ | |__   __| |_| |_ ___  _ __ 
 | |\/| |/ _` | '_ \|  __| / _` | | __/ _ \| '__|
 | |  | | (_| | |_) | |___| (_| | | || (_) | |   
 |_|  |_|\__,_| .__/|______\__,_|_|\__\___/|_|   
              | |                                
              |_|                                

    by Matthew Rundle

------------------------------------------------------------

A 2D tile-based map editor using C++ with the SDL libraries.

Created for use in the semester project for the Spring 2013
semester CSE20212 class (Fundamentals of Computing II) at
the University of Notre Dame.

------------------------------------------------------------

Credits:

    -Special thanks to David Gervais for the particular 
     tileset used in the creation of MapEditor. His work is
     published under the Creative Commons license. To view
     some of his work, visit:

     http://pousse.rapiere.free.fr/tome/tome-tiles.htm

	-Also, special thanks goes to Tim Jones of
	 http://www.sdltutorials.com for helping me make my
	 foray into SDL and helping me to devlop this map
	 editor tool

------------------------------------------------------------

Installation:

    -MapEditor requires installation of all SDL libaries

        -Resources can be found at http://www.libsdl.org/

    -Download all MapEditor files, and run the makefile

    -The "grounds32.gif" tileset must be located in
     containing folder "./tilesets/" relative to the 
     executable file

    -The "controlBar.png" and "selector.png" graphics must
     be located in containig folder "./graphics" relative
     to the location of the executable file

------------------------------------------------------------

Instructions:

    -Run MapEditor

    -If you do not want to load a map from file, MapEditor
     will generate a blank map for you. To do this, enter
     the X and Y coordinate (when prompted) of the tile that
     you want to fill the map.

        -To view the tileset, see ./maps/grounds32.gif

	-The X,Y schema starts with 0,0 in the top left

    -If you decide to load a map that you have saved,
     provide the relative path to that file

		-ie "./maps/narnia.map" (without quotes)

    -Regardless of whether you're generating a new map or
     loading an old one, MapEditor saves your map each time
     you close the program. When it asks for the file to 
     save to, provide a relative path

        -ie "./maps/narnia2.map" (without quotes)

        -If the file does not exist, one will be created there

        -You can save to the same file that you load from, just
         enter the same filepath for both options

        -Maps can have have any file name (.map, .foobar, etc)

------------------------------------------------------------

Controls:

    -WASD to control camera and navigate around map

    -Left/Right/Up/Down to select desired tile from the set

    -Mouse left click will place selected tile on cursor

------------------------------------------------------------

TODO: Add read/write functionality of maps. Print vector of 
tiles to a text file that can be read in later.


