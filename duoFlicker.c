float oldRGB[3],delta[3],RGB[3]; // global color values for RGB last, current and delta values
int dbg=0; // used to enable various debug printf statements to illustrate conditional debug data output

void getColors() // gets random values for the three RGB values
{
    int j,minj; //for loop variable and store of index of smallest value
    float minxcv=1.0; // variable to store lowest color value
    for (j=0;j<3;j++) // j goes from 0 to 2 over the for loop to get all three color values
    {
       RGB[j]=sqrt((float)rand()/0x7fffffff); // use random function rand to get random color values
       // 0x7fffffff  is max possible value of rand() // get new light value as a fraction from0.0 to 0.99999...
       delta[j]=(RGB[j]-oldRGB[j])/100.0; // calculate delta for stepping color chnage over 100 values
       if (RGB[j]<=minxcv) {minxcv=RGB[j];minj=j;} // set minj to index of smallest color value
       if (dbg==1) printf("value -> %f delta -> %f\n",RGB[j],delta[j]); // conditional debug output
    }
    // set smallest color to near zero to eliminate any persistant white colors
    RGB[minj]=0.001; //set smallest color value to near zero
    delta[minj]=(0.001-oldRGB[minj])/100.0; //recalculate delta for smallest color
}

void getSingleColor(int color)
{
   RGB[color]=sqrt((float)rand()/0x7fffffff); // use random function rand to get random color values
   // 0x7fffffff  is max possible value of rand() // get new light value as a fraction from0.0 to 0.99999...
   delta[color]=(RGB[color]-oldRGB[color])/100.0; // delta used to update colors in 100 smakk increments
}

void setValues()
{
    int j; // loop variable
	setRemoteHost("localhost");
    if (dbg==1) printf("%f %f %f deltas %f %f %f\n",oldRGB[0],oldRGB[1],oldRGB[2],delta[0],delta[1],delta[2]);
    // for debug print the old color and new delta values
    for (j=1;j<101;j++) // 100 increment values used
    {
      if (dbg==1) printf("%d\n",j); // degub print of loop iterator
      bAnalogWrite(11,oldRGB[0]+delta[0]*j); 
      bAnalogWrite(12,oldRGB[1]+delta[1]*j); 
      bAnalogWrite(13,oldRGB[2]+delta[2]*j); 
      Sleep(10000); // sleep 10 milliseconds between increments
      // usleep values specified in microseconds
   }
   for (j=0;j<3;j++) // loop to update final values in oldRGB
   {
      oldRGB[j]+=delta[j]*100.0; // final value is oldRGB + delta * 100
      if (oldRGB[j]<0.0) oldRGB[j]=0.001; // arithmetic errors in floats could make oldRGB negative so fix it
   }
   Sleep(500000); // sleep 0.5 seconds to show final color combinations
}
  int i,j; // loop variables
//  pwmSetup(11,0,10000); // initialize pwm on pin 18
//  pwmSetup(12,0,10000); // initialize pwm on pin 19
//  pwmSetup(13,0,10000); // initialize pww on pin 20
  for (j=0;j<3;j++) {oldRGB[j]=RGB[j]=0.001;delta[j]=0.0;} // give color values and deltas an initial value
  while (1) // do forever
  {
       // start with zero values
       //vary each color individually
       for (j=0;j<3;j++) // three colors
       {
          if (dbg==1) printf("\nColor %d\n",j);
          for (i=0;i<4;i++) // set random colors to led for times
           {getSingleColor(j);setValues();} // get single color value and update pwm outputs
          oldRGB[j]=RGB[j]=0.001; // set last color value to near zero
          delta[j]=0.0; // set last color delta to zero
       }
       // now set all three colors to random values
       for (i=0;i<800;i++) // do 800 iterations
       {
         /*if (i==7) dbg=1*/;
         if (dbg==1) printf("i %d ->",i); // conditional debug output
         getColors(); // get three random color values
         setValues(); // set values using a routine that steps the color changes
       }
       //when to iterations are complete do it again

   }

