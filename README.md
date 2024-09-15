# 2D-Split-Game

This is a 2D puzzle game where the player controls two objects in mirrored worlds. The goal is to move both objects to their respective endpoints simultaneously before time runs out. As the player moves one object, the mirrored object in the parallel world moves in a different direction, adding a unique challenge to the puzzle.

## Features
- **Simultaneous Object Movement:** Control two objects using `WASD` and arrow keys.
- **Mirrored Movements:** Moving one object affects the other object in a mirrored way.
- **Random Collection Points:** The collection points for both objects appear randomly, and the objects can be collected at the same time or at different times.
- **Time Limit:** The player has 60 seconds to collect both objects at their respective points.
- **Victory/Defeat Conditions:** If both objects reach their collection points, a victory screen is shown. If time runs out, a game over screen appears.
- **Undo Feature:** Allows the player to undo their last move if they make a mistake.

## Controls

- **Player 1 Movement** (Controls the original object):
  - `W` - Move up
  - `A` - Move left
  - `S` - Move down
  - `D` - Move right

- **Player 2 Movement** (Controls the mirrored object):
  - `Arrow Up` - Move up
  - `Arrow Down` - Move down
  - `Arrow Left` - Move left
  - `Arrow Right` - Move right

- **Undo Move**:
  - `U` - Undo the last movement step for both objects

### How Player Movements Affect Both Objects

- The game has two objects: **Player 1's Object** and **Player 2's Object**, existing in mirrored worlds.
- Moving **Player 1's Object** directly affects **Player 2's Object** in the following ways:
  - **Player 1** moving **right** will cause **Player 2's Object** to move **down**.
  - **Player 1** moving **left** will cause **Player 2's Object** to move **up**.
  - **Player 1** moving **up** will cause **Player 2's Object** to move **left**.
  - **Player 1** moving **down** will cause **Player 2's Object** to move **right**.

Similarly, controlling **Player 2's Object** affects **Player 1's Object** in a mirrored manner:
  - **Player 2** moving **right** will cause **Player 1's Object** to move **down**.
  - **Player 2** moving **left** will cause **Player 1's Object** to move **up**.
  - **Player 2** moving **up** will cause **Player 1's Object** to move **left**.
  - **Player 2** moving **down** will cause **Player 1's Object** to move **right**.

Both objects must reach their respective endpoints at the same time to win the game. If one object reaches its point without the other, the player can continue to move the remaining object to its endpoint before the 60-second timer runs out.

### How Random Collection Points Work
- The collection points for both objects are placed randomly on the game map.
- The objects can reach their points at the same time or at different times.
- If both objects reach their points within the 60-second time limit, the game shows a **victory** screen.
- If time runs out before both objects are collected, the game ends with a **game over** screen.

## Building and Running the Game

### Prerequisites
Make sure you have the required development libraries installed (e.g., Raylib,Opengl32).

### Clone the Repository
```bash
git clone https://github.com/Emosans/2d-split-game.git
cd src
```
### Compile the files
```bash
g++ -I../bin/include -L../bin/lib *.cpp -o../build/main -lraylib -lopengl32 -lwinmm -lgdi32
```
### Navigate to the build folder and run main.exe
```bash
cd ..
cd build
main.exe
```

**Enjoy Puzzling!**
