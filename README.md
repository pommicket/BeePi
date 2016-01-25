# BeePi
Uses the system speaker to play pi

**GNU/Linux only**

**Requires [beep](http://www.johnath.com/beep/)**

Takes the digits of pi and plays them using the following notes for each digit:
0 - B3  
1 - C4  
2 - D4  
3 - E4  
4 - F4  
5 - G4  
6 - A4  
7 - B4  
8 - C5  
9 - D5  

Pi is stored in pi.txt

To run BeePi:
```
./beepi [msPerNote]
```
Where msPerNote is the number of milliseconds per beep. (defaults to 200)

To build the source:
```
make
```
