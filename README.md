**This is an ongoing project*

# An Attempt at Making a Terraria Clone
This project is an attempt to explore game development from scratch with C++ by creating a pixel based 2-dimensional sandbox game with a grid system, similar to the popular game Terraria.

# Notable Features
The project has 2 notable features thus far.
1. Implementation of the Simple DirectMedia Layer Library (more specifically SDL2)
  - Stores textures and draw them in a window
  - Collects user input (such as key presses and mouse position) to make the map interactive

2. Takes an object-oriented approach to game development
  - Every distinguishable feature is implemented in classes, meaning any existing feature is easy to reproduce amd manipulate
  - Simplifies the relationships between objects, as well as their relationship with the game state

This game is made using principles such as chunk-based rendering systems, as well as algorithms to draw grid-item (block) styles depending on neighboring blocks.

## To-do
- [ ] Implement Procedural Map Generation
  - [x] Research how procedural terrain generation is done
    - [x] Implement Perlin Noise algorithm
    - [ ] Fix Bugs
  - [ ] Research procedural cave generation
    - [ ] Perlin Worms
- [ ] Implement Players and other entities
  - [ ] Implement Collisions
