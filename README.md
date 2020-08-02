# AVRaft

![Build with PlatformIO](https://img.shields.io/badge/build%20with-PlatformIO-orange?logo=data%3Aimage%2Fsvg%2Bxml%3Bbase64%2CPHN2ZyB3aWR0aD0iMjUwMCIgaGVpZ2h0PSIyNTAwIiB2aWV3Qm94PSIwIDAgMjU2IDI1NiIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiBwcmVzZXJ2ZUFzcGVjdFJhdGlvPSJ4TWlkWU1pZCI+PHBhdGggZD0iTTEyOCAwQzkzLjgxIDAgNjEuNjY2IDEzLjMxNCAzNy40OSAzNy40OSAxMy4zMTQgNjEuNjY2IDAgOTMuODEgMCAxMjhjMCAzNC4xOSAxMy4zMTQgNjYuMzM0IDM3LjQ5IDkwLjUxQzYxLjY2NiAyNDIuNjg2IDkzLjgxIDI1NiAxMjggMjU2YzM0LjE5IDAgNjYuMzM0LTEzLjMxNCA5MC41MS0zNy40OUMyNDIuNjg2IDE5NC4zMzQgMjU2IDE2Mi4xOSAyNTYgMTI4YzAtMzQuMTktMTMuMzE0LTY2LjMzNC0zNy40OS05MC41MUMxOTQuMzM0IDEzLjMxNCAxNjIuMTkgMCAxMjggMCIgZmlsbD0iI0ZGN0YwMCIvPjxwYXRoIGQ9Ik0yNDkuMzg2IDEyOGMwIDY3LjA0LTU0LjM0NyAxMjEuMzg2LTEyMS4zODYgMTIxLjM4NkM2MC45NiAyNDkuMzg2IDYuNjEzIDE5NS4wNCA2LjYxMyAxMjggNi42MTMgNjAuOTYgNjAuOTYgNi42MTQgMTI4IDYuNjE0YzY3LjA0IDAgMTIxLjM4NiA1NC4zNDYgMTIxLjM4NiAxMjEuMzg2IiBmaWxsPSIjRkZGIi8+PHBhdGggZD0iTTE2MC44NjkgNzQuMDYybDUuMTQ1LTE4LjUzN2M1LjI2NC0uNDcgOS4zOTItNC44ODYgOS4zOTItMTAuMjczIDAtNS43LTQuNjItMTAuMzItMTAuMzItMTAuMzJzLTEwLjMyIDQuNjItMTAuMzIgMTAuMzJjMCAzLjc1NSAyLjAxMyA3LjAzIDUuMDEgOC44MzdsLTUuMDUgMTguMTk1Yy0xNC40MzctMy42Ny0yNi42MjUtMy4zOS0yNi42MjUtMy4zOWwtMi4yNTggMS4wMXYxNDAuODcybDIuMjU4Ljc1M2MxMy42MTQgMCA3My4xNzctNDEuMTMzIDczLjMyMy04NS4yNyAwLTMxLjYyNC0yMS4wMjMtNDUuODI1LTQwLjU1NS01Mi4xOTd6TTE0Ni41MyAxNjQuOGMtMTEuNjE3LTE4LjU1Ny02LjcwNi02MS43NTEgMjMuNjQzLTY3LjkyNSA4LjMyLTEuMzMzIDE4LjUwOSA0LjEzNCAyMS41MSAxNi4yNzkgNy41ODIgMjUuNzY2LTM3LjAxNSA2MS44NDUtNDUuMTUzIDUxLjY0NnptMTguMjE2LTM5Ljc1MmE5LjM5OSA5LjM5OSAwIDAgMC05LjM5OSA5LjM5OSA5LjM5OSA5LjM5OSAwIDAgMCA5LjQgOS4zOTkgOS4zOTkgOS4zOTkgMCAwIDAgOS4zOTgtOS40IDkuMzk5IDkuMzk5IDAgMCAwLTkuMzk5LTkuMzk4em0yLjgxIDguNjcyYTIuMzc0IDIuMzc0IDAgMSAxIDAtNC43NDkgMi4zNzQgMi4zNzQgMCAwIDEgMCA0Ljc0OXoiIGZpbGw9IiNFNTcyMDAiLz48cGF0aCBkPSJNMTAxLjM3MSA3Mi43MDlsLTUuMDIzLTE4LjkwMWMyLjg3NC0xLjgzMiA0Ljc4Ni01LjA0IDQuNzg2LTguNzAxIDAtNS43LTQuNjItMTAuMzItMTAuMzItMTAuMzItNS42OTkgMC0xMC4zMTkgNC42Mi0xMC4zMTkgMTAuMzIgMCA1LjY4MiA0LjU5MiAxMC4yODkgMTAuMjY3IDEwLjMxN0w5NS44IDc0LjM3OGMtMTkuNjA5IDYuNTEtNDAuODg1IDIwLjc0Mi00MC44ODUgNTEuODguNDM2IDQ1LjAxIDU5LjU3MiA4NS4yNjcgNzMuMTg2IDg1LjI2N1Y2OC44OTJzLTEyLjI1Mi0uMDYyLTI2LjcyOSAzLjgxN3ptMTAuMzk1IDkyLjA5Yy04LjEzOCAxMC4yLTUyLjczNS0yNS44OC00NS4xNTQtNTEuNjQ1IDMuMDAyLTEyLjE0NSAxMy4xOS0xNy42MTIgMjEuNTExLTE2LjI4IDMwLjM1IDYuMTc1IDM1LjI2IDQ5LjM2OSAyMy42NDMgNjcuOTI2em0tMTguODItMzkuNDZhOS4zOTkgOS4zOTkgMCAwIDAtOS4zOTkgOS4zOTggOS4zOTkgOS4zOTkgMCAwIDAgOS40IDkuNCA5LjM5OSA5LjM5OSAwIDAgMCA5LjM5OC05LjQgOS4zOTkgOS4zOTkgMCAwIDAtOS4zOTktOS4zOTl6bS0yLjgxIDguNjcxYTIuMzc0IDIuMzc0IDAgMSAxIDAtNC43NDggMi4zNzQgMi4zNzQgMCAwIDEgMCA0Ljc0OHoiIGZpbGw9IiNGRjdGMDAiLz48L3N2Zz4=)

[![Build Status](https://travis-ci.org/willmendil/AVRaft.svg?branch=master)](https://travis-ci.org/willmendil/AVRaft)

AVRaft is a prototyping kit that gives makers a quick way to interact with alternators such as servos, stepper motors, ultrasonic sensor, etc... quickly withouth the need to take out your breadboard, and jumperwires.
The project is still in alpha and changes will acquire quite rapidly. The project was written in C++ using platformio. 

## Feature release!

  - Servo motors

Future integrations:
  - Stepper
  - DC (H-bridge?)
  - Relay
  - Ultrasound
  - Potentiometer
  - Button
  - LED

## 3D build and parts list

This first version of the AVRaft uses of the shelf electronics:

* [ArduinoNano](https://store.arduino.cc/arduino-nano)
* [Breakout nano shielf](https://www.ebay.fr/itm/Nano-V3-0-Prototype-Shield-I-O-Extension-Board-Expansion-Module-For-Arduino/173338546724?ssPageName=STRK%3AMEBIDX%3AIT&var=472048754874&_trksid=p2057872.m2749.l2649)
* [LCD I2C 16x2 screen](https://www.ebay.fr/itm/IIC-I2C-TWI-SP-I-Serial-Interface1602-16X2-Character-LCD-Module-Display-Yellow/252513792517?hash=item3acafeb205:g:sUQAAOSwu4BVk1Gj)
* [Tactil switches](https://www.ebay.fr/itm/20Set-Momentary-Tactile-Push-Button-Touch-Micro-Switch-4P-PCB-Caps-12x12x7ZZ/313155610947?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D20160908105057%26meid%3D186b7a9a61444340a2f6d9713bc0739c%26pid%3D100675%26rk%3D2%26rkt%3D15%26mehot%3Dnone%26sd%3D292942838254%26itm%3D313155610947%26pmt%3D1%26noa%3D1%26pg%3D2380057%26brand%3D-+Sans+marque%2FG%EF%BF%BDn%EF%BF%BDrique+-&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3A05bcb7f4-d499-11ea-a965-74dbd1802f49%7Cparentrq%3Aae42006c1730aad30fbee5c3fff17982%7Ciid%3A1) x3
* [10k resistor](https://www.ebay.fr/itm/x50-Pcs-10K-Ohm-Through-Hole-Resistor-1-10K-1-4-W-0-25-MF25-R215Z/163602093123?_trkparms=ispr%3D1&hash=item261771d443:g:gPUAAOSwItFc4-5k&enc=AQAFAAACYBaobrjLl8XobRIiIML1V4Imu%2Fn%2BzU5L90Z278x5ickkfOCvCjTOBWK8pwriaolq5nN%2B6bLD%2FFZDrcZXXFEH3PrHxAc%2B5gERJjgfLo7FuFyRYI3xvVKWg67PTUEzqpsUslCdVFt2NeHrZjf00e%2FcMRl%2FjWJST9Q49AMbxA2F0AHZIEXVSJx5Ty4kKs5eNG2RUpao1L4REFKg9dMLtAJy698Nd5ZGsaJC835BAcfsrZ%2Bdn9KTOQ%2Btim3YXHW6uHouKc9iDXExqCDpReSFQGCy7qi12LuM1v7yJlU1lO74XqEonlHj%2FOQB4nCrStiy35UxAAVjGPvk%2FGXi3%2Bt3D8CvgK7hcDW7Ckw%2FGEQXc8f5XUvhri4ZPwz9LiIF5TtKfR%2FobdMj85k4dCguvfcEXPw7mE9QrqpZVJF1Rf9q%2FJyQH%2Fs8lVMIhVWMTkPXO1gixGZ8gsdurdM761tTv3X6vUbsNV1vD2quy1WlxEIUf3eExZspZ94mec4gJNiD%2BJFHKuACXLvDg5O7W0p6o70RmVfvkhdtNzF7yrRo02QY0g2Ly42rFfh4qBJADh2Ifx0oTWyQGB%2BYCCRhS9YsBGU6g6HgoKJ6RcHa9rSLxgc9C0v%2FrYZyIojcPyIqGgTsBulT48y1Thlur8vOtjoqszB33652pTYf8Dj1vtoNY%2FXONYQ2GBnR%2FkR%2FxzSZ%2BrCQkksqDES01NlLT8SlHq1GvDEUeNmJcgzhp1qCSscCAbYdIycZaNto%2BJyabpN8iRt%2BgqzBxA98FPivhpwXC9pptvC2PCGPzIWUO5unGnzyFe1qjqhQcARo&checksum=163602093123e7155ccaed9e477495e220e98abd0d84) x3
* [Toggle switch](https://www.ebay.fr/itm/5-x-Mini-Momentary-On-Off-On-Toggle-Switch-Car-Dash-Dashboard-Boat-SPDT-12V/262175715088?hash=item3d0ae3ef10:g:Q9EAAOSwePhZeyZS)
* 9V battery
* [Battery wire socket](https://www.ebay.fr/itm/Connecteur-piles-9-volts-9V-Battery-Snap-on-Connector-Clip-with-Wire-Holder/263047972777?hash=item3d3ee187a9:g:z6IAAOSwd~RZSXKE)

Two 3D printed parts are required. 
#TODO Add details on the printed parts

## Installation

#### From binary
A binary package is available to flash directly on the arduino. 
#todo add flash instruction

#### From source

To compile the code from source, you will need [platformio](https://platformio.org/) installed on your favorite IDE (I used vscode). You will need to install a few dependencies though, basically every library for every supported devices. Below is a list of the libraries as well as the name of the other to elevate confusion.

#### Libraries
| NAME | VERSION | AUTHOR |
| ------ | ------ | ------ |
| LiquidCrystall_I2C | 1.1.4 | Frank de Brabander
| Servo | 1.1.6 | Michael Margolis
| Stepper | 1.1.3 | Arduino

You can then grab the project 
`git clone git@github.com:willmendil/AVRaft.git`

The import the project with platformio. If all the libraries are installed correctly, you should be able to flash your arduino nano directly. 


## Usage
To use this program, you will need to assemble the project and 3D print the enclosure (though you can make it without). You will have to select the device you want to interact with, plug it where it tells you to (e.g. servos D3) and you are done, you are able to quickly test and interact with these devices. For details on the parameters, see below

## Devices
The board supports a number of devices, each with their own parameters. The list of device should grow with time. 

* ### Servo
Pins: 
- IN1: D3

| NAME | DEFAULT | DESCRIPTION |
| ------ | ------ | ------ |
| Angle | 90 | Angle in degrees to which the servo will be set.
| Delay | 5 | Delay in millisecond in for loop to move the servo (only when w/ rst is true).
| w/ rst | 1 | Stands for "with reset", will move the servo to 0 and sweep to the give value, otherwise, the servo will just move to the value given in angle.
| MOVE | - | Move the servo to the given angle.

* ### Stepper
Pins: 
- IN1: D3
- IN2: D6
- IN3: D5
- IN4: D8

| NAME | DEFAULT | DESCRIPTION |
| ------ | ------ | ------ |
| CW | 1 | Set if rotation clockwise (1) or anti clockwise (0).
| Speed | 5 | Speed to move the motor (maximum value is 15 for 28BYJ-48).
| Delay | 5 | Delay in millisecond between steps.
| S/rev (not used) | 2048 | Number of steps per revolution. Small 28BYJ-48 is 2048. 
| MOVE | - | Move the motor until a key is pressed.

note: Tested on 28BYJ-48, for other type of motors, need to do some testing.


### Todos

 - Make custom break out board
 - Add more devices

License
----

GNU General Public License v3.0


**Free Software, Hell Yeah!**

