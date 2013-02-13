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

------------------------------------------------------------

Credits:

    -Special thanks to David Gervais for the particular 
     tileset used in the creation of MapEditor. His work is
     published under the Creative Commons license. To view
     some of his work, visit:

     http://pousse.rapiere.free.fr/tome/tome-tiles.htm

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

------------------------------------------------------------

Controls:

    -WASD to control camera and navigate around map

    -Left/Right/Up/Down to select desired tile from the set

    -Mouse left click will place selected tile on cursor

------------------------------------------------------------

TODO: Add read/write functionality of maps. Print vector of 
tiles to a text file that can be read in later.


