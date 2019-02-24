#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <string>   // for strings

 using namespace cv;
 using namespace std;


 char filename[128];
 

 /****************** for calculating the minimum and maximum value of threshold for any image ******************************/

 /*int RedL = 0;
 int RedH = 255;

 int GreenL = 0; 
 int GreenH = 255;

 int BlueL = 0;
 int BlueH = 255;
 */

 int main( int argc, char** argv )
 {
	   
	
/*
	 namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
 
 cvCreateTrackbar("RedL", "Control", &RedL, 255); //Red (0 - 255)
 cvCreateTrackbar("RedH", "Control", &RedH, 255);

 cvCreateTrackbar("GreenL", "Control", &GreenL, 255); //Green (0 - 255)
 cvCreateTrackbar("GreenH", "Control", &GreenH, 255);

 cvCreateTrackbar("BlueL", "Control", &BlueL, 255); //Blue (0 - 255)
 cvCreateTrackbar("BlueH", "Control", &BlueH, 255);
  
  */

	 
	 /********************************** capturing the video for the referance background ***************************************/
    VideoCapture back("C:\\Users\\bsrc\\Google Drive\\IIIT Hyderabad\\MS 1st SEM\\Computer Vision\\ASSIGNMENT 1\\201532655\\Chroma Keying\\back.mp4");

	
	/*************************************** reading the original video ************************************/
	VideoCapture front ("C:\\Users\\bsrc\\Google Drive\\IIIT Hyderabad\\MS 1st SEM\\Computer Vision\\ASSIGNMENT 1\\201532655\\Chroma Keying\\front.mp4");

    if ( !back.isOpened() || !front.isOpened() )  // if not success, exit program
        {
		 cout << "Cannot open the videos" << endl;
         return -1;
        }

	
   double imgWidth =  front.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double imgHeight = front.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
			 
            cout << "Frame Size = " << imgWidth << "x" << imgHeight << endl;  // printing the data obtained

	   // setting this framesize for the frame in which image will be opened
			Size frameSize(static_cast<int>(imgWidth), static_cast<int>(imgHeight));  
	
			// VideoWriter writevideo ("C:\\Users\\bsrc\\Desktop\\xyz.avi", CV_FOURCC('F','L','V','1'), 25, frameSize, true);CV_FOURCC('D','I','V','X')
		 VideoWriter writevideo ("C:\\Users\\bsrc\\Google Drive\\IIIT Hyderabad\\MS 1st SEM\\Computer Vision\\ASSIGNMENT 1\\201532655\\Chroma Keying\\Chromakeyvideo.wmv", CV_FOURCC('W','M','V','1') , 25, frameSize, true); 
	  
	    namedWindow("Replaced background Image",CV_WINDOW_AUTOSIZE);

 /*************************** opening the video frames *****************************/

      while (true)
    {  
		Mat imgOriginal;
        Mat final;
        Mat imgplace;
        

	
		bool bSuccess = front.read(imgOriginal); // read a new frame from video
		bool bSuccess1 = back.read(imgplace); // read a new frame from video
		
		if (!bSuccess || !bSuccess1 ) //if not success, break loop
        {
            
			cout << "Cannot read a frame from video stream" << endl;
             break;
        }

		
		/******************************************* CHROMA KEYING PROCESSING ********************************************/    
     // Create the destination matrix "final"
      final = Mat(imgplace.rows,imgplace.cols,CV_8UC3);
	  
	   for(int y=0; y<imgplace.rows; y++) 
		  {
              for(int x=0; x<imgplace.cols; x++) 
			    {
	              //if (imgOriginal.at<Vec3b>(y,x)[0] >= RedL && imgOriginal.at<Vec3b>(y,x)[0] <= RedH && imgOriginal.at<Vec3b>(y,x)[1] >= GreenL && imgOriginal.at<Vec3b>(y,x)[1] <= GreenH && imgOriginal.at<Vec3b>(y,x)[2] >= BlueL && imgOriginal.at<Vec3b>(y,x)[2] <= BlueH) 
                  if (imgOriginal.at<Vec3b>(y,x)[0] >= 0 && imgOriginal.at<Vec3b>(y,x)[0] <= 150 && imgOriginal.at<Vec3b>(y,x)[1] >= 171 && imgOriginal.at<Vec3b>(y,x)[1] <= 243 && imgOriginal.at<Vec3b>(y,x)[2] >= 42 && imgOriginal.at<Vec3b>(y,x)[2] <= 217)      
					
					      {
							    final.at<Vec3b>(y,x)[0]  = imgplace.at<Vec3b>(y,x)[0]; 
                         		final.at<Vec3b>(y,x)[1]= imgplace.at<Vec3b>(y,x)[1]; 
								final.at<Vec3b>(y,x)[2]= imgplace.at<Vec3b>(y,x)[2];
								
				          }
					else
						  {     

								final.at<Vec3b>(y,x)[0]= imgOriginal.at<Vec3b>(y,x)[0];
						        final.at<Vec3b>(y,x)[1]= imgOriginal.at<Vec3b>(y,x)[1];
						        final.at<Vec3b>(y,x)[2]= imgOriginal.at<Vec3b>(y,x)[2];
						   }
					      
			      }
	      } 

     	  		
                          
    imshow("Replaced background Image", final); //show the thresholded image

	writevideo.write(final); //writer the frame into the file    
		
		 if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       } 
     
	  
   }
 }


	

 

   	