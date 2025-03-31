# Gkit Documentaion v1.0

Gkit is a collection of functions that help us manipulate pixels on a graphics window to produce images.

To gain access to this library, download the Gkit.py and FPT.so files from this directory. If not already included in your own file set, upload them to the repl you are working in. Then import the functions from the library with these two import statements at the top of your file:

```from Gkit import *```

```from ctypes import *```


### IMPORTANT:

No Gkit functions will run until a call to ```G_init_graphics(w,h)``` (see setUp section below) is made. This call only needs to be done once, at the top of the code. Trying to call Gkit functions prior to this will likely cause a segmentation fault error.

No Gkit functions will run once the call to ```G_close()``` (see Setdown section below) is made. This call only needs to be done once, at the botom of the code. Trying to call Gkit functions after this will likely cause a segmentation fault error. 

### HOW GKIT DRAWS:

Gkit draws in layers. Every function call that changes something on the graphics window, will draw OVER the last thing that was drawn to the screen, in any place where they overlap. This pattern will continue for the entire run of the program

>For instance, if a small green circle was drawn to the center of the window, a larger circle drawn anytime later in the same spot will draw over the small green one, hiding it from view.
>
>Clearing the entire screen with a color (see G_clear() below), will effectively "erase" all things drawn to the screen up until that point. Replacing all the pixels on the screen with the chosen color.
>
Gkit relies on treating the Graphics Window as being made of (x,y) coordinate points. Each pixel making up the Graphics Window has a corresponding (x,y) point that can be set to a color using calls to the Gkit functions.


## 1. SetUp

 __```G_init_graphicsc(w,h)```__
>> Runs the necessary code to establish a ```width x height``` sized graphics window, and display it to the output screen. __This function MUST be called prior to any other calls to any of the Gkit functions.__
>>
>> Any ```width x height``` graphics window generated will have x-axis values from ```0``` to ```width-1```, and y-axis values from ```0``` to ```height-1```
>>
>>  __Arguments:__ ```w``` is the width of the graphics window in pixels. ```h``` is the height of the graphics window in pixels. Give both arguments as ints.
>>
>>  __Return Value:__ nothing, does not return a value
>
>Example:
>```
>screenW = 400
>screenH = 400 
>G_init_graphics(screenW, screenH)
>```



__```G_rgb(r,g,b)```__
>> Uses RGB values to set the color the program will draw next in. All subsequent Gkit function calls that draw images, will be drawn in the selected color until ```G_rgb(r,g,b)``` is called again to change it. ```G_rgb(r,g,b)``` may be called as many times as desired, each subsequent call overrides the color chosen with the last.
>>
>> __Arguments:__```r```, ```g```, and ```b``` each represent a ratio of the RGB color values. They can be any number between 0 and 1. Arguments can be given as ints or floats.
>> 
>>> For Example, to select an RGB value of 255, 0, 100:
>>> ```
>>> r = 255/255
>>> g = 0/255
>>> b = 100/255
>>> ```
>>RGB Color Picker: https://www.rapidtables.com/web/color/RGB_Color.html
>
>> __Return Value:__ nothing, does not return a value
>> 
>
>Example: set the color to an RGB value of 255,0,100 (magenta)
>```
>r = 255/255
>g = 0/255
>b = 100/255
>G_rgb(r,g,b)
>
>```
>
>Example: set the color to black
>```
>r = 0
>g = 0
>b = 0
>G_rgb(r,g,b)
>
>```



__```G_clear()```__
>> Colors all pixels on the screen the most rececently selected RGB color. ```G_rgb(r,g,b)``` must be called prior to a call to ```G_clear()```.
>>
>> __Arguments and Return Value:__  takes no arguments and returns nothing.
>
>Example: colors the entire screen white
>```
>r = 1
>g = 1
>b = 1
>G_rgb(r,g,b)
>G_clear()
>
>```

## 2. Draw to Graphics Window

__```G_point(x,y)```__
>> Colors a single pixel at coordinate (x,y) on the graphics window.
>>
>>  __Arguments__ ```x``` is the location on the x-axis of the pixel. ```y``` is the location on the y-axis of the pixel. Arguments can be given as floats or ints.
>>
>>__Return Value:__ nothing, does not return a value
>> 
>Example: draw a single point in red to the center of a 400 x 400 graphics window
>```
>r = 1
>g = 0
>b = 0
>G_rgb(r,g,b)
>x = 200
>y = 200
>G_point(x,y)
>
>```


