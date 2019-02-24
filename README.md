# Computer-Vision-Chroma-Keying

How to run this code:
Since this code is written in visual studio in windows 7, which does not have in-build C++ compiler, visual studio 2010  (comaptible with openCV 2.4.11) needs to be installed, for running the code, while testing.

Make file is not attached as code has been written and run in visual studio in windows7. 


         
Steps to install and configure visual studio with openCV 


Right click on 'My Computer' and click 'Properties' in the drop down menu. 

Click 'Advance System Settings' in the above window

Then click 'Environment Variables'.

Then click 'New' button at the bottom of the window

Type OPENCV_DIR against Variable name:. And type the location C:\opencv\build\x86\vc10\bin (path of the bin folder inside openCV according to system configuration(32bit or 64 bit) against the Variable value:. 


   
 Configure Visual Studio Express

Details of the step to install and configure openCV and include dll files, libraries and additional dependencies can be found in the below link.

http://opencv-srf.blogspot.in/2013/05/installing-configuring-opencv-with-vs.html

Once the configuration and installation is done, the main.cpp file (in the folder) code is copied into the visual studio and the libraries and dll files of openCV are configured with visual studio, before runing the code.
Also, the paths of the video and image files need to be changed, before building the code in openCV.

If everything is fine, the resulting video or image will be opened(in specified window) or saved(in specifed folder) as mentioned in code.
