# TOP-DOWN Adventure Game in SDL3

[SDL3/C Topdown Game](https://www.youtube.com/playlist?list=PLgBHxhPr3AsUlkPhMA9xgX_EyEmlwxcJd)

## Setup MSYS2/UCRT64

```bash
pacman -Syu
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
pacman -S mingw-w64-ucrt-x86_64-sdl3 mingw-w64-ucrt-x86_64-sdl3-image mingw-w64-ucrt-x86_64-sdl3-ttf
```

## Asserts

O_LOBSTER's [TOP-DOWN Adventure Pack](https://o-lobster.itch.io/adventure-pack)

Version: v.1.0

## Build and Run

```bat
:: Build out/game.exe
rake build

:: Run
rake
```
