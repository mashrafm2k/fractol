*This project has been created as part of the 42 curriculum by moashraf.*

# fract'ol

## Description

fract'ol is a small fractal exploration program built in C using the MiniLibX graphics library. The goal of the project is to generate and render mathematically defined fractals in a window, allowing the user to zoom in, pan around, and explore the infinite complexity of these structures in real time.

The program currently supports two fractals:

- **Mandelbrot** — the classic fractal defined by iterating `z = z² + c` where `c` is the point being tested.
- **Julia** — a related fractal where `c` is a fixed complex parameter supplied by the user, producing a wide variety of shapes depending on the value chosen.

Each fractal is rendered using smooth (Bernstein polynomial) coloring to produce visually rich gradients rather than harsh band transitions.

---

## Instructions

### Requirements

- A C compiler (`cc`)
- MiniLibX (included in the `mlx/` directory)
- libft (included in the `libft/` directory)
- **macOS**: Xcode command line tools (for OpenGL/AppKit frameworks)
- **Linux**: `libX11` and `libXext` development packages

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

```bash
./fractol mandelbrot
./fractol julia <re> <im>
```

**Examples:**

```bash
./fractol mandelbrot
./fractol julia -0.7 0.27
./fractol julia 0.285 0.01
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

- **Code review** — identifying bugs such as incorrect `ft_strncmp` lengths, misuse of `map()` instead of `get_color()` in the render loop, and missing header prototypes.
- **Zoom behavior** — implementing cursor-centered zoom by adjusting `shift_x`/`shift_y` relative to the mouse position in the complex plane.
- **Documentation** — generating this README.

All logic, mathematical understanding, and final implementation decisions were reviewed and validated by the student.