



### PROJECT: Qt Calculator GUI
* My first real C++ project (not counting robotics stuff). Built a calculator with a GUI using Qt6 and turned out pretty decent honestly.

## What it does:
* A fully functional calculator with a clean dark UI. Supports the usual arithmetic plus a few extras:

1. Basic operators -> addition, subtraction, multiplication, division (+ - * /)
2. Exponents -> ^ for powers
3. Parentheses -> auto-closes () and places cursor inside
4. Decimal support -> . works as expected
5. Backspace -> < deletes one character at a time
6. Clear -> C wipes the whole expression
7. Error handling -> shows ERROR on bad expressions instead of crashing

* The display evaluates expressions using QJSEngine so you can chain operations like (3+4)*2^3 and it just works.

## How to build & run
### Requirements
ToolVersionCMake >=3.16 C++17 Qt6.10.2 (Widgets, Gui, Core, Qml) and a Ninja Generator

### Steps
1. Clone the repo
bashgit clone https://github.com/marcdatboi/Qt-Calculator-GUI.git
cd Qt-Calculator-GUI
2. Configure with CMake
bashcmake -G Ninja -DCMAKE_BUILD_TYPE=Release -B build
3. Build
bashcmake --build build
4. Run
bash./build/Qt-Calculator-GUI
IDE Setup

Developed in CLion and VSCode
If using VSCode, grab the Qt Extension Pack from the marketplace before opening the project


Notes to self

* Buttons are mapped via a QMap<QChar, QList<int>> so adding new ones is easy — just drop in a new entry
* Expression evaluation is handled by QJSEngine::evaluate() which means it supports pretty much any valid JS math expression
* Forgot to use Qt signals/slots properly — buttons talk directly to the display widget instead. Would refactor this eventually
* The QMainWindow background stylesheet has a typo (QMainWindow: instead of QMainWindow) so that CSS rule never applied — fix this next time
