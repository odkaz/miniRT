# miniRT
![pikachu](https://user-images.githubusercontent.com/47331394/146163268-bba1d537-9dc3-4c75-89ea-b32aec9215eb.gif)

## Discription
This program will render simple geometric shapes using the ray tracing techniques, as well as handling the lighting and the different angles of the camera. The program is written in C only using some basic external functions such as math.h and [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx), due to the restrictions of the project.

## Usage guide
1.```git clone https://github.com/odkaz/miniRT.git;cd miniRT;make;make clean;```: This command will clone the repository and compile the project.

2.```./miniRT PATH```: The program takes the path to the .rt files as the first argument. You also can add ```--save``` option as the second argument to render the images into .bmp files.

Try for example,

```./miniRT rt_files/spheres.rt```: It will open an window like this ↓

<img width="624" alt="sphere" src="https://user-images.githubusercontent.com/47331394/146485760-f2e8a293-874b-4252-afba-bf661172c42e.png">

Now enjoy the beautiful images rendered by ray tracing!

### Controls

3.```tab```: Swich the camera to see from different angles.

4.```esc```: Exit the program, or you can click on the cross button to finish the program.
