# Calculator made with Qt6 and C++ in Qt Creator

It is still under development, but has working functions such as:
- multiplication 
- division
- exponentiation
- addition
- subtraction
- square root
  
It can also handle both negative and decimal numbers.


The UI was made with Qt Creator and styled with CSS. It attempts to mimic the clean look of the Windows 10/11 calculator.

<br>

![image](https://github.com/PirinenAO/qt-calculator/assets/119351375/c2b92930-575d-45ee-84c3-488c4e6cca22)

<br>

## To test this on Linux environment:

**Dependencies (Ubuntu and other Debian-based distros):**
```bash
sudo apt update && sudo apt install cmake && sudo apt install qt6-base-dev
```
**Clone the repository:**
```bash
git clone https://github.com/PirinenAO/qt-calculator.git
```
**Create build directory inside the project and move there:**
```bash
cd qt-calculator && mkdir build && cd build
```
**Generate build files:**
```bash
cmake ..
```
**Build executable:**
```bash
make
```
**Run:**
```bash
./app
```
