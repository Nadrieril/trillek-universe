trillek-universe
================
Space simulator base for Trillek.
Handles the simulation of celestial bodies orbiting each other (stricly keplerian orbits for now).


Context:
 - Newtonian physics
 - All objects are points
 - Space is centered around a sun
 - Coordinates are (long long?) integer multiples of some length unit (I assume cm is precise enough)
 - There will be enough planets/moons/heavy bodies to justify an efficient (restricted) n-body algorithm
 - The masses of smaller bodies (asteroids, ships...) are negligible

Goals:
 - Generate statistically accurate planetary system
 - Simulate said system efficiently, along with smaller bodies inside
 - Calculate efficiently the gravitational forces at any point in space
 - Be able to fast-forward simulation (e.g. in case of unvisited parts of space)

TODO:
 - Everything

The codes handles 3D even though the demo is basic 2D (for simplicity's sake).
