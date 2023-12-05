## Calculator made with Qt6 and C++

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

clone the repository:
```bash
git clone https://github.com/PirinenAO/qt-calculator.git
```
create build directory inside the project and move there:
```bash
cd qt-calculator && mkdir build && cd build
```
generate build files:
```bash
cmake ..
```
build executable:
```bash
make
```
run:
```bash
./app
```
