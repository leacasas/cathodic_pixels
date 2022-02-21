# Cathodic Pixels


_Trying to imitate old CRT TVs feel_

This is an algorithm that I made on 2021, which I intended to update and improve.

Code is within a Visual Studio 2022 solution and projects. Download, check if the openFrameworks reference path is correctly set and execute.

----
The steps of the most important aspect of this algo are very simple:

1. Load image and read color information for each channel
2. Map those color values in a 0-to-1 sliding scale.
3. Use those values to control parameters such as size and alpha of a figure (I do this)
4. Repeat for each pixel in the image

Additionally, I use that sliding scale to make some animation transitions between images.

> Screenshots of the effect:

> ![1](/bin/data/screenshots/173.png "")
> ![2](/bin/data/screenshots/418.png "")
> ![3](/bin/data/screenshots/604.png "")
> ![4](/bin/data/screenshots/754.png "")

----

made by Leandro Gabriel Casas ([@leandrogcasas](https://twitter.com/LeandroGCasas))
