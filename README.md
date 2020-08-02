# avrDevKit

Project in alpha. The idea is to make a small hand held arduino station that enables makers to quickly and easily test and set motors, sensors and other electronics without the need to fetch jumper wires etc... 

The program is written in C++ using platformio. The 3D files are also available to print with the details in the 3DPrint folder. Regarding the parts list, you will need: 

arduino nano
some sort of shield

So far the supports devices are:

- Servo



# AVRaft

[![N|Solid](https://cldup.com/dTxpPi9lDf.thumb.png)](https://nodesource.com/products/nsolid)

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

AVRaft is a prototyping kit that gives makers a quick way to interact with alternators such as servos, stepper motors, ultrasonic sensor, etc... quickly withouth the need to take out your breadboard, and jumperwires.
The project is still in alpha and changes will acquire quite rapidly. The project was written in C++ using platformio. 

# Feature release!

  - Servo motors

Future integrations:
  - Stepper
  - DC (H-bridge?)
  - Relay
  - Ultrasound
  - Potentiometer
  - Button
  - LED

### 3D build and parts list

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

### Installation

#### From binary
A binary package is available to flash directly on the arduino. 
#todo add flash instruction

#### From source

To compile the code from source, you will need platformio installed on your favorite IDE (I used vscode)
#### Dependencies
| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md][PlDb] |
| GitHub | [plugins/github/README.md][PlGh] |
| Google Drive | [plugins/googledrive/README.md][PlGd] |
| OneDrive | [plugins/onedrive/README.md][PlOd] |
| Medium | [plugins/medium/README.md][PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md][PlGa] |


Install the dependencies and devDependencies and start the server.

```sh
$ cd dillinger
$ npm install -d
$ node app
```

For production environments...

```sh
$ npm install --production
$ NODE_ENV=production node app
```

### Plugins

Dillinger is currently extended with the following plugins. Instructions on how to use them in your own application are linked below.

| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md][PlDb] |
| GitHub | [plugins/github/README.md][PlGh] |
| Google Drive | [plugins/googledrive/README.md][PlGd] |
| OneDrive | [plugins/onedrive/README.md][PlOd] |
| Medium | [plugins/medium/README.md][PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md][PlGa] |


### Development

Want to contribute? Great!

Dillinger uses Gulp + Webpack for fast developing.
Make a change in your file and instantaneously see your updates!

Open your favorite Terminal and run these commands.

First Tab:
```sh
$ node app
```

Second Tab:
```sh
$ gulp watch
```

(optional) Third:
```sh
$ karma test
```
#### Building for source
For production release:
```sh
$ gulp build --prod
```
Generating pre-built zip archives for distribution:
```sh
$ gulp build dist --prod
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 8080, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
docker build -t joemccann/dillinger:${package.json.version} .
```
This will create the dillinger image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 8080 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```

#### Kubernetes + Google Cloud

See [KUBERNETES.md](https://github.com/joemccann/dillinger/blob/master/KUBERNETES.md)


### Todos

 - Write MORE Tests
 - Add Night Mode

License
----

MIT


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
