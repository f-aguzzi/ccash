# ccash

Minimalist CLI tool to keep track of spending.

Save money like it's 1972!

The UI is created with `ncurses`.

## Building from source
Move to the `src` folder.
Using `clang`, the command line instruction would be:

```sh
clang clang ll.c tsv.c ui.c main.c -lncurses
```

Basically, throw all the `.c` files in there and link the
`ncurses` library.

No need for makefiles or anything, since it's a small project.
