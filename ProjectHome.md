The aim of this project is the development of a New TUIO Simulator for fast development and debugging of Multi-touch Applications.TUIO is a versatile protocol, designed specifically to meet the requirements of table-top tangible user interfaces.In order to develop applications one has to wait till one gets the required multi-touch screen.There is a Java based TUIO simulator but it does not help in utilizing the full capabilities of the protocol and only preliminary applications can be developed using it.

This project aims at a new Qt based fast and full featured simulator for Multi-Touch applications.The functionalities implemented are  :

1. User will be able to add customizable polygons to the table and thus the application could be developed for all sort of items.

2. The items will be able to rotate and translate independently and concurrently too.

3.The user will be able to set a path for the items to follow during the animation run and hence he/she will be relieved of moving the items again and again by the mouse.
The points on the path is given by clicking which are interpolated using Bezier curves.

4.The items created can be saved individually or in groups as a session in an XML file which can be reloaded on a future run so that the same gestures could be repeated again.

5.The simulator is now able to transmit TUIO data for multiple instances of both cursor and object - for created as well as  uploaded items .

6.On the animation timeline , the objects can now be set to animate during a normalized time period, so that changing the timeline affects the period of animation equally to all.

7. Multiple customizable TUIO sender can be set.

8. Two-finger emulation with right click supported. This is a most wanted feature from the  Apple Simulator and can be used to simulate pinching and zooming !!

9. Opacity control helps you make the simulator transparent and keep it above the application, thus giving an impression of touching the application itself.

10. Resize Table to fit your multi touch application.



**SIMTOUCH** : SimTouch is another TUIO simulator build using the Adobe Air runtime. The core benefit to using SimTouch is the transparent background allowing the application developer to have a better grasp of what he/she is 'touching'
http://code.google.com/p/simtouch/