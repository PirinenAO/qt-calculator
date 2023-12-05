## Calculator made with Qt6 and C++ in Qt creator

It is still under development, but has working functions such as:
- multiplication 
- division
- exponentiation
- addition
- subtraction
- square root
It can also handle both negative and decimal numbers.
The UI was made with Qt Creator and styled with CSS. It attempts to mimic the clean look of the Windows 10/11 calculator.

![image](https://github.com/PirinenAO/qt-calculator/assets/119351375/f0ca6e87-4c41-44c7-b550-1fb6b7e50932)

To test this on Linux environment:

```bash
git clone https://github.com/PirinenAO/qt-calculator.git
```

```bash
cd qt-calculator && mkdir build && cd build
```

```bash
cmake ..
```

```bash
make
```

```bash
./app
```
