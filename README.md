# Typing Trainer
#### Typing Trainer is a cross-platform program for training or testing blind typing. The application has many exercises and supports two languages for slow printing. All training and training results are stored in the SQL Lite database.

## Opportunities
+ Two modes: training and testing
+ Saving the results to the database
+ Measurement of printing speed and accuracy
+ Virtual keyboard
+ Three initial courses


## Using
When starting the program, we are greeted by the initial "Start" window where you can view or change the current "Lesson" and "Exercise", if desired, this window can be disabled in the settings.

![Start window](https://github.com/chaknoris16/TypingTrainer/blob/main/Screenshots/Start%20Window.png)
-


Next, we have the Main window where the Training mode is located.

![Main window](https://github.com/chaknoris16/TypingTrainer/blob/main/Screenshots/Main%20Window.png?raw=true)

At the bottom center is the Virtual Keyboard, the symbols that will be used in this exercise are highlighted on it, and the symbol that needs to be pressed now is highlighted, and if you press the wrong key, it will flash red.

---

### Typing testing

If you click on the "Testing" button at the top of the toolbar, a window for testing blind input will open, large texts are used there, the language of which can be selected in Settings.

![Testing window](https://github.com/chaknoris16/TypingTrainer/blob/main/Screenshots/Testing%20Window.png)

---


### Results
If we want to see the results of both the Simulator and the Testing, we can go to "Results", there you can see your attempts, what results and when we did it.

![Result Window](https://github.com/chaknoris16/TypingTrainer/blob/main/Screenshots/Result%20Window.png)


---
### Settings
One of the most important parts of the application is "Settings" here you can choose a test for Testing, for the Simulator you can change the Course and Lesson with Exercise if you have passed it. You can also hide the Start window and Virtual keyboard here

![Settings](https://github.com/chaknoris16/TypingTrainer/blob/main/Screenshots/Setting%20Windget.png)

## Dependencies
To successfully install and compile this project, you need the following dependencies:
- Compiler with C++ 17 support
- [CMake](https://cmake.org/) version 3.21 or higher
- [Qt6](https://doc.qt.io/qt-6/qtwidgets-index.html) - Widgets
- [Qt6](https://doc.qt.io/qt-6/qtsql-index.html) - Sql
- [GTest](https://github.com/google/googletest) is optional if you want to compile a program with tests
## Assembly and installation
bash
```bash

git clone https://github.com/chaknoris16/TypingTrainer.git
cd TypingTrainer
mkdir build && cd build
cmake ..
make
sudo make install

```
---
Shell
```shell

git clone https://github.com/chaknoris16/TypingTrainer.git
cd TypingTrainer
mkdir build && cd build
cmake ..
make
make install

```
---
If you want to compile an application with tests, you need to change:
```bash
cmake -DBUILD_TESTS=ON ..
```