__```G_line(xs,ys,xe,ye)```__
>> Draws a straight line between two (x,y) points on the graphics window.
>>
>> __Arguments:__ ```xs``` is the location on the x-axis of the first point, and ```ys``` is the location on the y-axis of the first point. ```xe``` is the location on the x-axis of the second point, and ```ye``` is the location on the y-axis of the second point. Arguments can be given as floats or ints.
>>
>> __Return Value:__ nothing, does not return a value
>> 
>Example: draw a black line from the upper left hand corner to the lower right hand corner on a 400 x 400 graphics window
>```
>r = 0
>g = 0
>b = 0
>G_rgb(r,g,b)
>
>x1 = 0
>y1 = 399
>
>x2 = 399
>y2 = 0
>G_line(x1,y1,x2,y2)
>
>```


__```G_rectangle(xl, yl, w, h)```__
>> Draws the outline of a ```w x h``` sized rectangle based on the (x,y) coordinates of its lower left hand corner. 
>>
>>__Arguments:__ ```xl``` is the location on the x-axis of the lower left corner point, and ```yl``` is the location on the y-axis of the lower left corner point. ```w``` is the width of the rectangle, and ```h``` is the height of the rectangle. Arguments can be given as ints or floats.
>>
>> __Return Value:__ nothing, does not return a value
>
>
>Example: draw a 100 x 50 green rectangle outline whose lower left hand corner is at point (200,200), on 400 x 400 graphics window
>```
>r = 0
>g = 1
>b = 0
>G_rgb(r,g,b,)
>
>lowLeftX = 200
>lowLeftY= 200
>width = 100
>height = 50
>G_rectangle(lowLeftX, lowLeftY, width, height)
>```



__```G_fill_rectangle(xl, yl, w, h)```__
>> Draws a color-filled rectangle of ```w x h``` size based on the (x,y) coordinates of its lower left hand corner. 
>>
>>__Arguments:__ ```xl``` is the location on the x-axis of the lower left corner point, and ```yl``` is the location on the y-axis of the lower left corner point. ```w``` is the width of the rectangle, and ```h``` is the height of the rectangle. Arguments can be given as ints or floats.
>>
>> __Return Value:__ nothing, does not return a value
>> 
>Example: draw a solid blue rectangle to cover the top right hand quandrant on a 400 x 400 graphics window
>```
>r = 0
>g = 0
>b = 1
>G_rgb(r,g,b,)
>
>lowLeftX = 200
>lowLeftY= 200
>width = 400 - lowLeftX
>height = 400 - lowLeftY
>G_fill_rectangle(lowLeftX, lowLeftY, width, height)
>
>```
>
>

__```G_triangle(x1,y1,x2,y2,x3,y3)```__
>> Draws a triangle based on three (x,y) coordinate points. A solid line will connect the first point to the second, the second to the third, and the first to the third.
>>
>>__Arguments:__ ```x1``` is the location on the x-axis of the first point```y1``` is the location on the y-axis of the first point,  ```x2``` is the location on the x-axis of the second point, ```y2``` is the location on the y-axis of the second point, ```x3``` is the location on the x-axis of the third point, ```y3``` is the location on the y-axis of the third point.

>> __Return Value:__ nothing, does not return a value
>> 

>Example: draw a red outline of a triangle from points (0,0), (200,200), (0,399)
>```
>r = 1
>g = 0
>b = 0
>G_rgb(r,g,b)
>
>x1 = 0
>y1 = 0
>x2 = 200
>y2 = 200
>x3 = 0
>y3 = 399
>G_triangle(x1,y1,x2,y2,x3,y3)
>
>```


__```G_fill_triangle(x1,y1,x2,y2,x3,y3)```__
>> Draws a color-filled triangle by connecting three (x,y) coordinate points. 
>>
>>__Arguments:__ ```x1``` is the location on the x-axis of the first point```y1``` is the location on the y-axis of the first point,  ```x2``` is the location on the x-axis of the second point, ```y2``` is the location on the y-axis of the second point, ```x3``` is the location on the x-axis of the third point, ```y3``` is the location on the y-axis of the third point.

>>Arguments can be given as ints or floats.

>> __Return Value:__ nothing, does not return a value
>> 

>Example: draw a solid green of a triangle from points (0,0), (200,200), (399,0)
>```
>r = 0
>g = 1
>b = 0
>G_rgb(r,g,b)
>
>x1 = 0
>y1 = 0
>x2 = 200
>y2 = 200
>x3 = 399
>y3 = 0
>G_fill_triangle(x1,y1,x2,y2,x3,y3)
>
>```
>


__```G_circle(x, y, r)```__
>> Draws the outline of a circle with a radius of ```r``` from some (x,y) centerpoint. The radius is measured in number of pixels.
>>
>>__Arguments:__ ```x``` is the location on the x-axis of the centerpoint, ```y``` is the location on the y-axis of the centerpoint, ```r``` is the length of this circles radius. Arguments can be given as ints or floats.

