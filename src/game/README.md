# `game` directory
this contains game logic.
### directories:
- `init`: init audio, window, load sound, etc. And close and unload them.
- `logic`: movement, spawn, logic, also game loop
- `sound`: yeah, like the directory name - sound loader and  player
- `texture`: texture loader & drawer
### files:
`var` (`h`/`cpp`): global variables
### Note for contributor:
Chill, but remember to write **clean code** with:
- Edit right place: for example: if you want to add windows init check. Add your change into `init/init.cpp`, not `logic/loguc.cpp` or another places.
- Comment if needed, for reader, and for longer furture
- Code style must be **same** with my original code:
1. Variables, function name: `camelCase`
2. Class, struct, namespace: `PascalCase` for struct, class, `snake_case` for namespace.
3. Macro: `ALL_CAPS`, i not recommended to use macros, use pure C/C++ instead if you can.
4. File name: `camelCase`
