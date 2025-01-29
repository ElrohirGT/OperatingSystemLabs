# Operating System Labs

Laboratorios para el curso de Sistemas Operativos.

## ¿Cómo usar este repositorio?

Cada laboratorio está resuelto en su propia branch dentro de este repositorio.
Por ejemplo, si quieres ver la solución para el lab1 simplemente ve a la branch lab1.

## ¿Cómo compilar el proyecto?

El comando para compilar cualquier .c en este proyecto es:

```bash
zig cc <file.c> -o <output.out>
```

`zig cc` es un wrapper alrededor de `clang` por lo que en realidad puedes usar `clang` en su lugar.

```bash
clang <file.c> -o <output.out>
```

En caso uses Nix y tengas Flakes habilitados puedes simplemente realizar:

```bash
nix develop
```

Y entrarás a una shell con todo lo que necesitas para compilar el proyecto.