>> __Return Value:__ nothing, does not return a value
>> 

>
>_Example:_ on a 400 x 400 graphics window, draw the outline of a blue circle whose centerpoint is at (200,200), and that has a radius of 20.
>```
>r = 0
>g = 0
>b = 1
>G_rgb(r,g,b)
>
>centerX = 200
>centerY = 200
>radius = 50
>G_circle(centerX,centerY, radius)
>
>```



__```G_fill_circle(x, y, r)```__
>> Draws a color-filled circle with a radius of ```r``` from some (x,y) centerpoint. The radius is measured in number of pixels.
>>
>>__Arguments:__ ```x``` is the location on the x-axis of the centerpoint, ```y``` is the location on the y-axis of the centerpoint, ```r``` is the length of this circles radius. Arguments can be given as ints or floats.

>> __Return Value:__ nothing, does not return a value
>> 

>_Example:_ draw a solid purple circle whose centerpoint is at (200,200), and that has a radius of 10.
>```
>r = 0.5
>g = 0.5
>b = 1
>G_rgb(r,g,b)
>
>centerX = 200
>centerY = 200
>radius = 20
>G_fill_circle(centerX,centerY, radius)
>
>```
>
## #3. Interactions
>
__```G_wait_key()```__
>> Pauses execution of the code until the user clicks inside the graphics window with the mouse, and hits any key on their keyboard. Code execution resumes once a key has been hit.
>>
>>__Arguments:__ None.

>> __Return Value:__ nothing, does not return a value
>> 

>_Example:_ On a 400 x 400 graphics window, draw a blue circle, wait for a key to be hit, then draw a red circle over the blue one
>```
>r = 0
>g = 0
>b = 1
>G_rgb(r,g,b)
>
>centerX = 200
>centerY = 200
>radius = 20
>G_fill_circle(centerX,centerY, radius)
>
>G_wait_key()
>
>r = 1
>g = 0
>b = 0
>G_rgb(r,g,b)
>
>centerX = 200
>centerY = 200
>radius = 50
>G_fill_circle(centerX,centerY, radius)
>
>```


__```G_wait_click(p)```__
>> Pauses execution of the code until the user clicks inside the graphics window with the mouse.  The coordinates of the users click will be stored inside of ```p```.
>>
>>__Arguments:__ ```p``` must be a predefined ```list``` that has an exact length of 2. The values stored in this list initially should be zeroes. ```G_wait_click(p)``` will modify these two values to reflect the x and y coordinate values from the users click.

>> __Return Value:__ nothing, does not return a value
>>
>_Example:_ click once on the screen to grab the (x,y) coordinates of the click's location, and use the saved values to draw a green circle in that spot:
>```
>
>point = [0,0]
>G_wait_click(point)
>
>centerX = point[0]
>centerY = point[1]
>radius = 20
>
>r = 0
>g = 1
>b = 0
>G_rgb(r,g,b)
>G_fill_Circle(centerX, centerY, radius)
>```

## SetDown

__```G_save_to_bmp_file(fName)```__
>> Saves the image generated by the code, to a BMP format file with the name ```<fName>.bmp```. If no file by this name already exists, this will generate a new file by that name. If a file by this name does already exists it will be overwritten with the current image.
>>
>>__Arguments:__ ```fName``` is a string that represents the name of the file to save the image to. It can be any string.

>> __Return Value:__ nothing, does not return a value
>>
> Example: save the current image to ```blueCircle.bmp```
> ```
>
> r = 0
> g = 0
> b = 1
> G_rgb(r,g,b)
>
> G_fill_circle(200,200,50)
>
> file = "blueCircle.bmp"
> G_save_to_bmp_file(file)
> ```

__```G_close()```__
>> Closes the graphics window completely. Graphics portion of the code is finished at this point, so no more calls to Gkit functions can be made. But program code can still be written and executed as usual.
>>
>>__Arguments:__ None.

>> __Return Value:__ nothing, does not return a value
>>
>> Example: after saving the image to a file, close the graphics window, but continue code that will output to the console```
>> ```
>>
>> r = 0
>> g = 0
>> b = 1
>> G_rgb(r,g,b)
>>
>> G_fill_circle(200,200,50)
>>
>> file = "blueCircle.bmp"
>> G_save_to_bmp_file(file)
>>
>> G_close()
>>
>> print("But this will still print to the console!")
>> print("And so will this: ")
>> x = 10
>> y = 20
>> print("1 + 20 is: ", x + y)
>> ```