

# JOYPAD

![joypad][1]

In this projetc i'm using a couple of old harddisk motor to build a new controller generation :) 
In this controller you have 2 rotative encoder (the 2 old harddisk brushelss motors), an Arduino, and a Bluetooth module.
Using bluetooth it's possible to interface this controller to any Android device (phone, phablet, tables) and to any pc (win/linux, don't know if mac is ok).

It's easy to use, and the idea of this project was born thinking to the **Etch & Sketch** interface.

My aim was to build also a **ZY plotter** and to drive it directly with this interface (like an Etch & Sketch 2.0 ). Maybe it will be ready for the MFR 14.

In the meanwhile, i realized an application for pc and Android that replicates the Etch & Sketch beaviour, and that you can play with using this new Joypad .
I designed also the case of this joypad and print it with my prusa i2.
Here a few photos of the backstage: http://bit.ly/JoyPad_photos

Source code (for Arduino, Android, PC and 3d .STL) soon!)

## BOM
### Electronic parts
**2x brushless motor** (BLCD)
you can find them in old hdds

**1x Arduino Mini / Nano**
the size is important :)

**1x Bluetooth Module HC-0X**
you can use any cheap HC-0X module

**1x BoostUp/StepUp**
you need this to power Arduino at 5v using only 2 AA batteries

**1x Battery Holder** (x 2AA batteries) - you can also print it


### Plastic parts
I've designed a few components.
You can find the source files (OpenSCAD) and STL here:
http://www.thingiverse.com/thing:364735

**1x case**

![enter image description here][2]

remember to print it using:
infill density=0, top solid layers=0, perimeters=4
 
**1x mask**

![enter image description here][3]


**2x knob**

Here you can choose you preferred version, or edit the parametric source file.
I like this:

![enter image description here][4]


  [1]: https://lh3.googleusercontent.com/-KqerylRjUac/U54qSr1es1I/AAAAAAAAQOQ/-PJLQkZsb5I/s1152/IMAG4746.jpg
  [2]: https://lh5.googleusercontent.com/-M71InRvu7HA/U54rGcoRdGI/AAAAAAAAQOg/Yq4ROLKxcvA/s731/Screenshot%2520-%252006162014%2520-%252001%253A23%253A41%2520AM.png
  [3]: https://lh5.googleusercontent.com/-8miuhkWCG7s/U54rnYrNDLI/AAAAAAAAQO4/jI7NQL4_69c/s717/Screenshot%2520-%252006162014%2520-%252001%253A28%253A18%2520AM.png
  [4]: https://lh5.googleusercontent.com/-9F9UkDHOWWs/U54ddUXt_oI/AAAAAAAAQNM/IktOU1f8dZU/s735/Screenshot%2520-%252006152014%2520-%252002%253A56%253A39%2520PM.png
