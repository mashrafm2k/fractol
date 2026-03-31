*This project has been created as part of the 42 curriculum by \<moashraf\>.*

# fract'ol

## Description

fract'ol is a small fractal exploration program built in C using the MiniLibX graphics library. The goal of the project is to generate and render mathematically defined fractals in a window, allowing the user to zoom in, pan around, and explore the infinite complexity of these structures in real time.

The program supports two fractals:

- **Mandelbrot** — the classic fractal defined by iterating `z = z² + c` where `c` is the point being tested.
- **Julia** — a related fractal where `c` is a fixed complex parameter supplied by the user, producing a wide variety of shapes depending on the value chosen.

Each fractal is rendered using smooth (Bernstein polynomial) coloring to produce visually rich gradients rather than harsh band transitions.

### Technical Design

The rendering engine was built around a **12-thread parallel architecture** using POSIX threads (`pthread`), designed specifically to take full advantage of a 12-core processor. The screen is divided into 12 horizontal strips, each assigned to a dedicated thread that computes its pixels independently. All threads are launched simultaneously and joined before the final image is flushed to the window, delivering significantly faster render times than a single-threaded approach — particularly noticeable when zooming deep into the fractal.

Additional optimizations include:

- **Cardioid and period-2 bulb detection** — the two largest black regions of the Mandelbrot set are identified analytically and skipped entirely, avoiding expensive iteration on the most common pixels.
- **Dynamic iteration scaling** — the iteration cap scales logarithmically with zoom depth, keeping renders fast at low zoom and progressively more detailed when zoomed in.
- **Cursor-centered zoom** — zoom is anchored to the mouse position by adjusting the complex plane shift on each scroll event.

---

## Instructions

### Requirements

- A C compiler (`cc`)
- **Linux**: `libX11` and `libXext` development packages

```bash
sudo apt-get install libx11-dev libxext-dev
```

### Compilation

```bash
make
```

To recompile from scratch:

```bash
make re
```

To clean object files:

```bash
make clean
```

To clean everything including the binary:

```bash
make fclean
```

### Execution

Launch the Mandelbrot set:

```bash
./fractol mandelbrot
```

Launch a Julia set with a complex parameter:

```bash
./fractol julia <re> <im>
```

### Examples

```bash
./fractol julia -0.7 0.27
```

```bash
./fractol julia 0.285 0.01
```

```bash
./fractol julia -0.4 0.6
```

### Controls

| Input | Action |
|---|---|
| Scroll up | Zoom in (centered on cursor) |
| Scroll down | Zoom out (centered on cursor) |
| Arrow keys / WASD | Pan the view |
| ESC | Exit the program |

---

## Resources

### Fractals & Mathematics

- [Mandelbrot Set — Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set — Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Smooth Coloring / Plotting Algorithms — Wikipedia](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)
- [Bernstein Polynomial Coloring — Inigo Quilez](https://iquilezles.org/articles/palettes/)
- [Interactive Fractal Explorer (visual reference)](https://mandel.gart.nz/)

### MiniLibX

- [MiniLibX Documentation — harm-smits](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX Linux Guide](https://github.com/42Paris/minilibx-linux)

### AI Usage

Claude (Anthropic) was used during this project for the following tasks:

- **Refactoring** — restructuring files for Norminette compliance, splitting logic across `main.c`, `parse.c`, `init.c`, `hooks.c`, `render.c`, `color.c`, `complex.c`, `fractal_math.c`, and `utils.c`.
- **Multithreading** — designing and implementing the 12-thread rendering architecture using `pthread`, including thread data structs, strip partitioning, and synchronization.
- **Optimizations** — cardioid/bulb early-exit for Mandelbrot, dynamic iteration scaling, and cursor-centered zoom.
- **Documentation** — generating this README.

All logic, mathematical understanding, and final implementation decisions were reviewed and validated by the student.