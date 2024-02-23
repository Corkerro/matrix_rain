# Assignment: Matrix Rain

## Participants

- **TeamLead**: [vsukhonos](https://lms.khpi.ucode-connect.study/users/vsukhonos)
- **Teammate**: [rosinnii](https://lms.khpi.ucode-connect.study/users/rosinnii)
- **Teammate**: [vtesliuk](https://lms.khpi.ucode-connect.study/users/vtesliuk)

## Description

This assignment entails creating a program that generates a matrix rain effect. Columns of varying heights filled with random characters scroll down the screen, with the first (lowest) character of each column being white and continuously changing, while the rest of the characters in the column are green by default. The background of the Terminal is black by default.

## Implementation

- The program must use all printable ASCII characters.
- It should exit when the 'q' key is pressed on the keyboard.
- It should not handle window resize events.
- The program should display usage information in case of invalid input.

## Additional Features

It's an opportunity to exercise creativity and imagination by implementing additional features to enhance the program. Here are some ideas:

- Implementing a `-s` flag to run the program in screensaver mode.
- Allowing the speed of the animation to be changed during runtime or program startup.
- Providing options to change the color of characters or the background during runtime or program startup.
- Printing messages from the Neo's Terminal like in the example `resources/creative.mp4`.
- Implementing other creative features, encouraging unique ideas and imagination.

## Resources

- See `resources/basic.mp4` for an example of basic functionality.
  ![an example of basic functionality](./resources/basic.gif)
- See `resources/creative.mp4` for examples of creative features.
  ![an examples of creative features](./resources/creative.gif)
  - See `resources/result.mp4` for examples of use.
    ![an examples of creative features](./resources/result.gif)

## Flags

`-s` to run the program in screenaver mode

## Run

### Compilation

```sh
make
```

### Starting the program

```sh
./matrix_rain [flag]
```

## Examples of use

![an examples of use](./resources/result.gif)

## Relevance

This assignment is part of the [ucode](https://lms.khpi.ucode-connect.study/) project in collaboration with [CBLWorld](https://lms.khpi.ucode-connect.study/). #ucode #CBLWorld
