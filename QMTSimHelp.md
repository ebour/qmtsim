# QMTSim Help #

QMTSim is a new advanced multi touch simulator based on Qt 4.4. Its written in C++ so now onwards there will be no JVM :)
The simulator helps you add new items ( both a tangible and a cursor ) in real time , customize their property and delete them when not required.
It also lets you define a path for the item to follow during the animation run.You can define the path by selecting points on the path  which are then joined using bezier curves giving a smooth path.The item with its properties along with its path if specified can be saved in a XML file which can be reloaded in future.All the items that are selected are saved in the same file. Thus selective bunch of items can be saved and uploaded.The path of the item can be changed also.
QMTSim also has the support for two-finger emulation with right click.
More features are discussed below in the appropriate section.
Hope you enjoy using QMTSim. For any more feature request or bug , please mail to mr.ashish.rai@gmail.com


# Details #

**Right and Left Mouse Clicks** : Using the left click you can emulate a single finger touch which you can navigate using the mouse without lifting the mouse finger. Two-finger touch for zooming etc can be emulated using the right click.You control one of the cursor with the mouse movement while the other is a mirror image of the first. The cursor is destroyed as soon as you lift your finger up and cursors with new IDs are created at next usage.

**Adding New Items**
: All types of 2D geometrical figures can be created and added to the table to represent various tangibles.These items can be stored in XML files for future use.

  * Add Polygon : A polygon can be added by specifying its vertices in a closed format ie you have to repeat the first vertex as the last vertex.Fiducial attached to it and its color can be specified too.

  * Add Ellipse : For sake of geometrical completeness, you can add an ellipse on the table by providing the rectangle containing it and specifying where to place it on the scene.

  * Add Cursor  : In order to support multiple cursors, an extra class of items called cursors is implemented which sends cursor data and thus emulates multiple cursors on the table.

**Delete Item** : All the items that are selected ( multiple items can be selected using Ctrl + left click ) can be deleted .

**Set Path** :With just one mouse at your disposal , even if you have multiple objects you can move just one at a time and hence will not be able to produce complex gestures. In order to overcome this, you can specify the path to be followed by the items which are required to move by providing points on the scene which are then joined using Bezier curve producing a smooth path.You can even provide normalized time period between which the motion should occur. Normalized time period helps you inflate or deflate the time of animation and the items co-ordinate accordingly to run in the stipulated time period.The points can be provided with the mouse or can be added numerically. The smoothness of the path formed between the points can be varied too.

**Start Animation** All the items whose path has been set will follow their path in the stipulated normalized time for the animation time set ( which is by default 10000 ms ).
The percentage of animation time is shown in the progress bar. You can **forward or backward  the animation time** using the animation timeline at the speed of your mouse.The animation can be paused and then restarted.

**NOTE** : Even while the animation is running , you are free to move objects with the mouse and use the cursor associated with the right and left clicks of the mouse.However it is advisable not to move items which are under animation.

**Reset Animation** : After the animation has been done, it can be re-started right from the place where they are present or changed with the mouse.They can all be set to their starting position by the Reset button.

**Save and Upload** : Once an item is created, it can be saved along with its all properties in an XML file and can be uploaded for future use leading to reuse of your hard work building the gesture. Items can be selectively saved by choosing only those items with ctrl-left click for multiple objects.Thus several gestures can be saved individually or as a session and uploaded in a similar fashion.

**Debug** : Debug window has been implemented as an external non-modal window which shows on when the debug is triggered from the file menu. The debug window comprises of four small views which shows the IDs of the alive tangibles and cursors separately and also what values are send in a SET TUIO data.

**TUIO Transmission** : The TUIO dats is not started to transmit until this button is pressed. A default TUIO sender is connected to 127.0.0.1 at port number 3333. Extra TUIO senders can be set using **Configure Transmission** by specifying appropriate address and port number. Currently there is support only for UDP packets.

**Opacity Control** :  A slider is provided to change the opacity of the QMTSim main window.This will help to keep the simulator just above the application, make QMTSim transpaernt , do a bit of resizing and then both the application and QMTSim will work in the same frame and give an impression that the application itself is loaded in the simulator.

**Resize Table**: The table, represented by the rectanguluar region, can be resized dynamically from a dialog which pops up when Menu->Resize Table is triggered. The dialog contains two sliders which control the height and width of the table.

When QMTSim is started, it starts with an opacity of 0.5 and buttons on the main window being hidden. The buttons can be viewed by Menu->View. They can again be hidden by Menu->View.

![http://mrashish.files.wordpress.com/2008/08/update10.jpg](http://mrashish.files.wordpress.com/2008/08/update10.jpg)


![http://mrashish.files.wordpress.com/2008/08/update11.jpg](http://mrashish.files.wordpress.com/2008/08/update11.jpg)

Please report any bug or query or feature-request to **mr.ashish.rai@gmail.com**

**HOPE YOU ENJOY USING QMTSim**