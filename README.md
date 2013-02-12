MapEditor
=========

by Matthew Rundle

2D tile-based map editor using C++ with the SDL libraries.




Needs Changes:

Fix control bar size on the right side to only contain 1 row from the sprite sheet (possibly put it on the top/bottom
horizontally). If done, need to change where the map detects a 'valid' placement of a tile (right now it is 
looking for anything not within the right control bar). Also, use 1-9 from keyboard to switch between them, and then plus and minus
keys to scroll between the options.
